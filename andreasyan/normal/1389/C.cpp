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
char a[N];

int dp[N][2];

void solv()
{
    scanf(" %s", (a + 1));
    for (n = 1; a[n]; ++n){}
    --n;
    int ans = N;
    for (char x = '0'; x <= '9'; ++x)
    {
        for (char y = '0'; y <= '9'; ++y)
        {
            dp[0][1] = N;
            for (int i = 1; i <= n; ++i)
            {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1] + 1;
                if (a[i] == x)
                    dp[i][1] = min(dp[i][1], dp[i - 1][0]);
                if (a[i] == y)
                    dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            }
            ans = min(ans, dp[n][0]);
            if (x == y)
                ans = min(ans, dp[n][1]);
        }
    }
    printf("%d\n", ans);
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