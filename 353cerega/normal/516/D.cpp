//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;


vector<vector<pair<ll,ll>>> g;
vector<ll> val;
vector<vector<int>> up;
int K = 18;

void dfs0(ll u, ll p)
{
    up[u][0] = p;
    for (int j=1;j<K;j++)
    {
        if (up[u][j-1]==-1) up[u][j] = -1;
        else up[u][j] = up[up[u][j-1]][j-1];
    }
    for (int i=0;i<g[u].size();i++)
    {
        ll v = g[u][i].X;
        if (v==p) continue;
        dfs0(v,u);
    }
}

ll A = 0;

vector<ll> dp;

ll x;

int calc(ll u)
{
    ll D = val[u]-x;
    for (int j=K-1;j>=0;j--)
    {
        if (up[u][j]!=-1 and val[up[u][j]]>=D)
        {
            u = up[u][j];
        }
    }
    return up[u][0];
}

void dfs(ll u, ll p)
{
    dp[u]++;
    ll u2 = calc(u);
    if (u2!=-1) dp[u2]--;
    for (int i=0;i<g[u].size();i++)
    {
        ll v = g[u][i].X;
        if (v==p) continue;
        dfs(v,u);
        dp[u] += dp[v];
    }
    A = max(A,dp[u]);
}

void solve()
{
    ll n;
    cin >> n;
    g.resize(n);
    for (ll i=1;i<n;i++)
    {
        ll u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        g[u].push_back({v,d});
        g[v].push_back({u,d});
    }
    ll u0 = 0, u1 = 0;
    {
        ll st = 0;
        vector<ll> d(n,mod*mod);
        d[st] = 0;
        set<pair<ll,ll>> kek;
        for (ll i=0;i<n;i++) kek.insert({d[i],i});
        while (kek.size()>1)
        {
            ll u = kek.begin()->Y;
            kek.erase({d[u],u});
            for (ll i=0;i<g[u].size();i++)
            {
                ll v = g[u][i].X;
                ll L = g[u][i].Y+d[u];
                if (d[v]<=L) continue;
                kek.erase({d[v],v});
                d[v] = L;
                kek.insert({d[v],v});
            }
        }
        u0 = kek.begin()->Y;
    }
    vector<vector<ll>> D(2);
    {
        ll st = u0;
        vector<ll> d(n,mod*mod);
        d[st] = 0;
        set<pair<ll,ll>> kek;
        for (ll i=0;i<n;i++) kek.insert({d[i],i});
        while (kek.size()>1)
        {
            ll u = kek.begin()->Y;
            kek.erase({d[u],u});
            for (ll i=0;i<g[u].size();i++)
            {
                ll v = g[u][i].X;
                ll L = g[u][i].Y+d[u];
                if (d[v]<=L) continue;
                kek.erase({d[v],v});
                d[v] = L;
                kek.insert({d[v],v});
            }
        }
        u1 = kek.begin()->Y;
        D[0] = d;
    }
    {
        ll st = u1;
        vector<ll> d(n,mod*mod);
        d[st] = 0;
        set<pair<ll,ll>> kek;
        for (ll i=0;i<n;i++) kek.insert({d[i],i});
        while (kek.size()>1)
        {
            ll u = kek.begin()->Y;
            kek.erase({d[u],u});
            for (ll i=0;i<g[u].size();i++)
            {
                ll v = g[u][i].X;
                ll L = g[u][i].Y+d[u];
                if (d[v]<=L) continue;
                kek.erase({d[v],v});
                d[v] = L;
                kek.insert({d[v],v});
            }
        }
        D[1] = d;
    }
    ll r = 0;
    val.resize(n);
    for (ll i=0;i<n;i++)
    {
        val[i] = max(D[0][i],D[1][i]);
        if (val[i]<val[r]) r = i;
    }
    up.resize(n,vector<int>(K));
    dfs0(r,-1);
    ll q;
    cin >> q;
    dp.resize(n);
    while (q--)
    {
        A = 0;
        cin >> x;
        for (ll i=0;i<n;i++) dp[i] = 0;
        dfs(r,-1);
        cout << A << "\n";
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