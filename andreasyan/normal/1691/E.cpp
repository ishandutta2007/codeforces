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

int n;
int p[N];

int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}
void kpc(int x, int y)
{
    if (x == 0 || y == 0)
        return;
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

vector<int> v[N * 4][2];

void ubd(int tl, int tr, int l, int r, int c, int i, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        v[pos][c].push_back(i);
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), c, i, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, c, i, pos * 2 + 1);
}

pair<int, int> qry(int tl, int tr, int x0, int x1, int pos)
{
    if (!x0 && !v[pos][0].empty())
        x0 = v[pos][0][0];
    if (!x1 && !v[pos][1].empty())
        x1 = v[pos][1][0];

    for (int i = 0; i < sz(v[pos][0]); ++i)
    {
        kpc(x1, v[pos][0][i]);
    }
    for (int i = 0; i < sz(v[pos][1]); ++i)
    {
        kpc(x0, v[pos][1][i]);
    }

    if (tl == tr)
    {
        pair<int, int> u = m_p(0, 0);
        if (!u.fi && !v[pos][0].empty())
            u.fi = v[pos][0][0];
        if (!u.se && !v[pos][1].empty())
            u.se = v[pos][1][0];

        v[pos][0].clear();
        v[pos][1].clear();
        return u;
    }

    int m = (tl + tr) / 2;
    pair<int, int> u = qry(tl, m, x0, x1, pos * 2);
    pair<int, int> u1 = qry(m + 1, tr, x0, x1, pos * 2 + 1);
    if (u1.fi && !u.fi)
        u.fi = u1.fi;
    if (u1.se && !u.se)
        u.se = u1.se;
    if (!u.fi && !v[pos][0].empty())
        u.fi = v[pos][0][0];
    if (!u.se && !v[pos][1].empty())
        u.se = v[pos][1][0];

    for (int i = 0; i < sz(v[pos][0]); ++i)
    {
        kpc(u.se, v[pos][0][i]);
    }
    for (int i = 0; i < sz(v[pos][1]); ++i)
    {
        kpc(u.fi, v[pos][1][i]);
    }

    v[pos][0].clear();
    v[pos][1].clear();
    return u;
}

int c[N], l[N], r[N];
void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
    }

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i] >> l[i] >> r[i];
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    sort(all(v));

    for (int i = 1; i <= n; ++i)
    {
        l[i] = lower_bound(all(v), l[i]) - v.begin() + 1;
        r[i] = lower_bound(all(v), r[i]) - v.begin() + 1;
        ubd(1, n * 2, l[i], r[i], c[i], i, 1);
    }
    qry(1, n * 2, 0, 0, 1);

    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    for (int i = 1; i <= n; ++i)
        c[fi(i)] = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += c[i];

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