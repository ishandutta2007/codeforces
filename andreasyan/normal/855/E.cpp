#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 70, K = 11;

long long dp[K][N][(1 << K)], dp1[K][N][(1 << K)];

void pre()
{
    for (int k = 2; k < K; ++k)
    {
        dp[k][0][0] = 1;
        for (int i = 0; i < N - 1; ++i)
        {
            for (int x = 0; x < (1 << k); ++x)
            {
                for (int j = 0; j < k; ++j)
                {
                    dp[k][i + 1][(x ^ (1 << j))] += dp[k][i][x];
                }
            }
        }
        dp1[k][0][0] = 1;
        for (int i = 0; i < N - 1; ++i)
        {
            for (int x = 0; x < (1 << k); ++x)
            {
                int s;
                if (i == 0)
                    s = 1;
                else
                    s = 0;
                for (int j = s; j < k; ++j)
                {
                    dp1[k][i + 1][(x ^ (1 << j))] += dp1[k][i][x];
                }
            }
        }
    }
}

long long pp(int k, long long x)
{
    int ans = 0;
    for (long long y = 1; y <= x; ++y)
    {
        long long u = y;
        int x = 0;
        while (u)
        {
            x ^= (1 << (u % k));
            u /= k;
        }
        if (x == 0)
            ++ans;
    }
    return ans;
}

long long p(int k, long long x)
{
    if (x == 0)
        return 0;
    vector<int> v;
    while (x)
    {
        v.push_back((x % k));
        x /= k;
    }
    reverse(v.begin(), v.end());
    long long ans = 0;
    for (int i = 1; i < (int)v.size(); ++i)
    {
        ans += dp1[k][i][0];
    }
    int p = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        int ss;
        if (i == 0)
            ss = 1;
        else
            ss = 0;
        for (int j = ss; j < v[i]; ++j)
        {
            ans += dp[k][(int)v.size() - i - 1][(p ^ (1 << j))];
        }
        p = (p ^ (1 << v[i]));
    }
    if (p == 0)
        ++ans;
    return ans;
}

void solv()
{
    pre();
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int k;
        long long l, r;
        scanf("%d%I64d%I64d", &k, &l, &r);
        printf("%I64d\n", p(k, r) - p(k, l - 1));
        //printf("%I64d\n", pp(k, r) - pp(k, l - 1));
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}