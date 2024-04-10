#include <iostream>

using namespace std;

const int MOD = 1000000000 + 7;

int dp[1005][2];

int main()
{
    int n, k, d;
    cin >> n >> k >> d;

    dp[0][0] = 1;
    for (int i = 0; i < n; ++ i)
        for (int edge = 1; edge <= k; ++ edge) {
            dp[i + edge][edge >= d] = (dp[i + edge][edge >= d] + dp[i][0]) % MOD;
            dp[i + edge][1] = (dp[i + edge][1] + dp[i][1]) % MOD;
        }

    cout << dp[n][1] << '\n';
    return 0;
}