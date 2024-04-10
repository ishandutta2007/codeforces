#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> v(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<ll> dp;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        dp.assign(n + 1, -1e17);
        dp[0] = 0;
        pair<ll,ll> mx1{0, 0};
        pair<ll,ll> mx2{0, 0};
        for (int i = 0; i < n; i++) {
            dp[c[i]] = max(dp[c[i]], dp[c[i]] + a * v[i]);
            if (c[i] != mx1.second) 
                dp[c[i]] = max(dp[c[i]], mx1.first + b * v[i]);
            if (c[i] != mx2.second) 
                dp[c[i]] = max(dp[c[i]], mx2.first + b * v[i]);
            pair<ll, ll> val{dp[c[i]], c[i]};
            if (mx1.second == val.second) {
                mx1 = val;
                continue;
            }
            if (mx2.second == val.second) {
                mx2 = val;
                if (mx2 > mx1)
                    swap(mx1, mx2);
                continue;
            }
            if (val > mx1) {
                mx2 = mx1;
                mx1 = val;
            } else if (val > mx2 && val.second != mx1.second) {
                mx2 = val;
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}