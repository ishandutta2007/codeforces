#include <bits/stdc++.h>
using namespace std;
const int N = 2003;
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
        this->x = (x % M);
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
    ban ans(1);
    while (n)
    {
        if (n % 2 == 1)
            ans = ans * x;
        x = x * x;
        n /= 2;
    }
    return ans;
}
ban operator/(const ban& a, const ban& b)
{
    return a * ast(b, M - 2);
}

int n, k;
int a[N];

ban dp[N][N * 2];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    dp[0][N] = ban(1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < N * 2; ++j)
        {
            if (dp[i][j].x == 0)
                continue;
            if (a[i + 1] == a[((i + 1) % n) + 1])
                dp[i + 1][j] = dp[i + 1][j] + dp[i][j] * ban(k);
            else
            {
                dp[i + 1][j] = dp[i + 1][j] + dp[i][j] * ban(k - 2);
                dp[i + 1][j - 1] = dp[i + 1][j - 1] + dp[i][j];
                dp[i + 1][j + 1] = dp[i + 1][j + 1] + dp[i][j];
            }
        }
    }
    ban ans;
    for (int j = N + 1; j < N * 2; ++j)
        ans = ans + dp[n][j];
    printf("%lld\n", ans.x);
    return 0;
}