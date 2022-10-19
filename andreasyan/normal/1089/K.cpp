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
const int N = 1000006, n = 1000000;

struct ban
{
    ll l, r, s;
};

ban mer(const ban& l, const ban& r)
{
    if (r.l == r.r)
        return l;
    ban res;
    res.l = l.l;
    res.s = l.s + r.s;
    if (l.r - r.l <= r.r - r.l - r.s)
        res.r = r.r;
    else
        res.r = r.r + (l.r - r.l) - (r.r - r.l - r.s);
    return res;
}

ban t[N * 4];

void bil(int tl, int tr, int pos)
{
    t[pos].l = tl;
    t[pos].r = tl;
    t[pos].s = 0;
    if (tl == tr)
        return;
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
}

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos].r = tl + y;
        t[pos].s = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return mer(qry(tl, m, l, m, pos * 2),
               qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

int qq;
int tt[N], dd[N];

ll qryy(int t)
{
    vector<pair<int, int> > v;
    for (int i = 1; i <= qq; ++i)
    {
        if (dd[i] == 0)
            continue;
        if (tt[i] <= t)
            v.push_back(m_p(tt[i], dd[i]));
    }
    sort(all(v));
    ll u = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].fi >= u)
            u = v[i].fi + v[i].se;
        else
            u += v[i].se;
    }
    return max(0LL, u - t);
}

void solv()
{
    bil(1, n, 1);
    scanf("%d", &qq);
    for (int i = 1; i <= qq; ++i)
    {
        char ty;
        scanf(" %c", &ty);
        if (ty == '+')
        {
            int t, d;
            scanf("%d%d", &t, &d);
            tt[i] = t;
            dd[i] = d;
            ubd(1, n, t, d, 1);
        }
        else if (ty == '-')
        {
            int i;
            scanf("%d", &i);
            int t = tt[i];
            dd[i] = 0;
            ubd(1, n, t, 0, 1);
        }
        else
        {
            int t;
            scanf("%d", &t);
            //printf("%I64d\n", qryy(t));
            //continue;
            printf("%I64d\n", max(0LL, qry(1, n, 1, t, 1).r - t));
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}