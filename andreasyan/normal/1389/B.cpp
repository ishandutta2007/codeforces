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
const int N = 100005;

int n, k, z;
int a[N];

int dp[N][10];

void solv()
{
    scanf("%d%d%d", &n, &k, &z);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 0; i < n + 3; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = a[1];

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j <= z; ++j)
        {
            if (dp[i][j] == -1)
                continue;
            int x = 1 + (i - j) - j;
            if (x > 1)
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[x - 1]);
            }
            if (x < n)
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[x + 1]);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= z; ++j)
        ans = max(ans, dp[k][j]);

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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}