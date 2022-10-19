#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26);
    int ans = (int) s.size();
    for (int i = (int) s.size() - 1; i >= 0; --i) {
        if (cnt[s[i] - 'a'] == 0) {
            ans = i;
        }
        cnt[s[i] - 'a']++;
    }
    for (int i = ans; i < (int) s.size(); ++i) {
        cout << s[i];
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