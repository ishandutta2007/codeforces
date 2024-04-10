#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, m;
char a[N][N];

int p[N + N];
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

vector<int> g[N + N];

int c[N + N];
bool dfs(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h] == 1)
            return true;
        if (c[h] == 0)
        {
            if (dfs(h))
                return true;
        }
    }
    c[x] = 2;
    return false;
}

int ans[N + N];
void dfs1(int x)
{
    c[x] = 1;
    int maxu = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs1(h);
        maxu = max(maxu, ans[h]);
    }
    ans[x] = maxu + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n + m; ++i)
        p[i] = i;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i - 1][j - 1] == '=')
            {
                kpc(i, n + j);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i - 1][j - 1] == '>')
                g[fi(i)].push_back(fi(n + j));
            if (a[i - 1][j - 1] == '<')
                g[fi(n + j)].push_back(fi(i));
        }
    }
    for (int i = 1; i <= n + m; ++i)
    {
        if (!c[i])
        {
            if (dfs(i))
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n + m; ++i)
        c[i] = 0;
    for (int i = 1; i <= n + m; ++i)
    {
        if (!c[i])
            dfs1(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[fi(i)] << ' ';
    }
    cout << endl;
    for (int j = 1; j <= m; ++j)
    {
        cout << ans[fi(n + j)] << ' ';
    }
    cout << endl;
    return 0;
}