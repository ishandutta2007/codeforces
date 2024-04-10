#include <bits/stdc++.h>
using namespace std;
const int N = 1003, M = 55, INF = 1000000009;

char g[N];

int n;
char s[N];

int an, bn;
char a[N], b[N];
int ha, hb;

int aa[M][26], bb[M][26];

int dp[N][M][M];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> g;
    n = strlen(g);
    for (int i = 1; i <= n; ++i)
        s[i] = g[i - 1];
    cin >> g;
    an = strlen(g);
    for (int i = 1; i <= an; ++i)
        a[i] = g[i - 1];
    cin >> g;
    bn = strlen(g);
    for (int i = 1; i <= bn; ++i)
        b[i] = g[i - 1];

    for (int i = 2; i <= an; ++i)
    {
        bool z = true;
        for (int jj = 1, ii = i; ii <= an; ++jj, ++ii)
        {
            if (a[ii] != a[jj])
            {
                z = false;
                break;
            }
        }
        if (z)
        {
            ha = an - i + 1;
            break;
        }
    }
    for (int i = 2; i <= bn; ++i)
    {
        bool z = true;
        for (int jj = 1, ii = i; ii <= bn; ++jj, ++ii)
        {
            if (b[ii] != b[jj])
            {
                z = false;
                break;
            }
        }
        if (z)
        {
            hb = bn - i + 1;
            break;
        }
    }

    for (int i = 0; i < an; ++i)
        aa[i][a[1] - 'a'] = 1;
    for (int i = 1; i < an; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            bool z = true;
            for (int ii = 1, jj = j; jj <= i; ++ii, ++jj)
            {
                if (a[ii] != a[jj])
                {
                    z = false;
                    break;
                }
            }
            if (z)
            {
                aa[i][(a[i - j + 2] - 'a')] = max(aa[i][(a[i - j + 2] - 'a')], i - j + 2);
            }
        }
    }
    for (int i = 0; i < bn; ++i)
        bb[i][b[1] - 'a'] = 1;
    for (int i = 1; i < bn; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            bool z = true;
            for (int ii = 1, jj = j; jj <= i; ++ii, ++jj)
            {
                if (b[ii] != b[jj])
                {
                    z = false;
                    break;
                }
            }
            if (z)
            {
                bb[i][(b[i - j + 2] - 'a')] = max(bb[i][(b[i - j + 2] - 'a')], i - j + 2);
            }
        }
    }

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < an; ++j)
        {
            for (int k = 0; k < bn; ++k)
            {
                dp[i][j][k] = -INF;
            }
        }
    }

    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < an; ++j)
        {
            for (int k = 0; k < bn; ++k)
            {
                if (s[i + 1] == '*')
                {
                    for (char ss = 'a'; ss <= 'z'; ++ss)
                    {
                        int jj = aa[j][ss - 'a'];
                        int kk = bb[k][ss - 'a'];
                        int ydp = dp[i][j][k];
                        if (jj == an)
                        {
                            ydp++;
                            jj = ha;
                        }
                        if (kk == bn)
                        {
                            ydp--;
                            kk = hb;
                        }
                        dp[i + 1][jj][kk] = max(dp[i + 1][jj][kk], ydp);
                    }
                }
                else
                {
                    int jj = aa[j][s[i + 1] - 'a'];
                    int kk = bb[k][s[i + 1] - 'a'];
                    int ydp = dp[i][j][k];
                    if (jj == an)
                    {
                        ydp++;
                        jj = ha;
                    }
                    if (kk == bn)
                    {
                        ydp--;
                        kk = hb;
                    }
                    dp[i + 1][jj][kk] = max(dp[i + 1][jj][kk], ydp);
                }
            }
        }
    }
    int ans = -INF;
    for (int j = 0; j < an; ++j)
    {
        for (int k = 0; k < bn; ++k)
            ans = max(ans, dp[n][j][k]);
    }
    cout << ans << endl;
    return 0;
}