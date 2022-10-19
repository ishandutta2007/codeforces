#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 2003;

int n;
int a[N][N];

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

vector<pair<int, int> > g[N];

bool dfs(int x, int p, int pp, long long d)
{
    if (a[pp][x] != d)
        return false;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].first;
        if (h == p)
            continue;
        if (!dfs(h, x, pp, d + g[x][i].second))
            return false;
    }
    return true;
}

bool stg()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j && a[i][j])
                return false;
            if (i != j && !a[i][j])
                return false;
            if (a[i][j] != a[j][i])
                return false;
        }
    }
    vector<pair<int, pair<int, int> > > v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            v.push_back(m_p(a[i][j], m_p(i, j)));
        }
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 0; i < v.size(); ++i)
    {
        int x = v[i].second.first, y = v[i].second.second;
        int z = v[i].first;
        if (fi(x) == fi(y))
            continue;
        kpc(x, y);
        g[x].push_back(m_p(y, z));
        g[y].push_back(m_p(x, z));
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!dfs(i, i, i, 0))
            return false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    if (!stg())
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}