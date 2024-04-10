#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1000006, INF = 1000000009;
struct ban
{
    int l, r;
};
bool operator<(const ban& a, const ban& b)
{
    return a.r < b.r;
}

int n;
ban a[N];

struct ban1
{
    int minu, mini;
    ban1()
    {
        minu = INF;
    }
    ban1(int minu, int mini)
    {
        this->minu = minu;
        this->mini = mini;
    }
};
ban1 mer(const ban1& l, const ban1& r)
{
    if (l.minu < r.minu)
        return l;
    return r;
}

ban1 t[N * 4];

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban1(y, x);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban1 qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return ban1();
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int m;
pair<int, int> b[N];

vector<int> g[N];
bool c[N];
void dfs(int x)
{
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        dfs(h);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].l, &a[i].r);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        vector<ban1> v;
        while (1)
        {
            ban1 u = qry(1, n + n, a[i].l, a[i].r, 1);
            if (u.minu > a[i].l)
                break;
            b[++m] = m_p(u.mini, a[i].r);
            v.push_back(u);
            ubd(1, n + n, u.mini, INF, 1);
            if (m == n)
            {
                printf("NO\n");
                return 0;
            }
        }
        for (int i = 0; i < v.size(); ++i)
            ubd(1, n + n, v[i].mini, v[i].minu, 1);
        ubd(1, n + n, a[i].r, a[i].l, 1);
    }
    for (int i = 1; i <= m; ++i)
    {
        g[b[i].first].push_back(b[i].second);
        g[b[i].second].push_back(b[i].first);
    }
    dfs(a[1].r);
    int q = 0;
    for (int i = 1; i <= n + n; ++i)
    {
        if (c[i])
            ++q;
    }
    if (q == n)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}