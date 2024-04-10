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
const int N = 1003, K = 1000006, M = 1000000007;

struct ban
{
    ll x;
    ban()
    {
        x = 0;
    }
    ban(ll x)
    {
        this->x = (x % M);
    }
};
ban operator+(const ban& a, const ban& b)
{
    return ban(a.x + b.x);
}
ban operator-(const ban& a, const ban& b)
{
    return ban(a.x - b.x + M);
}
ban operator*(const ban& a, const ban& b)
{
    return ban(a.x * b.x);
}

ban ast(ban x, int n)
{
    ban ans(1);
    while (n)
    {
        if (n % 2 == 1)
            ans = ans * x;
        x = x * x;
        n /= 2;
    }
    return ans;
}

ban f[K], rf[K];

void pre()
{
    f[0] = ban(1);
    for (int i = 1; i < K; ++i)
        f[i] = f[i - 1] * ban(i);
    rf[K - 1] = ast(f[K - 1], M - 2);
    for (int i = K - 2; i >= 0; --i)
        rf[i] = rf[i + 1] * ban(i + 1);
}

ban C(int n, int k)
{
    return (f[n] * rf[k] * rf[n - k]);
}

int n, m, k;
ban dp[N][N];

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    if (m == 1)
    {
        printf("%lld\n", ast(k, n).x);
        return;
    }
    dp[0][0] = ban(1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            dp[i + 1][j] = dp[i + 1][j] + dp[i][j] * ban(j);
            dp[i + 1][j + 1] = dp[i + 1][j + 1] + dp[i][j];
        }
    }
    ban ans;
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 0; y <= x; ++y)
        {
            if (k < 2 * x - y)
                continue;
            ban yans(1);
            yans = yans * C(k, 2 * x - y);
            yans = yans * C(2 * x - y, y);
            yans = yans * C(2 * x - 2 * y, x - y);
            yans = yans * dp[n][x];
            yans = yans * f[x];
            yans = yans * dp[n][x];
            yans = yans * f[x];
            yans = yans * ast(y, n * m - n * 2);
            ans = ans + yans;
        }
    }
    printf("%lld\n", ans.x);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}