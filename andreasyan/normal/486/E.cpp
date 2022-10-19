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
const int N = 100005, m = 100001;
const pair<int, int> M = m_p(997310591, 999838507);

bool prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

pair<int, int> sum(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi + b.fi) % M.fi, (a.se + b.se) % M.se);
}

pair<int, int> pro(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi * 1LL * b.fi) % M.fi, (a.se * 1LL * b.se) % M.se);
}

int n;
int a[N];

pair<int, pair<int, int> > mer(const pair<int, pair<int, int> >& l, const pair<int, pair<int, int> >& r)
{
    if (l.fi > r.fi)
        return l;
    if (l.fi < r.fi)
        return r;
    return m_p(l.fi, sum(l.se, r.se));
}

pair<int, pair<int, int> > p[N], s[N];

pair<int, pair<int, int> > t[N * 4];
void ubd(int tl, int tr, int x, pair<int, pair<int, int> > y, int pos)
{
    if (tl == tr)
    {
        t[pos] = mer(t[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

pair<int, pair<int, int> > qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(0, m_p(0, 0));
    if (tl == l && tr == r)
    {
        return t[pos];
    }
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    a[n + 1] = m;

    p[0] = m_p(0, m_p(1, 1));
    ubd(0, m, a[0], p[0], 1);
    for (int i = 1; i <= n; ++i)
    {
        p[i] = qry(0, m, 0, a[i] - 1, 1);
        p[i].fi++;
        ubd(0, m, a[i], p[i], 1);
    }

    for (int i = 0; i < N * 4; ++i)
        t[i] = m_p(0, m_p(0, 0));

    s[n + 1] = m_p(0, m_p(1, 1));
    ubd(0, m, a[n + 1], s[n + 1], 1);
    for (int i = n; i >= 1; --i)
    {
        s[i] = qry(0, m, a[i] + 1, m, 1);
        s[i].fi++;
        ubd(0, m, a[i], s[i], 1);
    }

    pair<int, pair<int, int> > yans = m_p(0, m_p(0, 0));
    for (int i = 1; i <= n; ++i)
    {
        yans = mer(yans, p[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (p[i].fi + s[i].fi - 1 != yans.fi)
            printf("1");
        else if (pro(p[i].se, s[i].se) == yans.se)
            printf("3");
        else
            printf("2");
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    /*int x = 990000000 + rnd() % 10000000;
    while (!prime(x))
        ++x;
    printf("%d\n", x);*/
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}