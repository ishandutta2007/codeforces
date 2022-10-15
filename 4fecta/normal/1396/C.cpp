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

const int MN = 1000005;

int n, a[MN], r1, r2, r3, d, base[MN], style[MN], dp[MN][2]; //1 dmg, 1 aoe dmg, instakill

int32_t main() {
    boost();

    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        base[i] = r1 * a[i] + r3;
        style[i] = min(r2 + r1, r1 * (a[i] + 2));
        dp[i][0] = min(dp[i - 1][0] + base[i], dp[i - 1][1] + min(base[i], style[i]) + d + d);
        dp[i][1] = dp[i - 1][0] + style[i];
    }
    int ans = min(dp[n][0], dp[n][1] + d + d), sum = base[n];
    for (int i = n - 1; i > 0; i--) sum += style[i] + d, ans = min(ans, dp[i - 1][0] + sum);
    printf("%lld\n", ans + d * (n - 1));

    return 0;
}