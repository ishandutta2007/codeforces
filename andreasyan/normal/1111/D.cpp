#include <bits/stdc++.h>
using namespace std;
const int N = 100005, K = 55, M = 1000000007;

int ast(int x, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        int y = ast(x, n / 2);
        return (1LL * y * y) % M;
    }
    else
    {
        int y = ast(x, n - 1);
        return (1LL * y * x) % M;
    }
}

int h(char x)
{
    if ('a' <= x && x <= 'z')
        return x - 'a' + 1;
    return x - 'A' + 26 + 1;
}

int n, m = 52;
char a[N];

int q[K];

int f[N / 2];
int ff;

bool u[N / 2];

vector<int> v;

void pre()
{
    f[0] = 1;
    for (int i = 1; i <= n / 2; ++i)
        f[i] = (1LL * f[i - 1] * i) % M;
    ff = (1LL * f[n / 2] * f[n / 2]) % M;
    for (int i = 1; i <= m; ++i)
        ff = (1LL * ff * ast(f[q[i]], M - 2)) % M;

    u[0] = true;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = n / 2; j >= 0; --j)
        {
            if (u[j] && j + q[i] <= n / 2)
                u[j + q[i]] = true;
        }
    }

    for (int i = 0; i <= n / 2; ++i)
    {
        if (u[i])
            v.push_back(i);
    }
}

int dp[K][N / 2];

int dp0[K][N / 2];
int dp1[K][N / 2];

int dp2[N / 2];

int ans[K][K];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a;
    n = strlen(a);

    /*n = 100000;
    for (int i = 0; i < n; ++i)
    {
        if (rand() % 2)
        {
            a[i] = 'a';
            a[i] += (rand() % 26);
        }
        else
        {
            a[i] = 'A';
            a[i] += (rand() % 26);
        }
    }*/

    for (int i = 0; i < n; ++i)
        q[h(a[i])]++;

    pre();
    //cout << v.size() << endl;

    int t = 0;

    dp0[0][0] = 1;
    for (int i = 0; i < m; ++i)
    {
        t += q[i];

        for (int jj = 0; jj < v.size(); ++jj)
        {
            int j = v[jj];

            int k = t - j;
            if (k < 0)
                break;
            if (j + q[i + 1] <= n / 2)
            {
                dp0[i + 1][j + q[i + 1]] += dp0[i][j];
                dp0[i + 1][j + q[i + 1]] %= M;
            }
            if (k + q[i + 1] <= n / 2 && q[i + 1])
            {
                dp0[i + 1][j] += dp0[i][j];
                dp0[i + 1][j] %= M;
            }
        }
    }

    t = 0;
    dp[m + 1][0] = 1;
    for (int i = m + 1; i > 1; --i)
    {
        t += q[i];
        for (int jj = 0; jj < v.size(); ++jj)
        {
            int j = v[jj];

            int k = t - j;
            if (k < 0)
                break;
            if (j + q[i - 1] <= n / 2)
            {
                dp[i - 1][j + q[i - 1]] += dp[i][j];
                dp[i - 1][j + q[i - 1]] %= M;
            }
            if (k + q[i - 1] <= n / 2 && q[i - 1])
            {
                dp[i - 1][j] += dp[i][j];
                dp[i - 1][j] %= M;
            }
        }
    }

    for (int x = 1; x <= m; ++x)
    {
        for (int i = x; i <= m; ++i)
        {
            for (int jj = 0; jj < v.size(); ++jj)
            {
                int j = v[jj];
                dp1[i][j] = 0;
            }
        }
        int t = 0;
        for (int i = 0; i < m; ++i)
        {
            t += q[i];

            if (i < x - 1)
                continue;
            if (i == x - 1)
            {
                for (int jj = 0; jj < v.size(); ++jj)
                {
                    int j = v[jj];
                    dp1[i][j] = dp0[i][j];
                }
            }

            for (int jj = 0; jj < v.size(); ++jj)
            {
                int j = v[jj];

                int k = t - j;
                if (k < 0)
                    break;
                if (j + q[i + 1] <= n / 2)
                {
                    dp1[i + 1][j + q[i + 1]] += dp1[i][j];
                    dp1[i + 1][j + q[i + 1]] %= M;
                }
                if (k + q[i + 1] <= n / 2 && i + 1 != x && q[i + 1])
                {
                    dp1[i + 1][j] += dp1[i][j];
                    dp1[i + 1][j] %= M;
                }
            }
        }
        ans[x][x] = dp1[m][n / 2];
        ans[x][x] = (1LL * ff * ans[x][x]) % M;
        ans[x][x] += ans[x][x];
        ans[x][x] %= M;

        t = 0;
        for (int y = m; y > x; --y)
        {
            for (int jj = 0; jj < v.size(); ++jj)
            {
                int j = v[jj];
                dp2[j] = 0;
            }

            t += q[y + 1];

            if (y == 4)
                cout << "";

            int i = y + 1;
            for (int jj = 0; jj < v.size(); ++jj)
            {
                int j = v[jj];
                int k = t - j;
                if (k < 0)
                    break;
                if (j + q[i - 1] <= n / 2)
                {
                    dp2[j + q[i - 1]] += dp[i][j];
                    dp2[j + q[i - 1]] %= M;
                }
            }

            for (int jj = 0; jj < v.size(); ++jj)
            {
                int j = v[jj];
                ans[x][y] += ((1LL * dp1[y - 1][j] * dp2[n / 2 - j]) % M);
                ans[x][y] %= M;
            }
            ans[x][y] = (1LL * ans[x][y] * ff) % M;
            ans[x][y] += ans[x][y];
            ans[x][y] %= M;
            ans[y][x] = ans[x][y];
        }
    }

    int qq;
    cin >> qq;
    while (qq--)
    {
        int i, j;
        cin >> i >> j;
        --i;
        --j;
        cout << ans[h(a[i])][h(a[j])] << endl;
    }
    return 0;
}