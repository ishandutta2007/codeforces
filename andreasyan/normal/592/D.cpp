#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n, m;
vector<int> a[N];
bool c[N];

int d[N];
void dfs(int x, int p)
{
    if (x == p)
        d[x] = 0;
    else
        d[x] = d[p] + 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
}

int q[N];
void dfs1(int x, int p)
{
    if (c[x])
        q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs1(h, x);
        q[x] += q[h];
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= m; ++i)
    {
        int x;
        scanf("%d", &x);
        c[x] = true;
    }
    for (int x = 1; x <= n; ++x)
    {
        if (c[x])
        {
            dfs(x, x);
            int z = x;
            for (int y = 1; y <= n; ++y)
            {
                if (c[y] && d[y] > d[z])
                {
                    z = y;
                }
            }
            dfs(z, z);
            x = z;
            for (int y = 1; y <= n; ++y)
            {
                if (c[y] && d[y] > d[x])
                {
                    x = y;
                }
            }
            printf("%d\n", min(x, z));
            int ans = 0;
            dfs1(1, 1);
            for (int x = 1; x <= n; ++x)
            {
                if (0 < q[x] && q[x] < m)
                    ans += 2;
            }
            ans -= d[x];
            printf("%d\n", ans);
            return 0;
        }
    }
    return 0;
}