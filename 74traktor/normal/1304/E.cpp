#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
vector < int > g[maxn];
int dp[maxn][19];
int h[maxn];

void dfs(int v, int p) {
    h[v] = h[p] + 1;
    dp[v][0] = p;
    for (int i = 1; i <= 18; ++i) dp[v][i] = dp[dp[v][i - 1]][i - 1];
    for (auto u : g[v]) if (u != p) dfs(u, v);
}

int get_la(int u, int x) {
    for (int j = 0; j <= 18; ++j) {
        if ((x&(1 << j)) > 0) u = dp[u][j];
    }
    return u;
}

int get_lca(int u, int v) {
    if (h[u] > h[v]) u = get_la(u, h[u] - h[v]);
    else v = get_la(v, h[v] - h[u]);
    if (u == v) return u;
    for (int i = 18; i >= 0; --i) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i], v = dp[v][i];
        }
    }
    return dp[u][0];
}

int dist(int u, int v) {
    return h[u] + h[v] - 2 * h[get_lca(u, v)];
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, v, q, x, y, a, b, k;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> x >> y >> a >> b >> k;
        int t = dist(a, b);
        if (t <= k && (k - t) % 2 == 0) {
            cout << "YES" << '\n';
            continue;
        }
        t = dist(a, x) + dist(y, b) + 1;
        if (t <= k && (k - t) % 2 == 0) {
            cout << "YES" << '\n';
            continue;
        }
        t = dist(a, x) + dist(x, y) + 2 + dist(y, b);
        if (t <= k && (k - t) % 2 == 0) {
            cout << "YES" << '\n';
            continue;
        }
        swap(x, y);
        t = dist(a, x) + dist(y, b) + 1;
        if (t <= k && (k - t) % 2 == 0) {
            cout << "YES" << '\n';
            continue;
        }
        t = dist(a, x) + dist(x, y) + 2 + dist(y, b);
        if (t <= k && (k - t) % 2 == 0) {
            cout << "YES" << '\n';
            continue;
        }
        cout << "NO" << '\n';
    }
    return 0;
}