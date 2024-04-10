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
const int N = 800;
const ll INF = 1000000009000000009;

int n, qq;
int a[N];

ll dp[N][N];

void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = n; i >= 1; --i)
    {
        for (int j = 1; j <= (n - i + 1); ++j)
        {
            dp[i][j] = INF;
            if (j <= n - i)
                dp[i][j] = dp[i + 1][j];
            dp[i][j] = min(dp[i][j], max(0LL, dp[i + 1][j - 1] - a[i]));
        }
    }
    while (qq--)
    {
        ll s;
        scanf("%lld", &s);
        int l = 1, r = n;
        int ans = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (dp[1][m] <= s)
            {
                ans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        printf("%d\n", n - ans);
    }
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