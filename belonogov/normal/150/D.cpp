#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 152;
const int inf = 1e9;


int dp[maxn][maxn][maxn];
int res[maxn][maxn];
char s[maxn];
int a[maxn];


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int n, ans;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i + 1]);
    a[0] = -1;
    scanf("\n%s", s);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        dp[0][i][0] = 0;
    for (int len = 1; len <= n; len++)
        for (int i = 0; i + len <= n; i++) {
            for (int k = len; k >= 0; k--) {
                if (k == 0)
                    for (int t = 0; t <= len; t++)
                        if (a[t] != -1 && dp[len][i][t] != -1)
                            dp[len][i][0] = max(dp[len][i][0], dp[len][i][t] + a[t]);
                if (k >= 2 && s[i] == s[i + len - 1])
                    dp[len][i][k] = max(dp[len][i][k], dp[len - 2][i + 1][k - 2]);
                if (k == 1) { 
                    dp[len][i][k] = max(dp[len][i][k], dp[len - 1][i + 1][k - 1]);
                    dp[len][i][k] = max(dp[len][i][k], dp[len - 1][i][k - 1]);
                }
                for (int t = 1; t < len; t++) {
                    if (dp[t][i][k] != -1 && dp[len - t][i + t][0] != -1)
                        dp[len][i][k] = max(dp[len][i][k], dp[t][i][k] + dp[len - t][i + t][0]);
                    if (dp[t][i][0] != -1 && dp[len - t][i + t][k] != -1)
                        dp[len][i][k] = max(dp[len][i][k], dp[t][i][0] + dp[len - t][i + t][k]);
                }
            }
        }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                res[i][j] = max(res[i][j], dp[i][j][k]);
    for (int len = 1; len <= n; len++)
        for (int i = 0; i + len <= n; i++)
            for (int j = 1; j < len; j++)
                res[len][i] = max(res[len][i], res[j][i] + res[len - j][i + j]);
    ans = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            ans = max(ans, res[i][j]);
    printf("%d\n", ans);
    return 0;
}