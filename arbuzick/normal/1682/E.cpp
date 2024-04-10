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
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    vector<vector<int>> g(n);
    map<pair<int, int>, int> ind;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        ind[{x, y}] = ind[{y, x}] = i;
    }
    vector<int> tin(n), tout(n), pr(n);
    int t = 0;
    for (int i = 0; i < n; ++i) {
        if (!tin[i]) {
            y_combinator([&](auto dfs, int v, int p) -> void {
                tin[v] = ++t;
                pr[v] = p;
                vector<pair<int, int>> g_nw;
                for (auto u : g[v]) {
                    if (u != p) {
                        dfs(u, v);
                        g_nw.emplace_back(tin[u], u);
                    }
                }
                sort(g_nw.begin(), g_nw.end());
                g[v].clear();
                for (auto [vl, u] : g_nw) {
                    g[v].push_back(u);
                }
                tout[v] = ++t;
            })(i, -1);
        }
    }
    auto check = [&](int x, int y) {
        if (y == pr[x]) {
            swap(x, y);
        }
        return (tin[y] <= tin[p[x]] && tout[p[x]] <= tout[y]) && !(tin[y] <= tin[p[y]] && tout[p[y]] <= tout[y]);
    };
    auto fnd = [&](int x) {
        if (p[x] == x) {
            return -1;
        }
        int i = upper_bound(g[x].begin(), g[x].end(), p[x], [&](int a, int b) {
                    return tin[a] < tin[b];
                }) -
                g[x].begin();
        if (i != 0) {
            i--;
            if (tin[g[x][i]] <= tin[p[x]] && tout[p[x]] <= tout[g[x][i]]) {
                return g[x][i];
            }
        }
        if (pr[x] != -1 && !(tin[x] <= tin[p[x]] && tout[p[x]] <= tout[x])) {
            return pr[x];
        }
        return -1;
    };
    vector<pair<int, int>> ans;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        int j = fnd(i);
        if (j != -1 && check(i, j) && i < j) {
            q.emplace(i, j);
        }
    }
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (!check(i, j)) {
            continue;
        }
        ans.emplace_back(i, j);
        swap(p[i], p[j]);
        int x = fnd(i), y = fnd(j);
        if (x != -1 && check(i, x)) {
            q.emplace(i, x);
        }
        if (y != -1 && check(j, y)) {
            q.emplace(j, y);
        }
    }
    for (auto p : ans) {
        cout << ind[p] + 1 << ' ';
    }
    cout << '\n';
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