#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
    }
    
    std::vector<int> Q;
    std::vector<int> dis(n, n), mn(n, n);
    dis[0] = 0;
    Q.push_back(0);
    for (int i = 0; i < (int)Q.size(); ++i) {
        int u = Q[i];
        mn[u] = dis[u];
        for (int v : E[u]) {
            if (dis[v] == n) {
                dis[v] = dis[u] + 1;
                Q.push_back(v);
            } else {
                mn[u] = std::min(mn[u], dis[v]);
            }
        }
    }
    std::reverse(Q.begin(), Q.end());
    for (int u : Q) {
        for (int v : E[u]) {
            if (dis[u] < dis[v]) {
                mn[u] = std::min(mn[u], mn[v]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << mn[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}