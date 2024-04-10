#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

bool stg(int x)
{
    while (x)
    {
        if (x % 10 != 4 && x % 10 != 7)
            return false;
        x /= 10;
    }
    return true;
}

vector<int> v;

int n, m;
int a[N];

char ty[N][10];
int ll[N], rr[N], d[N];

vector<int> vv[N];

int t[N * 4];

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry(int tl, int tr, int y, int pos)
{
    if (tl == tr)
    {
        if (y - t[pos] == 0)
            return tl;
        return -1;
    }
    int m = (tl + tr) / 2;
    if (y - t[pos * 2] <= 0)
        return qry(tl, m, y, pos * 2);
    return qry(m + 1, tr, y - t[pos * 2], pos * 2 + 1);
}

void ubd1(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (!t[pos])
        return;
    if (tl == tr)
    {
        t[pos] = 0;
        return;
    }
    int m = (tl + tr) / 2;
    ubd1(tl, m, l, min(m, r), pos * 2);
    ubd1(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry1(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry1(tl, m, l, min(m, r), pos * 2) +
            qry1(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

vector<int> b[N];

void solv()
{
    for (int i = 1; i <= 10000; ++i)
    {
        if (stg(i))
        {
            v.push_back(i);
        }
    }
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
    {
        scanf(" %s", &ty[i]);
        if (ty[i][0] == 'a')
            scanf("%d%d%d", &ll[i], &rr[i], &d[i]);
        else
            scanf("%d%d", &ll[i], &rr[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        if (ty[i][0] == 'a')
        {
            vv[ll[i]].push_back(i);
            vv[rr[i] + 1].push_back(-i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < vv[i].size(); ++j)
        {
            if (vv[i][j] < 0)
                ubd(1, m, -vv[i][j], 0, 1);
            else
                ubd(1, m, vv[i][j], d[vv[i][j]], 1);
        }
        for (int j = 0; j < v.size(); ++j)
        {
            if (a[i] >= v[j])
                continue;
            int u = qry(1, m, v[j] - a[i], 1);
            if (u != -1)
                b[u].push_back(i);
        }
    }
    memset(t, 0, sizeof t);
    for (int i = 1; i <= n; ++i)
    {
        if (stg(a[i]))
            ubd(1, n, i, 1, 1);
    }
    for (int i = 1; i <= m; ++i)
    {
        if (ty[i][0] == 'a')
        {
            ubd1(1, n, ll[i], rr[i], 1);
            for (int j = 0; j < b[i].size(); ++j)
                ubd(1, n, b[i][j], 1, 1);
        }
        else
            printf("%d\n", qry1(1, n, ll[i], rr[i], 1));
    }
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