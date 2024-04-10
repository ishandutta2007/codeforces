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
const int N = 1000006, M = 998244353;

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

int f[N], rf[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;
}

int C(int n, int k)
{
    return (f[n] * 1LL * rf[k]) % M * rf[n - k] % M;
}

int n, m;
int x[N], y[N];

/*int c[N];
int dp[N][N];

int F0(int n, int q)
{
    memset(c, 0, sizeof c);
            memset(dp, 0, sizeof dp);
            for (int i = 2; i <= q + 1; ++i)
                c[i] = 1;

            dp[0][0] = 1;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (c[i])
                    {
                        for (int k = 0; k < j; ++k)
                        {
                            dp[i][j] += dp[i - 1][k];
                        }
                    }
                    else
                    {
                        for (int k = 0; k <= j; ++k)
                        {
                            dp[i][j] += dp[i - 1][k];
                        }
                    }
                }
            }

            int ans = 0;
            for (int j = 1; j <= n; ++j)
                ans += dp[n][j];
    return ans;
}*/

int F(int n, int q)
{
    q = n - q;
    --q;
    ++n;
    return C(n + q - 1, q);
}

int t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = (t[pos * 2] + t[pos * 2 + 1]);
}

int qry(int tl, int tr, int q, int pos)
{
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    if ((m - tl + 1) - t[pos * 2] >= q)
        return qry(tl, m, q, pos * 2);
    return qry(m + 1, tr, q - ((m - tl + 1) - t[pos * 2]), pos * 2 + 1);
}

void solv()
{
    /*for (n = 1; n <= 10; ++n)
    {
        for (int q = n - 1; q >= 0; --q)
        {
            if (F0(n, q) != F(n, q))
            {
                cout << n << ' ' << q << "\n";
                F(n, q);
                return;
            }
        }
    }*/
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> x[i] >> y[i];

    int q = 0;
    set<int> s;
    vector<int> v;
    for (int i = m; i >= 1; --i)
    {
        int u = qry(1, n, y[i], 1);
        v.push_back(u);
        ubd(1, n, u, 1, 1);
        if (u != n && s.find(u + 1) == s.end())
            ++q;
        s.insert(u);
    }

    cout << F(n, q) << "\n";

    for (int i = 0; i < sz(v); ++i)
        ubd(1, n, v[i], 0, 1);
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
        solv();
    return 0;
}