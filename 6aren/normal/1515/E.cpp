#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> power_2(n + 1);
    vector<vector<int>> C(n + 1, vector<int>(n + 1));
    power_2[0] = 1;
    for (int i = 1; i <= n; i++) power_2[i] = power_2[i - 1] * 2 % m;
    for (int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % m;
        }
    }


    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == j) dp[i][j] = power_2[i - 1];
            for (int k = 2; k < i; k++) {
                if (j > i - k)
                    dp[i][j] = (dp[i][j] + dp[k - 1][j - (i - k)] *
                                               power_2[i - k - 1] % m *
                                               C[j][i - k]) %
                               m;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + dp[n][i]) % m;
    }
    cout << res << '\n';

    return 0;
}