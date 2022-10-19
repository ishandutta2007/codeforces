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
const int N = 252;

int n;
int a[N];

int dp[N * 2][N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    sort(a + 1, a + n + 1);

    for (int t = 0; t <= 2 * n + 2; ++t)
    {
        for (int i = 0; i <= n; ++i)
        {
            dp[t][i] = N * N;
        }
    }

    dp[0][0] = 0;
    for (int t = 0; t < 2 * n + 2; ++t)
    {
        for (int i = 0; i <= n; ++i)
        {
            if (i < n)
                dp[t + 1][i + 1] = min(dp[t + 1][i + 1], dp[t][i] + abs((t + 1) - a[i + 1]));
            dp[t + 1][i] = min(dp[t + 1][i], dp[t][i]);
        }
    }

    printf("%d\n", dp[2 * n + 2][n]);
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