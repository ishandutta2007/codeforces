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
    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    vector<int> l, r;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        if (t[i] * 1LL * 3 <= m) {
            l.push_back(t[i]);
        } else {
            r.push_back(t[i]);
        }
    }
    vector<vector<int>> g(l.size());
    for (int i = 0; i < (int) l.size(); ++i) {
        for (int j = 0; j < (int) r.size(); ++j) {
            if (r[j] * 1LL * 2 + l[i] <= m && r[j] % l[i] == 0) {
                g[i].push_back(j);
            }
        }
    }
    vector<int> mt(r.size(), -1), used(l.size()), pr(l.size(), -1);
    for (int i = 0; i < (int) l.size(); ++i) {
        used.assign(l.size(), 0);
        y_combinator([&](auto try_kuhn, int v) -> bool {
            if (used[v]) {
                return false;
            }
            used[v] = 1;
            for (auto u : g[v]) {
                if (mt[u] == -1 || try_kuhn(mt[u])) {
                    mt[u] = v;
                    return true;
                }
            }
            return false;
        })(i);
    }
    if (count(mt.begin(), mt.end(), -1)) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < (int) r.size(); ++i) {
        pr[mt[i]] = i;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < (int) l.size(); ++i) {
        if (pr[i] != -1) {
            ans.push_back({r[pr[i]] * 2 + l[i], r[pr[i]] + l[i]});
        } else {
            ans.push_back({l[i] * 3, l[i] * 2});
        }
    }
    cout << ans.size() << '\n';
    for (auto [a, b] : ans) {
        cout << a << ' ' << b << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}