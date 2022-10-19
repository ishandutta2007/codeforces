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
const int N = 100005;

int n, m;
char a[N];

ll dp[N][8];

void solv()
{
    cin >> n >> m;
    cin >> (a + 1);

    for (int i = 1; i <= n; ++i)
        a[i] -= 'a';

    dp[0][2 + 4] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int x = 0; x < (1 << 3); ++x)
        {
            int dp0[3];
            for (int j = 0; j < 3; ++j)
            {
                if (i + j - 1 < 0 || i + j - 1 > n)
                {
                    dp0[j] = -1;
                    continue;
                }
                if ((x & (1 << j)))
                    dp0[j] = min(i, i + j - 1);
                else
                    dp0[j] = min(i, i + j - 1) - 1;
            }
            for (int u = 0; u < m; ++u)
            {
                int dp1[3];
                for (int j = 0; j < 3; ++j)
                {
                    if (i + 1 + j - 1 < 0 || i + 1 + j - 1 > n)
                    {
                        dp1[j] = -1;
                        continue;
                    }
                    dp1[j] = 0;
                    if (j - 1 >= 0)
                        dp1[j] = max(dp1[j], dp1[j - 1]);
                    if (j + 1 < 3)
                        dp1[j] = max(dp1[j], dp0[j + 1]);
                    if (i + j > 0 && i + j <= n && u == a[i + j])
                        dp1[j] = max(dp1[j], dp0[j] + 1);
                }
                int y = 0;
                for (int j = 0; j < 3; ++j)
                {
                    if (dp1[j] == -1)
                        continue;
                    if (dp1[j] == min(i + 1, i + 1 + j - 1))
                        y |= (1 << j);
                    else if (dp1[j] == min(i + 1, i + 1 + j - 1) - 1)
                        y |= 0;
                    else
                    {
                        y = -1;
                        break;
                    }
                }
                if (y != -1)
                    dp[i + 1][y] += dp[i][x];
            }
        }
    }

    ll ans = 0;
    for (int x = 0; x < (1 << 3); ++x)
    {
        if (!(x & 2))
            ans += dp[n][x];
    }

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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}