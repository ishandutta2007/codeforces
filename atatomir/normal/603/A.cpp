#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 100011

int n, i, k;
char s[maxN];
int dp[maxN][3][2];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s", &n, s + 1);

    int id = s[1] - '0';
    dp[1][0][id] = dp[1][1][id] = dp[1][2][id] = 1;
    dp[1][0][id ^ 1] = dp[1][1][id ^ 1] = dp[1][2][id ^ 1] = 0;


    for (i = 2; i <= n; i++) {
        for (k = 0; k < 3; k++) {
            dp[i][k][0] = dp[i - 1][k][0];
            dp[i][k][1] = dp[i - 1][k][1];

            if (s[i] == '0')
                dp[i][k][0] = max(dp[i][k][0], dp[i - 1][k][1] + 1);
            else
                dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k][0] + 1);

            if (k == 0) continue;
            if (s[i] == '0')
                dp[i][k][0] = max(dp[i][k][0], dp[i - 1][k - 1][0] + 1);
            else
                dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - 1][1] + 1);
        }
    }

    int ans = max(max(dp[n][0][0], dp[n][0][1]), max(dp[n][1][0], dp[n][1][1]));
    ans = max(ans, max(dp[n][2][0], dp[n][2][1]));
    printf("%d", ans);

    return 0;
}