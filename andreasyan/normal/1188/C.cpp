#include <bits/stdc++.h>
using namespace std;
const int N = 1003, M = 998244353;

int n, k;
int a[N];

int q[100005];
int ii[100005];

int dp[N][N][2];
int p[N][N][2];

int ans;
void cdp(int x)
{
    dp[0][0][0] = 1;
    p[0][0][0] = 1;
    for (int i = 1; i <= n; ++i)
        p[i][0][0] = 1;
    for (int kk = 1; kk <= k; ++kk)
    {
        int j = 0;
        for (int i = 1; i <= n; ++i)
        {
            while (j != n && a[j + 1] + x < a[i])
                ++j;
            dp[i][kk][0] = p[j][kk - 1][0];
            dp[i][kk][1] = p[j][kk - 1][1];
            if (a[i] - x >= 0)
                dp[i][kk][1] += (((dp[ii[a[i] - x]][kk - 1][0] + dp[ii[a[i] - x]][kk - 1][1]) * 1LL * q[a[i] - x]) % M);
            dp[i][kk][1] %= M;
        }
        p[0][kk][0] = dp[0][kk][0];
        p[0][kk][1] = dp[0][kk][1];
        for (int i = 1; i <= n; ++i)
        {
            p[i][kk][0] = (p[i - 1][kk][0] + dp[i][kk][0]) % M;
            p[i][kk][1] = (p[i - 1][kk][1] + dp[i][kk][1]) % M;
        }
    }
    ans = (ans + ((x * 1LL * p[n][k][1]) % M)) % M;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        q[a[i]]++;
        ii[a[i]] = i;
    }
    a[0] = -100005;
    for (int x = 1; x <= (a[n] / (k - 1)); ++x)
        cdp(x);
    cout << ans << endl;
    return 0;
}