#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 8;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            if (s[i][j] == '#' && s[i + 1][j + 1] == '#' && s[i + 1][j - 1] == '#') {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return;
            }
        }
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