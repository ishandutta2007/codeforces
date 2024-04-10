#include <iostream>

using namespace std;

const int MAXN = 4005, MAXX = 1000 * 1000 + 5;
int a[MAXN], dp[MAXN][MAXN], prv[MAXX];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        dp[0][i] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++)
            dp[i + 1][j + 1] = dp[prv[a[j]]][i + 1] + 1;
        prv[a[i]] = i + 1;
    }
    int ans = 0;
    for(int i = 0; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            ans = max(ans, dp[i][j]);
    cout << ans << '\n';
    return 0;
}