#include <bits/stdc++.h>
using namespace std;

typedef long long int   ll;
typedef long double     ld;
typedef pair<ll,ll>     pll;

#define all(x)          x.begin(),x.end()
#define Sort(x)         sort(all(x))
#define X               first
#define Y               second
#define sep             " "
#define endl            "\n"
#define INF             1e18
#define MOD             1e9+7
#define fastio          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 110;
ll n, m, par[MAXN], chg[MAXN], mark[MAXN];
vector<pll> adj[MAXN];
vector<pair<pll, ll>> bad;

ll Find(ll u)
{
    if (par[u] == -1)   return u;
    par[u] = Find(par[u]);
    return par[u];
}

void Union(ll u, ll v, ll w)
{
    ll pu = Find(u), pv = Find(v);
    if (pu != pv)
    {
        par[pv] = pu;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    else
    {
        bad.push_back({{u,v},w});
    }
}

void dfs(ll u, ll cnt=0)
{
    mark[u] = 1;
    chg[u] = cnt%2;
    for (pll e : adj[u])
    {
        ll v = e.X, w = e.Y;
        if (!mark[v])
        {
            dfs(v, cnt + (w==0));
        }
    }
}

int main()
{
    fastio;   //stupid persons use cin and cout
    fill(par, par+MAXN, -1);
    cin >> n >> m;
    for (ll i=0; i<m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        Union(u, v, w);
    }
    for (ll i=1; i<=n; i++)
    {
        if (!mark[i])
            dfs(i);
    }
    for (auto e : bad)
    {
        ll u = e.X.X, v = e.X.Y, w = e.Y;
        if ((chg[u]+chg[v]+w)%2 == 0)
        {
            return cout << "Impossible" << endl, 0;
        }
    }
    vector<ll> vec;
    for (ll i=1; i<=n; i++)
    {
        if (chg[i] == 1)    vec.push_back(i);
    }
    cout << vec.size() << endl;
    for (ll i : vec)
    {
        cout << i << sep;
    }
    cout << endl;
    return 0;
}