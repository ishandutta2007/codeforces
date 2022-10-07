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
    
    std::vector<long long> f(n);

    auto get_f = [&](auto &self, int u, int fa) -> void {
        f[u] = a[u];
        for (int v : E[u]) {
            if (v != fa) {
                self(self, v, u);
                f[u] += std::max(f[v], 0ll);
            }
        }
    };

    get_f(get_f, 0, -1);

    long long max = *std::max_element(f.begin(), f.end());

    std::vector<long long> g(n);

    int ans = 0;

    auto get_g = [&](auto &self, int u, int fa) -> void {
        g[u] = a[u];
        for (int v : E[u]) {
            if (v != fa) {
                self(self, v, u);
                g[u] += std::max(g[v], 0ll);
            }
        }
        if (g[u] == max) {
            ++ans;
            g[u] = 0;
        }
    };

    get_g(get_g, 0, -1);
    std::cout << max * ans << " " << ans << "\n";
}