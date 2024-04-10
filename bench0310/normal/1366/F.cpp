#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct line
{
    ll k,n;
    line(ll a,ll b){k=a;n=b;}
    ll e(ll x){return (k*x+n);}
    friend ll intersect(line a,line b){return (a.n-b.n)/(b.k-a.k);}
    friend bool bad(line a,line b,line c){return ((a.n-b.n)*(c.k-b.k)>=(b.n-c.n)*(b.k-a.k));}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    vector<array<int,3>> edges(m);
    for(auto &[a,b,c]:edges) cin >> a >> b >> c;
    const ll inf=(1ll<<60);
    vector<ll> d(n+1,-inf);
    d[1]=0;
    ll res=0;
    const ll mod=1000000007;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    auto chmax=[&](ll &a,ll b){a=max(a,b);};
    const int lim=1000000;
    vector<ll> best(lim+1,-inf);
    for(int i=1;i<=m;i++)
    {
        vector<ll> nd(n+1,-inf);
        for(auto [a,b,c]:edges)
        {
            chmax(nd[a],d[b]+c);
            chmax(nd[b],d[a]+c);
        }
        d=nd;
        ll mx=0;
        for(int j=1;j<=n;j++) chmax(mx,d[j]);
        res=add(res,mx);
        for(auto [a,b,c]:edges) chmax(best[c],max(d[a],d[b])+(m-i)*c);
    }
    deque<line> o;
    for(int i=1;i<=lim;i++)
    {
        if(best[i]==-inf) continue;
        line now(i,best[i]);
        while(o.size()>=2&&bad(o[o.size()-2],o[o.size()-1],now)) o.pop_back();
        o.push_back(now);
    }
    ll x=1;
    int sz=o.size();
    for(int i=0;i<sz;i++)
    {
        ll y=min(ll(q-m),(i+1<sz?intersect(o[i],o[i+1]):inf));
        if(x<=y)
        {
            ll a=o[i].e(x);
            ll k=o[i].k;
            res=add(res,mul(y-x+1,a%mod));
            res=add(res,mul(k,((y-x)*(y-x+1)/2)%mod));
            x=y+1;
        }
    }
    cout << res << "\n";
    return 0;
}