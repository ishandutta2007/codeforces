#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 105, MOD = 1e9 + 7;

int n, a[MN], b[MN], c[MN], psa[MN], psum[MN], q, x, dp[12000005], ndp[12000005], lo_ans = 1;
map<int, int> memo;

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i], psa[i] = psa[i - 1] + c[i], lo_ans = lo_ans * (c[i] + 1) % MOD;
    for (int i = 1; i < n; i++) cin >> b[i];
    int sum = 0;
    for (int i = 2; i <= n; i++) a[i] = a[i - 1] + b[i - 1];
    int v = 0;
    for (int i = 1; i <= n; i++) sum += a[i], psum[i] = psum[i - 1] + a[i];
    for (int i = 1; i <= n; i++) v = min(v, -(psum[i] / i));
    //printf("%lld\n", sum);
    //if (x > c[1]) return 0 * printf("0\n");
    cin >> q;
    while (q--) {
        cin >> x;
        if (x < v - 100) printf("%lld\n", lo_ans);
        else if (x > v + 100) printf("0\n");
        else if (memo.count(x)) printf("%lld\n", memo[x]);
        else {
            memset(dp, 0, sizeof(dp));
            memset(ndp, 0, sizeof(ndp));
            int ans = 0;
            dp[0] = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= psa[i - 1]; j++) {
                    int lo = 0, hi = c[i];
                    //if (i == 1) lo = max(lo, x);
                    ndp[j + lo] += dp[j];
                    ndp[j + lo] %= MOD;
                    ndp[j + hi + 1] -= dp[j];
                    ndp[j + hi + 1] %= MOD;
                }
                for (int j = 1; j <= psa[i]; j++) {
                    ndp[j] += ndp[j - 1];
                    ndp[j] %= MOD;
                }
                for (int j = 0; j <= psa[i]; j++) {
                    dp[j] = ndp[j];
                    if (j < psum[i] + x * i) dp[j] = 0;
                }
                //printf("\n");
                for (int j = 0; j <= psa[i] + 1; j++) {
                    ndp[j] = 0;
                }
            }
            for (int i = 0; i <= psa[n]; i++) ans += dp[i], ans %= MOD;
            ans %= MOD, ans += MOD, ans %= MOD;
            printf("%lld\n", memo[x] = ans);
        }
    }

    return 0;
}