#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << 2 << '\n';
    vector<int> used(n + 1);
    int prv = 1;
    cout << 1 << ' ';
    used[1] = 1;
    int pos = 2;
    while (pos <= n) {
        if (prv * 2 > n) {
            if (used[pos]) {
                pos++;
            } else {
                prv = pos;
                cout << pos << ' ';
                used[pos] = 1;
            }
        } else {
            cout << prv * 2 << ' ';
            used[prv * 2] = 1;
            prv *= 2;
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