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
const int N = 300005;
const ll INF = 1000000009000000009;

int n;
int a[N];

ll p[2][N];

vector<pair<ll, int> > v[2][N];

ll maxu[2][N * 4];

void ubd(int ti, int tl, int tr, int x, ll y, int pos)
{
    if (tl == tr)
    {
        maxu[ti][pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(ti, tl, m, x, y, pos * 2);
    else
        ubd(ti, m + 1, tr, x, y, pos * 2 + 1);
    maxu[ti][pos] = max(maxu[ti][pos * 2], maxu[ti][pos * 2 + 1]);
}

int qry(int ti, int tl, int tr, int l, int r, ll y, int pos)
{
    if (l > r)
        return n;
    if (tl == l && tr == r)
    {
        if (maxu[ti][pos] <= y)
            return n;
    }
    if (tl == tr)
        return tl - 1;
    int m = (tl + tr) / 2;
    int u = qry(ti, tl, m, l, min(m, r), y, pos * 2);
    if (u != n)
        return u;
    return qry(ti, m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        p[0][i] = p[0][i - 1];
        p[1][i] = p[1][i - 1];
        p[(i % 2)][i] += a[i];
        p[1 - (i % 2)][i] -= a[i];
    }

    ll ans = 0;
    /*for (int l = 1; l <= n; ++l)
    {
        for (int i = l + 1; i <= n; ++i)
        {
            if (p[(i - 1) % 2][i - 1] - a[i] > p[(i - 1) % 2][l - 1])
                break;
            if (p[(i - 1) % 2][i - 1] - a[i] == p[(i - 1) % 2][l - 1])
                ++ans;
        }
    }*/

    for (int z = 0; z < 2; ++z)
    {
        for (int i = 1; i <= n; ++i)
        {
            v[z][i].clear();
        }
    }

    for (int i = n; i >= 1; --i)
    {
        int u = min(qry(0, 1, n, i + 1, n, p[0][i - 1], 1), qry(1, 1, n, i + 1, n, p[1][i - 1], 1));

        v[0][u].push_back(m_p(p[0][i - 1], 1));
        v[0][i - 1].push_back(m_p(p[0][i - 1], -1));
        v[1][u].push_back(m_p(p[1][i - 1], 1));
        v[1][i - 1].push_back(m_p(p[1][i - 1], -1));

        ubd((i - 1) % 2, 1, n, i, p[(i - 1) % 2][i - 1] - a[i], 1);
        ubd(1 - (i - 1) % 2, 1, n, i, -INF, 1);

    }

    map<ll, int> mp[2];
    for (int i = 1; i <= n; ++i)
    {
        mp[(i - 1) % 2][p[(i - 1) % 2][i - 1] - a[i]]++;
        for (int z = 0; z < 2; ++z)
        {
            for (int j = 0; j < sz(v[z][i]); ++j)
            {
                if (mp[z].find(v[z][i][j].fi) != mp[z].end())
                    ans += v[z][i][j].se * 1LL * mp[z][v[z][i][j].fi];
            }
        }
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

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}