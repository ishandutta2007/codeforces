#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    int LG = std::__lg(n) + 1;
    std::vector<std::vector<int>> fa(n, std::vector<int>(LG, -1));
    int rt = std::min_element(a.begin(), a.end()) - a.begin();

    auto dfs = [&](auto &self, int u) -> void {
        for (int i = 1; i < LG && fa[u][i - 1] != -1; ++i) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (int v : E[u]) {
            if (v != fa[u][0]) {
                fa[v][0] = u;
                self(self, v);
            }
        }
    };

    dfs(dfs, rt);

    long long ans = 0;
    for (int u = 0; u < n; ++u) {
        if (u != rt) {
            long long s = a[u] + a[fa[u][0]];
            for (int i = 1; i <= LG; ++i) {
                if (i < LG && fa[u][i] != -1) {
                    s = std::min(s, a[u] + 1ll * a[fa[u][i]] * (i + 1));
                } else {
                    s = std::min(s, a[u] + 1ll * a[rt] * (i + 1));
                    break;
                }
            }
            ans += s;
        }
    }
    std::cout << ans << "\n";
}