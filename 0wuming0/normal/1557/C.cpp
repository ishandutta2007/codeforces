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
ll dp[200005];
ll _2[200005];
ll solve(ll n,ll k)
{
    if(k==0)return 1;
    if(n%2)
    {
        return (_2[n-1]+1)*solve(n,k-1)%mod;
    }
    else
    {
        return ((_2[n-1]-1)*solve(n,k-1)+dp[k-1])%mod;
    }
}
int main()
{
    _2[0]=1;
    for(int i=1;i<=200000;i++)_2[i]=_2[i-1]*2%mod;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        dp[0]=1;
        for(int i=1;i<=200000;i++)dp[i]=dp[i-1]*_2[n]%mod;
        cout<<solve(n,k)<<endl;
    }
    return 0;
}