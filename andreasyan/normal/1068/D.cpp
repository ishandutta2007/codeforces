#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 998244353, m = 200;

int n;
int a[N];

int dpn[m + 2][2], dp[m + 2][2];

int p[m + 2][2];

int sum(int l, int r, int z)
{
    if (r == m + 1)
        r = m;
    return (p[r][z] - p[l - 1][z] + M) % M;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    if (a[1] == -1)
    {
        for (int j = 1; j <= m; ++j)
            dpn[j][0] = dp[j][0] = 1;
    }
    else
    {
        for (int j = a[1]; j <= a[1]; ++j)
            dpn[j][0] = dp[j][0] = 1;
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            p[j][0] = (p[j - 1][0] + dpn[j][0]) % M;
            p[j][1] = (p[j - 1][1] + dpn[j][1]) % M;
            dp[j][0] = dp[j][1] = 0;
        }
        if (a[i] == -1)
        {
            for (int j = 1; j <= m; ++j)
            {
                dp[j][0] += sum(1, j - 1, 0);
                dp[j][0] %= M;
                dp[j][0] += sum(1, j - 1, 1);
                dp[j][0] %= M;
                dp[j][1] += dpn[j][0];
                dp[j][1] %= M;
                dp[j][1] += dpn[j][1];
                dp[j][1] %= M;
                //
                dp[j][1] += sum(j + 1, m, 1);
                dp[j][1] %= M;
            }
        }
        else
        {
            for (int j = a[i]; j <= a[i]; ++j)
            {
                dp[j][0] += sum(1, j - 1, 0);
                dp[j][0] %= M;
                dp[j][0] += sum(1, j - 1, 1);
                dp[j][0] %= M;
                dp[j][1] += dpn[j][0];
                dp[j][1] %= M;
                dp[j][1] += dpn[j][1];
                dp[j][1] %= M;
                //
                dp[j][1] += sum(j + 1, m, 1);
                dp[j][1] %= M;
            }
        }
        for (int j = 1; j <= m; ++j)
        {
            dpn[j][0] = dp[j][0];
            dpn[j][1] = dp[j][1];
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; ++j)
    {
        ans += dp[j][1];
        ans %= M;
    }
    cout << ans << endl;
    return 0;
}