#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1e9+7;
ll dev(ll a)
{
    ll ans=1;
    ll b=mod-2;
    for(;b;b>>=1,a=a*a%mod)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
    }
    return ans;
}
ll dp[1005][1005];
int main()
{
    ll k,a,b;
    cin>>k>>a>>b;
    ll c=dev(a+b);
    a=a*c%mod;b=b*c%mod;
    ll fi=dev(b);
    ll se=dev(a);
    for(int i=1;i<=1000;i++)
    {
        dp[i][i]=(i+fi-1)%mod;
        for(int j=i+1;j<=1000;j++)
        {
            dp[j][i]=(dp[j-1][i]+1)%mod;
        }
    }
    for(int i=1;i<=1000;i++)for(int j=i-1;j>=1;j--)
    {
        dp[j][i]=(a*dp[j+1][i]+b*dp[j][i-j]%mod+b*j)%mod;
    }
    cout<<dp[1][k]<<endl;
    return 0;
}