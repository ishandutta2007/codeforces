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
const int N = 102, M = 100005;

int n, m, qq;
ll a[N];
ll b[M];

ll maxu[M * 4];
ll laz[M * 4];

struct ban1
{
    ll s, laz1, laz2;
    ban1()
    {
        s = laz1 = laz2 = 0;
    }
};

ban1 t1[M * 4];

ll sum(int d)
{
    return d * 1LL * (d + 1) / 2;
}

void shi(int pos)
{
    if (laz[pos] == 0)
        return;
    ll ylaz = laz[pos];
    maxu[pos * 2] += ylaz;
    laz[pos * 2] += ylaz;

    maxu[pos * 2 + 1] += ylaz;
    laz[pos * 2 + 1] += ylaz;
    laz[pos] = 0;
}

void shi1(int tl, int tr, int pos)
{
    if (t1[pos].laz1 == 0 && t1[pos].laz2 == 0)
        return;

    int m = (tl + tr) / 2;

    ll laz1 = t1[pos].laz1;
    ll laz2 = t1[pos].laz2;

    t1[pos * 2].s += sum(m - tl + 1) * laz1 + laz2 * (m - tl + 1);
    t1[pos * 2].laz1 += laz1;
    t1[pos * 2].laz2 += laz2;

    laz2 += laz1 * (m - tl + 1);

    t1[pos * 2 + 1].s += sum(tr - m) * laz1 + laz2 * (tr - m);
    t1[pos * 2 + 1].laz1 += laz1;
    t1[pos * 2 + 1].laz2 += laz2;

    t1[pos].laz1 = t1[pos].laz2 = 0;
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        maxu[pos] = b[tl] - b[tl - 1];
        t1[pos].s = b[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);

    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
    t1[pos].s = t1[pos * 2].s + t1[pos * 2 + 1].s;
}

void ubd(int tl, int tr, int l, int r, ll y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        maxu[pos] += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);

    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, ll y, int pos)
{
    if (l > r)
        return M;
    if (tl == l && tr == r)
    {
        if (maxu[pos] <= y)
            return M;
    }
    if (tl == tr)
    {
        return tl;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    int u = qry(tl, m, l, min(m, r), y, pos * 2);
    if (u < M)
        return u;
    return qry(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

void ubd1(int tl, int tr, int l, int r, ll y1_, ll y2, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t1[pos].s += sum(r - l + 1) * y1_ + y2 * (r - l + 1);
        t1[pos].laz1 += y1_;
        t1[pos].laz2 += y2;
        return;
    }
    shi1(tl, tr, pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd1(tl, m, l, r, y1_, y2, pos * 2);
    else if (l > m)
        ubd1(m + 1, tr, l, r, y1_, y2, pos * 2 + 1);
    else
    {
        ubd1(tl, m, l, m, y1_, y2, pos * 2);
        ubd1(m + 1, tr, m + 1, r, y1_, y2 + (m - l + 1) * y1_, pos * 2 + 1);
    }

    t1[pos].s = t1[pos * 2].s + t1[pos * 2 + 1].s;
}

ll qry1(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
    {
        return t1[pos].s;
    }
    shi1(tl, tr, pos);
    int m = (tl + tr) / 2;
    return qry1(tl, m, l, min(m, r), pos * 2) +
            qry1(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

void solv()
{
    cin >> n >> m >> qq;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];

    bil(1, m, 1);

    while (qq--)
    {
        int ty, k, d;
        cin >> ty >> k >> d;
        if (ty == 1)
        {
            for (int i = n - k + 1; i <= n; ++i)
                a[i] += d * (i - (n - k));
        }
        else
        {
            ubd(1, m, m - k + 1, m, d, 1);
            ubd1(1, m, m - k + 1, m, d, 0, 1);
        }

        ll ans = 0;
        int j = 1;
        for (int i = 1; i <= n; ++i)
        {
            int u;
            if (i == n)
                u = m;
            else
                u = qry(1, m, j + 1, m, a[i + 1] - a[i], 1) - 1;

            u = min(u, m);
            ans += qry1(1, m, j, u, 1);
            ans += (u - j + 1) * a[i];

            j = u;
        }


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