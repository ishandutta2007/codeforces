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
const int N = 255, M = 998244353;

int n, k;

int ast[N][N];
int c[N][N];

int p[N][N];
int dp[N][N];

void solv()
{
    cin >> n >> k;
    --n;

    for (int i = 0; i < N; ++i)
    {
        ast[i][0] = 1;
        for (int j = 1; j < N; ++j)
            ast[i][j] = (ast[i][j - 1] * 1LL * i) % M;
    }
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
    }

    dp[0][0] = 1;
    for (int j = 0; j <= k; ++j)
        p[0][j] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int u = 1; u <= k; ++u)
        {
            int g = 1;
            for (int i0 = i - 1; i0 >= 0; --i0)
            {
                g = (g * 1LL * ast[k - u + 1][i0]) % M;
                int yans = (p[i0][u - 1] * 1LL * g) % M;
                yans = (yans * 1LL * c[i][i0]) % M;
                dp[i][u] = (dp[i][u] + yans) % M;
            }
        }
        for (int j = 1; j <= k; ++j)
            p[i][j] = (p[i][j - 1] + dp[i][j]) % M;
    }

    cout << p[n][k] << "\n";
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