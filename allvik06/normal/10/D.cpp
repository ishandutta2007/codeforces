#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    set<int> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                s.insert(a[i]);
                break;
            }
        }
    }
    unordered_map<int, int> d, o;
    int ii = 1;
    for (int i : s) {
        o[ii] = i;
        d[i] = ii;
        ++ii;
    }
    for (int i = 0; i < n; ++i) {
        if (d[a[i]] == 0) {
            a[i] += 1000;
        } else {
            a[i] = d[a[i]];
        }
    }
    for (int i = 0; i < m; ++i) {
        if (d[b[i]] == 0) {
            b[i] += 1000;
        } else {
            b[i] = d[b[i]];
        }
    }
    vector<vector<vector<short>>> dp(n, vector<vector<short>>(m, vector<short>(ii, 0)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || j == 0) {
                if (i > 0) {
                    dp[i][j] = dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] = dp[i][j - 1];
                }
                if (a[i] == b[j]) {
                    dp[i][j][a[i]] = 1;
                }
                continue;
            }
            if (a[i] == b[j]) {
                dp[i][j][a[i]] = 1;
                for (int k = 1; k < a[i]; ++k) {
                    dp[i][j][a[i]] = max((short) (dp[i - 1][j - 1][k] + 1), dp[i][j][a[i]]);
                }
            }
            for (int k = 1; k < ii; ++k) {
                dp[i][j][k] = max((short) (dp[i - 1][j][k]), dp[i][j][k]);
            }
            for (int k = 1; k < ii; ++k) {
                dp[i][j][k] = max((short) (dp[i][j - 1][k]), dp[i][j][k]);
            }
        }
    }
    short maxx = 0;
    pair<int, int> now = {n - 1, m - 1};
    int kn = 0;
    for (int k = 1; k < ii; ++k) {
        if (maxx < dp[n - 1][m - 1][k]) {
            kn = k;
        }
        maxx = max(maxx, dp[n - 1][m - 1][k]);
    }
    cout << maxx << "\n";
    vector<int> ans;
    while (dp[now.first][now.second][kn] > (short) 0) {
        int flag = 0;
        if (a[now.first] == b[now.second] && a[now.first] <= kn) {
            if (dp[now.first][now.second][kn] == 1) {
                ans.push_back(now.first);
                break;
            }
            for (int k = 1; k < a[now.first]; ++k) {
                if (dp[now.first - 1][now.second - 1][k] == dp[now.first][now.second][kn] - 1) {
                    ans.push_back(now.first);
                    now = {now.first - 1, now.second - 1};
                    kn = k;
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                continue;
            }
        }
        if (now.first == 0 && now.second == 0) {
            break;
        }
        if (now.first != 0) {
            if (dp[now.first - 1][now.second][kn] == dp[now.first][now.second][kn]) {
                --now.first;
                continue;
            }
        }
        if (now.second != 0) {
            if (dp[now.first][now.second - 1][kn] == dp[now.first][now.second][kn]) {
                --now.second;
                continue;
            }
        }
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << o[a[ans[i]]] << " ";
    }
    return 0;
}