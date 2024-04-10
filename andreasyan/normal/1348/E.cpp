#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 503;
const long long INF = 10004000000009;

int n, k;
int a[N], b[N];

pair<long long, int> dp[N];
pair<long long, int> ndp[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    for (int i = 1; i < k; ++i)
        dp[i] = m_p(-INF, 0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < k; ++j)
            ndp[j] = m_p(-INF, 0);
        for (int j = 0; j < k; ++j)
        {
            if (dp[j].first == -INF)
                continue;
            ndp[(j + a[i]) % k] = max(ndp[(j + a[i]) % k], m_p(dp[j].first + (j + a[i]) / k + (dp[j].second + b[i]) / k, (dp[j].second + b[i]) % k));
            for (int u = 0; u < k; ++u)
            {
                int t = k - u;
                if (!(u <= a[i] && t <= b[i]))
                    continue;
                a[i] -= u;
                b[i] -= t;
                ndp[(j + a[i]) % k] = max(ndp[(j + a[i]) % k], m_p(dp[j].first + (j + a[i]) / k + (dp[j].second + b[i]) / k + 1, (dp[j].second + b[i]) % k));
                a[i] += u;
                b[i] += t;
            }
        }
        for (int j = 0; j < k; ++j)
            dp[j] = ndp[j];
    }
    long long ans = 0;
    for (int j = 0; j < k; ++j)
        ans = max(ans, dp[j].first);
    printf("%lld\n", ans);
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