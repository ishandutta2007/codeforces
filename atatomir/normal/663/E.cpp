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

#define maxN 20
#define maxM 100011

int n, m, i, j, k, l, st, nxt;
char s[maxM];
int nr[maxM];

int dp[maxN + 1][1 << maxN];
int ans[1 << maxN];
int sol;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%s\n", s + 1);
        for (j = 1; j <= m; j++)
            if (s[j] == '1')
                nr[j] |= 1 << i;
    }

    for (i = 1; i <= m; i++) {
        dp[0][nr[i]]++;
        ans[nr[i]] += n;
    }

    st = (1 << n);
    for (i = 1; i <= n; i++) {
        for (j = 0; j < st; j++) {
            dp[i][j] = 0;


            if (i <= 2) {
                for (k = 0; k < n; k++) {
                    nxt = j ^ (1 << k);
                    for (l = 1; i - l >= 0; l++)
                        dp[i][j] += (l & 1 ? +1 : -1) * dp[i - l][ l & 1? nxt : j ];
                }
            } else {
                dp[i][j] += (i - 2 - n) * dp[i - 2][j];
                for (k = 0; k < n; k++)
                    dp[i][j] += dp[i - 1][j ^ (1 << k)];
            }

            dp[i][j] /= i;

            ans[j] += dp[i][j] * max(i, n - i);
        }
    }

    for (i = 0; i < st; i++)
        sol = max(sol, ans[i]);

    printf("%d", n * m - sol);



    return 0;
}