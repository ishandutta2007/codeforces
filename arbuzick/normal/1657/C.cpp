#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0, pos = 0;
    for (int i = 0; i < n; ++i) {
        if (pos != i && (s[pos] == '(' || s[pos] == s[i])) {
            cnt++;
            pos = i + 1;
        }
    }
    cout << cnt << ' ' << n - pos << '\n';
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