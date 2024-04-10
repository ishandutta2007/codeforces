#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;
const int K = 64;

long long m, k;

long long dp[K][K];

long long stgg(long long n)
{
    memset(dp, 0, sizeof dp);
    long long q = 0;
    for (long long i = 62; i >= 0; --i)
    {
        if ((n & (1LL << i)))
        {
            dp[i][q]++;
            for (long long j = 0; j < 62; ++j)
            {
                dp[i][j] += dp[i + 1][j];
                dp[i][j + 1] += dp[i + 1][j];
            }
            ++q;
        }
        else
        {
            for (long long j = 0; j < 62; ++j)
            {
                dp[i][j] += dp[i + 1][j];
                dp[i][j + 1] += dp[i + 1][j];
            }
        }
    }
    if (q == k)
        return dp[0][k] + 1;
    return dp[0][k];
}

long long stg(long long n)
{
    return stgg(n * 2) - stgg(n);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    /*scanf("%lld", &k);
    for (int n = 1; n <= 100; ++n)
    {
        int qq = 0;
        for (int x = n + 1; x <= n + n; ++x)
        {
            int q = 0;
            for (int i = 0; i < 10; ++i)
            {
                if ((x & (1 << i)))
                    ++q;
            }
            if (q == k)
                ++qq;
        }
        printf("%lld %d\n", stg(n), qq);
    }
    return 0;*/
    scanf("%lld%lld", &m, &k);
    long long l = 1, r = 1000000000000000000;
    while (l <= r)
    {
        long long n = (l + r) / 2;
        long long u = stg(n);
        if (u == m)
        {
            printf("%lld\n", n);
            return 0;
        }
        if (u < m)
            l = n + 1;
        else
            r = n - 1;
    }
    return 0;
}