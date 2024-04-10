#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 600005, K = 5003;
const long long INF = 10000000010;

int n, k;
int a[N];

long long dp[K][K];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 0; i <= (n % k); ++i)
    {
        for (int j = 0; j <= k - (n % k); ++j)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i <= (n % k); ++i)
    {
        for (int j = 0; j <= k - (n % k); ++j)
        {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[(i + 1) * ((n / k) + 1) + j * (n / k)] - a[i * ((n / k) + 1) + j * (n / k) + 1]);
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[i * ((n / k) + 1) + (j + 1) * (n / k)] - a[i * ((n / k) + 1) + j * (n / k) + 1]);
        }
    }
    printf("%lld\n", dp[(n % k)][k - (n % k)]);
    return 0;
}