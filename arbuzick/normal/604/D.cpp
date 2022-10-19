#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int p, k;
    cin >> p >> k;
    if (k == 0) {
        int ans = 1;
        for (int i = 1; i < p; ++i) {
            ans = ans * 1LL * p % mod;
        }
        cout << ans << '\n';
    } else {
        vector<int> used(p);
        int ans = 1;
        if (k == 1) {
            ans = p;
        }
        for (int i = 1; i < p; ++i) {
            if (!used[i]) {
                int v = i;
                while (!used[v]) {
                    used[v] = 1;
                    v = v * 1LL * k % p;
                }
                ans = ans * 1LL * p % mod;
            }
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}