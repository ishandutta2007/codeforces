#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

struct port {
    int x, y, s;
};

const int MN = 200005, MOD = 998244353;

int n, x, y, s, dp[MN], psa[MN];
port a[MN];

int bs(int x) {
    int lo = 1, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (a[mid].x < x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> s;
        a[i] = {x, y, s};
    }
    int ans = a[n].x + 1;
    for (int i = 1; i <= n; i++) {
        int base = a[i].x - a[i].y;
        int id = bs(a[i].y);
        if (id < i) base += psa[i - 1] - psa[id - 1];
        dp[i] = base % MOD;
        psa[i] = (psa[i - 1] + dp[i]) % MOD;
        if (a[i].s) ans += dp[i];
        //printf("%d %d\n", dp[i], id);
    }
    ans %= MOD, ans += MOD, ans %= MOD;
    printf("%lld\n", ans);

    return 0;
}