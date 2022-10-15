#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005, MOD = 1e9 + 7;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int twos(int x) {
    int ret = 0;
    while (x % 2 == 0) x /= 2, ret++;
    return ret;
}

int n, a[MN], cnt[35][2], f[35];

int32_t main() {
    boost();

    cin >> n;
    int ans = fpow(2, n) - 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int t = twos(a[i]);
        for (int j = 0; j < t; j++) cnt[j][0]++;
        cnt[t][1]++;
    }
    for (int i = 32; i > 0; i--) {
        if (!cnt[i][1]) continue;
        ans -= fpow(2, cnt[i][1] - 1) * fpow(2, cnt[i][0]) % MOD;
        ans %= MOD;
    }
    ans %= MOD, ans += MOD, ans %= MOD;
    printf("%lld\n", ans);

    return 0;
}