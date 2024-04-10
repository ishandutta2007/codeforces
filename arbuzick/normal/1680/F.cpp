#include <bits/stdc++.h>

using namespace std;

template <typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template <typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), g2(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> pr(n, -1), d(n), used(n), tin(n), tout(n);
    vector<array<int, 2>> mn(n), mx(n);
    int t = 0;
    y_combinator([&](auto dfs, int v) -> void {
        tin[v] = t;
        t++;
        used[v] = 1;
        mn[v] = {n * 10, n * 10};
        mx[v] = {-1, -1};
        for (auto u : g[v]) {
            if (!used[u]) {
                pr[u] = v;
                d[u] = d[v] ^ 1;
                g2[v].push_back(u);
                dfs(u);
                for (int i = 0; i < 2; ++i) {
                    mn[v][i] = min(mn[v][i], mn[u][i]);
                    mx[v][i] = max(mx[v][i], mx[u][i]);
                }
            } else if (u != pr[v] && tin[u] < tin[v]) {
                mn[v][d[v] ^ d[u]] = min(mn[v][d[v] ^ d[u]], tin[u]);
                mx[v][d[v] ^ d[u]] = max(mx[v][d[v] ^ d[u]], tin[u]);
            }
        }
        tout[v] = t;
        t++;
    })(0);
    int count_edges = 0;
    int fl = 0;
    for (int i = 0; i < n; ++i) {
        for (auto j : g[i]) {
            if (i < j && d[i] == d[j]) {
                count_edges++;
                fl = d[i];
            }
        }
    }
    if (count_edges <= 1) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << (d[i] ^ fl ^ 1);
        }
        cout << '\n';
        return;
    }
    bool ans = false;
    y_combinator([&](auto dfs, int v, bool ch = true) -> void {
        int count_br = 0;
        for (auto u : g2[v]) {
            if (mx[u][0] != -1) {
                count_br++;
            }
        }
        for (auto u : g[v]) {
            if (!(tin[v] <= tin[u] && tout[u] <= tout[v]) && u != pr[v] && d[u] == d[v]) {
                ch = false;
            }
        }
        if (!ch) {
            return;
        }
        for (auto u : g2[v]) {
            if (mx[u][0] != -1) {
                count_br--;
            }
            if (!count_br && mn[u][1] > tin[v] && mx[u][0] <= tin[v]) {
                ans = true;
                cout << "YES\n";
                for (int i = 0; i < n; ++i) {
                    if (tin[u] <= tin[i] && tout[i] <= tout[u]) {
                        cout << (d[i] ^ 1 ^ d[u]);
                    } else {
                        cout << (d[i] ^ d[u]);
                    }
                }
                cout << '\n';
                return;
            } else if (!count_br) {
                dfs(u);
            }
            if (mx[u][0] != -1) {
                count_br++;
            }
            if (ans) {
                return;
            }
        }
    })(0);
    if (!ans) {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}