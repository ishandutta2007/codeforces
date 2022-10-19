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
const int N = 4003, M = 998244353;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int n, k, l;
int c[N][N];
int r[N];
int f[N];
int dp[N][N];

void solv()
{
    cin >> n >> k >> l;
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
    for (int i = 1; i < N; ++i)
        r[i] = ast(i, M - 2);
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;

    dp[0][0] = 1;
    for (int i = 0; i <= 2 * n; ++i)
    {
        for (int q = 0; q <= i; ++q)
        {
            dp[i + 1][q + 1] = (dp[i + 1][q + 1] + dp[i][q]) % M;
            if (q)
                dp[i + 1][q - 1] = (dp[i + 1][q - 1] + dp[i][q] * 1LL * q) % M;
        }
    }

    int ans = 0;
    for (int i = 1; i < n * 2; ++i)
    {
        for (int q = k; q <= min(i, n * 2 - i); ++q)
        {
            if ((i - q) % 2 != 0)
                continue;
            int yans = (c[i][q] * 1LL * c[n * 2 - i][q]) % M;
            yans = (yans * 1LL * f[q]) % M;
            yans = (yans * 1LL * dp[(i - q)][0]) % M;
            yans = (yans * 1LL * dp[(n * 2 - i - q)][0]) % M;
            ans = (ans + yans) % M;
        }
    }
    ans = (ans * 1LL * ast(dp[2 * n][0], M - 2)) % M;

    ans = (ans * 1LL * l) % M;
    ans = (ans * 1LL * r[n * 2 + 1]) % M;

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}