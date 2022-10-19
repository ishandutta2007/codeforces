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

struct ban
{
    int a, c;
};
bool operator<(const ban& a, const ban& b)
{
    return a.a < b.a;
}

int n;
ban a[N];

ll minu[N * 4];
void ubd(int tl, int tr, int x, ll y, int pos)
{
    if (tl == tr)
    {
        minu[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
}

ll qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return INF;
    if (tl == l && tr == r)
        return minu[pos];
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

ll minu1[N * 4];
void ubd1(int tl, int tr, int x, ll y, int pos)
{
    if (tl == tr)
    {
        minu1[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd1(tl, m, x, y, pos * 2);
    else
        ubd1(m + 1, tr, x, y, pos * 2 + 1);
    minu1[pos] = min(minu1[pos * 2], minu1[pos * 2 + 1]);
}

ll qry1(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return INF;
    if (tl == l && tr == r)
        return minu1[pos];
    int m = (tl + tr) / 2;
    return min(qry1(tl, m, l, min(m, r), pos * 2),
               qry1(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].a >> a[i].c;
    sort(a + 1, a + n + 1);

    for (int i = 0; i < N * 4; ++i)
        minu[i] = minu1[i] = INF;

    for (int i = n; i >= 1; --i)
    {
        int g = i;
        int l = i, r = n;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[m].a - a[i].a <= a[i].c)
            {
                g = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }

        ll u = qry(1, n, i + 1, g, 1);
        u = min(u, -a[i].a - a[i].c + qry1(1, n, g + 1, n, 1));
        if (i == n)
            u = 0;

        ubd(1, n, i, u, 1);
        ubd1(1, n, i, u + a[i].a, 1);
    }

    ll s = 0;
    for (int i = 1; i <= n; ++i)
        s += a[i].c;

    cout << qry(1, n, 1, 1, 1) + s << "\n";
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