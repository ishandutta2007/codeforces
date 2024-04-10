#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n, m;
int a[N];
int u[N];

vector<pair<int, int> > v[N];
vector<int> vv[N];

int t[N * 4];
void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos]++;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int ans[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        u[a[i]] = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        v[r].push_back(m_p(l, i));
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; j += i)
        {
            if (u[i] < u[j])
                vv[u[j]].push_back(u[i]);
            else
                vv[u[i]].push_back(u[j]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < vv[i].size(); ++j)
            ubd(1, n, vv[i][j], 1);
        for (int j = 0; j < v[i].size(); ++j)
            ans[v[i][j].second] = qry(1, n, v[i][j].first, i, 1);
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
    return 0;
}