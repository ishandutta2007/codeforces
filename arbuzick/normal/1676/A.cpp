#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    cout << (s[0] + s[1] + s[2] == s[3] + s[4] + s[5] ? "YES" : "NO") << "\n";
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