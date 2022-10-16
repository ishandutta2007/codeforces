#include <iostream>
#include <algorithm>

#define inf 1000005
using namespace std;

int x[100005];
int h[100005];

int dp[3][100005];

inline void upd (int &x, int y) {
    if (y > x)
        x = y;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> x[i] >> h[i];

    dp[0][1] = 1;
    dp[1][1] = 0;
    dp[2][1] = -inf;

    x[n + 1] = x[n] + h[n] + 1;

    if (x[1] + h[1] < x[2])
        upd(dp[2][1], 1);

    for (int i = 2; i <= n; i++) {
        dp[0][i] = -inf;
        if (x[i] - h[i] > x[i - 1]) {
            upd(dp[0][i], 1 + dp[0][i - 1]);
            upd(dp[0][i], 1 + dp[1][i - 1]);
        }

        if (x[i] - h[i] > x[i - 1] + h[i - 1])
            upd(dp[0][i], 1 + dp[2][i - 1]);

        dp[1][i] = 0;

        upd(dp[1][i], dp[0][i - 1]);
        upd(dp[1][i], dp[1][i - 1]);

        if (x[i] > x[i - 1] + h[i - 1])
            upd(dp[1][i], dp[2][i - 1]);

        dp[2][i] = -inf;
        if (x[i] + h[i] < x[i + 1]) {
            upd(dp[2][i], 1 + dp[0][i - 1]);
            upd(dp[2][i], 1 + dp[1][i - 1]);

            if (x[i] > x[i - 1] + h[i - 1])
                upd(dp[2][i], 1 + dp[2][i - 1]);
        }
    }

    cout << dp[2][n] << '\n';
    return 0;
}