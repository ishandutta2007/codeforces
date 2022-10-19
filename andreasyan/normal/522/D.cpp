#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 500005;

int n, m;
int a[N];
vector<pair<int, int> > v[N];

int t[N * 4];

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = min(t[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return N;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int ans[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        v[r].push_back(m_p(l, i));
    }
    for (int i = 0; i < N * 4; ++i)
        t[i] = N;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        if (mp.find(a[i]) != mp.end())
            ubd(1, n, mp[a[i]], i - mp[a[i]], 1);
        mp[a[i]] = i;
        for (int j = 0; j < v[i].size(); ++j)
        {
            ans[v[i][j].second] = qry(1, n, v[i][j].first, i, 1);
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        if (ans[i] == N)
            ans[i] = -1;
        printf("%d\n", ans[i]);
    }
    return 0;
}