#include <iostream>

using namespace std;

const int MAXN = 5005, INF = 1000 * 1000 * 1000 + 5;
int h[MAXN], dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> h[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = INF;
    for(int i = 1; i <= n; i++)
        dp[0][i] = i - 1;
    for(int i = 1; i < n; i++)
        for(int j = i + 1, sumj = h[i], k = i, sumk = 0, mindp = INF;
            j <= n; sumj += h[j], j++) {
            while(k > 0 && sumk + h[k - 1] <= sumj) {
                k--;
                sumk += h[k];
                mindp = min(mindp, dp[k][i]);
            }
            dp[i][j] = mindp + (j - i - 1);
        }
    int ans = INF;
    for(int i = 0; i < n; i++)
        ans = min(ans, dp[i][n]);
    cout << ans << '\n';
    return 0;
}