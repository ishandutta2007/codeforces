#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    std::vector<int> sz(n);

    auto get_sz = [&](auto self, int u, int fa) -> void {
        sz[u] = 1;
        for (int v : E[u]) {
            if (v != fa) {
                self(self, v, u);
                sz[u] += sz[v];
            }
        }
    };

    auto get_mx = [&](auto self, int u, int fa) -> std::pair<long long, int> {
        std::pair<long long, int> res(1ll * sz[u] * (sz[u] + 1) / 2, u);
        for (int v : E[u]) {
            if (v != fa) {
                auto tmp = self(self, v, u);
                tmp.first += 1ll * (sz[u] - sz[v]) * (sz[u] - sz[v] + 1) / 2;
                res = std::min(res, tmp);
            }
        }
        return res;
    };

    get_sz(get_sz, 0, -1);
    int rt = get_mx(get_mx, 0, -1).second;
    get_sz(get_sz, rt, -1);
    std::cout << 1ll * n * n - get_mx(get_mx, rt, -1).first << "\n";
}