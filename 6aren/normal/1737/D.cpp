#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include<cp/debugger.hpp>
#else 
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> edges;
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            edges.push_back({u, v, w});
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            dis[u][v] = dis[v][u] = 1;
        }
        for (int i = 0; i < n; i++) dis[i][i] = 0;
        for (int k = 0; k < n; k++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    if (dis[u][v] > dis[u][k] + dis[k][v]) {
                        dis[u][v] = dis[u][k] + dis[k][v];
                    }
                }
            }
        }
        long long res = 1e18;
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            res = min(res, 1LL * w * (dis[0][u] + dis[n - 1][v] + 1));
            res = min(res, 1LL * w * (dis[0][v] + dis[n - 1][u] + 1));
            for (int i = 0; i < n; i++) {
                int foo = min(dis[i][u], dis[i][v]);
                res = min(res, 1LL * w * (dis[0][i] + dis[i][n - 1] + foo + 2));
            }
        }
        cout << res << '\n';
    }
    return 0;
}