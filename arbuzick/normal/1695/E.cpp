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
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n * 2);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y, i);
        if (x != y) {
            g[y].emplace_back(x, i);
        }
    }
    vector<vector<int>> ans;
    vector<int> used_vertex(n * 2), used_edge(n);
    for (int i = 0; i < n * 2; ++i) {
        if (!used_vertex[i] && !g[i].empty()) {
            ans.push_back({});
            y_combinator([&](auto dfs, int v) -> void {
                ans.back().push_back(v);
                if (used_vertex[v]) {
                    return;
                }
                used_vertex[v] = 1;
                for (auto [u, ind] : g[v]) {
                    if (!used_edge[ind]) {
                        used_edge[ind] = 1;
                        dfs(u);
                        ans.back().push_back(v);
                    }
                }
            })(i);
            ans.back().pop_back();
            if (ans.back().size() == 2) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    cout << n << ' ' << 2 << '\n';
    int pos = 0;
    vector<array<int, 2>> a(n);
    vector<array<char, 2>> s1(n), s2(n);
    for (int i = 0; i < (int)ans.size(); ++i) {
        for (int j = pos; j < pos + (int)ans[i].size() / 2; ++j) {
            a[j][0] = ans[i][j - pos];
            a[j][1] = ans[i].rbegin()[j - pos];
            if (j + 1 != pos + (int)ans[i].size() / 2) {
                s1[j][0] = s1[j][1] = ((j - pos) % 2 ? 'D' : 'U');
            } else {
                s1[j][0] = ((j - pos) % 2 ? 'D' : 'L');
                s1[j][1] = ((j - pos) % 2 ? 'D' : 'R');
            }
            if (j == pos) {
                s2[j][0] = 'L';
                s2[j][1] = 'R';
            } else if (j + 1 != pos + (int)ans[i].size() / 2) {
                s2[j][0] = s2[j][1] = ((j - pos) % 2 ? 'U' : 'D');
            } else {
                s2[j][0] = ((j - pos) % 2 ? 'L' : 'D');
                s2[j][1] = ((j - pos) % 2 ? 'R' : 'D');
            }
        }
        pos += ans[i].size() / 2;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << a[i][j] + 1 << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << s1[i][j];
        }
        cout << '\n';
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << s2[i][j];
        }
        cout << '\n';
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