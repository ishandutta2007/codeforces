#include <bits/stdc++.h>
using namespace std;
const int N = 2003;
const int M = 998244353;

int n;
char aa[N];
char a[N];

int p[N];
int q(int l, int r)
{
    if (l > r)
        return 0;
    return p[r] - p[l - 1];
}

int ast[N];

int dp[N][N];

int main()
{
    scanf(" %s", aa);
    n = strlen(aa);
    for (int i = 1; i <= n; ++i)
    {
        a[i] = aa[i - 1];
        p[i] = p[i - 1];
        if (a[i] == '?')
            ++p[i];
    }
    ast[0] = 1;
    for (int i = 1; i <= n; ++i)
        ast[i] = (ast[i - 1] * 2) % M;
    for (int d = 2; d <= n; ++d)
    {
        for (int l = 1; l <= (n - d + 1); ++l)
        {
            int r = l + d - 1;
            if (a[l] == '?' && a[r] == '?')
            {
                dp[l][r] = (dp[l][r] - dp[l + 1][r - 1] + M) % M;
                dp[l][r] = (dp[l][r] + dp[l][r - 1]) % M;
                dp[l][r] = (dp[l][r] + dp[l + 1][r]) % M;
                dp[l][r] = (dp[l][r] + (dp[l + 1][r - 1] + ast[q(l + 1, r - 1)]) % M) % M;
            }
            else if (a[l] == '?')
            {
                if (a[r] == '(')
                {
                    dp[l][r] = dp[l][r - 1];
                }
                else
                {
                    dp[l][r] = (dp[l + 1][r] + (dp[l + 1][r - 1] + ast[q(l + 1, r - 1)]) % M) % M;
                }
            }
            else if (a[r] == '?')
            {
                if (a[l] == ')')
                {
                    dp[l][r] = dp[l + 1][r];
                }
                else
                {
                    dp[l][r] = (dp[l][r - 1] + (dp[l + 1][r - 1] + ast[q(l + 1, r - 1)]) % M) % M;
                }
            }
            else
            {
                if (a[l] == '(' && a[r] == ')')
                {
                    dp[l][r] = (dp[l + 1][r - 1] + ast[q(l + 1, r - 1)]) % M;
                }
                else
                {
                    if (a[l] == '(')
                    {
                        dp[l][r] = dp[l][r - 1];
                    }
                    else
                    {
                        dp[l][r] = dp[l + 1][r];
                    }
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}