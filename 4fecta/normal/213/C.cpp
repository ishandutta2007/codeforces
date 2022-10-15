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

const int MN = 305;

int n, a[MN][MN], dp[2 * MN][MN][MN]; //diag num, row1, row2;

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
    memset(dp, -0x3f, sizeof(dp));
    dp[2][1][1] = a[1][1];
    for (int d = 3; d <= 2 * n; d++) {
        for (int r1 = 1; r1 <= n; r1++) {
            for (int r2 = r1; r2 <= n; r2++) {
                int c1 = d - r1, c2 = d - r2;
                if (c1 < 1 || c1 > n || c2 < 1 || c2 > n) continue;
                int sum = a[r1][c1];
                if (r1 != r2) sum += a[r2][c2];
                dp[d][r1][r2] = sum + max({dp[d - 1][r1][r2], dp[d - 1][r1 - 1][r2], dp[d - 1][r1][r2 - 1], dp[d - 1][r1 - 1][r2 - 1]});
            }
        }
    }
    printf("%d\n", dp[2 * n][n][n]);

    return 0;
}