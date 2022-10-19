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
const int N = 200005;
const int M = 998244353;

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
    if (k < 0 || k > n)
        return 0;
    return (f[n] * 1LL * rf[k]) % M * rf[n - k] % M;
}

int n, m;
int q[N], t[N];

int s[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        s[pos] += y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    s[pos] = s[pos * 2] + s[pos * 2 + 1];
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return s[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        ++q[x];
    }
    for (int i = 1; i <= m; ++i)
        cin >> t[i];

    for (int i = 1; i < N; ++i)
    {
        if (q[i])
            ubd(1, N - 5, i, q[i], 1);
    }

    int yans = 1;
    int qq = 0;
    for (int i = 1; i < N; ++i)
    {
        qq += q[i];
        yans = (yans * 1LL * C(qq, q[i])) % M;
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (i == n + 1)
        {
            ans = (ans + yans) % M;
            break;
        }

        int yyans = yans;
        yyans = (yyans * 1LL * qry(1, N - 5, 1, t[i] - 1, 1)) % M;
        yyans = (yyans * 1LL * ast(qq, M - 2)) % M;
        ans = (ans + yyans) % M;

        if (q[t[i]])
        {
            yans = (yans * 1LL * q[t[i]]) % M;
            yans = (yans * 1LL * ast(qq, M - 2)) % M;
            --q[t[i]];
            --qq;
            ubd(1, N - 5, t[i], -1, 1);
        }
        else
            break;
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

    pre();

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}