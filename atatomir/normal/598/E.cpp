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


#define maxN 31
#define maxK 51
#define inf 1000000000

int i, j, c, n, x, y, z;
int dp[maxN][maxN][maxK];

void pre() {
    int c1, t;
    int n = 30;
    int m = 30;
    int k = 50;
    int limit;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j < i) {
                memcpy(dp[i][j], dp[j][i], sizeof(dp[i][j]));
                continue;
            }

            limit = i * j;
            for (c = limit + 1; c <= k; c++) dp[i][j][c] = inf;
            limit = min(limit, k + 1);

            for (c = 1; c < limit; c++) {

                dp[i][j][c] = inf;
                for (c1 = 0; c1 <= c; c1++) {
                    int aux = inf;

                    for (t = 1; t < i; t++)
                        aux = min(aux, dp[t][j][c1] + dp[i - t][j][c - c1] + j * j);

                    for (t = 1; t < j; t++)
                        aux = min(aux, dp[i][t][c1] + dp[i][j - t][c - c1] + i * i);

                    dp[i][j][c] = min(dp[i][j][c], aux);
                }
            }
        }
    }

}



int main()
{
    //freopen("test.in","r",stdin);

    pre();

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        printf("%d\n", dp[x][y][z]);
    }


    return 0;
}