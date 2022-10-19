#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s.size() == 2) {
        cout << s[1] << '\n';
    } else {
        sort(s.begin(), s.end());
        cout << s[0] << '\n';
    }
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