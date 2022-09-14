#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long sz;
    sz = 600;
    long long n, m, mod, i, j, board[sz][sz], s[sz], a, b, k, p, q, dp1[sz][sz], dp2[sz][sz];
    char c;
    bool f;
    cin >> n >> m >> mod;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    for (i = 0; i < n; i++)
        s[i] = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            s[i] += board[j][i];
    f = true;
    p = 0;
    q = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 0)
            p++;
        else
            if (s[i] == 1)
                q++;
            else
                if (s[i] != 2)
                    f = false;
    }
    if (2 * p + q != 2 * (n - m))
        f = false;
    if (f)
    {
        for (i = 0; i <= n; i++)
            for (j = 0; j <= n; j++)
                dp1[i][j] = 1;
        for (k = 1; k <= n - m; k++)
        {
            for (a = 0; a <= k; a++)
                {
                    b = 2 * k - 2 * a;
                    dp2[a][b] = 0;
                    if (a > 1)
                        dp2[a][b] = (dp2[a][b] + dp1[a - 2][b + 2] * a * (a - 1) / 2) % mod;

                    if (a > 0 && b > 0)
                        dp2[a][b] = (dp2[a][b] + dp1[a - 1][b] * a * b) % mod;

                    if (b > 1)
                        dp2[a][b] = (dp2[a][b] + dp1[a][b - 2] * b * (b - 1) / 2) % mod;
                }
            for (i = 0; i <= k; i++)
                    dp1[i][2 * k - 2 * i] = dp2[i][2 * k - 2 * i];
        }
        cout << (dp1[p][q]);
    }
    else
        cout << 0;

    return 0;
}