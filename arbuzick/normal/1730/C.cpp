#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<vector<int>> pos(10);
    for (int i = 0; i < (int) s.size(); ++i) {
        pos[s[i] - '0'].push_back(i);
    }
    vector<int> cnt(10);
    int start = 0;
    for (int i = 0; i < 10; ++i) {
        if (!pos[i].empty()) {
            for (int j = start; j <= pos[i].back(); ++j) {
                if (s[j] - '0' == i) {
                    cnt[s[j] - '0']++;
                } else {
                    cnt[min(s[j] - '0' + 1, 9)]++;
                }
            }
            start = max(start, pos[i].back() + 1);
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            cout << i;
        }
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