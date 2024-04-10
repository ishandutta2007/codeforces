#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;

int n;
vector<int> a[N];

const int m = 19;
int p[N][m];

int d[N];
int q[N];

int tin[N], tout[N], ti;

void dfs(int x, int pp)
{
    tin[x] = ++ti;
    d[x] = d[pp] + 1;
    p[x][0] = pp;
    for (int i = 1; i < m; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];
    q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == pp)
            continue;
        dfs(h, x);
        q[x] += q[h];
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int go(int x, int y)
{
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return x;
}

int go_d(int x, int d)
{
    for (int i = m - 1; i >= 0; --i)
    {
        if ((1 << i) <= d)
        {
            x = p[x][i];
            d -= (1 << i);
        }
    }
    return x;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == y)
        {
            printf("%d\n", n);
            continue;
        }
        if (isp(x, y))
        {
            swap(x, y);
        }
        if (isp(y, x))
        {
            if ((d[x] - d[y] + 1) % 2 == 0)
            {
                printf("0\n");
                continue;
            }
            int u = go_d(x, (d[x] - d[y]) / 2);
            printf("%d\n", q[u] - q[go(x, u)]);
            continue;
        }
        int z = p[go(x, y)][0];
        if ((d[x] + d[y] - 2 * d[z] + 1) % 2 == 0)
        {
            printf("0\n");
            continue;
        }
        if (d[y] - d[z] == d[x] - d[z])
        {
            printf("%d\n", n - q[go(x, z)] - q[go(y, z)]);
            continue;
        }
        if (d[y] - d[z] > d[x] - d[z])
        {
            swap(x, y);
        }
        int u = go_d(x, (d[x] + d[y] - 2 * d[z]) / 2);
        printf("%d\n", q[u] - q[go(x, u)]);
    }
    return 0;
}