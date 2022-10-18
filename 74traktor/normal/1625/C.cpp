#include<bits/stdc++.h>

using namespace std;

int const maxn = 505;
int a[maxn];
int d[maxn];
int dp[2][maxn][maxn];
int inf = 1e9 + 7;

main() {
#ifdef karpovich
    freopen("input.txt", "r", stdin);
#endif // karpovich
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l, k;
    cin >> n >> l >> k;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j) dp[0][i][j] = inf, dp[1][i][j] = inf;
    dp[1][1][0] = 0;
    for (int i = 2; i <= n; ++i) {
        int now = i % 2;
        for (int v = 0; v <= i; ++v) {
            for (int cnt = 0; cnt <= k; ++cnt) dp[now][v][cnt] = inf;
        }
        for (int v = 1; v < i; ++v) {
            for (int cnt = 0; cnt <= k; ++cnt) {
                dp[now][i][cnt] = min(dp[now][i][cnt], dp[(now^1)][v][cnt] + (d[i] - d[i - 1]) * a[v]);
                if (cnt) {
                    dp[now][v][cnt] = min(dp[now][v][cnt], dp[(now^1)][v][cnt - 1] + (d[i] - d[i - 1]) * a[v]);
                }
            }
        }
    }
    int ans = inf;
    for (int i = 1; i <= n; ++i) {
        for (int cnt = 0; cnt <= k; ++cnt) {
            ans = min(ans, (l - d[n]) * a[i] + dp[n % 2][i][cnt]);
        }
    }
    cout << ans << '\n';
    return 0;
}