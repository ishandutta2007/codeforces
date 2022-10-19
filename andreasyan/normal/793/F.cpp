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

int n, m;
int u[N];
vector<pair<int, int> > v[N];

pair<int, int> maxu[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        maxu[pos] = max(maxu[pos], m_p(y, x));
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

pair<int, int> qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(0, 0);
    if (tl == l && tr == r)
        return maxu[pos];
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int rec(int x)
{
    pair<int, int> u = qry(1, n, x, x, 1);
    pair<int, int> q = qry(1, n, x, u.fi, 1);
    if (q == u)
        return u.fi;
    u.fi = rec(q.se);
    ubd(1, n, x, u.fi, 1);
    return u.fi;
}

int ans[N];
void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        u[i] = i;
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        u[r] = l;
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        v[y].push_back(m_p(x, i));
    }

    for (int i = 1; i <= n; ++i)
    {
        ubd(1, n, i, i, 1);
    }

    for (int i = 1; i <= n; ++i)
    {
        ubd(1, n, u[i], i, 1);
        for (int j = 0; j < sz(v[i]); ++j)
        {
            ans[v[i][j].se] = rec(v[i][j].fi);
        }
    }

    for (int i = 0; i < m; ++i)
        cout << ans[i] << "\n";
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