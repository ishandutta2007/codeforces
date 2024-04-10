#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct w
{
    int x, y;
    int len;
    int type;
    int di;
    w(int a, int b, int c, int d, int e)
    {
        x = a, y = b;
        len = c;
        type = d;
        di = e;
    }
    w()
    {
    }
};

bool operator < (w a, w b)
{
    if (a.x != b.x)
    {
        return a.x < b.x;
    }
    if (a.y != b.y)
    {
        return a.y < b.y;
    }
    if (a.len != b.len)
    {
        return a.len < b.len;
    }
    if (a.type != b.type)
    {
        return a.type < b.type;
    }
    return a.di < b.di;
}

int t[228];
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int n;
int cnt = 0;

map <pair <int, int>, int> used;
map <w, int> g;
int rrrr = 0;

void dfs(int x, int y, int len, int type, int di)
{
    rrrr++;
    if (g.count({x, y, len, type, di}))
    {
        return;
    }
    cnt += !used[{x, y}];
    used[{x, y}] = 1;
    g[{x, y, len, type, di}] = 1;
    if (len == 0)
    {
        if (di != n - 1)
        {
            dfs(x, y, t[di + 1], (type + 1) % 8, di + 1);
            dfs(x, y, t[di + 1], (type + 7) % 8, di + 1);
        }
    }
    else
    {
        dfs(x + dx[type], y + dy[type], len - 1, type, di);
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    dfs(0, 0, t[0] - 1, 0, 0);
    cout << cnt << '\n';
}