#include <bits/stdc++.h>
using namespace std;
const int N = 8;
const int M = 1000000007;

int anc(int h, int x, int y)
{
    int dp[N][2] = {};
    dp[0][1] = 1;
    for (int i = 1; i <= h; ++i)
    {
        if ((x & (1 << (i - 1))) && (y & (1 << (i - 1))))
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % M;
            dp[i][1] = dp[i - 1][0];
        }
        else
        {
            dp[i][0] = dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % M;
        }
    }
    return dp[h][1];
}

struct ban
{
    int n, m;
    int a[1 << N][1 << N];
    ban()
    {
        n = m = 0;
        memset(a, 0, sizeof a);
    }
    ban(int n, int m)
    {
        this->n = n;
        this->m = m;
        memset(a, 0, sizeof a);
    }
};
ban operator*(const ban& a, const ban& b)
{
    ban res(a.n, b.m);
    assert(a.m == b.n);
    for (int i = 0; i < a.n; ++i)
    {
        for (int j = 0; j < b.m; ++j)
        {
            for (int k = 0; k < a.m; ++k)
            {
                res.a[i][j] += (a.a[i][k] * 1LL * b.a[k][j]) % M;
                res.a[i][j] %= M;
            }
        }
    }
    return res;
}
ban zro(int n)
{
    ban res(n, n);
    for (int i = 0; i < n; ++i)
        res.a[i][i] = 1;
    return res;
}
ban ast(const ban& x, int n)
{
    if (n == 0)
        return zro(x.n);
    if (n % 2 == 0)
    {
        ban y = ast(x, n / 2);
        return y * y;
    }
    else
    {
        ban y = ast(x, n - 1);
        return y * x;
    }
}

int w[N];

ban z[N];

int main()
{
    for (int i = 1; i <= 7; ++i)
        cin >> w[i];

    for (int i = 1; i <= 7; ++i)
    {
        z[i].n = (1 << i);
        z[i].m = (1 << i);
        for (int x = 0; x < (1 << i); ++x)
        {
            for (int y = 0; y < (1 << i); ++y)
            {
                z[i].a[x][y] = anc(i, x, y);
            }
        }
    }

    ban t(1, (1 << 1));
    t.a[0][1] = 1;
    t = t * ast(z[1], w[1]);
    for (int i = 2; i <= 7; ++i)
    {
        ban nt(1, (1 << i));
        for (int x = 0; x < (1 << (i - 1)); ++x)
            nt.a[0][x | (1 << (i - 1))] = t.a[0][x];
        t = nt;
        t = t * ast(z[i], w[i]);
    }
    cout << t.a[0][(1 << 7) - 1] << endl;
    return 0;
}