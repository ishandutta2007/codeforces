#include <bits/stdc++.h>

using namespace std;

template <typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun &&fun) : fun(std::forward<const Fun>(fun)) {}

    template <typename... Args>
    auto operator()(Args &&...args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<array<pair<int, int>, 2>> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> d[i][j].first >> d[i][j].second;
            d[i][j].first--, d[i][j].second--;
        }
    }
    int m;
    cin >> m;
    vector<array<pair<int, int>, 2>> qs(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> qs[i][j].first >> qs[i][j].second;
            qs[i][j].first--, qs[i][j].second--;
        }
        if (max(qs[i][0].first, qs[i][0].second) > max(qs[i][1].first, qs[i][1].second)) {
            swap(qs[i][0], qs[i][1]);
        }
    }
    vector<long long> ans(m, n * 1LL * n + 10);
    vector<int> ind;
    auto dist = [&](pair<int, int> a, pair<int, int> b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };
    for (int i = 0; i < m; ++i) {
        if (max(qs[i][0].first, qs[i][0].second) == max(qs[i][1].first, qs[i][1].second)) {
            ans[i] = dist(qs[i][0], qs[i][1]);
        } else {
            ind.push_back(i);
        }
    }
    y_combinator([&](auto solve, int l, int r, vector<int> ind) -> void {
        if (l == r) {
            return;
        }
        int m = (l + r) / 2;
        auto calc_dp = [&](int l, int m, int r, vector<array<array<long long, 2>, 2>> &dp_suf, vector<array<array<long long, 2>, 2>> &dp_pref) {
            dp_pref[0][0][0] = dp_pref[0][1][1] = 0;
            dp_pref[0][0][1] = dp_pref[0][1][0] = dist(d[m][0], d[m][1]);
            for (int i = m + 1; i < r; ++i) {
                for (int st = 0; st < 2; ++st) {
                    for (int nw = 0; nw < 2; ++nw) {
                        dp_pref[i - m][st][nw] = n * 1LL * n + 10;
                    }
                }
                for (int st = 0; st < 2; ++st) {
                    for (int prv = 0; prv < 2; ++prv) {
                        for (int nw = 0; nw < 2; ++nw) {
                            dp_pref[i - m][st][nw] = min(dp_pref[i - m][st][nw], dp_pref[i - m - 1][st][prv] + 1 + dist({d[i - 1][prv].first + 1 - prv, d[i - 1][prv].second + prv}, d[i][nw]));
                        }
                    }
                }
            }
            dp_suf[m - l][0][0] = dp_suf[m - l][1][1] = 0;
            dp_suf[m - l][0][1] = dp_suf[m - l][1][0] = dist(d[m][0], d[m][1]);
            for (int i = m - 1; i >= l; --i) {
                for (int st = 0; st < 2; ++st) {
                    for (int nw = 0; nw < 2; ++nw) {
                        dp_suf[i - l][st][nw] = n * 1LL * n + 10;
                    }
                }
                for (int st = 0; st < 2; ++st) {
                    for (int prv = 0; prv < 2; ++prv) {
                        for (int nw = 0; nw < 2; ++nw) {
                            dp_suf[i - l][st][nw] = min(dp_suf[i - l][st][nw], dp_suf[i - l + 1][st][prv] + 1 + dist({d[i][nw].first + 1 - nw, d[i][nw].second + nw}, d[i + 1][prv]));
                        }
                    }
                }
            }
        };
        vector<array<array<long long, 2>, 2>> dp_suf(m - l + 1), dp_pref(r - m);
        calc_dp(l, m, r, dp_suf, dp_pref);
        vector<array<array<long long, 2>, 2>> dp_suf2, dp_pref2;
        if (m != l) {
            dp_suf2.resize(m - l);
            dp_pref2.resize(r - m + 1);
            calc_dp(l, m - 1, r, dp_suf2, dp_pref2);
        }
        vector<int> ind_l, ind_r;
        for (auto i : ind) {
            if (max(qs[i][1].first, qs[i][1].second) < m) {
                ind_l.push_back(i);
            } else if (max(qs[i][0].first, qs[i][0].second) > m) {
                ind_r.push_back(i);
            } else {
                int val_st = max(qs[i][0].first, qs[i][0].second), val_fn = max(qs[i][1].first, qs[i][1].second);
                if (val_fn == m) {
                    for (int st = 0; st < 2; ++st) {
                        for (int md = 0; md < 2; ++md) {
                            for (int fn = 0; fn < 2; ++fn) {
                                ans[i] = min(ans[i], dist(d[val_st][st], qs[i][0]) + dp_suf2[val_st - l][md][st] + dp_pref2[val_fn - m][md][fn] + 1 + dist({d[val_fn - 1][fn].first + 1 - fn, d[val_fn - 1][fn].second + fn}, qs[i][1]));
                            }
                        }
                    }
                } else {
                    for (int st = 0; st < 2; ++st) {
                        for (int md = 0; md < 2; ++md) {
                            for (int fn = 0; fn < 2; ++fn) {
                                ans[i] = min(ans[i], dist(d[val_st][st], qs[i][0]) + dp_suf[val_st - l][md][st] + dp_pref[val_fn - m - 1][md][fn] + 1 + dist({d[val_fn - 1][fn].first + 1 - fn, d[val_fn - 1][fn].second + fn}, qs[i][1]));
                            }
                        }
                    }
                }
            }
        }
        if (l != r - 1) {
            solve(l, m, ind_l);
            solve(m, r, ind_r);
        }
    })(0, n - 1, ind);
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << '\n';
    }
}

