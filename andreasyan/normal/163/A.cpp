#include <bits/stdc++.h>
using namespace std;
const int N = 5003, M = 1000000007;

int n, m;
char ab[N];
char a[N], b[N];

int dp[N][N], p[N][N];

int main()
{
    cin >> ab;
    n = strlen(ab);
    for (int i = 1; i <= n; ++i)
        a[i] = ab[i - 1];
    cin >> ab;
    m = strlen(ab);
    for (int i = 1; i <= m; ++i)
        b[i] = ab[i - 1];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i] == b[j])
                dp[i][j] = (p[i - 1][j - 1] + 1) % M;
        }
        p[i][0] = dp[i][0];
        for (int j = 1; j <= m; ++j)
            p[i][j] = (p[i][j - 1] + dp[i][j]) % M;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = (ans + p[i][m]) % M;

    cout << ans << endl;
    return 0;
}