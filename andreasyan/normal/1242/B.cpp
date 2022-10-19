#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
vector<int> a[N];

int t[N * 4];
void bil(int tl, int tr, int pos)
{
    t[pos] = tl;
    if (tl == tr)
        return;
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return -1;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos] = -1;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}

void dfs(int x)
{
    ubd(1, n, x, 1);
    int l = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int r = a[x][i] - 1;
        while (1)
        {
            int h = qry(1, n, l, r, 1);
            if (h == -1)
                break;
            dfs(h);
        }
        l = a[x][i] + 1;
    }
    int r = n;
    while (1)
    {
        int h = qry(1, n, l, r, 1);
        if (h == -1)
            break;
        dfs(h);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        sort(a[i].begin(), a[i].end());
    bil(1, n, 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (qry(1, n, i, i, 1) != -1)
        {
            ++ans;
            dfs(i);
        }
    }
    cout << ans - 1 << endl;
    return 0;
}