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
const int N = 402;
const ll INF = 1000000009000000009;

struct ban
{
    int s, f, c, r;
};

int n, m;
int a[N];

int dp[N][N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int s = 1; s <= n; ++s)
    {
        for (int f = s + 1; f <= n; ++f)
        {
            dp[s][f][0] = dp[s][f - 1][0] + (a[f] - a[f - 1]);
        }
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int s = 1; s <= n; ++s)
        {
            int i = s;
            for (int f = s + 1; f <= n; ++f)
            {
                while (i <= f && dp[s][i][k - 1] <= dp[i][f][0])
                    ++i;
                dp[s][f][k] = min(max(dp[s][i][k - 1], dp[i][f][0]),
                                  max(dp[s][i - 1][k - 1], dp[i - 1][f][0]));
            }
        }
    }
    ll ans = 0;
    while (m--)
    {
        int s, f, c, r;
        scanf("%d%d%d%d", &s, &f, &c, &r);
        ans = max(ans, dp[s][f][r] * 1LL * c);
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}