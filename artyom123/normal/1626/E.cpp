#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18;

vector<vector<int>> g;
vector<int> c;
vector<int> ans;
vector<int> sz, dp;
vector<int> nei;

void dfs(int v, int p, int ok, int up) {
    if (ok) ans[v] = 1;
    int total = 0;
    for (auto &to : g[v]) {
        if (to == p) continue;
        total += dp[to];
    }
    for (auto &to : g[v]) {
        if (to == p) continue;
        if (dp[to]) ans[v] = 1;
        int need = 2 - c[to];
        dfs(to, v, ok || (nei[v] != -1 && sz[v] + up - sz[to] >= need) || (total - dp[to] > 0), up + sz[v] - sz[to]);
    }
}

void dfs1(int v, int p) {
    sz[v] += c[v];
    for (auto &to : g[v]) {
        if (to == p) continue;
        dfs1(to, v);
        dp[v] |= dp[to];
        int cnt = sz[to];
        if (nei[v] == to) cnt--;
        if (cnt > 0 && nei[v] != -1) dp[v] = 1;
        sz[v] += sz[to];
    }
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int n;
    cin >> n;
    g.resize(n);
    c.resize(n);
    ans.resize(n);
    nei.resize(n, -1);
    dp.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i + 1 < n; i++) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        g[v].pb(u);
        g[u].pb(v);
        if (c[v] || c[u]) ans[v] = ans[u] = 1;
        if (c[v] && !c[u]) nei[u] = v;
        if (c[u] && !c[v]) nei[v] = u;
    }
    dfs1(0, -1);
    dfs(0, -1, 0, 0);
    for (auto &c : ans) cout << c << " ";
    return 0;
}