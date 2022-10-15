#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 300005, MOD = 998244353;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    else return ret * ret % MOD;
}

int n, m, p3[MN], p2[MN], i2[MN];

int ways(int len) {
    if (len <= 1) return 0;
    //printf("%d\n", len);
    int top = (3 * (len - 1) + 1) * fpow(2, len - 1) % MOD - fpow(-1, len - 1);
    top %= MOD, top += MOD, top %= MOD;
    int bot = 9;
    assert(top >= 0 && bot >= 0);
    return top * fpow(bot, MOD - 2) % MOD * fpow(p2[len], MOD - 2) % MOD;
}

signed main() {
    boost();

    p2[0] = p3[0] = 1;
    for (int i = 1; i < MN; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
        p3[i] = p3[i - 1] * 3 % MOD;
        i2[i] = fpow(p2[i], MOD - 2);
    }
    cin >> n >> m;
    //assert(n <= 5 && m <= 5);
    char a[n + 5][m + 5];
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        int len = 0;
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            assert(a[i][j] == 'o' || a[i][j] == '*');
            if (a[i][j] == 'o') cnt++;
            if (a[i][j] == '*') ans += ways(len), ans %= MOD, assert(ans >= 0), len = 0;
            else len++;
        }
        ans += ways(len), ans %= MOD;
        assert(ans >= 0);
    }
    if (cnt <= 1) return 0 * printf("0\n");
    for (int j = 1; j <= m; j++) {
        int len = 0;
        for (int i = 1; i <= n; i++) {
            assert(a[i][j] == 'o' || a[i][j] == '*');
            if (a[i][j] == '*') ans += ways(len), ans %= MOD, assert(ans >= 0), len = 0;
            else len++;
        }
        ans += ways(len), ans %= MOD;
        assert(ans >= 0);
    }
    ans *= p2[cnt];
    assert(ans >= 0);
    //ans %= MOD, ans += MOD, ans %= MOD;
    assert(ans >= 0);
    printf("%lld\n", ans % MOD);

    return 0;
}