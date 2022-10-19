#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
vector<int> v[N];

unordered_map<int, int> p[N];

int fi(int c, int x)
{
    if (p[c][x] == x)
        return x;
    return p[c][x] = fi(c, p[c][x]);
}

void kpc(int c, int x, int y)
{
    x = fi(c, x);
    y = fi(c, y);
    p[c][x] = y;
}

map<int, int> ans[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        if (p[c].find(x) == p[c].end())
            p[c][x] = x;
        if (p[c].find(y) == p[c].end())
            p[c][y] = y;
        kpc(c, x, y);
        v[x].push_back(c);
        v[y].push_back(c);
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(v[i].begin(), v[i].end());
        vector<int> vv;
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (!i || v[i][j] != v[i][j - 1])
                vv.push_back(v[i][j]);
        }
        v[i] = vv;
    }
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (ans[x].find(y) != ans[x].end())
        {
            printf("%d\n", ans[x][y]);
            continue;
        }
        if (v[x].size() > v[y].size())
            swap(x, y);
        for (int j = 0; j < v[x].size(); ++j)
        {
            int c = v[x][j];
            if (p[c].find(y) != p[c].end())
            {
                if (fi(c, x) == fi(c, y))
                    ++ans[x][y];
            }
        }
        ans[y][x] = ans[x][y];
        printf("%d\n", ans[x][y]);
    }
    return 0;
}