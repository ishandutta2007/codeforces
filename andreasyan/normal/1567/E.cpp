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

int n, q;
int a[N];

struct ban
{
    ll ans;
    int l, r;
    int q;
    ban()
    {
        ans = 0;
        l = r = 0;
        q = 0;
    }
    ban(int x)
    {
        if (x == 1)
        {
            ans = 1;
            l = r = 1;
        }
        else
        {
            ans = 0;
            l = r = 0;
        }
        q = 1;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;

    res.l = l.l;
    if (l.l == l.q)
        res.l = l.q + r.l;

    res.r = r.r;
    if (r.r == r.q)
        res.r = r.q + l.r;

    res.q = l.q + r.q;

    res.ans = l.ans + r.ans;
    res.ans -= (l.r * 1LL * (l.r + 1) / 2);
    res.ans -= (r.l * 1LL * (r.l + 1) / 2);
    res.ans += ((l.r + r.l) * 1LL * (l.r + r.l + 1) / 2);

    return res;
}

ban t[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban((a[tl] <= a[tl + 1]));
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban((a[tl] <= a[tl + 1]));
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return ban();
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    bil(1, n, 1);

    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int x, y;
            cin >> x >> y;
            a[x] = y;
            if (x - 1 >= 1)
                ubd(1, n, x - 1, 1);
            ubd(1, n, x, 1);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << qry(1, n, l, r - 1, 1).ans + (r - l + 1) << "\n";
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

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}