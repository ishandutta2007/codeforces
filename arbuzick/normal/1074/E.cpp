#include <bits/stdc++.h>

using namespace std;

void make_swaps(vector<vector<int>> a, vector<vector<int>> ans) {
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (i % 3 == 0) {
            for (auto v : a) {
                for (auto val : v) {
                    cout << val << ' ';
                }
                cout << '\n';
            }
            cout << '\n';
        }
        map<int, int> nxt;
        for (int j = 0; j < (int)ans[i].size(); ++j) {
            nxt[ans[i][(j + 1) % ans[i].size()]] = ans[i][j];
        }
        for (auto &v : a) {
            for (auto &val : v) {
                if (nxt.count(val)) {
                    val = nxt[val];
                }
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<pair<int, int>> pos(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            a[i][j]--;
            pos[a[i][j]] = {i, j};
        }
    }
    auto a_old = a;
    vector<vector<int>> ans;
    int sum = 0;
    auto do_swap = [&](int i1, int j1, int i2, int j2) {
        sum += 14;
        if (i1 == i2) {
            if (j1 > j2) {
                swap(j1, j2);
            }
            if (i1 >= 1 && j1 >= 1) {
                vector<int> f = {-1, a[i1 - 1][j1 - 1], a[i1 - 1][j1], a[i1 - 1][j1 + 1], a[i1][j1 - 1], a[i1][j1], a[i1][j1 + 1]};
                ans.push_back({f[2], f[3], f[6], f[5]});
                ans.push_back({f[4], f[1], f[5], f[6]});
                ans.push_back({f[1], f[4], f[6], f[5], f[3], f[2]});
            } else if (i1 >= 1) {
                vector<int> f = {-1, a[i1 - 1][j1], a[i1 - 1][j1 + 1], a[i1 - 1][j1 + 2], a[i1][j1], a[i1][j1 + 1], a[i1][j1 + 2]};
                ans.push_back({f[1], f[4], f[5], f[2]});
                ans.push_back({f[3], f[5], f[4], f[6]});
                ans.push_back({f[1], f[2], f[3], f[6], f[4], f[5]});
            } else if (j1 >= 1) {
                vector<int> f = {-1, a[i1][j1 - 1], a[i1][j1], a[i1][j1 + 1], a[i1 + 1][j1 - 1], a[i1 + 1][j1], a[i1 + 1][j1 + 1]};
                ans.push_back({f[2], f[5], f[6], f[3]});
                ans.push_back({f[1], f[4], f[2], f[3]});
                ans.push_back({f[1], f[3], f[2], f[6], f[5], f[4]});
            } else {
                vector<int> f = {-1, a[i1][j1], a[i1][j1 + 1], a[i1][j1 + 2], a[i1 + 1][j1], a[i1 + 1][j1 + 1], a[i1 + 1][j1 + 2]};
                ans.push_back({f[1], f[2], f[5], f[4]});
                ans.push_back({f[2], f[1], f[3], f[6]});
                ans.push_back({f[1], f[2], f[4], f[5], f[6], f[3]});
            }
        } else {
            if (i1 > i2) {
                swap(i1, i2);
            }
            if (i1 >= 1 && j1 >= 1) {
                vector<int> f = {-1, a[i1 - 1][j1 - 1], a[i1][j1 - 1], a[i1 + 1][j1 - 1], a[i1 - 1][j1], a[i1][j1], a[i1 + 1][j1]};
                ans.push_back({f[2], f[3], f[6], f[5]});
                ans.push_back({f[4], f[1], f[5], f[6]});
                ans.push_back({f[1], f[4], f[6], f[5], f[3], f[2]});
            } else if (j1 >= 1) {
                vector<int> f = {-1, a[i1][j1 - 1], a[i1 + 1][j1 - 1], a[i1 + 2][j1 - 1], a[i1][j1], a[i1 + 1][j1], a[i1 + 2][j1]};
                ans.push_back({f[1], f[4], f[5], f[2]});
                ans.push_back({f[3], f[5], f[4], f[6]});
                ans.push_back({f[1], f[2], f[3], f[6], f[4], f[5]});
            } else if (i1 >= 1) {
                vector<int> f = {-1, a[i1 - 1][j1], a[i1][j1], a[i1 + 1][j1], a[i1 - 1][j1 + 1], a[i1][j1 + 1], a[i1 + 1][j1 + 1]};
                ans.push_back({f[2], f[5], f[6], f[3]});
                ans.push_back({f[1], f[4], f[2], f[3]});
                ans.push_back({f[1], f[3], f[2], f[6], f[5], f[4]});
            } else {
                vector<int> f = {-1, a[i1][j1], a[i1 + 1][j1], a[i1 + 2][j1], a[i1][j1 + 1], a[i1 + 1][j1 + 1], a[i1 + 2][j1 + 1]};
                ans.push_back({f[1], f[2], f[5], f[4]});
                ans.push_back({f[2], f[1], f[3], f[6]});
                ans.push_back({f[1], f[2], f[4], f[5], f[6], f[3]});
            }
        }
    };
    for (int i = 0; i < n * m; ++i) {
        while (pos[i].second > i % m) {
            do_swap(pos[i].first, pos[i].second, pos[i].first, pos[i].second - 1);
            swap(a[pos[i].first][pos[i].second], a[pos[i].first][pos[i].second - 1]);
            pos[a[pos[i].first][pos[i].second]].second++;
            pos[i].second--;
        }
        while (pos[i].second < i % m) {
            do_swap(pos[i].first, pos[i].second, pos[i].first, pos[i].second + 1);
            swap(a[pos[i].first][pos[i].second], a[pos[i].first][pos[i].second + 1]);
            pos[a[pos[i].first][pos[i].second]].second--;
            pos[i].second++;
        }
        while (pos[i].first > i / m) {
            if (i % m != m - 1) {
                sum += 4;
                ans.push_back({a[pos[i].first][pos[i].second], a[pos[i].first - 1][pos[i].second], a[pos[i].first - 1][pos[i].second + 1], a[pos[i].first][pos[i].second + 1]});
                map<int, int> nxt;
                for (int j = 0; j < (int)ans.back().size(); ++j) {
                    nxt[ans.back()[(j + 1) % ans.back().size()]] = ans.back()[j];
                }
                int x = 0;
                for (auto &v : a) {
                    int y = 0;
                    for (auto &val : v) {
                        if (nxt.count(val)) {
                            val = nxt[val];
                            pos[val] = {x, y};
                        }
                        y++;
                    }
                    x++;
                }
                continue;
            }
            do_swap(pos[i].first, pos[i].second, pos[i].first - 1, pos[i].second);
            swap(a[pos[i].first][pos[i].second], a[pos[i].first - 1][pos[i].second]);
            pos[a[pos[i].first][pos[i].second]].first++;
            pos[i].first--;
        }
    }
    // make_swaps(a_old, ans);
    assert(sum <= 100000);
    cout << ans.size() << '\n';
    for (auto v : ans) {
        cout << v.size() << ' ';
        for (auto val : v) {
            cout << val + 1 << ' ';
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