#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, m;
pair<int, int> b[N];
vector<int> v[N * 10];

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

int ans[N];

vector<int> g[N], gi[N];
int tin[N], fup[N], ti;
bool c[N];
void dfs(int x, int pi)
{
    c[x] = true;
    fup[x] = tin[x] = ++ti;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        int hi = gi[x][i];
        if (hi == pi)
            continue;
        if (c[h])
            fup[x] = min(fup[x], tin[h]);
        else
        {
            dfs(h, gi[x][i]);
            if (fup[h] > tin[x])
                ans[hi] = 2;
            fup[x] = min(fup[x], fup[h]);
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        v[z].push_back(i);
        b[i] = m_p(x, y);
    }
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 0; i < N * 10; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            int u = v[i][j];
            int x = b[u].first;
            int y = b[u].second;
            x = fi(x);
            y = fi(y);
            c[x] = c[y] = false;
            g[x].clear();
            g[y].clear();
            gi[x].clear();
            gi[y].clear();
        }
        for (int j = 0; j < v[i].size(); ++j)
        {
            int u = v[i][j];
            int x = b[u].first;
            int y = b[u].second;
            x = fi(x);
            y = fi(y);
            if (x == y)
            {
                ans[u] = 0;
            }
            else
            {
                ans[u] = 1;
                g[x].push_back(y);
                g[y].push_back(x);
                gi[x].push_back(u);
                gi[y].push_back(u);
            }
        }
        for (int j = 0; j < v[i].size(); ++j)
        {
            int u = v[i][j];
            int x = b[u].first;
            int y = b[u].second;
            x = fi(x);
            y = fi(y);
            if (!c[x])
                dfs(x, -1);
        }
        for (int j = 0; j < v[i].size(); ++j)
        {
            int u = v[i][j];
            int x = b[u].first;
            int y = b[u].second;
            kpc(x, y);
        }
    }
    for (int i = 0; i < m; ++i)
    {
        if (ans[i] == 0)
            printf("none\n");
        else if (ans[i] == 1)
            printf("at least one\n");
        else
            printf("any\n");
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