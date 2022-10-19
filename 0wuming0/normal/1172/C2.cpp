#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
int a[200005];
int b[200005];
ll dp[3005];
ll suma,sumb;
ll pows(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)
    {
        if(b&1)ans=ans*a%mod;
    }
    return ans;
}
ll dev(ll n)
{
    return pows(n%mod,mod-2);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)scanf("%d",b+i);
    for(int i=1;i<=n;i++)
    {
        if(a[i])
        {
            suma+=b[i];
        }
        else sumb+=b[i];
    }
    dp[0]=1;
    for(int num=0;num<m;num++)
    {
        for(int i=num;i>=0;i--)
        {
            int j=num-i;
            ll devn=dev(suma+i+sumb-j);
            dp[i+1]=(dp[i+1]+(suma+i)*devn%mod*dp[i])%mod;
            dp[i]=(sumb-j)*devn%mod*dp[i]%mod;
        }
    }
    ll ansa=0,ansb=0;
    for(int i=0;i<=m;i++)
    {
        int j=m-i;
        ansa+=i*dp[i]%mod;
        ansb+=j*dp[i]%mod;
    }
    ansa%=mod;ansb%=mod;
    ll deva=dev(suma);
    ll devb=dev(sumb);
    for(int i=1;i<=n;i++)
    {
        if(a[i])cout<<b[i]*(deva*ansa%mod+1)%mod<<endl;
        else cout<<b[i]*(1-devb*ansb%mod+mod)%mod<<endl;
    }
    return 0;
}
/*
2 0
0 1
2 1
*/