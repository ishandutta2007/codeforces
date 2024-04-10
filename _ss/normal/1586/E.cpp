#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 3e5 + 10;
vi G[N], T[N];
int n, q, m, vis[N], p[N], h[N], val[N];

void dfs(int u)
{
    vis[u] = 1;
    for (int v : G[u])
        if (!vis[v]) h[v] = h[u] + 1, dfs(v), p[v] = u, T[u].eb(v);
}

int res = 0, dp[N];

void dfs2(int u)
{
    for (int v : T[u])
    {
        dfs2(v);
        dp[u] += dp[v];
    }
    res += dp[u] / 2;
    dp[u] &= 1;
    if (dp[u] && !val[u]) res++, dp[u] = 0;
    if (val[u]) dp[u] = 1;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        G[u].eb(v);
        G[v].eb(u);
    }
    dfs(1);
    cin >> q;
    vector<vi> ans;
    for (int i = 1, u, v; i <= q; ++i)
    {
        cin >> u >> v;
        vi vt1, vt2;
        while (u != v)
        {
            if (h[u] >= h[v]) val[u] ^= 1, vt1.eb(u), u = p[u];
            else val[v] ^= 1, vt2.eb(v), v = p[v];
        }
        vt1.eb(u);
        reverse(all(vt2));
        for (int x : vt2) vt1.eb(x);
        ans.eb(vt1);
    }
    int flag = 0;
    for (int i = 2; i <= n; ++i) flag |= val[i];
    if (!flag)
    {
        cout << "YES\n";
        for (vi vt : ans)
        {
            cout << vt.size() << "\n";
            for (int x : vt) cout << x << " ";
            cout << "\n";
        }
        return 0;
    }
    dfs2(1);
    cout << "NO\n" << res;
    return 0;
}