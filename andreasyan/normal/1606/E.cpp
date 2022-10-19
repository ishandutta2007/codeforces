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
const int N = 505, M = 998244353;

int c[N][N];
int ast[N][N];

bool me[N][N];
int dp[N][N];
int rec(int n, int x)
{
    if (n == 0)
        return 1;
    if (x <= 0)
        return 0;
    if (n == 1)
        return 0;

    if (me[n][x])
        return dp[n][x];
    me[n][x] = true;

    for (int q = 0; q <= n; ++q)
    {
        int u = (rec(n - q, x - (n - 1)) * 1LL * ast[min(x, n - 1)][q]) % M;
        dp[n][x] = (dp[n][x] + u * 1LL * c[n][q]) % M;
    }

    return dp[n][x];
}

void solv()
{
    int n, x;
    cin >> n >> x;

    cout << rec(n, x) << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }

    for (int i = 0; i < N; ++i)
    {
        ast[i][0] = 1;
        for (int j = 1; j < N; ++j)
            ast[i][j] = (ast[i][j - 1] * 1LL * i) % M;
    }

    int tt = 1;
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}