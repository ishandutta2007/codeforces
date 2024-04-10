#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    set<char> used;
    int ans = 0;
    for (auto ch : s) {
        if (used.size() == 3 && !used.count(ch)) {
            used.clear();
        }
        if (used.empty()) {
            ans++;
        }
        used.insert(ch);
    }
    cout << ans << '\n';
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