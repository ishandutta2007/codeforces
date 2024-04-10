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
const int N = 1503, M = 998244353;

int n;
int a[N][N];

int p[N];
int qk[N];
vector<int> dp[N];

int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);

    p[x] = y;
    qk[y] += qk[x];

    vector<int> ndp;
    ndp.assign(sz(dp[x]) + sz(dp[y]) - 1, 0);
    for (int i = 1; i < sz(dp[x]); ++i)
    {
        for (int j = 1; j < sz(dp[y]); ++j)
        {
            ndp[i + j] = (ndp[i + j] + dp[x][i] * 1LL * dp[y][j]) % M;
        }
    }
    dp[y] = ndp;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }

    vector<pair<int, pair<int, int> > > v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            v.push_back(m_p(a[i][j], m_p(i, j)));
        }
    }
    sort(all(v));

    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
        qk[i] = 0;
        dp[i].push_back(0);
        dp[i].push_back(1);
    }

    for (int i = 0; i < sz(v); ++i)
    {
        int x = v[i].se.fi;
        int y = v[i].se.se;

        if (fi(x) != fi(y))
            kpc(x, y);
        ++qk[fi(x)];

        if (qk[fi(x)] == (sz(dp[fi(x)]) - 1) * (sz(dp[fi(x)]) - 2) / 2)
            dp[fi(x)][1] = (dp[fi(x)][1] + 1) % M;
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << dp[fi(1)][i] << ' ';
    }
    cout << "\n";
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