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
const int N = 1003;

int n, m;
int a[N][N];

pair<int, int> dp[N][N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i + j == 2)
            {
                dp[i][j] = m_p(a[i][j], a[i][j]);
            }
            else
            {
                if (i - 1 >= 1 && j - 1 >= 1)
                    dp[i][j] = m_p(min(dp[i - 1][j].fi, dp[i][j - 1].fi) + a[i][j], max(dp[i - 1][j].se, dp[i][j - 1].se) + a[i][j]);
                else if (i - 1 >= 1)
                    dp[i][j] = m_p(dp[i - 1][j].fi + a[i][j], dp[i - 1][j].se + a[i][j]);
                else
                    dp[i][j] = m_p(dp[i][j - 1].fi + a[i][j], dp[i][j - 1].se + a[i][j]);
            }
        }
    }

    if (dp[n][m].fi % 2 == 0 && dp[n][m].fi <= 0 && 0 <= dp[n][m].se)
        cout << "YES\n";
    else
        cout << "NO\n";
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