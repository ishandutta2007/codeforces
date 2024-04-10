#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 500005, m = 500000;

int n;
int a[N];

vector<pair<int, int> > v[N];
int uu[N];
int u[N];

vector<int> q[N * 4];

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        q[pos].push_back(y);
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

int qry(int tl, int tr, int x, int pos)
{
    while (!q[pos].empty() && tr <= uu[q[pos].back()])
    {
        q[pos].pop_back();
    }
    if (!q[pos].empty())
        return q[pos].back();
    if (tl == tr)
    {
        return 0;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        return qry(tl, m, x, pos * 2);
    return qry(m + 1, tr, x, pos * 2 + 1);
}

int ans[N];
void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        v[r].push_back(m_p(l, i));
    }
    for (int i = 1; i <= n; ++i)
    {
        uu[a[i]] = u[a[i]];
        u[a[i]] = i;
        ubd(1, m, uu[a[i]] + 1, u[a[i]], a[i], 1);
        for (int j = 0; j < v[i].size(); ++j)
        {
            ans[v[i][j].second] = qry(1, m, v[i][j].first, 1);
        }
    }
    for (int i = 0; i < q; ++i)
        printf("%d\n", ans[i]);
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