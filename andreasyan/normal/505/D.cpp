#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
vector<int> a[N], b[N];

int c[N];

bool dfs(int x)
{
    c[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (c[h] == 1)
            return true;
        if (c[h] == 0)
            if (dfs(h))
                return true;
    }
    c[x] = 2;
    return false;
}

bool z[N];

int k;
void dfs1(int x)
{
    c[x] = k;
    for (int i = 0; i < b[x].size(); ++i)
    {
        int h = b[x][i];
        if (!c[h])
            dfs1(h);
    }
}

int q[N];
bool zz[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        b[y].push_back(x);
        b[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (c[i]) continue;
        z[i] = dfs(i);
    }
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            ++k;
            dfs1(i);
        }
    }
    for (int i = 1; i <= n; ++i)
        if (z[i])
            zz[c[i]] = true;
    for (int i = 1; i <= n; ++i)
        q[c[i]]++;
    int ans = 0;
    for (int i = 1; i <= k; ++i)
    {
        if (zz[i])
            ans += q[i];
        else
            ans += (q[i] - 1);
    }
    cout << ans << endl;
    return 0;
}