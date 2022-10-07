#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    std::vector<int> dep(n, -1);
    std::vector<int> fa(n);

    auto dfs = [&](auto &self, int u) -> void {
        for (int v : E[u]) {
            if (dep[v] == -1) {
                dep[v] = dep[u] + 1;
                fa[v] = u;
                self(self, v);
            }
        }
    };

    dep[0] = 0;
    dfs(dfs, 0);

    int q;
    std::cin >> q;

    std::vector<int> c(n);
    std::vector<std::vector<int>> ans;

    auto add = [&](int u, int v) {
        std::vector<int> A, B;
        if (dep[u] > dep[v]) {
            while (dep[u] > dep[v]) {
                A.push_back(u);
                c[u] ^= 1;
                u = fa[u];
            }
        } else {
            while (dep[v] > dep[u]) {
                B.push_back(v);
                c[v] ^= 1;
                v = fa[v];
            }
        }
        if (u == v) {
            A.push_back(u);
        } else {
            while (u != v) {
                A.push_back(u);
                B.push_back(v);
                c[u] ^= 1;
                c[v] ^= 1;
                u = fa[u];
                v = fa[v];
            }
            A.push_back(u);
        }
        A.insert(A.end(), B.rbegin(), B.rend());
        ans.push_back(A);
    };

    for (int i = 1; i <= q; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        add(u, v);
    }

    if (std::find(c.begin(), c.end(), 1) == c.end()) {
        std::cout << "YES\n";
        for (const auto &v : ans) {
            std::cout << v.size() << "\n";
            for (int x : v) {
                std::cout << x + 1 << " ";
            }
            std::cout << "\n";
        }
    } else {
        std::cout << "NO\n";

        int ans = 0;

        auto get_ans = [&](auto &self, int u, int h) -> void {
            for (int v : E[u]) {
                if (fa[v] == u) {
                    if (c[v]) {
                        h ^= 1;
                        ans += h;
                        self(self, v, 1);
                    } else {
                        self(self, v, 0);
                    }
                }
            }
        };

        get_ans(get_ans, 0, 0);
        std::cout << ans << "\n";
    }
}