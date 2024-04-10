#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

vector<int> g[N];

bool c[N];
int d[N];
queue<int> q;
void bfs()
{
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (!c[h])
            {
                c[h] = true;
                d[h] = d[x] + 1;
                q.push(h);
            }
        }
    }
}

int ans[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (i - a[i] >= 1)
            g[i - a[i]].push_back(i);
        if (i + a[i] <= n)
            g[i + a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 1)
        {
            c[i] = true;
            d[i] = 0;
            q.push(i);
        }
    }
    bfs();
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 0)
        {
            if (!c[i])
                ans[i] = -1;
            else
                ans[i] = d[i];
        }
    }
    memset(c, false, sizeof c);
    memset(d, 0, sizeof d);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 0)
        {
            c[i] = true;
            d[i] = 0;
            q.push(i);
        }
    }
    bfs();
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 1)
        {
            if (!c[i])
                ans[i] = -1;
            else
                ans[i] = d[i];
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}