#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn];
int dp[maxn];
int sum[maxn], pref[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, p, k;
    cin >> t;
    for (int j = 1; j <= t; ++j) {
        cin >> n >> p >> k;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 0; i <= n; ++i) sum[i] = 0, pref[i] = pref[i - 1] + a[i];
        for (int i = 1; i <= n; ++i) {
            if (i < k) {
                if (pref[i] <= p) ans = i;
            }
            else {
                int add = sum[i % k] + a[i] + pref[i % k];
                if (add <= p) ans = i;
            }
            if (i >= k) sum[i % k] += a[i];
        }
        cout << ans << '\n';
        //cout << dp[n] << '\n';
    }
    return 0;
}