void solve2() {
    int n;
    cin >> n;
    vector<array<pair<int, int>, 2>> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> d[i][j].first >> d[i][j].second;
            d[i][j].first--, d[i][j].second--;
        }
    }
    vector<vector<array<array<long long, 2>, 2>>> go(17, vector<array<array<long long, 2>, 2>>(n));
    auto dist = [&](pair<int, int> a, pair<int, int> b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };
    for (int i = 0; i < 17; ++i) {
        for (int j = 0; j < n - (1 << i); ++j) {
            if (i == 0) {
                for (int st = 0; st < 2; ++st) {
                    for (int fn = 0; fn < 2; ++fn) {
                        go[i][j][st][fn] = 1 + dist({d[j][st].first + 1 - st, d[j][st].second + st}, d[j + 1][fn]);
                    }
                }
            } else {
                go[i][j][0][0] = go[i][j][0][1] = go[i][j][1][0] = go[i][j][1][1] = n * 1LL * n + 10;
                for (int st = 0; st < 2; ++st) {
                    for (int md = 0; md < 2; ++md) {
                        for (int fn = 0; fn < 2; ++fn) {
                            go[i][j][st][fn] = min(go[i][j][st][fn], go[i - 1][j][st][md] + go[i - 1][j + (1 << (i - 1))][md][fn]);
                        }
                    }
                }
            }
        }
    }
    int m;
    cin >> m;
    vector<array<pair<int, int>, 2>> qs(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> qs[i][j].first >> qs[i][j].second;
            qs[i][j].first--, qs[i][j].second--;
        }
        if (max(qs[i][0].first, qs[i][0].second) > max(qs[i][1].first, qs[i][1].second)) {
            swap(qs[i][0], qs[i][1]);
        }
        int val_st = max(qs[i][0].first, qs[i][0].second), val_fn = max(qs[i][1].first, qs[i][1].second);
        if (val_st == val_fn) {
            cout << dist(qs[i][0], qs[i][1]) << '\n';
            continue;
        }
        array<array<long long, 2>, 2> dp;
        dp[0][0] = dp[1][1] = 0;
        dp[0][1] = dp[1][0] = dist(d[val_st][0], d[val_st][1]);
        int nw = val_st;
        for (int i = 16; i >= 0; --i) {
            if (nw + (1 << i) < val_fn) {
                array<array<long long, 2>, 2> dp_nw;
                for (int st = 0; st < 2; ++st) {
                    for (int fn = 0; fn < 2; ++fn) {
                        dp_nw[st][fn] = n * 1LL * n + 10;
                    }
                }
                for (int st = 0; st < 2; ++st) {
                    for (int md = 0; md < 2; ++md) {
                        for (int fn = 0; fn < 2; ++fn) {
                            dp_nw[st][fn] = min(dp_nw[st][fn], dp[st][md] + go[i][nw][md][fn]);
                        }
                    }
                }
                nw += (1 << i);
                dp = dp_nw;
            }
        }
        long long ans = n * 1LL * n + 10;
        for (int st = 0; st < 2; ++st) {
            for (int fn = 0; fn < 2; ++fn) {
                ans = min(ans, dist(d[val_st][st], qs[i][0]) + dp[st][fn] + 1 + dist({d[val_fn - 1][fn].first + 1 - fn, d[val_fn - 1][fn].second + fn}, qs[i][1]));
            }
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        // solve();
        solve2();
    }
    return 0;
}