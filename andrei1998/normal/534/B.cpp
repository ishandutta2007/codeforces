#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[105][2005];

int main()
{
    memset(dp, -1, sizeof(dp));

    int v1, v2, t, d;

    cin >> v1 >> v2 >> t >> d;

    dp[1][v1] = v1;
    for (int i = 1; i < t; i++)
        for (int j = 0; j < 2005; j++)
            if (dp[i][j] != -1)
                for (int k = -d; k <= d; k++)
                    if (j + k >= 0)
                        dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + j + k);

    if (dp[t][v2] == -1)
        cout << "0\n";
    else
        cout << dp[t][v2] << '\n';
    return 0;
}