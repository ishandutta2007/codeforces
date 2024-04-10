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
const int N = 77;

int n, m, k;
int a[N][N];

int dp[N * N];

int maxu[N];

int dpp[N];
int ndpp[N];

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    }

    for (int j = 0; j < k; ++j)
        dpp[j] = -N * N * N;
    dpp[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < N * N; ++j)
            dp[j] = m;
        dp[0] = 0;
        for (int j = 1; j <= m; ++j)
        {
            for (int u = N * N - a[i][j] - 1; u >= 0; --u)
                dp[u + a[i][j]] = min(dp[u + a[i][j]], dp[u] + 1);
        }
        for (int j = 0; j < N; ++j)
            maxu[j] = -N * N * N;
        for (int j = 0; j < N * N; ++j)
        {
            if (dp[j] <= m / 2)
                maxu[(j % k)] = max(maxu[(j % k)], j);
        }
        for (int j = 0; j < k; ++j)
            ndpp[j] = -N * N * N;
        for (int j = 0; j < k; ++j)
        {
            for (int u = 0; u < k; ++u)
            {
                ndpp[(j + u) % k] = max(ndpp[(j + u) % k], dpp[j] + maxu[u]);
            }
        }
        for (int j = 0; j < k; ++j)
            dpp[j] = ndpp[j];
    }
    printf("%d\n", dpp[0]);
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