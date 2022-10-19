#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m, h;
int u[N];

vector<int> a[N];
vector<int> b[N];

int c[N];

vector<int> v;
void dfs0(int x)
{
    c[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs0(h);
    }
    v.push_back(x);
}

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

bool cc[N];

int q[N];
int main()
{
    scanf("%d%d%d", &n, &m, &h);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &u[i]);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (u[y] < u[x])
            swap(x, y);
        if (u[y] - u[x] == 1)
        {
            a[x].push_back(y);
            b[y].push_back(x);
        }
        if (u[y] == h - 1 && u[x] == 0)
        {
            a[y].push_back(x);
            b[x].push_back(y);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
            dfs0(i);
    }
    reverse(v.begin(), v.end());
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; ++i)
    {
        int x = v[i];
        if (!c[x])
        {
            ++k;
            dfs1(x);
        }
    }
    for (int i = 1; i <= n; ++i)
        q[c[i]]++;
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i];
            if (c[x] != c[y])
                cc[c[x]] = true;
        }
    }
    int ans = n;
    for (int i = 1; i <= k; ++i)
    {
        if (!cc[i])
            ans = min(ans, q[i]);
    }
    for (int i = 1; i <= k; ++i)
    {
        if (!cc[i])
        {
            if (q[i] == ans)
            {
                cout << ans << endl;
                for (int x = 1; x <= n; ++x)
                {
                    if (c[x] == i)
                    {
                        cout << x << ' ';
                    }
                }
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}