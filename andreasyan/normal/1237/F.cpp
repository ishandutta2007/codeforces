#include <bits/stdc++.h>
using namespace std;
const int N = 3603, M = 998244353;

int n, m, q;

int tt, ts;
bool t[N], s[N];

int dpt[N][N], dps[N][N];

int u[N][N];
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &q);
    while (q--)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        t[x1] = true;
        t[x2] = true;
        s[y1] = true;
        s[y2] = true;
    }
    dpt[0][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int q = 0; q <= n; ++q)
        {
            if (i + 2 <= n)
            {
                if (!t[i + 1] && !t[i + 2])
                    dpt[i + 2][q + 1] = (dpt[i + 2][q + 1] + dpt[i][q]) % M;
            }
            dpt[i + 1][q] = (dpt[i + 1][q] + dpt[i][q]) % M;
        }
    }
    dps[0][0] = 1;
    for (int j = 0; j < m; ++j)
    {
        for (int q = 0; q <= m; ++q)
        {
            if (j + 2 <= m)
            {
                if (!s[j + 1] && !s[j + 2])
                    dps[j + 2][q + 1] = (dps[j + 2][q + 1] + dps[j][q]) % M;
            }
            dps[j + 1][q] = (dps[j + 1][q] + dps[j][q]) % M;
        }
    }
    ////////////////////////////
    for (int i = 1; i <= n; ++i)
    {
        if (!t[i])
            ++tt;
    }
    for (int j = 1; j <= m; ++j)
    {
        if (!s[j])
            ++ts;
    }
    u[0][0] = 1;
    for (int i = 1; i < N; ++i)
    {
        u[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            u[i][j] = (i * 1LL * u[i - 1][j - 1]) % M;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i * 2 + j > tt)
                continue;
            if (j * 2 + i > ts)
                continue;
            int us = (u[tt - i * 2][j] * 1LL * dps[m][j]) % M;
            int ut = (u[ts - j * 2][i] * 1LL * dpt[n][i]) % M;
            ans += (us * 1LL * ut) % M;
            ans %= M;
        }
    }
    cout << ans << endl;
    return 0;
}