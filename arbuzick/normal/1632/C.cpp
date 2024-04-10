#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = b - a;
    for (int i = 0; i < b - a; ++i) {
        ans = min(ans, i + 1 + ((a + i) | b) - b);
        ans = min(ans, i + 1 + (a | (b + i)) - (b + i));
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