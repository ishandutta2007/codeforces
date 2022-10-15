#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 4000005;

int n, MOD, dp[MN], psa[MN];

int32_t main() {
    boost();

    cin >> n >> MOD;
    dp[1] = 1;
    int sum = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        psa[i] += psa[i - 1];
        psa[i] %= MOD, psa[i] += MOD, psa[i] %= MOD;
        dp[i] = (sum + psa[i]) % MOD;
        /*for (int z = 2; z <= i;) {
            int val = i / z;
            int nxt = i / val + 1;
            dp[i] += dp[i / z] * (nxt - z);
            z = nxt;
            cnt++;
        }*/
        for (int mul = 2; mul <= n; mul++) {
            int lft = i * mul, rit = lft + mul;
            if (lft > n) break;
            psa[lft] += dp[i];
            psa[lft] %= MOD;
            if (rit <= n) psa[rit] -= dp[i], psa[rit] %= MOD;
        }
        if (i > 1) sum = (sum + dp[i]) % MOD;
    }
    printf("%lld\n", dp[n]);
    //printf("%lld\n", cnt);
    /*for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) printf("%d ", cnt[i][j]);
        printf("\n");
    }*/

    return 0;
}