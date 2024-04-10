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
const int N = 5003;

int n;
int a[N];

int dp[N][N];

int q[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            dp[i][j] = -N * N;
    }
    for (int j = 1; j <= n; ++j)
        dp[0][j] = 0;

    for (int i = 1; i <= n; ++i)
    {
        dp[i][a[i]] = dp[i - 1][a[i]] + 1;
        int maxu = 0;
        for (int j = i; j >= 1; --j)
        {
            ++q[a[j]];
            maxu = max(maxu, q[a[j]]);
            if ((i - j + 1) % 2 == 0 && maxu <= (i - j + 1) / 2)
            {
                if (j > 1)
                    dp[i][a[j - 1]] = max(dp[i][a[j - 1]], dp[j - 1][a[j - 1]]);
                else
                {
                    for (int k = 1; k <= n; ++k)
                        dp[i][k] = max(dp[i][k], 0);
                }
            }
        }
        for (int j = 1; j <= i; ++j)
            --q[a[j]];
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dp[n][i]);
    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}