#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, b, x, y;
    cin >> n >> b >> x >> y;
    int nw = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        if (nw + x <= b) {
            nw += x;
        } else {
            nw -= y;
        }
        sum += nw;
    }
    cout << sum << '\n';
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