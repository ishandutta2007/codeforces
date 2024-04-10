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
const int N = 102;
int M;

int n, m, k;

int C[N][N];
int f[N];

int dp[N][N][N];

void solv()
{
    cin >> n >> m >> k >> M;

    for (int i = 0; i < N; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    }
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;

    for (int m0 = 0; m0 <= n; ++m0)
        dp[0][m0][0] = 1;
    for (int n0 = 1; n0 <= n; ++n0)
    {
        for (int m0 = 1; m0 <= n0; ++m0)
        {
            if (m0 == 1)
            {
                dp[n0][m0][1] = f[n0];
                continue;
            }
            for (int i = 1; i <= n0; ++i)
            {
                for (int k0 = 0; k0 <= i - 1; ++k0)
                {
                    if (dp[i - 1][m0 - 1][k0] == 0)
                        continue;
                    for (int k1 = 0; k1 <= n0 - i; ++k1)
                    {
                        if (dp[n0 - i][m0 - 1][k1] == 0)
                            continue;

                        int yans = (dp[i - 1][m0 - 1][k0] * 1LL * dp[n0 - i][m0 - 1][k1]) % M;
                        yans = (yans * 1LL * C[n0 - 1][i - 1]) % M;

                        dp[n0][m0][k0 + k1] = (dp[n0][m0][k0 + k1] + yans) % M;
                    }
                }
            }
            /*dp[n0][m0][0] = 1;
            for (int i = 1; i <= n0; ++i)
                dp[n0][m0][0] = (dp[n0][m0][0] * 1LL * i) % M;
            for (int k0 = 1; k0 < K; ++k0)
                dp[n0][m0][0] = (dp[n0][m0][0] - dp[n0][m0][k0] + M) % M;*/
        }
        for (int m0 = n0 + 1; m0 <= n; ++m0)
        {
            dp[n0][m0][0] = f[n0];
        }
    }

    cout << dp[n][m][k] << "\n";
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