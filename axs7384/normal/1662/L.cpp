#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 9;

int n, v;
struct DP { int id, t, a, c; } dp[N];
long long mp[N];

struct BIT {
    int n, maxv[N];
    void init(int _n) {
        n = _n; fill_n(maxv, n + 5, -INT_MAX);
    }
    void upd(int p, int k) {
        for (; p <= n; p += p & -p) maxv[p] = max(maxv[p], k);
    }
    int q(int p) {
        int r = -INT_MAX;
        for (; p; p -= p & -p) r = max(r, maxv[p]);
        return r;
    }
} bit;

void cdq(int l, int r) {
    if (l == r) {
        return;
    }
    int m = (l + r) >> 1;
    cdq(l, m);
    sort(dp + l, dp + r + 1, [](const DP &a, const DP &b)
        { return a.a == b.a ? a.t < b.t : a.a < b.a; });
    int tot = 0;
    for (int i = l; i <= r; ++i) {
        mp[++tot] = (long long)v * dp[i].t - dp[i].a;
    }
    sort(mp + 1, mp + tot + 1);
    tot = unique(mp + 1, mp + tot + 1) - mp - 1;
    bit.init(tot);
    for (int i = l; i <= r; ++i) {
        int j = lower_bound(mp + 1, mp + tot + 1,
            (long long)v * dp[i].t - dp[i].a) - mp;
        if (dp[i].id <= m) {
            bit.upd(j, dp[i].c);
        }
        else {
            dp[i].c = max(dp[i].c, bit.q(j) + 1);
        }
    }
    sort(dp + l, dp + r + 1, [](const DP &a, const DP &b)
        { return a.a == b.a ? a.t < b.t : a.a > b.a; });
    tot = 0;
    for (int i = l; i <= r; ++i) {
        mp[++tot] = (long long)v * dp[i].t + dp[i].a;
    }
    sort(mp + 1, mp + tot + 1);
    tot = unique(mp + 1, mp + tot + 1) - mp - 1;
    bit.init(tot);
    for (int i = l; i <= r; ++i) {
        int j = lower_bound(mp + 1, mp + tot + 1,
            (long long)v * dp[i].t + dp[i].a) - mp;
        if (dp[i].id <= m) {
            bit.upd(j, dp[i].c);
        }
        else {
            dp[i].c = max(dp[i].c, bit.q(j) + 1);
        }
    }
    sort(dp + l, dp + r + 1, [](const DP &a, const DP &b)
        { return a.id < b.id; });

    // cout << "debug: " << l << ' ' << r << endl;
    // for (int i = l; i <= r; ++i) {
    //     cout << "  " << i << ' ' << dp[i].t << ' ' << dp[i].a << ' ' << dp[i].c << endl;
    // }

    cdq(m + 1, r);
}

int main() {
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; ++i) scanf("%d", &dp[i].t);
    for (int i = 1; i <= n; ++i) scanf("%d", &dp[i].a);
    for (int i = 1; i <= n; ++i) { dp[i].id = i; dp[i].c = -INT_MAX; }
    cdq(0, n);
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i].c);
    printf("%d\n", ans);
    return 0;
}

/*
5 1
1 3 6 9 11 
2 20 -17 -15 -13
*/