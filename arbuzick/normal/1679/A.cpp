#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    if (n % 2 == 1 || n < 4) {
        cout << -1 << '\n';
        return;
    }
    cout << (n + 5) / 6 << ' ' << n / 4 << '\n';
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