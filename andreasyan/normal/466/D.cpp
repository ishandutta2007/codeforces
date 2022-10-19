#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 2003, M = 1000000007;

int n, h;
int a[N];

int dp[N];
int ndp[N];

void solv()
{
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        a[i] = h - a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        memset(ndp, 0, sizeof ndp);
        for (int j = 0; j <= n; ++j)
        {
            if (dp[j])
            {
                ndp[j] = (ndp[j] + dp[j]) % M;
                ndp[j + 1] = (ndp[j + 1] + dp[j]) % M;
            }
        }
        memcpy(dp, ndp, sizeof ndp);
        for (int j = 0; j <= n; ++j)
        {
            if (j != a[i])
            {
                dp[j] = 0;
            }
        }
        memset(ndp, 0, sizeof ndp);
        for (int j = 0; j <= n; ++j)
        {
            if (dp[j])
            {
                if (j)
                    ndp[j - 1] = (ndp[j - 1] + dp[j] * 1LL * j) % M;
                ndp[j] = (ndp[j] + dp[j]) % M;
            }
        }
        memcpy(dp, ndp, sizeof ndp);
    }
    printf("%d\n", dp[0]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}