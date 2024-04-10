#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int INF = 1e9;
const int mod = 998244353;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    vector<ll> flex(m + 1);
    vector<ll> dp(m + 1), pref(m + 2);
    for (int i = m; i >= 1; --i) {
        int max_kol = m / i;
        dp[0] = 1;
        for (int j = 1; j <= max_kol + 1; ++j) pref[j] = 1;
        for (int j = 0; j < n; ++j) {
            int min_kol1 = (a[j].first + i - 1) / i, max_kol1 = a[j].second / i;
            if (max_kol1 < min_kol1) {
                pref[max_kol + 1] = 0;
                break;
            }
            for (int k = max_kol; k >= min_kol1; --k) {
                dp[k] = (pref[k - min_kol1 + 1] - pref[k - min(k, max_kol1)] + mod) % mod;
            }
            for (int k = min_kol1 - 1; k >= 0; --k) dp[k] = 0;
            for (int k = 1; k <= max_kol + 1; ++k) {
                pref[k] = (pref[k - 1] + dp[k - 1]) % mod;
            }
        }
        flex[i] = pref[max_kol + 1];
        for (int j = 0; j <= max_kol; ++j) dp[j] = 0;
        for (int j = 1; j <= max_kol + 1; ++j) pref[j] = 0;
    }
    for (int i = m; i >= 1; --i) {
        for (int j = 2 * i; j <= m; j += i) {
            flex[i] = (flex[i] - flex[j] + mod) % mod;
        }
    }
    cout << flex[1];
}