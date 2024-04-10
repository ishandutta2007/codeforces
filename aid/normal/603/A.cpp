#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
char c[MAXN];
int dp[MAXN][3][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        c[i] -= '0';
    }
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 2; k++)
                dp[i][j][k] = -1;
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 2; k++)
                if(dp[i][j][k] >= 0) {
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                    if((c[i] ^ (j & 1)) != k)
                        dp[i + 1][j][c[i] ^ (j & 1)] =
                            max(dp[i + 1][j][c[i] ^ (j & 1)], dp[i][j][k] + 1);
                    if(j < 2)
                        dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
                }
    cout << max(dp[n][2][0], dp[n][2][1]) << '\n';
    return 0;
}