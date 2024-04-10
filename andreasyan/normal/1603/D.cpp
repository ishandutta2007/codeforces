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
const int N = 100005;
const int m = 18;
const ll INF = 1000000009000000009;

int g[N];
int u[N];

int p[N];

ll rec0(int l, int r, int m)
{
    if ((m / l) == (m / r))
        return (m / l) * 1LL * (m / l + 1) / 2 * 1LL * (p[r] - p[l - 1]);

    int mid = (l + r) / 2;
    return rec0(l, mid, m) + rec0(mid + 1, r, m);
}

ll f[N];

ll rec1(int l, int r, int m)
{
    if (l > r)
        return 0;
    if ((m / l) == (m / r))
        return (r - l + 1) * f[m / l];

    int mid = (l + r) / 2;
    return rec1(l, mid, m) + rec1(mid + 1, r, m);
}

ll dp[N][m];

void rec(int l, int r, int ul, int ur, int k)
{
    if (l > r)
        return;

    int m = (l + r) / 2;

    dp[m][k] = INF;
    int u;
    ll qq = rec1(ur + 2, m, m);
    for (int i = min(m, ur + 1); i >= ul + 1; --i)
    {
        qq += f[m / i];
        if (qq + dp[i - 1][k - 1] < dp[m][k])
        {
            dp[m][k] = qq + dp[i - 1][k - 1];
            u = i - 1;
        }
    }

    rec(l, m - 1, ul, u, k);
    rec(m + 1, r, u, ur, k);
}

void pre()
{
    int n = 100000;

    g[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (!u[i])
        {
            for (int j = i; j <= n; j += i)
                u[j] = i;
        }

        if ((i / u[i]) % u[i] == 0)
            g[i] = 0;
        else
            g[i] = g[i / u[i]] * -1;
    }

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + g[i];

    for (int i = 1; i <= n; ++i)
        f[i] = rec0(1, i, i);

    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
        dp[i][0] = INF;

    for (int j = 1; j < m; ++j)
    {
        dp[0][j] = 0;
        rec(1, n, 0, n, j);
    }
}

void solv()
{
    int n, k;
    cin >> n >> k;

    if (k >= m)
        cout << n << "\n";
    else
        cout << dp[n][k] << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}