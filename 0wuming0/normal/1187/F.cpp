#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1e9+7;
ll l[200005],r[200005];
ll invlen[200005];
ll e[200005];
ll se[200005];
ll pows(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
    }
    return ans;
}
ll inv(ll n)
{
    return pows(n,mod-2);
}
ll f(int i,int j)
{
    return max(0ll,min(r[i],r[j])-max(l[i],l[j])+1);
}
ll f(int i,int j,int k)
{
    return max(0ll,min(min(r[i],r[j]),r[k])-max(max(l[i],l[j]),l[k])+1);
}
ll ans1,ans2,ans;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%lld",l+i);
    for(int i=0;i<n;i++)scanf("%lld",r+i);
    for(int i=0;i<n;i++)invlen[i]=inv(r[i]-l[i]+1);
    //for(int i=0;i<n;i++)printf("%lld%c",invlen[i]," \n"[i==n-1]);
    //ll sum=0;
    for(int i=1;i<n;i++)
    {
        e[i]=f(i-1,i)*invlen[i-1]%mod*invlen[i]%mod;
        e[i]=1-e[i];
        e[i]%=mod;
        if(e[i]<0)e[i]+=mod;
    }
    for(int i=n-1;i>=1;i--)
    {
        se[i]=se[i+1]+e[i];
        se[i]%=mod;
    }
    for(int i=1;i<=n-3;i++)
    {
        ans2+=e[i]*se[i+2]%mod;
        ans2%=mod;
    }
    for(int i=2;i<n;i++)
    {
        ans2+=f(i-2,i-1,i)*invlen[i-1]%mod*invlen[i]%mod*invlen[i-2]%mod;
        ans2+=e[i]+e[i-1]+mod-1;
        ans2%=mod;
    }
    ans2=ans2*2%mod;
    ans1=3*se[1]%mod+1;
    ans=ans1+ans2;
    cout<<ans%mod<<endl;
    return 0;
}