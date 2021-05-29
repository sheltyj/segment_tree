#include<bits/stdc++.h>
using namespace std;
const int N=100001;
const int mod=1e9+7;


int a[N];
int st[4*N];

int constructST( int si, int l, int r)
{
    if(l==r)
    {
        st[si]=a[l];
        return a[l];
    }
    int mid=(l+r)/2;
    st[si]=constructST(2*si+1,l,mid) + 
           constructST(2*si+2,mid+1,r);
    return st[si];
}
int getSum(int si, int sl,int sr, int l, int r)
{
    if(l<=sl && sr>=r) return st[si];
    if(sr<l || sl>r ) return 0;
    int mid=(sl+sr)/2;
    return getSum(2*si+1, sl,mid,l,r)+
           getSum(2*si+2,mid+1,sr,l,r);

}
void Update(int si, int sl,int sr,int i, int diff)
{
    if(i>=sl && i<=sr)
    {
        st[si]+=diff;
        if(sl==sr) return;
        int mid=(sl+sr)/2;
        Update(2*si+1,sl,mid,i,diff);
        Update(2*si+2,mid+1,sr,i,diff);
    }
    return;
    
}


class NumArray {
public:
    
    
    int n=0;
    NumArray(vector<int>& nums) {
         n=nums.size();
        for(int i=0;i<n;i++) a[i]=nums[i];
        constructST(0,0,n-1);
        
    }
    
    void update(int i, int val) {
        int diff=val-a[i];
        a[i]=val;
        Update(0,0,n-1,i,diff);
    }
    
    int sumRange(int i, int j) {
        return getSum(0,0,n-1,i,j);
    }
};