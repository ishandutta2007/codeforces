#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[100005];
ll b[100005];
ll n,k;
ll check(ll m)
{
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=0,r=a[i]+1;
        while(l+1!=r)
        {
            int x=l+r>>1;
            if(a[i]-1-3ll*x*(x+1)<m)r=x;
            else l=x;
        }
        b[i]=l;
        ans+=l;
    }
    return ans;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    ll l=-4e18;
    ll r=1e10;
    while(l+1!=r)
    {
        ll x=l+r;
        x/=2;
        if(check(x)<=k)r=x;
        else l=x;
    }
    k-=check(r);
    multimap<ll,int>mp;
    for(int i=1;i<=n;i++)
    {
        mp.insert(make_pair(a[i]-1-3*b[i]*(b[i]+1),i));
    }
    while(k--)
    {
        auto it=mp.end();
        it--;
        int i=it->second;
        mp.erase(it);
        if(a[i]==b[i])
        {
            k++;
        }
        else
        {
            b[i]++;
            mp.insert(make_pair(a[i]-1-3*b[i]*(b[i]+1),i));
        }
    }
    for(int i=1;i<=n;i++)printf("%lld%c",b[i]," \n"[i==n]);
    return 0;
}