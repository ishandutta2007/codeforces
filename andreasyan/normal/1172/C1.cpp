#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const long long M = 998244353;
struct ban
{
    long long x;
    ban()
    {
        x = 0;
    }
    ban(long long x)
    {
        this->x = x % M;
    }
};
ban operator+(const ban& a, const ban& b)
{
    return ban(a.x + b.x);
}
ban operator-(const ban& a, const ban& b)
{
    return ban(a.x - b.x + M);
}
ban operator*(const ban& a, const ban& b)
{
    return ban(a.x * b.x);
}
ban ast(ban x, long long n)
{
    ban res = ban(1);
    while (n)
    {
        if ((n & 1))
            res = res * x;
        x = x * x;
        n /= 2;
    }
    return res;
}
ban operator/(const ban& a, const ban& b)
{
    return a * ast(b, M - 2);
}

int n, m;
bool c[N];
int a[N];
int sum, sum0, sum1;

ban dp[N][N][N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
        if (c[i])
            sum1 += a[i];
        else
            sum0 += a[i];
    }

    for (int x = 1; x <= n; ++x)
    {
        dp[x][0][0][0] = ban(1);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                for (int k = 0; k <= i; ++k)
                {
                    int ysum = sum + k - (i - k);
                    int ax;
                    if (c[x])
                        ax = a[x] + j;
                    else
                        ax = a[x] - j;
                    if (c[x])
                    {
                        dp[x][i + 1][j + 1][k + 1] = dp[x][i + 1][j + 1][k + 1] + dp[x][i][j][k] * (ban(ax) / ban(ysum));
                    }
                    else
                    {
                        dp[x][i + 1][j + 1][k] = dp[x][i + 1][j + 1][k] + dp[x][i][j][k] * (ban(ax) / ban(ysum));
                    }

                    int a0;
                    if (c[x])
                        a0 = sum0 - (i - k);
                    else
                        a0 = sum0 - (i - k) - ax;
                    dp[x][i + 1][j][k] = dp[x][i + 1][j][k] + dp[x][i][j][k] * (ban(a0) / ban(ysum));

                    int a1;
                    if (c[x])
                        a1 = sum1 + k - ax;
                    else
                        a1 = sum1 + k;
                    dp[x][i + 1][j][k + 1] = dp[x][i + 1][j][k + 1] + dp[x][i][j][k] * (ban(a1) / ban(ysum));
                }
            }
        }
        ban ans;
        for (int j = 0; j <= m; ++j)
        {
            for (int k = 0; k <= m; ++k)
            {
                if (c[x])
                    ans = ans + dp[x][m][j][k] * (a[x] + j);
                else
                    ans = ans + dp[x][m][j][k] * (a[x] - j);
            }
        }
        cout << ans.x << endl;
    }
    return 0;
}