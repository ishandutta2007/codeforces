#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 503, M = 998244353;

int n, m;
int a[N];

int dp[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int l = 1; l <= n + 1; ++l)
        dp[l][l - 1] = 1;
    for (int d = 1; d <= n; ++d)
    {
        for (int l = 1; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            int minu = N, k;
            for (int i = l; i <= r; ++i)
            {
                if (a[i] < minu)
                {
                    minu = a[i];
                    k = i;
                }
            }
            int rr = 0;
            for (int i = k; i <= r; ++i)
            {
                rr = (rr + dp[k + 1][i] * 1LL * dp[i + 1][r]) % M;
            }
            int ll = 0;
            for (int i = k; i >= l; --i)
            {
                ll = (ll + dp[i][k - 1] * 1LL * dp[l][i - 1]) % M;
            }
            dp[l][r] = (ll * 1LL * rr) % M;
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}