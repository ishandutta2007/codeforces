#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n % 2;
    for (int i = n / 2; i >= 0 && n - i < n && s[i] == s[n - i]; --i) {
        ans++;
    }
    for (int i = n / 2 - 1; i >= 0 && n - i - 2 < n && s[i] == s[n - i - 2]; --i) {
        ans++;
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