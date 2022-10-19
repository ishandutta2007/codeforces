#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n, m;
vector<int> a[N];

vector<pair<int, int> > ans;

int s, f, ds, df;

bool c[N];

void dfs(int x)
{
    c[x] = true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs(h);
    }
}

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    scanf("%d%d%d%d", &s, &f, &ds, &df);
    if (ds > df)
    {
        swap(s, f);
        swap(ds, df);
    }
    c[s] = true;
    for (int i = 0; i < a[s].size(); ++i)
    {
        int h = a[s][i];
        if (h == f)
            continue;
        if (!c[h])
        {
            dfs(h);
            --ds;
            ans.push_back(m_p(s, h));
            kpc(s, h);
        }
    }
    bool z = false;
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            dfs(f);
            ans.push_back(m_p(s, f));
            kpc(s, f);
            --ds;
            --df;
            z = true;
            break;
        }
    }
    for (int i = 1; i <= n; ++i)
        assert(c[i]);
    memset(c, false, sizeof c);
    c[f] = true;
    if (z)
        dfs(s);
    for (int i = 0; i < a[f].size(); ++i)
    {
        int h = a[f][i];
        if (h == s)
            continue;
        if (!c[h])
        {
            dfs(h);
            --df;
            ans.push_back(m_p(f, h));
            kpc(f, h);
        }
    }
    for (int i = 1; i <= n; ++i)
        assert(c[i]);
    if (ds < 0 || df < 0)
    {
        printf("No\n");
        return 0;
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i];
            if (x == s || x == f || y == s || y == f)
                continue;
            if (fi(x) != fi(y))
            {
                ans.push_back(m_p(x, y));
                kpc(x, y);
            }
        }
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i];
            if (fi(x) != fi(y))
            {
                if ((x == f || y == f))
                {
                    if (df == 0)
                        continue;
                    --df;
                }
                if ((x == s || y == s))
                {
                    if (ds == 0)
                        continue;
                    --ds;
                }
                ans.push_back(m_p(x, y));
                kpc(x, y);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (fi(i) != fi(1))
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    for (int i = 0; i < n - 1; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}
/*
4 4
1 2
2 3
3 4
4 1
1 3 1 2
*/