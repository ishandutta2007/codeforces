//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;


vector<vector<ll>> g;
vector<ll> col;
ll F = 0;

void dfs(ll u, ll c)
{
    col[u] = c;
    for (ll v: g[u])
    {
        if (col[u]==col[v])
        {
            F = 1;
            return;
        }
        if (col[v]==-1)
        {
            dfs(v,1-col[u]);
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    col.resize(n,-1);
    g.resize(n);
    for (ll i=0;i<m;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (ll i=0;i<n;i++)
    {
        if (col[i]==-1) dfs(i,0);
    }
    if (F==1)
    {
        cout << -1 << "\n";
        return;
    }
    vector<vector<ll>> ans(2);
    for (ll i=0;i<n;i++) ans[col[i]].push_back(i);
    sort(ans[0].begin(),ans[0].end());
    sort(ans[1].begin(),ans[1].end());
    for (ll b=0;b<2;b++)
    {
        cout << ans[b].size() << "\n";
        for (ll x: ans[b]) cout << x+1 << " ";
        cout << "\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}