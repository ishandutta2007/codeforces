#include <bits/stdc++.h>

using namespace std;

void solve() {
    int s;
    cin >> s;
    int _s = s;
    int len = 0;
    for (int i = 9; s > 0; --i, len++) {
        s -= i;
    }
    s = _s;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1;; ++j) {
            if (j + (9 + 9 - (len - i - 2)) * (len - i - 1) / 2 >= s) {
                s -= j;
                cout << j;
                break;
            }
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