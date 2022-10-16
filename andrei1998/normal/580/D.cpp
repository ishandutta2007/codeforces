#include <iostream>

#define lint long long int
using namespace std;

int sat[20];
int cost[20][20];

lint dp[(1 << 18) + 5][20];

inline void upd (lint &dp, lint val) {
    if (val > dp)
        dp = val;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++ i)
        cin >> sat[i];

    int x, y;
    while (k --) {
        cin >> x >> y;
        cin >> cost[x - 1][y - 1];
    }

    for (int i = 0; i < n; ++ i)
        dp[1 << i][i] = sat[i];

    int j;
    lint ans = 0;
    for (int i = 1; i < (1 << n); ++ i)
        for (j = 0; j < n; ++ j)
            if (i & (1 << j)) {
               // cout << "stare " << i << ' ' << j << ' ' << dp[i][j] << endl;

                if (__builtin_popcount(i) == m)
                    if (dp[i][j] > ans)
                        ans = dp[i][j];

                    for (k = 0; k < n; ++ k)
                        if (!(i & (1 << k)))
                            upd(dp[i | (1 << k)][k], dp[i][j] + sat[k] + cost[j][k]);
            }

    cout << ans << '\n';
    return 0;
}