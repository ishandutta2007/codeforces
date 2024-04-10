#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
const long long INF = 1000000009000000009;

int n, q, s;

long long ans[N];

pair<long long, int> minu[N * 4];
long long laz[N * 4];

pair<long long, int> mer(const pair<long long, int>& l, const pair<long long, int>& r)
{
    if (l.first < r.first)
        return l;
    return r;
}

void shi(int pos)
{
    minu[pos * 2].first = min(minu[pos * 2].first, laz[pos]);
    laz[pos * 2] = min(laz[pos * 2], laz[pos]);
    minu[pos * 2 + 1].first = min(minu[pos * 2 + 1].first, laz[pos]);
    laz[pos * 2 + 1] = min(laz[pos * 2 + 1], laz[pos]);
    laz[pos] = INF;
}

void bil_minu(int tl, int tr, int pos)
{
    minu[pos] = m_p(INF, tl);
    laz[pos] = INF;
    if (tl == tr)
    {
        return;
    }
    int m = (tl + tr) / 2;
    bil_minu(tl, m, pos * 2);
    bil_minu(m + 1, tr, pos * 2 + 1);
}

void ubd_minu(int tl, int tr, int l, int r, long long y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        minu[pos].first = min(minu[pos].first, y);
        laz[pos] = min(laz[pos], y);
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd_minu(tl, m, l, min(m, r), y, pos * 2);
    ubd_minu(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    minu[pos] = mer(minu[pos * 2], minu[pos * 2 + 1]);
}

bool c[N];
void ubd_c(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        c[x] = true;
        minu[pos].first = INF;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd_c(tl, m, x, pos * 2);
    else
        ubd_c(m + 1, tr, x, pos * 2 + 1);
    minu[pos] = mer(minu[pos * 2], minu[pos * 2 + 1]);
}

vector<pair<pair<int, int>, int> > v[N * 4];
void ubd_v(int tl, int tr, int l, int r, pair<pair<int, int>, int> y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        v[pos].push_back(y);
        return;
    }
    int m = (tl + tr) / 2;
    ubd_v(tl, m, l, min(m, r), y, pos * 2);
    ubd_v(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

bool c1[N];
void qry_v(int tl, int tr, int x, int pos)
{
    while (!v[pos].empty())
    {
        pair<pair<int, int>, int> u = v[pos].back();
        v[pos].pop_back();
        if (c1[u.second])
            continue;
        c1[u.second] = true;
        ubd_minu(1, n, u.first.first, u.first.first, u.first.second + ans[x], 1);
    }
    if (tl == tr)
        return;
    int m = (tl + tr) / 2;
    if (x <= m)
        qry_v(tl, m, x, pos * 2);
    else
        qry_v(m + 1, tr, x, pos * 2 + 1);
}

vector<pair<pair<int, int>, int> > g[N];

void solv()
{
    scanf("%d%d%d", &n, &q, &s);
    for (int i = 0; i < q; ++i)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int x, y, d;
            scanf("%d%d%d", &x, &y, &d);
            g[x].push_back(m_p(m_p(y, y), d));
        }
        else if (ty == 2)
        {
            int x, l, r, d;
            scanf("%d%d%d%d", &x, &l, &r, &d);
            g[x].push_back(m_p(m_p(l, r), d));
        }
        else
        {
            int x, l, r, d;
            scanf("%d%d%d%d", &x, &l, &r, &d);
            ubd_v(1, n, l, r, m_p(m_p(x, d), i), 1);
        }
    }
    for (int i = 1; i <= n; ++i)
        ans[i] = -1;
    bil_minu(1, n, 1);
    ubd_minu(1, n, s, s, 0, 1);
    while (1)
    {
        if (minu[1].first == INF)
            break;
        int x = minu[1].second;
        long long d = minu[1].first;
        if (c[x])
        {
            ubd_c(1, n, x, 1);
            continue;
        }
        ubd_c(1, n, x, 1);
        ans[x] = d;
        for (int i = 0; i < g[x].size(); ++i)
        {
            ubd_minu(1, n, g[x][i].first.first, g[x][i].first.second, d + g[x][i].second, 1);
        }
        qry_v(1, n, x, 1);
    }
    for (int i = 1; i <= n; ++i)
        printf("%lld ", ans[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}