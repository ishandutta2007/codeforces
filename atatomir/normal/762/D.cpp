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

#define maxN 100011

const int ln = 3;

int n, i, j;
ll m[ln + 2][maxN];

ll dp[4][maxN];

void upd(ll &a, ll b) {
    a = max(a, b);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= ln; i++)
        for (j = 1; j <= n; j++)
            scanf("%lld", &m[i][j]);

    for (i = 0; i <= n; i++)
        dp[1][i] = dp[2][i] = dp[3][i] = -1LL << 60;

    dp[1][0] = 0;

    for (i = 0; i < n; i++) {
        upd(dp[1][i + 1], dp[1][i] + m[1][i + 1]);
        upd(dp[2][i + 1], dp[1][i] + m[1][i + 1] + m[2][i + 1]);
        upd(dp[3][i + 1], dp[1][i] + m[1][i + 1] + m[2][i + 1]+ m[3][i + 1]);

        upd(dp[1][i + 1], dp[2][i] + m[1][i + 1] + m[2][i + 1]);
        upd(dp[2][i + 1], dp[2][i] + m[2][i + 1]);
        upd(dp[3][i + 1], dp[2][i] + m[2][i + 1] + m[3][i + 1]);

        upd(dp[1][i + 1], dp[3][i] + m[1][i + 1] + m[2][i + 1] + m[3][i + 1]);
        upd(dp[2][i + 1], dp[3][i] + m[2][i + 1] + m[3][i + 1]);
        upd(dp[3][i + 1], dp[3][i] + m[3][i + 1]);

        if (i + 1 == n) continue;

        upd(dp[3][i + 2], dp[1][i] + m[1][i + 1] + m[1][i + 2] +
                                     m[2][i + 1] + m[2][i + 2] +
                                     m[3][i + 1] + m[3][i + 2]);

        upd(dp[1][i + 2], dp[3][i] + m[1][i + 1] + m[1][i + 2] +
                                     m[2][i + 1] + m[2][i + 2] +
                                     m[3][i + 1] + m[3][i + 2]);
    }

    printf("%lld", dp[3][n]);




    return 0;
}