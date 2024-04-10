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

const int MN = 3005;

int t, n, a[MN], dp[MN][MN];

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 2; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = i - 1; j > 0; j--) {
                if (j + a[j] >= i) {
                    dp[i][j + a[j]] = min(dp[i][j + a[j]], dp[j][i - 1] + cnt++);
                }
            }
            for (int j = 2; j <= n; j++) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
        printf("%d\n", dp[n][n]);
    }

    return 0;
}