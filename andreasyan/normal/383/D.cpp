#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1003, m = 10004, M = 1000000007;

int n;
int a[N];

int dp[m * 2];
int ndp[m * 2];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int ans = 0;
    dp[m] = 1;
    for (int i = 1; i <= n; ++i)
    {
        memset(ndp, 0, sizeof ndp);
        for (int j = 0; j < 2 * m; ++j)
        {
            if (dp[j])
            {
                ndp[j - a[i]] = (ndp[j - a[i]] + dp[j]) % M;
                ndp[j + a[i]] = (ndp[j + a[i]] + dp[j]) % M;
            }
        }
        memcpy(dp, ndp, sizeof ndp);
        ans = (ans + dp[m]) % M;
        dp[m] = (dp[m] + 1) % M;
    }
    printf("%d\n", ans);
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