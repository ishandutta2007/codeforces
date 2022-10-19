#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1000006, M = 1000000007;

int n;
char a[N];

int dp[N][5];

int main()
{
    scanf(" %s", a);
    n = strlen(a);
    if (a[0] == '*')
    {
        dp[0][0] = 1;
    }
    else if (a[0] == '0')
    {
        dp[0][1] = 1;
    }
    else if (a[0] == '1')
    {
        dp[0][2] = 1;
    }
    else if (a[0] == '2')
    {
        printf("0\n");
        return 0;
    }
    else
    {
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 1;
    }
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == '*')
        {
            dp[i][0] += dp[i - 1][0];
            dp[i][0] %= M;
            dp[i][0] += dp[i - 1][2];
            dp[i][0] %= M;
            dp[i][0] += dp[i - 1][4];
            dp[i][0] %= M;
        }
        else if (a[i] == '0')
        {
            dp[i][1] += dp[i - 1][1];
            dp[i][1] %= M;
            dp[i][1] += dp[i - 1][3];
            dp[i][1] %= M;
        }
        else if (a[i] == '1')
        {
            dp[i][2] += dp[i - 1][1];
            dp[i][2] %= M;
            dp[i][2] += dp[i - 1][3];
            dp[i][2] %= M;
            dp[i][3] += dp[i - 1][0];
            dp[i][3] %= M;
        }
        else if (a[i] == '2')
        {
            dp[i][4] += dp[i - 1][0];
            dp[i][4] %= M;
        }
        else
        {
            dp[i][0] += dp[i - 1][0];
            dp[i][0] %= M;
            dp[i][0] += dp[i - 1][2];
            dp[i][0] %= M;
            dp[i][0] += dp[i - 1][4];
            dp[i][0] %= M;
            dp[i][1] += dp[i - 1][1];
            dp[i][1] %= M;
            dp[i][1] += dp[i - 1][3];
            dp[i][1] %= M;
            dp[i][2] += dp[i - 1][1];
            dp[i][2] %= M;
            dp[i][2] += dp[i - 1][3];
            dp[i][2] %= M;
            dp[i][3] += dp[i - 1][0];
            dp[i][3] %= M;
            dp[i][4] += dp[i - 1][0];
            dp[i][4] %= M;
        }
    }
    int ans = 0;
    ans += dp[n - 1][0];
    ans %= M;
    ans += dp[n - 1][1];
    ans %= M;
    ans += dp[n - 1][3];
    ans %= M;
    printf("%d\n", ans);
    return 0;
}