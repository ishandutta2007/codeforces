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

#define maxN 1024
#define sigma 8

const int mask = (1 << sigma);

int n, i, ans, new_conf, dif;
int v[maxN], wh[maxN];
vector<int> pos[sigma];
bool used[maxN];

int dp[1 << sigma][maxN];

bool check(int cnt) {
    int i, j;

    for (i = 0; i < mask; i++)
        for (j = 0; j <= n; j++)
            dp[i][j] = -3 * n;

    for (i = 0; i <= n; i++) dp[0][i] = 0;
    for (i = 1; i < mask; i++) {
        for (j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];

            if (i & (1 << v[j])) {
                new_conf = i ^ (1 << v[j]);
                if (wh[j] >= cnt - 1)
                    dp[i][j] = max(dp[i][j], cnt + dp[new_conf][ pos[v[j]][ wh[j] - cnt + 1 ] - 1 ]);
                if (wh[j] >= cnt)
                    dp[i][j] = max(dp[i][j], cnt + 1 + dp[new_conf][ pos[v[j]][ wh[j] - cnt ] - 1 ]);
            }
        }
    }

    return dp[mask - 1][n] >= 8 * cnt;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        pos[--v[i]].pb(i);
        wh[i] = pos[v[i]].size() - 1;

        if (!used[v[i]]) {
            used[v[i]] = true;
            dif++;
        }
    }



    ans = 0;
    for (int step = 1 << 10; step > 0; step >>= 1)
        if (8 * (ans + step) <= n)
            if (check(ans + step))
                ans += step;


    if (ans == 0) {
        printf("%d", dif);
        return 0;
    }

    check(ans);
    printf("%d", dp[mask - 1][n]);


    return 0;
}