#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> used(26), prv(26, -1);
    for (int i = 0; i < n; ++i) {
        used[s[i] - 'a'] = 1;
    }
    bool ch = true;
    for (int i = 0; i < n; ++i) {
        if (prv[s[i] - 'a'] != -1) {
            for (int j = 0; j < 26; ++j) {
                if (used[j] && prv[j] < prv[s[i] - 'a']) {
                    ch = false;
                }
            }
        }
        prv[s[i] - 'a'] = i;
    }
    cout << (ch ? "YES\n" : "NO\n");
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