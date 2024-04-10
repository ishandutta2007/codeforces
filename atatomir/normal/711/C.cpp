#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 111

int n, m, k, i, j, act, nxt;
int col[maxN];
ll pay[maxN][maxN];
ll dp[maxN][maxN][maxN];

void upd(ll& dest, ll sour) {
    if (dest == 0)
        dest = sour;
    else
        dest = min(dest, sour);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= n; i++) scanf("%d", &col[i]);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%lld", &pay[i][j]);

    if (col[1] == 0) {
        for (i = 1; i <= m; i++)
            dp[1][1][i] = 1 + pay[1][i];
    } else {
        dp[1][1][col[1]] = 1;
    }

    for (i = 1; i < n; i++) {
        for (j = 1; j <= i; j++) {
            for (act = 1; act <= m; act++) {
                if (dp[i][j][act] == 0) continue;

                if (col[i + 1] == 0) {
                    for (nxt = 1; nxt <= m; nxt++)
                        upd(dp[i + 1][j + (act != nxt ? 1 : 0)][nxt], dp[i][j][act] + pay[i + 1][nxt]);
                } else {
                    nxt = col[i + 1];
                    upd(dp[i + 1][j + (act != nxt ? 1 : 0)][nxt], dp[i][j][act]);
                }
            }
        }
    }

    ll ans = 1LL << 60;
    for (i = 1; i <= m; i++)
        if (dp[n][k][i] != 0)
            ans = min(ans, dp[n][k][i]);

    if (ans == 1LL << 60) ans = 0;
    printf("%lld", ans - 1);


    return 0;
}