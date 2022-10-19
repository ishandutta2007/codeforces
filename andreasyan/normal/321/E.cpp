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
const int N = 4003, K = 802, INF = 1000000009;

int n, m;
char a[N][N];

int p[N][N];

int dp[K][N];

void rec(int k, int l, int r, int l0, int r0)
{
    if (l > r)
        return;
    int m = (l + r) / 2;
    dp[k][m] = INF;
    int mini = -1;
    for (int i = l0; i <= r0; ++i)
    {
        int u = dp[k - 1][i] + (p[m][m] + p[i][i] - p[m][i] - p[i][m]) / 2;
        if (u < dp[k][m])
        {
            dp[k][m] = u;
            mini = i;
        }
    }
    rec(k, l, m - 1, l0, mini);
    rec(k, m + 1, r, mini, r0);
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf(" %c", &a[i][j]);
            a[i][j] -= '0';
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            p[i][j] = p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1] + a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
        dp[0][i] = INF;

    for (int k = 1; k <= m; ++k)
    {
        rec(k, k, n, k - 1, n);
    }

    printf("%d\n", dp[m][n]);
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}