#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102;
const ll INF = 1000000009000000009;

int n, m;
ll a[N][N];

ll dp[2][N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%lld", &a[i][j]);
        }
    }
    ll ans = INF;
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            for (int i = 1; i <= x; ++i)
            {
                for (int j = 1; j <= y; ++j)
                {
                    dp[0][i][j] = INF;
                    if (a[i][j] < (a[x][y] - (x - i) - (y - j)))
                        continue;
                    if (i == 1 && j == 1)
                    {
                        dp[0][i][j] = abs(a[i][j] - (a[x][y] - (x - i) - (y - j)));
                        continue;
                    }
                    if (i > 1)
                        dp[0][i][j] = min(dp[0][i][j], abs(a[i][j] - (a[x][y] - (x - i) - (y - j))) +
                                          dp[0][i - 1][j]);
                    if (j > 1)
                        dp[0][i][j] = min(dp[0][i][j], abs(a[i][j] - (a[x][y] - (x - i) - (y - j))) +
                                          dp[0][i][j - 1]);
                    dp[0][i][j] = min(dp[0][i][j], INF);
                }
            }
            for (int i = n; i >= x; --i)
            {
                for (int j = m; j >= y; --j)
                {
                    dp[1][i][j] = INF;
                    if (a[i][j] < (a[x][y] + (i - x) + (j - y)))
                        continue;
                    if (i == n && j == m)
                    {
                        dp[1][i][j] = abs(a[i][j] - (a[x][y] + (i - x) + (j - y)));
                        continue;
                    }
                    if (i < n)
                        dp[1][i][j] = min(dp[1][i][j], abs(a[i][j] - (a[x][y] + (i - x) + (j - y))) +
                                          dp[1][i + 1][j]);
                    if (j < m)
                        dp[1][i][j] = min(dp[1][i][j], abs(a[i][j] - (a[x][y] + (i - x) + (j - y))) +
                                          dp[1][i][j + 1]);
                    dp[1][i][j] = min(dp[1][i][j], INF);
                }
            }
            ans = min(ans, dp[0][x][y] + dp[1][x][y]);
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}