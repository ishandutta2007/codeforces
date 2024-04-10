#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll ans[200005];
ll r[200005];
ll gcd(ll a,ll b)
{
    if(a==0||b==0)return a+b;
    return gcd(b,a%b);
}
ll solve2(ll r,ll mod)
{
    ll q=r/mod*mod;
    ll ans=0;
    ans+=(r/mod+1)*(r-q+1);
    ll n=r/mod;
    ans+=n*(n+1)/2*mod;
    return ans;
}
ll solve(ll l,ll r,ll mod)
{//cout<<l<<"  "<<r<<endl;
    if(l==0)return solve2(r,mod);
    return solve2(r,mod)-solve2(l-1,mod);
}
int main()
{
    ll n,a,b;
    cin>>n>>a>>b;
    ll g=gcd(a,b);
    ll k=a/g;//cout<<g<<endl;
    ll m=0;
    ll now=0;
    for(int i=1;i<k;i++)
    {
        if(now<b)now+=(b-now)/a*a;
        while(now<b)now+=a;
        m=max(m,now);
        now-=b;
        ans[i]=m;
    }
    m=0;
    for(int i=1;i<k;i++)
    {
        m-=b;
        m%=a;
        if(m<0)m+=a;
        r[i]=m;
    }
    ll anss=0;
    for(int i=0;i<k;i++)
    {
        //cout<<ans[i]<<"  "<<r[i]<<endl;
        if(ans[i]>n)continue;
        anss+=solve(ans[i]-r[i],n-r[i],a);
    }
    cout<<anss<<endl;
    return 0;
}