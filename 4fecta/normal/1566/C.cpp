#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

int n, dp[MN], psa[2][MN], a[2][MN];
char c;

int mex(int x, int y) {
    if (!x && !y) return 1;
    if (x && y) return 0;
    return 2;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> c;
                a[i][j] = c - '0';
                psa[i][j] = psa[i][j - 1] + a[i][j];
            }
        }
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + mex(a[0][i], a[1][i]);
            if (a[0][i] ^ a[1][i]) continue;
            int lo = 0, hi = i - 1, mid;
            while (lo < hi) {
                mid = (lo + hi + 1) >> 1;
                int sum = psa[0][i] - psa[0][mid - 1] + psa[1][i] - psa[1][mid - 1];
                int len = i - mid + 1;
                if (sum == 2 * len || sum == 0) hi = mid - 1;
                else lo = mid;
            }
            if (lo) dp[i] = max(dp[i], dp[lo - 1] + 2);
        }
        printf("%lld\n", dp[n]);
    }

    return 0;
}