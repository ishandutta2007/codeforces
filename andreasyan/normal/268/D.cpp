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
const int N = 33, M = 1000000009;

int n, h;

int dp[2][N][N][N];
int ndp[2][N][N][N];

int uz(int z)
{
    if (z == 0)
        return 1;
    return h;
}

int ut(int i)
{
    if (i == h)
        return 1;
    return 0;
}

void solv()
{
    scanf("%d%d", &n, &h);
    dp[0][0][0][0] = 1;
    for (int ii = 1; ii <= n; ++ii)
    {
        memset(ndp, 0, sizeof ndp);
        for (int z = 0; z < 2; ++z)
        {
            for (int i = 0; i <= h; ++i)
            {
                for (int j = 0; j <= h; ++j)
                {
                    for (int k = 0; k <= h; ++k)
                    {
                        // z
                        ndp[z][min(i + 1, h)][min(j + 1, h)][min(k + 1, h)] += dp[z][i][j][k];
                        ndp[z][min(i + 1, h)][min(j + 1, h)][min(k + 1, h)] %= M;
                        // i
                        ndp[ut(i)][uz(z)][min(j + 1, h)][min(k + 1, h)] += dp[z][i][j][k];
                        ndp[ut(i)][uz(z)][min(j + 1, h)][min(k + 1, h)] %= M;
                        // j
                        ndp[ut(j)][uz(z)][min(i + 1, h)][min(k + 1, h)] += dp[z][i][j][k];
                        ndp[ut(j)][uz(z)][min(i + 1, h)][min(k + 1, h)] %= M;
                        // k
                        ndp[ut(k)][uz(z)][min(i + 1, h)][min(j + 1, h)] += dp[z][i][j][k];
                        ndp[ut(k)][uz(z)][min(i + 1, h)][min(j + 1, h)] %= M;
                    }
                }
            }
        }
        memcpy(dp, ndp, sizeof ndp);
    }
    int ans = 0;
    for (int z = 0; z < 2; ++z)
    {
        for (int i = 0; i <= h; ++i)
        {
            for (int j = 0; j <= h; ++j)
            {
                for (int k = 0; k <= h; ++k)
                {
                    if (z == 1 && i == h && j == h && k == h)
                        continue;
                    ans += dp[z][i][j][k];
                    ans %= M;
                }
            }
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}