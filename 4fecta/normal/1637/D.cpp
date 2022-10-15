#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 105, MV = 10005;

int n, a[MN], b[MN], dp[MN][2 * MV];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 0, sq = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i], sq += a[i] * a[i];
        for (int i = 1; i <= n; i++) cin >> b[i], sum += b[i], sq += b[i] * b[i];
        memset(dp, 0, sizeof(dp));
        dp[0][MV] = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] > b[i]) swap(a[i], b[i]);
            int v = b[i] - a[i];
            for (int j = 0; j < 2 * MV; j++) {
                if (j + v >= 2 * MV) break;
                dp[i][j + v] |= dp[i - 1][j];
            }
            for (int j = v; j < 2 * MV; j++) {
                dp[i][j - v] |= dp[i - 1][j];
            }
        }
        int i = n, j = MV;
        while (!dp[i][j]) j++;
        int d = j - MV;
        int s1 = (sum - d) / 2;
        int s2 = s1 + d;
        s1 = s1 * s1;
        s2 = s2 * s2;
        printf("%lld\n", s1 + s2 + sq * (n - 2));
    }

    return 0;
}