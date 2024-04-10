#include <iostream>

using namespace std;

const int inf  = 1e9 + 5;
int dp[2][155][11935]; //ULTIMA DIMENSIUNE E 155 * 155 de fapt si de drept

inline void upd (int &dp, int val) {
    if (val < dp)
        dp = val;
}

int v[155];

int main()
{
    int n, k, s;
    cin >> n >> k >> s;

    if (s > n * (n - 1) / 2)
        s = n * (n - 1) / 2;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    int j, l;
    dp[0][0][s] = 0;

    bool h = 0;
    for (int i = 0; i < n; ++ i, h ^= 1) {
        for (j = 0; j <= k && j <= i + 1; ++ j)
            for (l = 0; l <= s; ++ l)
                dp[h ^ 1][j][l] = inf;

        for (j = 0; j <= k && j <= i; ++ j)
            for (l = 0; l <= s; ++ l) {
                upd(dp[h ^ 1][j][l], dp[h][j][l]);
                upd(dp[h ^ 1][j + 1][l - (i - j)], dp[h][j][l] + v[i + 1]);
            }
    }

    int ans = inf;
    for (l = 0; l <= s; ++ l)
        if (dp[h][k][l] < ans)
            ans = dp[h][k][l];

    cout << ans << '\n';
    return 0;
}