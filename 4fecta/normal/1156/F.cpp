#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 5005, MOD = 998244353;

int n, a[MN], dp[MN][MN], ans, freq[MN], nxt[MN], inv[MN]; //how many cards have been taken, cur index

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p % 2) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int frac(int num, int dem) {
    return num * inv[dem] % MOD;
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) inv[i] = fpow(i, MOD - 2);
    for (int i = 1; i <= n; i++) cin >> a[i], dp[0][i] = frac(1, n), freq[a[i]]++;
    sort(a + 1, a + n + 1);
    int num = 0x3f3f3f3f, idx = n + 1;
    for (int i = n; i > 0; i--) {
        if (a[i] != num) num = a[i], idx = i + 1;
        nxt[i] = idx;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += dp[i][j] * frac(freq[a[j]] - 1, n - i - 1); ans %= MOD;
            dp[i + 1][nxt[j]] += dp[i][j] * frac(1, n - i - 1); dp[i + 1][nxt[j]] %= MOD;
        }
        for (int j = 1; j <= n; j++) dp[i + 1][j] += dp[i + 1][j - 1], dp[i + 1][j] %= MOD;
    }
    printf("%lld\n", ans % MOD);

    return 0;
}