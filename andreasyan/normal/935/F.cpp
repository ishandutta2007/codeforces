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
const ll INF = 1000000009000000009;

int n;
int a[N];

struct ban
{
    ll minu;
    int mini;
    bool hill;
    bool hl, hr;
    ll xl, xr;
    ll slop;
    ll sum;
    int q;
    ban(){}
    ban(int i, ll x)
    {
        minu = x;
        mini = i;
        hill = false;
        hl = hr = false;
        xl = xr = x;
        slop = INF;
        sum = 0;
        q = 1;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    if (l.minu < r.minu)
    {
        res.minu = l.minu;
        res.mini = l.mini;
    }
    else
    {
        res.minu = r.minu;
        res.mini = r.mini;
    }

    res.hill = (l.hill || r.hill);
    if (l.hr && l.xr >= r.xl)
        res.hill = true;
    if (r.hl && r.xl >= l.xr)
        res.hill = true;

    res.hl = l.hl;
    if (l.q == 1 && l.xr >= r.xl)
        res.hl = true;
    res.hr = r.hr;
    if (r.q == 1 && r.xl >= l.xr)
        res.hr = true;

    res.xl = l.xl;
    res.xr = r.xr;

    res.slop = min(l.slop, r.slop);
    res.slop = min(res.slop, abs(l.xr - r.xl));

    res.sum = l.sum + r.sum;
    res.sum = res.sum + abs(l.xr - r.xl);

    res.q = l.q + r.q;

    return res;
}

ban t[N * 4];
ll laz[N * 4];

void shii(int pos, ll u)
{
    t[pos].minu += u;
    t[pos].xl += u;
    t[pos].xr += u;
    laz[pos] += u;
}

void shi(int pos)
{
    if (!laz[pos])
        return;
    shii(pos * 2, laz[pos]);
    shii(pos * 2 + 1, laz[pos]);
    laz[pos] = 0;
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(tl, a[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (tl == l && tr == r)
    {
        shii(pos, y);
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, y, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, y, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, y, pos * 2);
        ubd(m + 1, tr, m + 1, r, y, pos * 2 + 1);
    }
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return mer(qry(tl, m, l, m, pos * 2),
               qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

ll get(int i)
{
    return qry(1, n, i, i, 1).xl;
}

ll pox(int i, int x)
{
    ll ans = t[1].sum;
    if (i > 1)
        ans -= abs(get(i - 1) - get(i));
    if (i < n)
        ans -= abs(get(i + 1) - get(i));
    if (i > 1)
        ans += abs(get(i - 1) - (get(i) + x));
    if (i < n)
        ans += abs(get(i + 1) - (get(i) + x));
    return ans;
}

ll qryy(int l, int r, int x)
{
    ban u = qry(1, n, l, r, 1);
    if (u.hill)
        return t[1].sum + 2 * x;

    ll ans = max(pox(l, x), pox(r, x));
    ans = max(ans, pox(u.mini, x));

    ll slop = INF;
    if (l <= u.mini - 1)
        slop = min(slop, qry(1, n, l, u.mini - 1, 1).slop);
    if (u.mini + 1 <= r)
        slop = min(slop, qry(1, n, u.mini + 1, r, 1).slop);

    if (slop != INF)
    {
        ans = max(ans, t[1].sum);
        if (x > slop)
            ans = max(ans, t[1].sum + 2 * (x - slop));
    }

    return ans;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    bil(1, n, 1);

    int qq;
    cin >> qq;
    while (qq--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            cout << qryy(l, r, x) << "\n";
        }
        else
        {
            int l, r, y;
            cin >> l >> r >> y;
            ubd(1, n, l, r, y, 1);
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}