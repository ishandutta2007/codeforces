#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 300005;

int n;
int a[N], b[N];

vector<int> va[N], vb[N];

int u[N];

int t[N * 4];

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = max(t[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

bool solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        va[i].clear();
        vb[i].clear();
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        va[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &b[i]);
        vb[b[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (va[i].size() != vb[i].size())
            return false;
        for (int j = 0; j < va[i].size(); ++j)
            u[va[i][j]] = vb[i][j];
    }
    for (int i = 0; i < (n + 5) * 4; ++i)
        t[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (qry(1, n, 1, a[i], 1) > u[i])
            return false;
        ubd(1, n, a[i], u[i], 1);
    }
    return true;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}