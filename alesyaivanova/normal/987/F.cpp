#include <bits/stdc++.h>

using namespace std;

int a[1 << 22];
bool q[1 << 22];
bool used[1 << 22][2];
int n, m;

void dfs(int v, int e)
{
    used[v][e] = true;
    if (e == 0)
    {
        if ((q[v]) && (!used[v][1]))
            dfs(v, 1);
        return;
    }
    int k = (1 << n) - 1 - v;
    if (q[k] && !used[k][0])
    {
        dfs(k, 0);
    }
    int to = 1;
    for (int i = 0; i < n; i++)
    {
        if (!(v & to))
        {
            int u = (v | to);
            if (!used[u][1])
                dfs(u, 1);
        }
        to *= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        q[a[i]] = true;
    }
    int num = 0;
    for (int i = 0; i < m; i++)
    {
        if (!used[a[i]][0])
        {
            dfs(a[i], 0);
            num++;
        }
    }
    cout << num;
}