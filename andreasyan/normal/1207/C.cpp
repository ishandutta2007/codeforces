#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long INF = 100000000000000017;

int n, x, y;
char a[N];

long long dp[N][2];
void solv()
{
    scanf("%d%d%d", &n, &x, &y);
    scanf(" %s", a);
    for (int i = 0; i <= n; ++i)
        dp[i][0] = dp[i][1] = INF;
    dp[0][0] = y;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '1' || a[i + 1] == '1')
        {
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + x * 2 + y * 2);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + x + 2 * y);
        }
        else
        {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + x + y);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + x * 2 + y);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + x * 2 + y * 2);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + x + 2 * y);
        }
    }
    cout << dp[n][0] << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}