#include <iostream>
#include <cstdio>

using namespace std;
int a[200][200];
int b[200];
int c[200][200];
int sum[200];
int dp[200][10010];

int main()
{
   int n, i, j, jj, d, k, m;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++){
        scanf("%d", &b[i]);
        for (j = 0; j < b[i]; j++){
            scanf("%d", &a[i][j]);
            sum[i] += a[i][j];
        }
    }
    for (i = 0; i < n; i++)
        for (j = 0; j <= b[i]; j++){
            d = 0;
            for (jj = 0; jj < b[i]; jj++){
                //if (jj < b[i] - j){
                    d += a[i][jj];
                //}
                if (jj - b[i] + j >= 0)
                    d -= a[i][jj - b[i] + j];
                if (jj >= b[i] - j - 1)
                    c[i][j] = max(c[i][j], sum[i] - d);

              /*  d += a[i][jj];
                if (jj < b[i] - j)
                    continue;
                d -= a[i][jj - b[i] + j];
                c[i][j] = max(c[i][j], sum[i] - d);
         */  }
        }

    for (i = 0; i < n; i++)
        for (j = 0; j <= m; j++)
            for (jj = 0; jj <= min(b[i], j); jj++){
                k = 0;
                if (i)
                    k = dp[i - 1][j - jj];
                k += c[i][jj];
                if (j - jj >= 0)
                    dp[i][j] = max(dp[i][j], k);
            }

    cout << dp[n - 1][m];
    return 0;
}