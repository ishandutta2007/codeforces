//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = int;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;


vector<vector<ll>> g, g2;
vector<ll> q, col, was;

void dfs0(ll u)
{
    was[u] = 1;
    for (ll v: g[u]) if (was[v]==0) dfs0(v);
    q.push_back(u);
}

void dfs1(ll u, ll C)
{
    was[u] = 1;
    col[u] = C;
    for (ll v: g2[u])
    {
        if (was[v]==0) dfs1(v,C);
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    g.resize(n);
    g2.resize(n);
    col.resize(n);
    was.resize(n);
    for (ll i=0;i<m;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g2[v].push_back(u);
    }
    ll A = n;
    for (ll i=0;i<n;i++) if (was[i]==0) dfs0(i);
    reverse(q.begin(),q.end());
    for (ll i=0;i<n;i++) was[i] = 0;
    ll sz = 0;
    for (ll x: q) if (was[x]==0) dfs1(x,sz++);
    vector<ll> bad(sz), D(sz);
    for (ll i=0;i<n;i++)
    {
        for (ll v: g[i])
        {
            if (col[i]!=col[v]) bad[col[i]] = 1;
        }
        D[col[i]]++;
    }
    for (ll i=0;i<sz;i++) if (bad[i]==0 and D[i]>1) A++;
    for (ll c=0;c<sz;c++)
    {
        if (bad[c]==1 or D[c]==1) continue;
        ll mn = mod;
        for (ll st=0;st<n;st++)
        {
            if (col[st]!=c) continue;
            vector<ll> Q, d;
            Q.push_back(st);
            d.push_back(0);
            for (ll i=0;i<n;i++) was[i] = 0;
            was[st] = 1;
            ll F = 0;
            for (ll w=0;w<Q.size() and F==0;w++)
            {
                ll u = Q[w];
                for (ll v: g[u])
                {
                    if (v==st)
                    {
                        F = 1;
                        mn = min(mn,d[w]+1);
                    }
                    if (was[v]==1) continue;
                    Q.push_back(v);
                    was[v] = 1;
                    d.push_back(d[w]+1);
                }
            }
        }
        A += mn*998;
    }
    cout << A << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}