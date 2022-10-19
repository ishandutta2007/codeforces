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
const int N = 18;

char u[300];

bool stg(ll x)
{
    bool c[16] = {};

    ll y = x;
    while (y)
    {
        c[y % 16] = true;
        y /= 16;
    }

    y = 0;
    for (int i = 0; i < 16; ++i)
        y += c[i] * (1 << i);
    return ((x ^ y) < x);
}

ll dp[N][N][2][N];
ll P(char a[])
{
    int n = strlen(a);

    memset(dp, 0LL, sizeof dp);
    dp[0][0][1][16] = 1;
    for (int i = 0; i < n; ++i)
    {
        if (i < n - 4)
        {
            for (int j = 0; j < 16; ++j)
            {
                for (int k = 0; k < 16; ++k)
                {
                    dp[i + 1][max(j, k)][0][16] += dp[i][j][0][16];
                    if (k < u[a[i]])
                        dp[i + 1][max(j, k)][0][16] += dp[i][j][1][16];
                    else if (k == u[a[i]])
                        dp[i + 1][max(j, k)][1][16] += dp[i][j][1][16];
                }
            }
        }
        else
        {
            for (int j = 0; j < 16; ++j)
            {
                for (int k = 0; k < 16; ++k)
                {
                    for (int p = (n - i) * 4 - 1; p >= max(j, k); --p)
                    {
                        if (!((k << ((n - i - 1) * 4)) & (1 << p)))
                            continue;
                        dp[i + 1][max(j, k)][0][p] += dp[i][j][0][16];
                        if (k < u[a[i]])
                            dp[i + 1][max(j, k)][0][p] += dp[i][j][1][16];
                        else if (k == u[a[i]])
                            dp[i + 1][max(j, k)][1][p] += dp[i][j][1][16];
                    }
                    for (int p = 0; p < 17; ++p)
                    {
                        dp[i + 1][max(j, k)][0][p] += dp[i][j][0][p];
                        if (k < u[a[i]])
                            dp[i + 1][max(j, k)][0][p] += dp[i][j][1][p];
                        else if (k == u[a[i]])
                            dp[i + 1][max(j, k)][1][p] += dp[i][j][1][p];
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int j = 0; j < 16; ++j)
        ans += (dp[n][j][0][j] + dp[n][j][1][j]);
    return ans;
}

char l[N], r[N];
void solv()
{

    for (char i = '0'; i <= '9'; ++i)
        u[i] = i - '0';
    for (char i = 'a'; i <= 'f'; ++i)
        u[i] = 10 + i - 'a';

    int qq;
    cin >> qq;
    while (qq--)
    {
        cin >> l >> r;

        ll ans = P(r) - P(l);

        ll x = 0;
        for (int i = 0; i < strlen(l); ++i)
        {
            x = (x * 16 + u[l[i]]);
        }
        ans += stg(x);

        cout << ans << "\n";
    }
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