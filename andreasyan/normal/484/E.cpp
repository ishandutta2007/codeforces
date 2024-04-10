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
const int N = 100005, L = 24;

int n;
pair<int, int> a[N];

struct ban
{
    int l, r, ans, s;
    ban()
    {
        ans = l = r = 0;
        s = 0;
    }
    ban(int x)
    {
        if (x == 0)
            ans = l = r = 0;
        else
            ans = l = r = 1;
        s = 1;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    if (l.s == l.l)
        res.l = l.s + r.l;
    else
        res.l = l.l;
    if (r.s == r.r)
        res.r = r.s + l.r;
    else
        res.r = r.r;
    res.ans = max(l.ans, r.ans);
    res.ans = max(res.ans, l.r + r.l);
    res.s = l.s + r.s;
    return res;
}

int z;
int ul[N * L], ur[N * L];

ban t[N * L];

int bil(int tl, int tr)
{
    int pos = ++z;
    t[pos].s = (tr - tl + 1);
    if (tl == tr)
        return pos;
    int m = (tl + tr) / 2;
    ul[pos] = bil(tl, m);
    ur[pos] = bil(m + 1, tr);
    return pos;
}

int ubd(int tl, int tr, int x, int pos)
{
    int ypos = ++z;
    ul[ypos] = ul[pos];
    ur[ypos] = ur[pos];
    if (tl == tr)
    {
        t[ypos] = ban(1);
        return ypos;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ul[ypos] = ubd(tl, m, x, ul[pos]);
    else
        ur[ypos] = ubd(m + 1, tr, x, ur[pos]);
    t[ypos] = mer(t[ul[ypos]], t[ur[ypos]]);
    return ypos;
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return ban();
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), ul[pos]),
               qry(m + 1, tr, max(m + 1, l), r, ur[pos]));
}

int root[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].fi);
        a[i].se = i;
    }
    sort(a + 1, a + n + 1);
    root[n + 1] = bil(1, n);
    for (int i = n; i >= 1; --i)
    {
        root[i] = ubd(1, n, a[i].se, root[i + 1]);
    }
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int l0, r0, d;
        scanf("%d%d%d", &l0, &r0, &d);
        int l = 1, r = n;
        int ans = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (qry(1, n, l0, r0, root[m]).ans >= d)
            {
                ans = a[m].fi;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        printf("%d\n", ans);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}