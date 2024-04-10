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
    vector<int> fn(n);
    y_combinator([&](auto dfs, int v) -> void {
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
        fn[v] = mx1 + mx2 - d[v] * 2;
        for (auto u : g[v]) {
            if (d[u] > d[v]) {
                dfs(u);
                fn[v] = max(fn[v], fn[u]);
            }
        }
    })(0);
    vector<pair<int, int>> vals;
    for (int i = 0; i < n; ++i) {
        // cout << kek[i] << ' ' << fn[i] << '\n';
        vals.emplace_back(kek[i], (fn[i] + 1) / 2);
    }
    sort(vals.begin(), vals.end());
    vector<int> pr(n + 1, n);
    for (int i = 0; i < n; ++i) {
        pr[i + 1] = min(pr[i], vals[i].second);
    }
    for (int x = 1; x <= n; ++x) {
        int l = 0, r = mx_d[0];
        while (l < r - 1) {
            int m = (l + r) / 2;
            auto p = lower_bound(vals.begin(), vals.end(), make_pair(m + 1, 0)) - vals.begin();
            if (pr[p] + x > m) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << r << ' ';
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