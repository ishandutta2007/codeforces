#include <iostream>

using namespace std;

int dp[1005][1005];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    if (n >= m) {
        cout << "YES\n";
        return 0;
    }

    int val, j;
    cin >> val;

    dp[1][val % m] = 1;

    for (int i = 2; i <= n; ++ i) {
        cin >> val;
        dp[i][val % m] = 1;

        for (j = 0; j < m; ++ j)
            if (dp[i - 1][j]) {
                dp[i][(j + val) % m] = 1;
                dp[i][j] = 1;
            }
    }

    if (dp[n][0])
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}