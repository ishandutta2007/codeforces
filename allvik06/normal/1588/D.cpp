#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;
int n;
map <char, vector <int>> dp;
map <char, vector <pair <char, int>>> p;
vector <map <char, vector <int>>> all;

void lazy_dp(char c, int mask) {
    if (dp[c][mask] != -1) return;
    dp[c][mask] = 1;
    char flex[2] = {'a', 'A'};
    for (int i = 0; i < 26; ++i) {
        for (char start : flex) {
            char now = start + i;
            int new_mask = 0;
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                int last_pos = all[j][c][(mask >> j) & 1];
                if (all[j][now].empty()) {
                    ok = false;
                    break;
                }
                if (all[j][now][0] > last_pos) {
                    continue;
                }
                if (all[j][now].size() == 1) {
                    ok = false;
                    break;
                }
                if (all[j][now][1] > last_pos) {
                    new_mask += (1 << j);
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                lazy_dp(now, new_mask);
                if (dp[c][mask] < dp[now][new_mask] + 1) {
                    dp[c][mask] = dp[now][new_mask] + 1;
                    p[c][mask] = make_pair(now, new_mask);
                }
            }
        }
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector <string> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        all.assign(n, {});
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (int)a[i].size(); ++j) {
                all[i][a[i][j]].push_back(j);
            }
        }
        dp.clear();
        p.clear();
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                dp['a' + i].push_back(-1);
                p['a' + i].emplace_back('a', 0);
                dp['A' + i].push_back(-1);
                p['A' + i].emplace_back('a', 0);
            }
        }
        int ans_len = 0;
        char s;
        int mask;
        for (int i = 0; i < 26; ++i) {
            char flex[2] = {'a', 'A'};
            for (char c : flex) {
                char start = c + i;
                bool ok = true;
                for (int j = 0; j < n; ++j) {
                     if (all[j][start].empty()) {
                         ok = false;
                         break;
                     }
                }
                if (ok) {
                    lazy_dp(start, 0);
                    if (dp[start][0] > ans_len) {
                        ans_len = dp[start][0];
                        mask = 0;
                        s = start;
                    }
                }
            }
        }
        string answer;
        while ((int)answer.size() < ans_len) {
            answer += s;
            int new_mask = p[s][mask].second;
            s = p[s][mask].first;
            mask = new_mask;
        }
        cout << ans_len << "\n";
        cout << answer << "\n";
    }
}

/*

 */