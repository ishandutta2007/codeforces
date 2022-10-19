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
const int N = 203, INF = 1000000009;

int n, m;
char a[N];
char b[4];

int dp[N][N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    scanf(" %s", (a + 1));
    scanf(" %s", (b + 1));

    if (b[1] == b[2])
    {
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == b[1])
                ++ans;
        }
        ans = min(n, ans + m);
        ans = (ans * (ans - 1)) / 2;
        printf("%d\n", ans);
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                dp[i][j][k] = -INF;
            }
        }
    }

    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            for (int k = 0; k <= m; ++k)
            {
                if (a[i + 1] == b[1])
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k]);
                else if (a[i + 1] == b[2])
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + j);
                else
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
                dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + j);
            }
        }
    }

    int ans = -INF;
    for (int j = 0; j <= n; ++j)
    {
        for (int k = 0; k <= m; ++k)
        {
            ans = max(ans, dp[n][j][k]);
        }
    }
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
    tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}