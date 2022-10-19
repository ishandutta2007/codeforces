#include"bits/stdc++.h"
#define ll long long
using namespace std;
ll mod=1000000007;
int main()
{
    int n,l,r,m;
    cin>>n>>l>>r;
    ll a[3]={0};
    while((r-l)%3)
    {
        a[l%3]++;
        l++;
    }
    a[l%3]++;
    a[0]+=(r-l)/3;
    a[1]+=(r-l)/3;
    a[2]+=(r-l)/3;
    ll ans[3]={1};
    for(int i=0;i<n;i++)
    {
        ll a0,a1,a2;
        a0=ans[0];
        a1=ans[1];
        a2=ans[2];
        ans[0]=a0*a[0]+a1*a[2]+a2*a[1];
        ans[1]=a0*a[1]+a1*a[0]+a2*a[2];
        ans[2]=a0*a[2]+a1*a[1]+a2*a[0];
        ans[0]%=mod;
        ans[1]%=mod;
        ans[2]%=mod;
    }
    cout<<ans[0]<<endl;
    return 0;
}