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
const int N = 5003, INF = 1000000009;

int n, m;
char a[N], b[N];

int dp[N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    scanf(" %s", (a + 1));
    scanf(" %s", (b + 1));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1);
            dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1);
            if (a[i] == b[j])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            ans = max(ans, dp[i][j]);
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
    solv();
    return 0;
}