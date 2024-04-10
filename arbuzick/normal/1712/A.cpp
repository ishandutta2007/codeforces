#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
        if (p[i] < k && i >= k) {
            ans++;
        }
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