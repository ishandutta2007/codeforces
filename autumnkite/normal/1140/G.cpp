#include <bits/stdc++.h>

template<typename T>
struct matrix {
    static const T INF = std::numeric_limits<T>::max() / 2;
    
    T a[2][2];

    matrix() : a{INF, INF, INF, INF} {}

    T *operator[](int x) {
        return a[x];
    }

    const T *operator[](int x) const {
        return a[x];
    }

    matrix operator*(const matrix &rhs) const {
        matrix res;
        for (int i = 0; i < 2; ++i) {
            for (int k = 0; k < 2; ++k) {
                for (int j = 0; j < 2; ++j) {
                    res.a[i][j] = std::min(res.a[i][j], a[i][k] + rhs.a[k][j]);
                }
            }
        }
        return res;
    }

    matrix rev() const {
        matrix res(*this);
        std::swap(res.a[0][1], res.a[1][0]);
        return res;
    }
};

using matll = matrix<long long>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<std::tuple<int, long long, long long>>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        long long w1, w2;
        std::cin >> u >> v >> w1 >> w2;
        --u, --v;
        E[u].emplace_back(v, w1, w2);
        E[v].emplace_back(u, w1, w2);
    }

    std::vector<long long> f(n), g(n);

    auto solve_f = [&](auto &self, int u, int fa) -> void {
        f[u] = a[u];
        for (auto [v, w1, w2] : E[u]) {
            if (v != fa) {
                self(self, v, u);
                f[u] = std::min(f[u], f[v] + w1 + w2);
            }
        }
    };

    auto solve_g = [&](auto &self, int u, int fa) -> void {
        g[u] = std::min(g[u], a[u]);
        for (auto [v, w1, w2] : E[u]) {
            if (v != fa) {
                g[v] = std::min(g[u], f[u]) + w1 + w2;
                self(self, v, u);
            }
        }
    };

    solve_f(solve_f, 0, -1);
    g[0] = a[0];
    solve_g(solve_g, 0, -1);

    for (int i = 0; i < n; ++i) {
        a[i] = std::min(f[i], g[i]);
    }

    int LG = std::__lg(n) + 1;
    std::vector<int> dep(n);
    std::vector<std::vector<int>> fa(n, std::vector<int>(LG, -1));
    std::vector<std::vector<matll>> st(n, std::vector<matll>(LG));

    auto dfs = [&](auto &self, int u) -> void {
        for (int i = 1; i < LG && fa[u][i - 1] != -1; ++i) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
            st[u][i] = st[u][i - 1] * st[fa[u][i - 1]][i - 1];
        }
        for (auto [v, w1, w2] : E[u]) {
            if (v != fa[u][0]) {
                dep[v] = dep[u] + 1;
                fa[v][0] = u;
                st[v][0][0][0] = std::min(w1, a[u] + a[v] + w2);
                st[v][0][1][1] = std::min(w2, a[u] + a[v] + w1);
                st[v][0][0][1] = std::min(a[u] + w1, a[v] + w2);
                st[v][0][1][0] = std::min(a[v] + w1, a[u] + w2);
                self(self, v);
            }
        }
    };

    dep[0] = 0;
    dfs(dfs, 0);

    auto query = [&](int u, int v) {
        bool swapped = false;
        if (dep[u] < dep[v]) {
            std::swap(u, v);
            swapped = true;
        }
        matll su, sv;
        su[0][0] = su[1][1] = 0;
        su[0][1] = su[1][0] = a[u];
        sv[0][0] = sv[1][1] = 0;
        sv[0][1] = sv[1][0] = a[v];
        for (int i = LG - 1; i >= 0; --i) {
            if (fa[u][i] != -1 && dep[fa[u][i]] >= dep[v]) {
                su = su * st[u][i];
                u = fa[u][i];
            }
        }
        if (u != v) {
            for (int i = LG - 1; i >= 0; --i) {
                if (fa[u][i] != fa[v][i]) {
                    su = su * st[u][i];
                    sv = sv * st[v][i];
                    u = fa[u][i];
                    v = fa[v][i];
                }
            }
            su = su * st[u][0];
            sv = sv * st[v][0];
        }
        if (swapped) {
            std::swap(su, sv);
        }
        return su * sv.rev();
    };

    int q;
    std::cin >> q;
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        std::cout << query(u >> 1, v >> 1)[u & 1][v & 1] << "\n";
    }
}