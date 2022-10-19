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
const int N = 202, K = 1003, M = 1000000007;

int n, k;
int a[N];

int dp[N][N][K];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int q = 0; q <= n; ++q)
        {
            for (int j = 0; j <= k; ++j)
            {
                if (j + q * (a[i + 1] - a[i]) <= k)
                {
                    dp[i + 1][q][j + q * (a[i + 1] - a[i])] = (dp[i + 1][q][j + q * (a[i + 1] - a[i])] + dp[i][q][j] * 1LL * (q + 1)) % M;
                    dp[i + 1][q + 1][j + q * (a[i + 1] - a[i])] = (dp[i + 1][q + 1][j + q * (a[i + 1] - a[i])] + dp[i][q][j]) % M;
                    dp[i + 1][q - 1][j + q * (a[i + 1] - a[i])] = (dp[i + 1][q - 1][j + q * (a[i + 1] - a[i])] + dp[i][q][j] * 1LL * q) % M;
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= k; ++j)
        ans = (ans + dp[n][0][j]) % M;
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}