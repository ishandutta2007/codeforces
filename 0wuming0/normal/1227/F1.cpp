#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
ll jie[200005],devjie[200005];
ll dev[200005];
ll _2[200005];
ll _k[200005];
ll c(ll n,ll m)
{
    return jie[n]*devjie[m]%mod*devjie[n-m]%mod;
}
int a[200005];
ll solve2(ll n)
{
    if(n%2)return _2[n-1];
    else
    {
        ll ans=(_2[n]-c(n,n/2))*dev[2]%mod;
        if(ans<0)ans+=mod;
        return ans;
    }
}
ll solve(ll n,ll k)
{
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=solve2(n-i)*c(n,i)%mod*_k[i]%mod;
    }
    return ans%mod;
}
int main()
{
    jie[0]=devjie[0]=1;
    dev[1]=1;jie[1]=devjie[1]=_2[0]=1;
    for(int i=2;i<200005;i++)dev[i]=(mod-mod/i)*dev[mod%i]%mod;
    for(int i=2;i<200005;i++)
    {
        jie[i]=jie[i-1]*i%mod;
        devjie[i]=devjie[i-1]*dev[i]%mod;
    }
    for(int i=1;i<200005;i++)_2[i]=_2[i-1]*2%mod;
    ll n,k;
    cin>>n>>k;
    ll s=0,ans=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=a[(i+1)%n])s++;
    }
    for(int i=s;i<n;i++)ans=ans*k%mod;
    _k[0]=1;
    for(int i=1;i<200005;i++)_k[i]=_k[i-1]*(k-2)%mod;
    ans=ans*solve(s,k)%mod;
    cout<<ans<<endl;
    return 0;
}