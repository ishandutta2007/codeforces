#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102, M = 1003;

int n, m;
int x[N];

double dp[N * M];
double p[N * M];
double ndp[N * M];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    if (m == 1)
    {
        printf("1\n");
        return;
    }
    int s = 0;
    dp[0] = m - 1;
    for (int i = 1; i <= n; ++i)
    {
        p[0] = dp[0];
        for (int j = 1; j <= n * m; ++j)
            p[j] = (p[j - 1] + dp[j]);
        ndp[0] = 0;
        for (int j = 1; j <= n * m; ++j)
        {
            if (j - m <= 0)
                ndp[j] = p[j - 1] / (m - 1);
            else
                ndp[j] = (p[j - 1] - p[j - m - 1]) / (m - 1);
            if (j - x[i] >= 0)
                ndp[j] -= (dp[j - x[i]] / (m - 1));
        }
        for (int j = 0; j <= n * m; ++j)
            dp[j] = ndp[j];
        s += x[i];
    }
    double ans = 0;
    for (int j = 0; j < s; ++j)
    {
        ans += dp[j];
    }
    ans += 1;
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