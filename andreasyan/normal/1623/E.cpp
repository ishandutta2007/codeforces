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

int n, k;
char a[N];
int l[N], r[N];
int p[N];

int tin[N], tout[N], ti;
int d[N];
vector<int> v;
void rec(int x)
{
    if (x == 0)
        return;
    d[x] = d[p[x]] + 1;

    tin[x] = ++ti;

    rec(l[x]);
    v.push_back(x);
    rec(r[x]);

    tout[x] = ti;
}

bool so(int x, int y)
{
    return tin[x] < tin[y];
}

bool c[N];

bool b[N * 4];
void ubdb(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        b[pos] = true;
        return;
    }
    int m = (tl + tr) / 2;
    ubdb(tl, m, l, min(m, r), pos * 2);
    ubdb(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

int qryb(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return b[pos];
    int m = (tl + tr) / 2;
    if (x <= m)
        return (qryb(tl, m, x, pos * 2) || b[pos]);
    return (qryb(m + 1, tr, x, pos * 2 + 1) || b[pos]);
}

int t[N * 4];
void ubd(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos]++;
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

int qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos];
    int m = (tl + tr) / 2;
    if (x <= m)
        return (qry(tl, m, x, pos * 2) + t[pos]);
    return (qry(m + 1, tr, x, pos * 2 + 1) + t[pos]);
}

void tp(int x)
{
    if (x == 0)
        return;
    tp(l[x]);
    putchar(a[x]);
    if (c[x])
        putchar(a[x]);
    tp(r[x]);
}

void solv()
{
    cin >> n >> k;
    cin >> (a + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> l[i] >> r[i];
        p[l[i]] = p[r[i]] = i;
    }

    rec(1);

    for (int i = 0; i < n - 1; ++i)
    {
        if (a[v[i]] != a[v[i + 1]])
        {
            vector<int> vv;
            for (int j = i; j >= 0; --j)
            {
                if (a[v[j]] != a[v[i]])
                    break;
                vv.push_back(v[j]);
            }
            sort(all(vv), so);

            if (a[v[i]] > a[v[i + 1]])
            {
                for (int i = 0; i < sz(vv); ++i)
                {
                    int x = vv[i];
                    if (c[x])
                        continue;
                    ubdb(1, n, tin[x], tout[x], 1);
                }
            }
            else
            {
                for (int i = 0; i < sz(vv); ++i)
                {
                    int x = vv[i];
                    if (qryb(1, n, tin[x], 1))
                        continue;
                    if (d[x] - qry(1, n, tin[x], 1) <= k)
                    {
                        while (1)
                        {
                            if (x == 0 || c[x])
                                break;
                            c[x] = true;
                            --k;
                            ubd(1, n, tin[x], tout[x], 1);
                            x = p[x];
                        }
                    }
                }
            }
        }
    }

    tp(1);
    putchar('\n');
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