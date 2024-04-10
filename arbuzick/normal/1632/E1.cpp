#include <bits/stdc++.h>

using namespace std;

template<typename Fun>
struct y_combinator {
    const Fun fun;
 
    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}
 
    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(n), mx_d(n), kek(n);
    y_combinator([&](auto dfs, int v, int pr, int dst) -> void {
        d[v] = mx_d[v] = dst;
        for (auto u : g[v]) {
            if (u != pr) {
                dfs(u, v, dst + 1);
                mx_d[v] = max(mx_d[v], mx_d[u]);
            }
        }
    })(0, 0, 0);
    y_combinator([&](auto dfs, int v, int pr, int lol) -> void {
        int mx1 = d[v], mx2 = d[v];
        for (auto u : g[v]) {
            if (u != pr) {
                if (mx_d[u] > mx1) {
                    mx2 = mx1;
                    mx1 = mx_d[u];
                } else {
                    mx2 = max(mx2, mx_d[u]);
                }
            }
        }
        kek[v] = lol;
        for (auto u : g[v]) {
            if (u != pr) {
                if (mx_d[u] == mx1) {
                    dfs(u, v, max(lol, mx2));
                } else {
                    dfs(u, v, max(lol, mx1));
                }
            }
        }
    })(0, 0, 0);
    vector<int> fn(n, n);
    for (int i = 1; i < n; ++i) {
        vector<int> mx_d2(n);
        y_combinator([&](auto dfs, int v) -> void {
            fn[i] = min(fn[i], max(mx_d[v] - d[v], mx_d2[v]));
            int mx1 = d[v], mx2 = d[v];
            for (auto u : g[v]) {
                if (d[u] > d[v]) {
                    if (mx_d[u] > mx1) {
                        mx2 = mx1;
                        mx1 = mx_d[u];
                    } else {
                        mx2 = max(mx2, mx_d[u]);
                    }
                }
            }
            for (auto u : g[v]) {
                if (d[u] > d[v]) {
                    if (mx_d[u] == mx1) {
                        mx_d2[u] = max(mx_d2[v] + 1, mx2 - d[v] + 1);
                    } else {
                        mx_d2[u] = max(mx_d2[v] + 1, mx1 - d[v] + 1);
                    }
                    dfs(u);
                }
            }
        })(i);
    }
    for (int x = 1; x <= n; ++x) {
        int ans = mx_d[0];
        for (int i = 1; i < n; ++i) {
            ans = min(ans, max(kek[i], fn[i] + x));
        }
        cout << ans << ' ';
    }
    cout << '\n';
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