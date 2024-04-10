#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 105, MR = 60005;

int n, r, dp[MN][MR], ans;
pii a[MN];

bool cmp(pii x, pii y) {
    return x.f + x.s > y.f + y.s;
}

int main() {
    boost();

    cin >> n >> r;
    for (int i = 1; i <= n; i++) cin >> a[i].f >> a[i].s;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i].s < 0) {a[i].f = max(a[i].f, -a[i].s); continue;}
        if (a[i].f <= r) r += a[i].s, ans++;
        else break;
    }
    sort(a + 1, a + n + 1, cmp);
    memset(dp, -0x3f, sizeof(dp));
    dp[0][r] = ans;
    //printf("%d %d %d\n", 0, r, dp[0][r]);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MR; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j < -a[i].s || a[i].s >= 0 || j < a[i].f) continue;
            dp[i][j + a[i].s] = max(dp[i][j + a[i].s], dp[i - 1][j] + 1);
        }
        //for (int j = 0; j < MR; j++) if (dp[i][j] > 0) printf("%d %d %d\n", i, j, dp[i][j]);
    }
    for (int j = 0; j < MR; j++) ans = max(ans, dp[n][j]);
    printf("%d\n", ans);

    return 0;
}