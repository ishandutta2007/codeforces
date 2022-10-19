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
const int N = 403;

int n, M;

int ast2[N];
int c[N][N];

int dp[N][N];

void solv()
{
    cin >> n >> M;

    ast2[0] = 1;
    for (int i = 1; i < N; ++i)
        ast2[i] = (ast2[i - 1] * 2) % M;
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }

    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            for (int k = 1; i + k <= n; ++k)
            {
                dp[i + k + 1][j + k] = (dp[i + k + 1][j + k] + dp[i][j] * 1LL * c[j + k][k] % M * ast2[k - 1]) % M;
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= n; ++j)
        ans = (ans + dp[n + 1][j]) % M;

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