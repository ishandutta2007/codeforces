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
const int N = 1000006;

int n;
int a[N];

int u[N][2];

ll dp[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    u[n][0] = u[n][1] = n;
    for (int i = n - 1; i >= 1; --i)
    {
        u[i][0] = u[i][1] = i;
        if (a[i] <= a[i + 1])
            u[i][0] = u[i + 1][0];
        if (a[i] >= a[i + 1])
            u[i][1] = u[i + 1][1];
    }
    for (int i = 0; i < n; ++i)
    {
        dp[u[i + 1][0]] = max(dp[u[i + 1][0]], dp[i] + a[u[i + 1][0]] - a[i + 1]);
        dp[u[i + 1][1]] = max(dp[u[i + 1][1]], dp[i] + a[i + 1] - a[u[i + 1][1]]);
        if (u[i + 1][0] != i + 1)
            dp[u[i + 1][0] - 1] = max(dp[u[i + 1][0] - 1], dp[i] + a[u[i + 1][0] - 1] - a[i + 1]);
        if (u[i + 1][1] != i + 1)
            dp[u[i + 1][1] - 1] = max(dp[u[i + 1][1] - 1], dp[i] + a[i + 1] - a[u[i + 1][1] - 1]);
    }
    printf("%lld\n", dp[n]);
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