#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 2005, MOD = 1e9 + 7;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int n, m, k, dp[MN][MN];

int rec(int ac, int re) {
    if (dp[ac][re] != -1) return dp[ac][re];
    if (!ac) return dp[ac][re] = 0;
    if (!re) return dp[ac][re] = ac * k % MOD;
    int take = rec(ac - 1, re); //lower val
    int rej = rec(ac, re - 1); //higher val
    return dp[ac][re] = (take + rej) % MOD * fpow(2, MOD - 2) % MOD;
}

int32_t main() {
    boost();

    /*int ans = 1;
    for (int i = 1; i <= 99; i++) ans = ans * fpow(2, MOD - 2) % MOD;
    printf("%lld\n", ans);*/
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) dp[i][j] = -1;
        }
        printf("%lld\n", rec(m, n - m));
    }

    return 0;
}