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

#define maxN 2018

int n, i, j;
int a[maxN];
int sum[4][maxN];

int dp_up[maxN][maxN][3];
int dp_down[maxN][maxN][3];
int ans = 0;

void upd(int& a, int b) {
    a = max(a, b);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[1][i] = sum[1][i - 1];
        sum[2][i] = sum[2][i - 1];

        sum[a[i]][i]++;
    }

    for (i = 1; i <= n; i++) {
        dp_up[i][i][a[i]] = dp_down[i][i][a[i]] = 1;

        upd(dp_up[i][i][2], dp_up[i][i][1]);
        upd(dp_down[i][i][1], dp_down[i][i][2]);

        for (j = i + 1; j <= n; j++) {
            memcpy(dp_up[i][j], dp_up[i][j - 1], sizeof(dp_up[i][j]));
            memcpy(dp_down[i][j], dp_down[i][j - 1], sizeof(dp_down[i][j]));

            upd(dp_up[i][j][ a[j] ], dp_up[i][j - 1][ a[j] ] + 1);
            upd(dp_down[i][j][ a[j] ], dp_down[i][j - 1][ a[j] ] + 1);

            upd(dp_up[i][j][2], dp_up[i][j][1]);
            upd(dp_down[i][j][1], dp_down[i][j][2]);
        }
    }

    ans = max(sum[1][n], sum[2][n]);
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            upd(ans, dp_up[1][i - 1][2] + sum[2][n] - sum[2][i - 1]);
            upd(ans, sum[1][i - 1] + dp_down[i][j][1] + sum[2][n] - sum[2][j]);
            upd(ans, sum[1][j] + dp_up[j + 1][n][2]);
        }
    }

    cout << ans;


    return 0;
}