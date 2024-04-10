#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 5003;

int n, T;
int t[N], p[N];

double ast[102][N];

double dp[N];
double ndp[N];

void solv()
{
    scanf("%d%d", &n, &T);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &p[i], &t[i]);
    }
    for (int i = 0; i <= 100; ++i)
    {
        ast[i][0] = 1;
        for (int j = 1; j <= T; ++j)
            ast[i][j] = (ast[i][j - 1] * i / 100);
    }
    dp[0] = 1;
    double ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        double u = 0;
        for (int j = 1; j <= T; ++j)
        {
            if (t[i] == 1)
            {
                ndp[j] = dp[j - 1];
            }
            else
            {
                u *= ast[100 - p[i]][1];
                if (j - t[i] >= 0)
                    u -= (dp[j - t[i]] * ast[100 - p[i]][t[i] - 1]);
                u += dp[j - 1];
                ndp[j] = ast[p[i]][1] * u;
                if (j - t[i] >= 0)
                    ndp[j] += dp[j - t[i]] * ast[100 - p[i]][t[i] - 1];
            }
            if (i == n)
            {
                ans += ndp[j] * i;
                continue;
            }
            if (j + t[i + 1] <= T)
                continue;
            ans += ndp[j] * i * ast[100 - p[i + 1]][T - j];
        }
        memcpy(dp, ndp, sizeof ndp);
    }
    printf("%.12f\n", ans);
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