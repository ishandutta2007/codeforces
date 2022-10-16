#include <iostream>

using namespace std;

const int MAXN = 1005, INF = 1000 * 1000 * 1000 + 5;
int w[MAXN], h[MAXN], dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> w[i] >> h[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < MAXN; j++)
            dp[i][j] = INF;
    dp[0][0] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < MAXN; j++) {
            if(dp[i][j] >= INF)
                continue;
            dp[i + 1][max(j, h[i])] =
                min(dp[i + 1][max(j, h[i])], dp[i][j] + w[i]);
            dp[i + 1][max(j, w[i])] =
                min(dp[i + 1][max(j, w[i])], dp[i][j] + h[i]);
        }
    int ans = INF;
    for(int i = 0; i < MAXN; i++)
        if(dp[n][i] < INF)
            ans = min(ans, dp[n][i] * i);
    cout << ans << '\n';
    return 0;
}