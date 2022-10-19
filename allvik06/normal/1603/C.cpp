#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 998244353;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int ans = 0;
        vector <int> pref_sum(n + 1);
        vector <int> cur_t(n, 1);
        for (int i = 0; i < n; ++i) {
            int last = a[i];
            int flex = i;
            for (int j = i - 1; j >= 0; --j) {
                int new_t = (a[j] + last - 1) / last;
                if (new_t != cur_t[j]) {
                    flex = j;
                    cur_t[j] = new_t;
                    last = a[j] / new_t;
                } else break;
            }
            for (int j = flex; j <= i; ++j) {
                pref_sum[j + 1] = (pref_sum[j] + (cur_t[j] - 1) * (j + 1)) % mod;
            }
            ans += pref_sum[i + 1];
        }
        cout << ans % mod << "\n";
    }
}

/*

 */