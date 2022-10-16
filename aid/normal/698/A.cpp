#include <iostream>

using namespace std;

const int MAXN = 105;
int a[MAXN], dp[MAXN][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 3; j++)
            dp[i][j] = MAXN;
    dp[0][0] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++) {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + 1);
            if((a[i] & 1) && j != 1)
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][j]);
            if((a[i] & 2) && j != 2)
                dp[i + 1][2] = min(dp[i + 1][2], dp[i][j]);
        }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << '\n';
    return 0;
}