#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int M = 1000000007;
const int K = 10004, L = 64;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

long long n;
int k;

int rast[L];

int dp[L][K], p[L][K];

int main()
{
    for (int j = 0; j < L; ++j)
        rast[j] = ast(j, M - 2);
    cin >> n >> k;
    int ans = 1;
    for (long long i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            int q = 0;
            while (n % i == 0)
            {
                ++q;
                n /= i;
            }
            int x = 1;
            for (int j = 0; j <= q; ++j)
            {
                dp[j][0] = (x % M);
                if (j > 0)
                    p[j][0] = (p[j - 1][0] + dp[j][0]) % M;
                else
                    p[j][0] = dp[j][0];
                for (int kk = 1; kk <= k; ++kk)
                {
                    dp[j][kk] = (p[j][kk - 1] * 1LL * rast[j + 1]) % M;
                    if (j > 0)
                        p[j][kk] = (p[j - 1][kk] + dp[j][kk]) % M;
                    else
                        p[j][kk] = dp[j][kk];
                }
                x = (x * 1LL * i) % M;
            }
            ans = (ans * 1LL * dp[q][k]) % M;
        }
    }
    if (n > 1)
    {
        long long i = n;
        int q = 1;
        int x = 1;
        for (int j = 0; j <= q; ++j)
        {
            dp[j][0] = (x % M);
            if (j > 0)
                p[j][0] = (p[j - 1][0] + dp[j][0]) % M;
            else
                p[j][0] = dp[j][0];
            for (int kk = 1; kk <= k; ++kk)
            {
                dp[j][kk] = (p[j][kk - 1] * 1LL * rast[j + 1]) % M;
                if (j > 0)
                    p[j][kk] = (p[j - 1][kk] + dp[j][kk]) % M;
                else
                    p[j][kk] = dp[j][kk];
            }
            x = (x * 1LL * i) % M;
        }
        ans = (ans * 1LL * dp[q][k]) % M;
    }
    cout << ans << endl;
    return 0;
}