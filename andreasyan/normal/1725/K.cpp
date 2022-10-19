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
const int N = 400005, m = 20, M = 1000000000;

int n;
int a[N];
int q;
int u[N];

vector<pair<int, int> > qv[N];
vector<int> qi[N];

int minu[N * 2 * 4];

vector<pair<int, int> > v;

int mer(int x, int y)
{
    int xx = x;
    if (xx >= sz(v))
        xx -= sz(v);
    int yy = y;
    if (yy >= sz(v))
        yy -= sz(v);
    if (xx < yy)
        return x;
    return y;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        minu[pos] = mer(minu[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l),r, y, pos * 2 + 1);
}

int qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        return minu[pos];
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        return mer(qry(tl, m, x, pos * 2), minu[pos]);
    return mer(qry(m + 1, tr, x, pos * 2 + 1), minu[pos]);
}

int p[N * 2][m];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> g;
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int x, y;
            cin >> x >> y;
            u[x] = sz(v);
            a[x] = y;
        }
        else if (ty == 2)
        {
            int x;
            cin >> x;
            g.push_back(a[x]);
            qv[u[x]].push_back(m_p(a[x], sz(v) - 1));
            qi[u[x]].push_back(i);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            g.push_back(l - 1);
            g.push_back(r + 1);
            v.push_back(m_p(l, r));
        }
    }
    sort(all(g));

    vector<pair<int, int> > yans;
    for (int i = 0; i < N * 2 * 4; ++i)
        minu[i] = sz(v) * 2;
    for (int j = 0; j < m; ++j)
        p[sz(v) * 2][j] = sz(v) * 2;
    for (int j = 0; j < sz(qv[sz(v)]); ++j)
    {
        yans.push_back(m_p(qi[sz(v)][j], qv[sz(v)][j].fi));
    }
    for (int i = sz(v) - 1; i >= 0; --i)
    {
        int l = v[i].fi, r = v[i].se;
        ubd(0, sz(g), lower_bound(all(g), l) - g.begin(), upper_bound(all(g), (l + r) / 2) - g.begin() - 1, i, 1);
        ubd(0, sz(g), lower_bound(all(g), (l + r) / 2 + 1) - g.begin(), upper_bound(all(g), r) - g.begin() - 1, i + sz(v), 1);

        p[i][0] = qry(0, sz(g), lower_bound(all(g), l - 1) - g.begin(), 1);
        p[i + sz(v)][0] = qry(0, sz(g), lower_bound(all(g), r + 1) - g.begin(), 1);
        for (int j = 1; j < m; ++j)
        {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
        for (int j = 1; j < m; ++j)
        {
            p[i + sz(v)][j] = p[p[i + sz(v)][j - 1]][j - 1];
        }

        for (int j = 0; j < sz(qv[i]); ++j)
        {
            int ans = qv[i][j].fi;
            int u = qv[i][j].se;
            int x = qry(0, sz(g), lower_bound(all(g), qv[i][j].fi) - g.begin(), 1);
            if (x < sz(v))
            {
                if (x <= u)
                    ans = v[x].fi - 1;
            }
            else
            {
                if (x - sz(v) <= u)
                    ans = v[x - sz(v)].se + 1;
            }
            for (int j = m - 1; j >= 0; --j)
            {
                int sx = x;
                x = p[x][j];
                if (x < sz(v))
                {
                    if (x <= u)
                        ans = v[x].fi - 1;
                    else
                        x = sx;
                }
                else
                {
                    if (x - sz(v) <= u)
                        ans = v[x - sz(v)].se + 1;
                    else
                        x = sx;
                }
            }

            yans.push_back(m_p(qi[i][j], ans));
        }
    }

    sort(all(yans));
    for (int i = 0; i < sz(yans); ++i)
        cout << yans[i].se << "\n";
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