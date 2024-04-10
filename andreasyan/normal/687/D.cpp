#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
const int N = 1003;

struct ban
{
    int i;
    int x, y, d;
};
bool operator<(const ban& a, const ban& b)
{
    return a.d < b.d;
}
bool soi(const ban& a, const ban& b)
{
    return a.i < b.i;
}

int n, m, q;
ban a[N * N];

int p[N];
int r[N];

vector<int> v;

int fi(int x)
{
    if (p[x] == x)
        return x;
    v.push_back(x);
    return p[x] = fi(p[x]);
}

int kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);

    if (x == y)
        return -1;

    v.push_back(x);
    v.push_back(y);
    r[x] = fi(r[x]);
    r[y] = fi(r[y]);
    v.push_back(r[x]);
    v.push_back(r[y]);

    if (p[r[x]] == y && p[r[y]] == x)
        return 0;

    if (r[x])
    {
        p[r[x]] = y;
    }
    if (r[y])
    {
        p[r[y]] = x;
    }

    r[x] = y;
    r[y] = x;

    return 1;
}

vector<int> t[N * N * 2];

void bil(int tl, int tr, int pos)
{
    if (tl != tr)
    {
        int m = (tl + tr) / 2;
        bil(tl, m, pos * 2);
        bil(m + 1, tr, pos * 2 + 1);

        vector<ban> v;

        int j = m + 1;
        for (int i = tl; i <= m; ++i)
        {
            while (j <= tr && a[j].d <= a[i].d)
                v.push_back(a[j++]);
            v.push_back(a[i]);
        }
        while (j <= tr)
            v.push_back(a[j++]);
        for (int i = tl; i <= tr; ++i)
            a[i] = v[i - tl];
    }

    for (int i = tr; i >= tl; --i)
    {
        int kk = kpc(a[i].x, a[i].y);
        if (kk == -1)
        {
            t[pos].push_back(a[i].i);
            break;
        }
        else if (kk == 1)
        {
            t[pos].push_back(a[i].i);
        }
    }
    for (int i = sz(v) - 1; i >= 0; --i)
    {
        p[v[i]] = v[i];
        r[v[i]] = 0;
    }
    v.clear();
}

vector<ban> u;
void qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        for (int i = 0; i < sz(t[pos]); ++i)
            u.push_back(a[t[pos][i]]);
        return;
    }
    int m = (tl + tr) / 2;
    qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    qry(tl, m, l, min(m, r), pos * 2);
}

void solv()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i)
    {
        a[i].i = i;
        cin >> a[i].x >> a[i].y >> a[i].d;
    }
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
    }

    bil(1, m, 1);

    sort(a + 1, a + m + 1, soi);

    for (int i = 1; i <= q; ++i)
    {
        int L, R;
        cin >> L >> R;

        u.clear();
        qry(1, m, L, R, 1);
        sort(all(u));

        int ans = -1;
        for (int j = sz(u) - 1; j >= 0; --j)
        {
            if (kpc(u[j].x, u[j].y) == -1)
            {
                ans = u[j].d;
                break;
            }
        }

        for (int i = sz(v) - 1; i >= 0; --i)
        {
            p[v[i]] = v[i];
            r[v[i]] = 0;
        }
        v.clear();

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