#include <iostream>
#include <iomanip>

using namespace std;

const int NMAX = 1000 + 5;
long double dp[NMAX][NMAX][3];

int main()
{
    int w, b;
    cin >> w >> b;

    for (int i = 1; i <= w; ++ i) {
        dp[i][0][0] = 1;
        dp[i][0][1] = 1;
        dp[i][0][2] = dp[i - 1][0][0];
    }

    for (int i = 1; i <= w; ++ i)
        for (int j = 1; j <= b; ++ j) {
            dp[i][j][0] = 1.0 * i / (i + j) + 1.0 * j / (i + j) * (1.0 - dp[i][j - 1][1]);
            dp[i][j][1] = 1.0 * i / (i + j) + 1.0 * j / (i + j) * (1.0 - dp[i][j - 1][2]);
            dp[i][j][2] = 1.0 * i / (i + j) * dp[i - 1][j][0] + 1.0 * j / (i + j) * dp[i][j - 1][0];
        }

    cout << fixed << setprecision(9) << dp[w][b][0] << '\n';
    return 0;
}