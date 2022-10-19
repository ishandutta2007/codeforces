#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> s(n), f(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cout << f[i] - s[i] << ' ';
        } else {
            cout << f[i] - max(s[i], f[i - 1]) << ' ';
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