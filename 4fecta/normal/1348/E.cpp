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

const int MN = 501;

int n, k, dp[2][MN][MN];
pii a[MN];

int32_t main() {
    boost();

    for (int i = 0; i < 2; i++) for (int j = 0; j < MN; j++) for (int k = 0; k < MN; k++) dp[i][j][k] = LLONG_MIN / 4;
    dp[0][0][0] = 0;
    cin >> n >> k;
    int ans = 0;
    int psum = 0;
    int R = 0, B = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].f >> a[i].s;
        R += a[i].f, B += a[i].s;
        int cnt = (a[i].f + a[i].s) / k;
        int rem = (a[i].f + a[i].s) % k;
        ans += cnt;
        for (int r = 0; r <= rem; r++) {
            int b = rem - r;
            if (r > a[i].f || b > a[i].s) continue;
            for (int pr = 0; pr <= psum; pr++) {
                int pb = psum - pr;
                dp[i & 1][(pr + r) % k][(pb + b) % k] = dp[1 - (i & 1)][pr][pb] + cnt + (pr + r) / k + (pb + b) / k;
            }
        }
        psum += a[i].f + a[i].s;
        psum %= k;
    }
    int tmp = R/k + B/k;
    int m1 = R%k, m2 = B%k;
    for (int i = 1; i <= n; i++) {
        if (a[i].f + a[i].s < k) continue;
        if (min(a[i].f, m1) + min(a[i].s, m2) < k) continue;
        tmp++;
        break;
    }
    ans = max(ans, tmp);
    for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) ans = max(ans, dp[n & 1][i][j]);
    printf("%lld\n", ans);

    return 0;
}