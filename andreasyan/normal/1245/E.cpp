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
const int n = 10;

int a[n][n];

double dp[n][n][2];

void solv()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i || j >= 6)
                {
                    for (int k = 1; k <= 6; ++k)
                    {
                        int u = j - k;
                        if (u >= 0)
                            dp[i][j][0] = (dp[i][j][0] + dp[i][u][1] + 1);
                        else
                        {
                            u = -u - 1;
                            dp[i][j][0] = (dp[i][j][0] + dp[i - 1][u][1] + 1);
                        }
                    }
                    dp[i][j][0] /= 6.0;
                }
                else
                {
                    if (j == 0)
                        continue;
                    for (int k = 1; k <= 6; ++k)
                    {
                        int u = j - k;
                        if (u >= 0)
                            dp[i][j][0] = (dp[i][j][0] + dp[i][u][1]);
                    }
                    dp[i][j][0] /= j;
                    dp[i][j][0] += (6.0 / j);
                }
                dp[i][j][1] = dp[i][j][0];
                if (a[i][j])
                {
                    dp[i][j][1] = min(dp[i][j][1], dp[i - a[i][j]][j][0]);
                }
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; --j)
            {
                for (int k = 1; k <= 6; ++k)
                {
                    int u = j + k;
                    if (u < n)
                        dp[i][j][0] = (dp[i][j][0] + dp[i][u][1] + 1);
                    else
                    {
                        u = n - 1 - (u - n);
                        dp[i][j][0] = (dp[i][j][0] + dp[i - 1][u][1] + 1);
                    }
                }
                dp[i][j][0] /= 6.0;
                dp[i][j][1] = dp[i][j][0];
                if (a[i][j])
                {
                    dp[i][j][1] = min(dp[i][j][1], dp[i - a[i][j]][j][0]);
                }
            }
        }
    }
    printf("%.10f\n", dp[n - 1][0][1]);
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