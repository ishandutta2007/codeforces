#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1e9+7;
ll pows(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)
    {
        if(b%2)ans=ans*a%mod;
    }
    return ans%mod;
}
ll dev(ll n)
{
    return pows(n,mod-2);
}
ll jie[1005];
int solve(int pos,int n,int &ans1,int &ans2)
{
    ans1=ans2=0;
    int left=0;
    int right=n;
    while(left<right)
    {
        int m=(left+right)/2;
        if(m!=pos)
        {
            if(m<pos)ans1++;
            else ans2++;
        }
        if(m<=pos)left=m+1;
        else right=m;
    }
}
int main()
{
    jie[0]=jie[1]=1;
    for(int i=2;i<=1000;i++)jie[i]=jie[i-1]*i%mod;
    int n,x,pos;
    cin>>n>>x>>pos;
    int ans1,ans2;
    solve(pos,n,ans1,ans2);
    int l,r;
    l=x-1;
    r=n-x;
    if(l<ans1||r<ans2)cout<<0<<endl;
    else
    {
        ll ans=jie[n-1-ans1-ans2];
        ans=ans*jie[l]%mod;
        ans=ans*jie[r]%mod;
        ll dans=jie[l-ans1]%mod*jie[r-ans2]%mod;
        ans=ans*dev(dans)%mod;
        cout<<ans<<endl;
    }
    return 0;
}