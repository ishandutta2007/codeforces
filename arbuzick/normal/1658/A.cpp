#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == '0' && s[i + 1] == '0') {
            ans += 2;
        } else if (i + 2 < n && s[i] == '0' && s[i + 2] == '0') {
            ans += 1;
        }
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