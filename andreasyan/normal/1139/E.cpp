#include <bits/stdc++.h>
using namespace std;
const int N = 5003;

int n, m;
int u[N];
int a[N];
vector<int> g[N];

int q;
int r[N];

int ans[N];

bool c[N];

int mp[N];

bool dfs(int x)
{
    if (c[x])
        return false;
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (mp[h] == -1 || dfs(mp[h]))
        {
            mp[h] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> u[i];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> r[i];
        c[r[i]] = true;
    }
    for (int i = 1; i <= n; ++i)
        if (!c[i])
            g[u[i]].push_back(a[i]);
    for (int i = 0; i < N; ++i)
        mp[i] = -1;
    int j = -1;
    for (int i = q; i >= 1; --i)
    {
        while (1)
        {
            memset(c, 0, sizeof c);
            if (!dfs(j + 1))
                break;
            ++j;
        }
        ans[i] = j + 1;
        g[u[r[i]]].push_back(a[r[i]]);
    }
    //cout << endl;
    for (int i = 1; i <= q; ++i)
        cout << ans[i] << endl;
    return 0;
}