#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1000006, INF = 1000000009;

int n;
vector<pair<char, int> > a[N];
int k;
int c[N];

int q[N];

void dfs0(int x)
{
    if (c[x])
        q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].second;
        dfs0(h);
        q[x] += q[h];
    }
}

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
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return INF;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int dp[N];

vector<int> v;
void dfs(int x, int p)
{
    int uu;
    if (v.empty())
        uu = 0;
    else
        uu = v.back();
    if (x)
    {
        dp[x] = dp[p] + 1;
        if (c[x])
            dp[x] = min(dp[x], uu + qry(0, n, 0, v.size() - 1, 1) + 1);
    }
    ubd(0, n, v.size(), dp[x] - uu, 1);
    int qq;
    if (c[x])
        qq = 1;
    else
        qq = 0;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].second;
        v.push_back(uu + qq);
        dfs(h, x);
        v.pop_back();
        qq += q[h];
    }
}

int ans[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int p;
        char c;
        scanf("%d %c", &p, &c);
        a[p].push_back(m_p(c, i));
    }
    for (int i = 0; i <= n; ++i)
        sort(a[i].begin(), a[i].end());
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i)
    {
        int x;
        scanf("%d", &x);
        c[x] = i;
    }
    dfs0(0);
    dfs(0, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            ans[c[i]] = dp[i];
    }
    for (int i = 1; i <= k; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}