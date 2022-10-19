#include <bits/stdc++.h>
using namespace std;
const int N = 5003, M = 1000000007;

int n;
char a[N];


int z[N][N];

int dp[N][N];
int s[N][N];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        z[i][i] = 1;
        int l = 0, r = 0;
        for (int j = i + 1; j <= n; ++j)
        {
            if (j <= r)
                z[i][j] = min(z[i][i + (j - l)], r - j + 1);
            while (a[i + z[i][j]] == a[j + z[i][j]])
                ++z[i][j];
            if (j + z[i][j] - 1 > r)
            {
                l = j;
                r = j + z[i][j] - 1;
            }
        }
    }
    for (int r = 1; r <= n; ++r)
    {
        for (int l = 1; l <= r; ++l)
        {
            if (a[l] != '0')
            {
                if (l == 1)
                {
                    dp[l][r] = 1;
                    continue;
                }
                int d = (r - l + 1);
                dp[l][r] = s[l - 1][max(1, l - d + 1)];
                if (l - d >= 1)
                {
                    // (l - d; l - 1)
                    if (z[l - d][l] < d && a[l + z[l - d][l]] > a[l - d + z[l - d][l]])
                        dp[l][r] = (dp[l][r] + dp[l - d][l - 1]) % M;
                }
            }
        }
        for (int l = r; l >= 1; --l)
        {
            s[r][l] = (s[r][l + 1] + dp[l][r]) % M;
        }
    }

    cout << s[n][1] << endl;
    return 0;
}