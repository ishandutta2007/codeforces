#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b + 2 > n || abs(a - b) > 1) {
        cout << -1 << '\n';
    } else {
        int pos1 = 1, pos2 = n, prv = -1;
        if (a >= b) {
            cout << pos1 << ' ';
            pos1++;
            prv = 1;
        } else {
            cout << pos2 << ' ';
            pos2--;
            prv = 0;
        }
        for (int i = 1; i < n; ++i) {
            if (prv == 1 && a > 0) {
                cout << pos2 << ' ';
                a--;
                pos2--;
                prv = 0;
            } else if (prv == 0 && b > 0) {
                cout << pos1 << ' ';
                b--;
                pos1++;
                prv = 1;
            } else if (prv == 1) {
                cout << pos1 << ' ';
                pos1++;
            } else {
                cout << pos2 << ' ';
                pos2--;
            }
        }
        cout << '\n';
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