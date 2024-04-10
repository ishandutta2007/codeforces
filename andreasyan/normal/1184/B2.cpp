#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
const long long INF = 1000000009000000009;
struct ban1
{
    int x, a, f;
};
struct ban2
{
    int x, d;
};

int n, m;
vector<int> g[N];
int d[N][N];
void bfs(int x)
{
    queue<int> q;
    d[x][x] = 1;
    q.push(x);
    while (!q.empty())
    {
        int y = q.front();
        q.pop();
        for (int i = 0; i < g[y].size(); ++i)
        {
            int h = g[y][i];
            if (!d[x][h])
            {
                d[x][h] = d[x][y] + 1;
                q.push(h);
            }
        }
    }
}

int n1, n2, k, h;
ban1 a[N];
ban2 b[N];

int z[N];
bool c[N];
bool dfs(int x)
{
    if (c[x])
        return false;
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!z[h])
        {
            z[h] = x;
            return true;
        }
        else
        {
            if (dfs(z[h]))
            {
                z[h] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int x = 1; x <= n; ++x)
        bfs(x);
    cin >> n1 >> n2 >> k >> h;
    for (int i = 1; i <= n1; ++i)
        cin >> a[i].x >> a[i].a >> a[i].f;
    for (int i = 1; i <= n2; ++i)
        cin >> b[i].x >> b[i].d;
    for (int i = 1; i <= n1; ++i)
        g[i].clear();
    for (int i = 1; i <= n1; ++i)
    {
        for (int j = 1; j <= n2; ++j)
        {
            if (a[i].a >= b[j].d && d[a[i].x][b[j].x] <= a[i].f)
                g[i].push_back(j);
        }
    }
    for (int i = 1; i <= n1; ++i)
    {
        memset(c, false, sizeof c);
        dfs(i);
    }
    int q = 0;
    for (int i = 1; i <= n2; ++i)
    {
        if (z[i])
            ++q;
    }
    long long ans = q * 1LL * k;
    for (int i = n1 - q; i <= n1; ++i)
    {
        ans = min(ans, (n1 - i) * 1LL * k + i * 1LL * h);
    }
    cout << ans << endl;
    return 0;
}