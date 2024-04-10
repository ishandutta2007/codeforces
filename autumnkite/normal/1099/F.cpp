#include <bits/stdc++.h>

class fenwick_tree {
protected:
    int n, LG;
    std::vector<long long> c, ct;

public:
    fenwick_tree(int _n)
    : n(_n), LG(std::__lg(n)), c(n + 1), ct(n + 1) {}

    void add(int x, long long v) {
        long long vt = v * x;
        for (++x; x <= n; x += x & -x) {
            c[x] += v;
            ct[x] += vt;
        }
    }

    std::tuple<int, long long, long long> find(long long vt) {
        int x = 0;
        long long now = 0, sum = 0;
        for (int i = LG; i >= 0; --i) {
            int y = x + (1 << i);
            if (y <= n && now + ct[y] <= vt) {
                now += ct[y];
                sum += c[y];
                x = y;
            }
        }
        return std::make_tuple(x, sum, now);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long all;
    std::cin >> n >> all;
    std::vector<int> a(n), t(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
    }
    int m = *std::max_element(t.begin(), t.end()) + 1;
    std::vector<std::vector<std::pair<int, int>>> E(n);
    std::vector<int> fa(n, -1), fw(n);
    for (int i = 1; i < n; ++i) {
        std::cin >> fa[i] >> fw[i];
        --fa[i];
        E[fa[i]].emplace_back(i, fw[i]);
    }

    std::vector<long long> dis(n);
    std::vector<long long> f(n);
    fenwick_tree T(m);

    auto dfs = [&](auto &self, int u) -> void {
        T.add(t[u], a[u]);
        if (2 * dis[u] > all) {
            f[u] = 0;
        } else {
            auto [x, cnt, sumT] = T.find(all - 2 * dis[u]);
            f[u] = cnt + (x < m ? (all - 2 * dis[u] - sumT) / x : 0);
        }
        for (auto [v, w] : E[u]) {
            dis[v] = dis[u] + w;
            self(self, v);
        }
        T.add(t[u], -a[u]);
    };

    dfs(dfs, 0);

    std::vector<long long> g(n);

    auto solve = [&](auto &self, int u) -> void {
        g[u] = f[u];
        long long mx = 0, se = 0;
        for (auto [v, w] : E[u]) {
            self(self, v);
            if (g[v] > mx) {
                se = mx, mx = g[v];
            } else if (g[v] > se) {
                se = g[v];
            }
        }
        g[u] = std::max(g[u], se);
    };

    solve(solve, 0);

    long long ans = f[0];
    for (auto [v, w] : E[0]) {
        ans = std::max(ans, g[v]);
    }
    std::cout << ans << "\n";
}