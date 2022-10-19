#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n), pos(k);
    vector<int> del_n(n), del_k(k), prv(k, -1), nxt(k, -1);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int sz;
        cin >> sz;
        a[i].resize(sz);
        for (int j = 0; j < sz; ++j) {
            cin >> a[i][j];
            a[i][j]--;
            if (!pos[a[i][j]].empty() && pos[a[i][j]].back() == i) {
                del_k[a[i][j]] = 1;
                s.insert(a[i][j]);
            }
            pos[a[i][j]].push_back(i);
            if (j > 0) {
                if (nxt[a[i][j - 1]] != -1 && nxt[a[i][j - 1]] != a[i][j]) {
                    del_k[a[i][j - 1]] = 1;
                    s.insert(a[i][j - 1]);
                }
                nxt[a[i][j - 1]] = a[i][j];
                if (prv[a[i][j]] != -1 && prv[a[i][j]] != a[i][j - 1]) {
                    del_k[a[i][j]] = 1;
                    s.insert(a[i][j]);
                }
                prv[a[i][j]] = a[i][j - 1];
            }
        }
    }
    while (!s.empty()) {
        int col = *s.begin();
        s.erase(col);
        for (auto i : pos[col]) {
            if (!del_n[i]) {
                del_n[i] = 1;
                for (auto val : a[i]) {
                    if (!del_k[val]) {
                        del_k[val] = 1;
                        s.insert(val);
                    }
                }
            }
        }
    }
    map<int, int> count;
    for (int i = 0; i < k; ++i) {
        if (del_k[i] || prv[i] != -1) {
            continue;
        }
        int len = 1, v = i;
        while (nxt[v] != -1) {
            v = nxt[v];
            len++;
        }
        count[len]++;
    }
    vector<int> dp(m + 1);
    dp[0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (auto [len, val] : count) {
            if (len > i) {
                continue;
            }
            dp[i] = (dp[i] + dp[i - len] * 1LL * val) % mod;
        }
    }
    cout << dp[m] << '\n';
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