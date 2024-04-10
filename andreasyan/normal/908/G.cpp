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
const int N = 703, M = 1000000007;

int n;
char a[N];

int ast[N];

int dp[N][N][2];

void ph(int& x, int y)
{
    x = (x + y) % M;
}

int u[10][N];

void solv()
{
    cin >> a;
    n = strlen(a);

    ast[0] = 1;
    for (int i = 1; i < N; ++i)
        ast[i] = (ast[i - 1] * 10LL) % M;

    int ans = 0;
    for (int t = 0; t < 10; ++t)
    {
        memset(dp, 0, sizeof dp);

        dp[0][0][1] = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int q = 0; q <= i; ++q)
            {
                for (int u = 0; u < 10; ++u)
                {
                    if (u <= t)
                        ph(dp[i + 1][q + 1][0], dp[i][q][0]);
                    else
                        ph(dp[i + 1][q][0], dp[i][q][0]);
                }
                for (int u = 0; u < a[i] - '0'; ++u)
                {
                    if (u <= t)
                        ph(dp[i + 1][q + 1][0], dp[i][q][1]);
                    else
                        ph(dp[i + 1][q][0], dp[i][q][1]);
                }
                if (a[i] - '0' <= t)
                    ph(dp[i + 1][q + 1][1], dp[i][q][1]);
                else
                    ph(dp[i + 1][q][1], dp[i][q][1]);
            }
        }

        for (int i = n - 1; i >= 0; --i)
        {
            u[t][i] = (u[t][i + 1] + dp[n][i + 1][0] + dp[n][i + 1][1]) % M;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < t; ++j)
                u[t][i] = (u[t][i] - u[j][i] + M) % M;

            ans = (ans + (u[t][i] * 1LL * ast[n - i - 1]) % M * t) % M;
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}