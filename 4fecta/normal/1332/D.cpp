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

const int MN = 505;

int n, m, k, a[MN][MN], dp[MN][MN];

int main() {
    boost();

//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
//    dp[1][1] = a[1][1];
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            dp[i][j] = max(dp[i][j], max(dp[i - 1][j] & a[i][j], dp[i][j - 1] & a[i][j]));
//            printf("%d ", dp[i][j]);
//        }
//        printf("\n");
//    }
//    printf("%d\n", dp[n][m]);
    cin >> k;
    if (!k) return 0 * printf("1 1\n1");
    printf("3 3\n");
    int sh = 0;
    for (int s = 25; s >= 0; s--) {
        if (k & (1 << s)) {
            sh = s + 1; break;
        }
    }
    sh = 1 << sh;
    printf("%d %d %d\n", k | sh, k, k);
    printf("%d %d %d\n", sh, sh, k | sh);
    printf("%d %d %d\n", sh, sh, k);

    return 0;
}