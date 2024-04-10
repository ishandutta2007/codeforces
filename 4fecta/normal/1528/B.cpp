#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 2000005, MOD = 998244353;

int n, dp[MN], psa[MN];

int32_t main() {
    boost();

    for (int i = 1; i < MN; i++) {
        for (int j = i + i; j < MN; j += i) dp[j]++;
    }
    cin >> n;
    dp[0] = dp[1] = 1;
    psa[0] = 1;
    psa[1] = 2;
    for (int i = 2; i <= n; i++) {
        dp[i] += psa[i - 1];
        dp[i] %= MOD;
        psa[i] = dp[i] + psa[i - 1];
        psa[i] %= MOD;
        //for (int j = 0; j < i; j++) dp[i] += dp[j], dp[i] %= MOD;
        //for (int j = 1; j * 2 <= i; j++) if (i % j == 0) dp[i]++;
        //dp[i] %= MOD;
    }
    printf("%lld\n", dp[n]);

    return 0;
}