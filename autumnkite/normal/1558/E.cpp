#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(n);
    for (int i = 1; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        std::cin >> b[i];
    }
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    auto check = [&](long long now) {
        std::vector<bool> vis(n);
        vis[0] = true;
        while (std::accumulate(vis.begin(), vis.end(), 0) < n) {
            std::vector<bool> tmp(n);
            std::vector<int> fa(n, -1);
            auto dfs = [&](auto &self, int u, long long t) {
                tmp[u] = true;
                for (int v : E[u]) {
                    if (v != fa[u]) {
                        if (tmp[v] || (!vis[u] && vis[v])) {
                            for (int x = u; !vis[x]; x = fa[x]) {
                                vis[x] = true;
                                now += b[x];
                            }
                            return true;
                        } else if (!vis[v] && t > a[v]) {
                            fa[v] = u;
                            if (self(self, v, t + b[v])) {
                                return true;
                            }
                        }
                    }
                }
                tmp[u] = false;
                return false;
            };
            bool flag = false;
            for (int i = 0; i < n; ++i) {
                if (vis[i]) {
                    if (dfs(dfs, i, now)) {
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag) {
                return false;
            }
        }
        return true;
    };

    int l = 0, r = 1000000001;
    while (l + 1 < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    std::cout << r << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}