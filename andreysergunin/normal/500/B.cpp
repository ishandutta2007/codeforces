#include<bits/stdc++.h>

using namespace std;

const int maxn = 500;
int a[maxn], qedge[maxn], vis[maxn], q[maxn], u[maxn];
vector<int> edge[maxn], col[maxn];

void dfs(int v, int color)
{
    int i;
    vis[v] = color;
    for (i = 0; i < qedge[v]; i++)
        if (vis[edge[v][i]] == 0)
            dfs(edge[v][i], color);
}


int main()
{
    int n, m, k, i, j, t;
    char c;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        qedge[i] = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            cin >> c;
            if (c == '1')
            {
                edge[i].push_back(j);
                qedge[i]++;
            }
        }
    for (i = 0; i < n; i++)
        vis[i] = 0;
    m = 0;
    for (i = 0; i < n; i++)
        if (vis[i] == 0)
        {
            m++;
            dfs(i, m);
        }
    for (i = 1; i <= n; i++)
        q[i] = 0;
    for (i = 0; i < n; i++)
    {
        col[vis[i]].push_back(a[i]);
        q[vis[i]]++;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 0; j < q[i]; j++)
            u[j] = col[i][j];
        sort(u, u + q[i]);
        for (j = 0; j < q[i]; j++)
            col[i][j] = u[j];

        q[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        cout << col[vis[i]][q[vis[i]]] << ' ';
        q[vis[i]]++;
    }
}