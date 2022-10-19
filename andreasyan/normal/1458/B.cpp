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
const int N = 102, INF = 1000000009;

int n;
int a[N], b[N];

int dp[N][4 * N * N];
int ndp[N][4 * N * N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i], &b[i]);

    for (int j = 0; j <= n; ++j)
        for (int k = 0; k <= n * 400; ++k)
            dp[j][k] = -INF;
    dp[0][n * 200] = 0;
    for (int i = 0; i < n; ++i)
    {
        memset(ndp, -INF, sizeof ndp);
        for (int j = 0; j <= i; ++j)
        {
            for (int k = (n - i) * 200; k <= (n + i) * 200; ++k)
            {
                if (dp[j][k] < 0)
                    continue;
                ndp[j][k - b[i + 1]] = max(ndp[j][k - b[i + 1]],
                                   dp[j][k] + max(0, min((k - n * 200), b[i + 1])));
                ndp[j + 1][k + (a[i + 1] - b[i + 1]) * 2] = max(ndp[j + 1][k + (a[i + 1] - b[i + 1]) * 2],
                                dp[j][k] + b[i + 1] * 2 + max(0, min(-(k - n * 200), (a[i + 1] - b[i + 1]) * 2)));
            }
        }
        memcpy(dp, ndp, sizeof ndp);
    }

    for (int j = 1; j <= n; ++j)
    {
        int ans = -INF;
        for (int k = 0; k <= n * 400; ++k)
            ans = max(ans, dp[j][k]);
        if (ans % 2 == 0)
            printf("%d ", ans / 2);
        else
            printf("%d.5 ", ans / 2);
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}