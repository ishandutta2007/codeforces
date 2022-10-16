#include <iostream>

using namespace std;

const int MAXN = 3005;
const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
long long p[MAXN], dp[MAXN][MAXN], a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    long long mn = p[0], ans = 0;
    for(int i = 0; i <= k; i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = -INF;
    for(int i = 1; i < n; i++) {
        dp[1][i] = p[i] - mn;
        mn = min(mn, p[i]);
        ans = max(ans, dp[1][i]);
    }
    mn = dp[1][0];
    a[0] = -INF;
    for(int i = 1; i < n; i++) {
        a[i] = mn - p[i];
        mn = max(mn, dp[1][i]);
    }
    for(int i = 2; i <= k; i++) {
        mn = a[0];
        for(int j = 1; j < n; j++) {
            dp[i][j] = mn + p[j];
            mn = max(mn, a[j]);
            ans = max(ans, dp[i][j]);
        }
        mn = dp[i][0];
        for(int j = 1; j < n; j++) {
            a[j] = mn - p[j];
            mn = max(mn, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}