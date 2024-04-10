#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 102, C = 20, M = 1000000007;

struct ban
{
    int n;
    int a[C][C];
    ban()
    {
        n = 0;
        memset(a, 0, sizeof a);
    }
};
ban operator*(const ban& a, const ban& b)
{
    ban ans;
    ans.n = a.n;
    for (int i = 0; i <= a.n; ++i)
    {
        for (int j = 0; j <= a.n; ++j)
        {
            for (int k = 0; k <= a.n; ++k)
            {
                ans.a[i][j] = (ans.a[i][j] + a.a[i][k] * 1LL * b.a[k][j]) % M;
            }
        }
    }
    return ans;
}

ban ast(ban x, long long n)
{
    ban ans;
    ans.n = x.n;
    for (int i = 0; i <= x.n; ++i)
        ans.a[i][i] = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = ans * x;
        x = x * x;
        n /= 2;
    }
    return ans;
}

int n;
long long k;
long long a[N], b[N];
int c[N];

int dp[C];
int ndp[C];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld%lld%d", &a[i], &b[i], &c[i]);
    }
    b[n] = k;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        ban x;
        x.n = c[i];
        for (int j = 0; j <= x.n; ++j)
        {
            if (j - 1 >= 0)
                x.a[j - 1][j] = 1;
            x.a[j][j] = 1;
            if (j + 1 <= x.n)
                x.a[j + 1][j] = 1;
        }
        x = ast(x, b[i] - a[i]);
        memset(ndp, 0, sizeof ndp);
        for (int j = 0; j <= x.n; ++j)
        {
            for (int i = 0; i <= x.n; ++i)
            {
                ndp[j] = (ndp[j] + x.a[i][j] * 1LL * dp[i]) % M;
            }
        }
        memset(dp, 0, sizeof dp);
        for (int j = 0; j <= c[i + 1]; ++j)
            dp[j] = ndp[j];
    }
    printf("%d\n", dp[0]);
    return 0;
}