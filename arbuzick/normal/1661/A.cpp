#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    long long ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        ans += min(abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]), abs(a[i] - b[i + 1]) + abs(b[i] - a[i + 1]));
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