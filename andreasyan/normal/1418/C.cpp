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
const int N = 200005;

int n;
int a[N];

int dp[N][2];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 0; i <= n; ++i)
        dp[i][0] = dp[i][1] = N;

    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (i - 2 >= 0)
            dp[i][0] = min(dp[i][0], dp[i - 2][1]);
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i]);
        if (i - 2 >= 0)
            dp[i][1] = min(dp[i][1], dp[i - 2][0] + a[i - 1] + a[i]);
    }
    printf("%d\n", min(dp[n][0], dp[n][1]));
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}