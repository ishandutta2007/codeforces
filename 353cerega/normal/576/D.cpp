//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;



void solve()
{
    ll n, m;
    cin >> n >> m;
    ll mx = 25000;
    vector<pair<ll,pair<ll,ll>>> e(m);
    vector<vector<pair<ll,ll>>> g(n);
    for (ll i=0;i<m;i++)
    {
        cin >> e[i].Y.X >> e[i].Y.Y >> e[i].X;
        e[i].Y.X--, e[i].Y.Y--;
    }
    sort(e.begin(),e.end());
    for (ll i=0;i<m;i++)
    {
        g[e[i].Y.X].push_back({e[i].Y.Y,i});
    }
    ll mx2 = 150;
    vector<vector<ll>> dp(mx2,vector<ll>(n));
    dp[0][0] = 1;
    ll T = 0;
    for (ll t=0;t<m;t++)
    {
        ll Q = mx2;
        while (T<e[t].X and Q--)
        {
            ll T1 = T%mx2;
            ll T2 = (T+1)%mx2;
            for (ll i=0;i<n;i++) dp[T2][i] = 0;
            for (ll w=0;w<t;w++)
            {
                ll u = e[w].Y.X;
                ll v = e[w].Y.Y;
                if (dp[T1][u]) dp[T2][v] = 1;
            }
            if (dp[T2][n-1]==1)
            {
                cout << T+1 << "\n";
                return;
            }
            T++;
        }
        if (e[t].X<T+mx*3/2)
        {
            while (T<e[t].X)
            {
                ll T1 = T%mx2;
                ll T2 = (T+1)%mx2;
                for (ll i=0;i<n;i++) dp[T2][i] = 0;
                for (ll w=0;w<t;w++)
                {
                    ll u = e[w].Y.X;
                    ll v = e[w].Y.Y;
                    if (dp[T1][u]) dp[T2][v] = 1;
                }
                if (dp[T2][n-1]==1)
                {
                    cout << T+1 << "\n";
                    return;
                }
                T++;
            }
            continue;
        }
        ll S = e[t].X-mx;
        for (ll i=0;i<n;i++)
        {
            vector<ll> was(n), q, d;
            was[i] = 1;
            q.push_back(i);
            d.push_back(1);
            ll L = mod;
            for (ll w=0;w<q.size();w++)
            {
                ll u = q[w];
                for (ll j=0;j<g[u].size();j++)
                {
                    if (g[u][j].Y>=t) continue;
                    ll v = g[u][j].X;
                    if (v==i)
                    {
                        L = d[w];
                        break;
                    }
                    if (was[v]==1) continue;
                    d.push_back(d[w]+1);
                    q.push_back(v);
                    was[v] = 1;
                }
                if (L!=mod) break;
            }
            if (L==mod)
            {
                for (ll x=0;x<mx2;x++) dp[x][i] = 0;
                continue;
            }
            vector<ll> val;
            for (ll x=0;x<mx2;x++)
            {
                if (dp[x][i]==0) continue;
                ll cur = T/mx2*mx2+x;
                if (cur>T) cur -= mx2;
                ll nxt = (S-cur)/L*L+cur;
                val.push_back(nxt);
            }
            for (ll x=0;x<mx2;x++) dp[x][i] = 0;
            for (ll x: val) dp[x%mx2][i] = 1;
        }
        T = S-mx2+1;
        while (T<S)
        {
            ll T1 = T%mx2;
            ll T2 = (T+1)%mx2;
            for (ll w=0;w<t;w++)
            {
                ll u = e[w].Y.X;
                ll v = e[w].Y.Y;
                if (dp[T1][u]) dp[T2][v] = 1;
            }
            T++;
        }
        while (T<e[t].X)
        {
            ll T1 = T%mx2;
            ll T2 = (T+1)%mx2;
            for (ll i=0;i<n;i++) dp[T2][i] = 0;
            for (ll w=0;w<t;w++)
            {
                ll u = e[w].Y.X;
                ll v = e[w].Y.Y;
                if (dp[T1][u]) dp[T2][v] = 1;
            }
            T++;
        }
    }
    ll Q = mx2;
    while (Q--)
    {
        ll T1 = T%mx2;
        ll T2 = (T+1)%mx2;
        for (ll i=0;i<n;i++) dp[T2][i] = 0;
        for (ll w=0;w<m;w++)
        {
            ll u = e[w].Y.X;
            ll v = e[w].Y.Y;
            if (dp[T1][u]) dp[T2][v] = 1;
        }
        if (dp[T2][n-1]==1)
        {
            cout << T+1 << "\n";
            return;
        }
        T++;
    }
    cout << "Impossible\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}