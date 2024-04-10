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
const int N = 1003, M = 998244353;

int n, m;
char a[N], b[N];

int dp[N][N][2];

void ph(int& x, int y)
{
    x = (x + y) % M;
}

void solv()
{
    scanf(" %s", (a + 1));
    for (n = 1; a[n]; ++n){}
    --n;
    scanf(" %s", (b + 1));
    for (m = 1; b[m]; ++m){}
    --m;

    for (int i = 1; i <= n; ++i)
        dp[i][0][0] = 1;
    for (int j = 1; j <= m; ++j)
        dp[0][j][1] = 1;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (!i && !j)
                continue;
            if (i && j)
            {
                if (i + 1 <= n && a[i + 1] != a[i])
                    ph(dp[i + 1][j][0], dp[i][j][0]);
                if (j + 1 <= m && b[j + 1] != a[i])
                    ph(dp[i][j + 1][1], dp[i][j][0]);
                if (i + 1 <= n && a[i + 1] != b[j])
                    ph(dp[i + 1][j][0], dp[i][j][1]);
                if (j + 1 <= m && b[j + 1] != b[j])
                    ph(dp[i][j + 1][1], dp[i][j][1]);
            }
            else if (i)
            {
                if (i + 1 <= n && a[i + 1] != a[i])
                    ph(dp[i + 1][0][0], dp[i][0][0]);
                for (int j = 1; j <= m; ++j)
                {
                    if (b[j] != a[i])
                        ph(dp[i][j][1], dp[i][0][0]);
                }
            }
            else if (j)
            {
                if (j + 1 <= m && b[j + 1] != b[j])
                    ph(dp[0][j + 1][1], dp[0][j][1]);
                for (int i = 1; i <= n; ++i)
                {
                    if (a[i] != b[j])
                        ph(dp[i][j][0], dp[0][j][1]);
                }
            }
            else
                assert(false);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            ph(ans, dp[i][j][0]);
            ph(ans, dp[i][j][1]);
        }
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
    //scanf("%d", &tt);
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}