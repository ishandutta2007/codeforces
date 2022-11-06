#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 507
#define maxLog 64

const ll limit = 1000000000000000000LL;

int n, m, i, j, x, y, c;
ll dp[maxLog][2][maxN];
bitset<maxN> wh[2][maxN], old[2][maxN];
ll ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) wh[0][i].reset(), wh[1][i].reset();

    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &c);
        wh[c][x][y] = 1;
        dp[0][c][x] = 1;
    }

    for (ll step = 1; step <= 60; step++) {
        for (i = 1; i <= n; i++) old[0][i] = wh[0][i], old[1][i] = wh[1][i];

        for (i = 1; i <= n; i++) {
            wh[0][i].reset();
            wh[1][i].reset();

            for (j = 1; j <= n; j++) {
                if (old[0][i][j] == true)
                    wh[0][i] |= old[1][j];
                if (old[1][i][j] == true)
                    wh[1][i] |= old[0][j];
            }

            for (j = 1; j <= n; j++) {

                if (wh[0][i][j]) {
                    dp[step][0][i] = max(dp[step][0][i], (1LL << step) + dp[step - 1][1][j]);
                    dp[step][0][i] = min(dp[step][0][i], limit + 1);
                }

                if (wh[1][i][j]) {
                    dp[step][1][i] = max(dp[step][1][i], (1LL << step) + dp[step - 1][0][j]);
                    dp[step][1][i] = min(dp[step][1][i], limit + 1);
                }
            }
        }

        for (i = 1; i <= n; i++) {
            dp[step][0][i] = max(dp[step][0][i], dp[step - 1][0][i]);
            dp[step][1][i] = max(dp[step][1][i], dp[step - 1][1][i]);
        }

        ans = max(ans, dp[step][0][1]);
    }

    ans = max(ans, dp[0][0][1]);
    if (ans > limit)
        ans = -1;

    printf("%lld", ans);


    return 0;
}