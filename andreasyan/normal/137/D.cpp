#include <bits/stdc++.h>
using namespace std;
const int N = 502;

int n;
char aa[N], a[N];
int m;

int dp[N][N];

int dp1[N][N];
int p[N][N];

bool c[N];
int main()
{
    cin >> aa;
    n = strlen(aa);
    for (int i = 1; i <= n; ++i)
        a[i] = aa[i - 1];
    cin >> m;

    for (int d = 1; d <= n; ++d)
    {
        for (int l = 1; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            if (a[l] == a[r])
                dp[l][r] = dp[l + 1][r - 1];
            else
                dp[l][r] = dp[l + 1][r - 1] + 1;
        }
    }

    for (int i = 0; i <= n; ++i)
    {
        for (int k = 0; k <= m; ++k)
            dp1[i][k] = N;
    }
    dp1[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int k = 1; k <= m; ++k)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp1[i][k] > dp1[j][k - 1] + dp[j + 1][i])
                {
                    dp1[i][k] = dp1[j][k - 1] + dp[j + 1][i];
                    p[i][k] = j;
                }
            }
        }
    }

    int minu = N, kk;
    for (int k = 1; k <= m; ++k)
    {
        if (dp1[n][k] < minu)
        {
            minu = dp1[n][k];
            kk = k;
        }
    }

    cout << dp1[n][kk] << endl;
    int i = n;
    int k = kk;
    while (1)
    {
        if (i == 0)
            break;
        i = p[i][k];
        --k;
        c[i] = true;
    }
    c[0] = true;
    c[n] = true;
    for(int i = 1; i <= n; ++i)
    {
        int l;
        for (int j = i - 1; ; --j)
        {
            if (c[j])
            {
                l = j + 1;
                break;
            }
        }
        int r;
        for (int j = i; ; ++j)
        {
            if (c[j])
            {
                r = j;
                break;
            }
        }

        int m = (l + r) / 2;
        if (i > m)
        {
            if ((r - l + 1) % 2 == 1)
                cout << a[m - (i - m)];
            else
                cout << a[m - (i - m) + 1];
        }
        else
        {
            cout << a[i];
        }

        if (c[i] && i < n)
        {
            cout << '+';
        }
    }
    cout << endl;
    return 0;
}