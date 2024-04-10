#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 500005;

int n, m;
pair<pair<int, int>, int> b[N];
vector<int> v[N];
vector<pair<int, int> > vv[N];

int q;
bool ans[N];

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

vector<int> u;

vector<pair<int, int> > g[N];
bool c[N];

bool dfs(int x, int p)
{
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].first;
        if (g[x][i].second == p)
            continue;
        if (c[h])
            return true;
        if (dfs(h, g[x][i].second))
            return true;
    }
    return false;
}

void stg(int ii)
{
    if (!ans[ii])
        return;
    for (int i = 0; i < u.size(); ++i)
    {
        int x = b[u[i]].first.first;
        int y = b[u[i]].first.second;
        if (fi(x) == fi(y))
        {
            ans[ii] = false;
            return;
        }
    }
    for (int i = 0; i < u.size(); ++i)
    {
        int x = b[u[i]].first.first;
        int y = b[u[i]].first.second;
        x = fi(x);
        y = fi(y);
        c[x] = c[y] = false;
        g[x].clear();
        g[y].clear();
    }
    for (int i = 0; i < u.size(); ++i)
    {
        int x = b[u[i]].first.first;
        int y = b[u[i]].first.second;
        x = fi(x);
        y = fi(y);
        g[x].push_back(m_p(y, i));
        g[y].push_back(m_p(x, i));
    }
    for (int i = 0; i < u.size(); ++i)
    {
        int x = b[u[i]].first.first;
        x = fi(x);
        if (!c[x])
        {
            if (dfs(x, -1))
            {
                ans[ii] = false;
                return;
            }
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &b[i].first.first, &b[i].first.second, &b[i].second);
        v[b[i].second].push_back(i);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i)
    {
        ans[i] = true;
        int qq;
        scanf("%d", &qq);
        while (qq--)
        {
            int x;
            scanf("%d", &x);
            vv[b[x].second].push_back(m_p(i, x));
        }
    }
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < vv[i].size(); ++j)
        {
            if (j && vv[i][j].first != vv[i][j - 1].first)
            {
                stg(vv[i][j - 1].first);
                u.clear();
            }
            u.push_back(vv[i][j].second);
        }
        if (!vv[i].empty())
        {
            stg(vv[i].back().first);
            u.clear();
        }
        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = b[v[i][j]].first.first;
            int y = b[v[i][j]].first.second;
            kpc(x, y);
        }
    }
    for (int i = 1; i <= q; ++i)
    {
        if (ans[i])
            printf("YES\n");
        else
            printf("NO\n");
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