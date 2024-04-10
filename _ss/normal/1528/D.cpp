#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 6e2 + 10;
vector<pii> G[N];
int n, m, d[N][N], vis[N], val[N], pref[N], suf[N];
int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        cin >> u >> v >> w;
        G[u].eb(v, w);
    }
    for (int sta = 0; sta < n; ++sta)
    {
        for (int i = 0; i < n; ++i) vis[i] = 0, d[sta][i] = 2e9;
        d[sta][sta] = 0;
        for (int i = 1; i < n; ++i)
        {
            int best = 2e9, u;
            for (int j = 0; j < n; ++j)
                if (!vis[j] && d[sta][j] < best) best = d[sta][j], u = j;
            vis[u] = 1;
            for (int j = 0; j < n; ++j) val[j] = 2e9;
            for (pii e : G[u]) val[(e.fi + best) % n] = best + e.se;
            pref[0] = val[0];
            for (int j = 1; j < n; ++j) pref[j] = min(pref[j - 1], val[j] - j);
            suf[n - 1] = val[n - 1] - (n - 1);
            for (int j = n - 2; j >= 0; --j) suf[j] = min(suf[j + 1], val[j] - j);
            for (int j = 0; j <= n; ++j) d[sta][j] = min({d[sta][j], pref[j] + j, suf[j] + j + n});
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) cout << d[i][j] << " ";
        cout << "\n";
    }
    return 0;
}