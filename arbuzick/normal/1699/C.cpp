#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int l = pos[0], r = pos[0] + 1, used = 1;
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (l <= pos[i] && pos[i] < r) {
            ans = ans * 1LL * (r - l - used) % mod;
            used++;
        } else {
            l = min(l, pos[i]);
            r = max(r, pos[i] + 1);
            used++;
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