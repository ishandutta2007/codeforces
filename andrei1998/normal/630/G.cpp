#include <iostream>

using namespace std;

long long int dp[505][10];

int main()
{
    int n;
    cin >> n;

    dp[1][0] = 1;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j < 9; ++ j) {
            dp[i + 1][j] += dp[i][j];
            dp[i][j + 1] += dp[i][j];
        }
    }

    cout << dp[n][3] * dp[n][5] << endl;
    return 0;
}