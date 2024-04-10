#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <algorithm>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1,base=16,base2=(1<<16)-1;
ll x,m,mod,kq=0,uoc=1e18,time=0;
vector<pii> nt,subnt[100],ht;
vector<ll> snt;

ll product(ll a,ll b)
{
    ll ans=0,d=0,t=1;
    for (;a;)
    {
        t=b*(a&base2)%mod;
        for (int i=0;i<d;i++) t=(t<<base)%mod;
        ans=ans+t;
        if (ans>=mod) ans-=mod;
        d++;
        a>>=base;
    }
    return ans;
}

ll modpow(ll a,ll h)
{
    ll ans=1;
    for (;h;h/=2)
    {
        if (h&1) ans=product(ans,a);
        a=product(a,a);
    }
    return ans;
}

void ptnt(vector<pii> &tmp, ll a)
{
    for (ll i=2;i*i<=a;i++)
        if (a%i==0)
        {
            ll d=0;
            while (a%i==0) d++,a/=i;
            tmp.pb({i,d});
        }
     if (a>1) tmp.pb({a,1});
}

vector<pii> compress(const vector<ll> &a)
{
    vector<pii> tmp;
    ll d=1,siz=a.size();
    for (ll i=0;i<siz-1;i++)
        if (a[i]!=a[i+1])
        {
            tmp.pb({a[i],d});
            d=1;
        }
        else d++;
    if (a.size()>0) tmp.pb({a.back(),d});
    return tmp;
}

void create(ll t,ll val,ll val2)
{
    if (t>=ht.size())
    {
        if (val2==1) uoc=min(uoc,val);
        return;
    }
    ll tmp=1;
    create(t+1,val,val2);
    for (int i=1;i<=ht[t].se;i++)
    {
        tmp*=ht[t].fi,val2=modpow(val2,ht[t].fi);
        create(t+1,val*tmp,val2);
    }
}

ll dem(vector<ll> tmp,ll val)
{
    sort(tmp.begin(),tmp.end());
    ll phi=1;
    for (int i=0;i<tmp.size();i++) phi*=tmp[i];
    ht=compress(tmp);
    mod=val;
    uoc=1e18;
    create(0,1,x%mod);
    if (uoc!=1e18 && uoc!=0)  return (phi/uoc); else return 0;
}

void counted(ll t,ll val)
{
    ll siz=nt.size();
    if (t>=siz)
    {
        kq+=dem(snt,val);
        return;
    }
    ll tmp=1;
    for (int i=0;i<=nt[t].se;i++) { if (i) tmp*=nt[t].fi;
    if (!i) counted(t+1,val);
    else if (i==1)
    {
        for (int j=0;j<subnt[t].size();j++)
            for (int y=1;y<=subnt[t][j].se;y++) snt.pb(subnt[t][j].fi);
        counted(t+1,val*tmp);
    }
    else
    {
        snt.pb(nt[t].fi);
        counted(t+1,val*tmp);
    }}
    for (int j=0;j<subnt[t].size();j++)
            for (int y=1;y<=subnt[t][j].se;y++) snt.pop_back();
    for (int i=2;i<=nt[t].se;i++) snt.pop_back();
}

int main()
{
    //freopen("ss.inp","r",stdin);
    cin>>m>>x;
    ptnt(nt,m);
    for (int i=0;i<nt.size();i++) ptnt(subnt[i],nt[i].fi-1);
    counted(0,1);
    cout<<kq+1;
    return 0;
}