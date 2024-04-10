#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 20, K = 12;
const int M = 998244353;

int k;
int dp[N][(1 << K)];
int dpq[N][(1 << K)];

int pp(long long x)
{
    vector<int> v;
    while (x)
    {
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    memset(dp, 0, sizeof dp);
    memset(dpq, 0, sizeof dpq);
    for (int i = 0; i < v.size(); ++i)
    {
        for (int x = 0; x < (1 << 10); ++x)
        {
            int qx = 0;
            for (int j = 0; j < 10; ++j)
            {
                if ((x & (1 << j)))
                    ++qx;
            }
            if (qx > k)
                continue;
            for (int j = 0; j < 10; ++j)
            {
                if (((x & (1 << j)) && qx == k) || qx < k)
                {
                    dp[i + 1][(x | (1 << j))] = (dp[i + 1][(x | (1 << j))] + ((dp[i][x] * 10LL) % M + (dpq[i][x] * 1LL * j) % M) % M) % M;
                    dpq[i + 1][(x | (1 << j))] = (dpq[i + 1][(x | (1 << j))] + dpq[i][x]) % M;
                }
            }
        }
        if (i == 0)
        {
            for (int j = 1; j < v[i]; ++j)
            {
                set<int> s;
                int x = 0;
                long long y = 0;
                for (int ii = 0; ii < i; ++ii)
                {
                    s.insert(v[ii]);
                    x |= (1 << v[ii]);
                    y = (y * 10) + v[ii];
                }
                s.insert(j);
                x |= (1 << j);
                y = (y * 10) + j;
                if (s.size() <= k)
                {
                    dp[i + 1][x] = (dp[i + 1][x] + (y % M)) % M;
                    dpq[i + 1][x] = (dpq[i + 1][x] + 1) % M;
                }
            }
        }
        else
        {
            for (int j = 0; j < v[i]; ++j)
            {
                set<int> s;
                int x = 0;
                long long y = 0;
                for (int ii = 0; ii < i; ++ii)
                {
                    s.insert(v[ii]);
                    x |= (1 << v[ii]);
                    y = (y * 10) + v[ii];
                }
                s.insert(j);
                x |= (1 << j);
                y = (y * 10) + j;
                if (s.size() <= k)
                {
                    dp[i + 1][x] = (dp[i + 1][x] + (y % M)) % M;
                    dpq[i + 1][x] = (dpq[i + 1][x] + 1) % M;
                }
            }
        }
    }
    int ans = 0;
    for (int x = 0; x < (1 << 10); ++x)
        ans = (ans + dp[v.size()][x]) % M;
    set<int> s;
    long long y = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        s.insert(v[i]);
        y = (y * 10) + v[i];
    }
    if (s.size() <= k)
        ans = (ans + y) % M;
    return ans;
}

int p(long long x)
{
    if (x == 0)
        return x;
    long long y = x;
    int q = 0;
    while (y)
    {
        ++q;
        y /= 10;
    }
    int ans = 0;
    y = 0;
    for (int i = 1; i < q; ++i)
    {
        y = (y * 10) + 9;
        ans = (ans + pp(y)) % M;
    }
    ans = (ans + pp(x)) % M;
    return ans;
}

int main()
{
    long long l, r;
    scanf("%lld%lld%d", &l, &r, &k);
    printf("%d\n", (p(r) - p(l - 1) + M) % M);
    return 0;
}