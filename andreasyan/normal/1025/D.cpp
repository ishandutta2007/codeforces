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
const int N = 702;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
int a[N];

bool c[N][N];

bool dp[N][N][2];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (gcd(a[i], a[j]) > 1)
                c[i][j] = true;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        dp[i][i - 1][0] = dp[i][i - 1][1] = dp[i + 1][i][0] = dp[i + 1][i][1] = true;
    }

    for (int d = 1; d <= n; ++d)
    {
        for (int l = 1; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            for (int i = l; i <= r; ++i)
            {
                if ((c[i][l - 1] || d == n) && dp[l][i - 1][1] && dp[i + 1][r][0])
                {
                    dp[l][r][0] = true;
                    break;
                }
            }
            for (int i = l; i <= r; ++i)
            {
                if (c[i][r + 1] && dp[l][i - 1][1] && dp[i + 1][r][0])
                {
                    dp[l][r][1] = true;
                    break;
                }
            }
        }
    }

    if (dp[1][n][0])
        cout << "Yes\n";
    else
        cout << "No\n";
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
        solv();
    return 0;
}