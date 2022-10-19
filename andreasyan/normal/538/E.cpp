#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n;
vector<int> a[N];

int d[N];
bool c[N];
int q[N];

void dfs(int x, int p)
{
    d[x] = d[p] + 1;
    if ((x != p && a[x].size() == 1) || a[x].empty())
    {
        c[x] = true;
        q[x] = 1;
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        q[x] += q[h];
    }
}

int maxu[N];
void dfs1(int x, int p)
{
    if (c[x])
    {
        maxu[x] = 1;
        return;
    }
    if (d[x] % 2 == 1)
    {
        int u = N;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (h == p)
                continue;
            dfs1(h, x);
            u = min(u, q[h] - maxu[h]);
        }
        maxu[x] = (q[x] - u);
    }
    else
    {
        int u = 0;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (h == p)
                continue;
            dfs1(h, x);
            u += (maxu[h] - 1);
        }
        maxu[x] = u + 1;
    }
}

int minu[N];
void dfs2(int x, int p)
{
    if (c[x])
    {
        minu[x] = 1;
        return;
    }
    if (d[x] % 2 == 1)
    {
        int u = 0;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (h == p)
                continue;
            dfs2(h, x);
            u += (q[h] - minu[h]);
        }
        minu[x] = q[x] - u;
    }
    else
    {
        int u = N;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (h == p)
                continue;
            dfs2(h, x);
            u = min(u, minu[h]);
        }
        minu[x] = u;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    dfs1(1, 1);
    dfs2(1, 1);
    printf("%d %d\n", maxu[1], minu[1]);
    return 0;
}