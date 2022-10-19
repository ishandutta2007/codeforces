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
const int N = 503;

int n, x;
int a[N];

int dp[N][N][N];

void solv()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 0; i <= n + 1; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                dp[i][j][k] = N;
    dp[0][0][x] = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                if (j <= a[i])
                    dp[i + 1][a[i]][k] = min(dp[i + 1][a[i]][k], dp[i][j][k]);
                if (a[i] > k && j <= k)
                    dp[i + 1][k][a[i]] = min(dp[i + 1][k][a[i]], dp[i][j][k] + 1);
            }
        }
    }

    int ans = N;
    for (int j = 0; j < N; ++j)
    {
        for (int k = 0; k < N; ++k)
        {
            ans = min(ans, dp[n + 1][j][k]);
        }
    }
    if (ans == N)
        printf("-1\n");
    else
        printf("%d\n", ans);
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