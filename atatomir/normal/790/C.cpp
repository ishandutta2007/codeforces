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

#define maxN 77
#define inf 1000001


int n, i, a, v, k, tp;
char s[maxN];

int total_a, total_v, total_k;
int pos_a[maxN], pos_v[maxN], pos_k[maxN];
int sum_a[maxN], sum_v[maxN], sum_k[maxN];

int dp[maxN][maxN][maxN][2];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s", &n, s + 1);
    for (i = 1; i <= n; i++) {
        sum_a[i] = sum_a[i - 1];
        sum_v[i] = sum_v[i - 1];
        sum_k[i] = sum_k[i - 1];

        if (s[i] != 'V' && s[i] != 'K') {
            pos_a[++total_a] = i;
            sum_a[i]++;
        }

        if (s[i] == 'V') {
            pos_v[++total_v] = i;
            sum_v[i]++;
        }

        if (s[i] == 'K') {
            pos_k[++total_k] = i;
            sum_k[i]++;
        }
    }

    for (a = 0; a <= total_a; a++)
        for (v = 0; v <= total_v; v++)
            for (k = 0; k <= total_k; k++)
                dp[a][v][k][0] = dp[a][v][k][1] = inf;


    int pos, wh;

    dp[0][0][0][0] = 0;
    for (a = 0; a <= total_a; a++) {
        for (v = 0; v <= total_v; v++) {
            for (k = 0; k <= total_k; k++) {
                for (tp = 0; tp < 2; tp++) {
                    int &act = dp[a][v][k][tp];
                    if (act >= inf) continue;

                    //! put a
                    if (a + 1 <= total_a) {
                        pos = pos_a[a + 1];
                        wh = pos + max(0, a - sum_a[pos - 1]) +
                                   max(0, v - sum_v[pos - 1]) +
                                   max(0, k - sum_k[pos - 1]);
                        dp[a + 1][v][k][0] = min(dp[a + 1][v][k][0], act + wh - (a + v + k + 1));
                    }

                    //! put v
                    if (v + 1 <= total_v) {
                        pos = pos_v[v + 1];
                        wh = pos + max(0, a - sum_a[pos - 1]) +
                                   max(0, v - sum_v[pos - 1]) +
                                   max(0, k - sum_k[pos - 1]);
                        dp[a][v + 1][k][1] = min(dp[a][v + 1][k][1], act + wh - (a + v + k + 1));
                    }


                    //! put k
                    if (k + 1 <= total_k && tp == 0) {
                        pos = pos_k[k + 1];
                        wh = pos + max(0, a - sum_a[pos - 1]) +
                                   max(0, v - sum_v[pos - 1]) +
                                   max(0, k - sum_k[pos - 1]);
                        dp[a][v][k + 1][0] = min(dp[a][v][k + 1][0], act + wh - (a + v + k + 1));
                    }
                }
            }
        }
    }

    int ans = min(dp[total_a][total_v][total_k][0],
                  dp[total_a][total_v][total_k][1]);


    printf("%d", ans);


    return 0;
}