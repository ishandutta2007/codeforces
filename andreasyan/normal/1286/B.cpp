#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 2002;

int n;
int r;
int u[N];
vector<int> a[N];
int ans[N];

void dfs1(int x, int y)
{
    ans[x] += y;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs1(h, y);
    }
}
void dfs2(int x, int y)
{
    if (ans[x] >= y)
        ++ans[x];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs2(h, y);
    }
}

int q[N];
void dfs(int x)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs(h);
        q[x] += q[h];
    }
    if (u[x] > q[x])
    {
        printf("NO\n");
        exit(0);
    }
    ++q[x];
    ++u[x];
    ans[x] = u[x];
    int p = 0;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs1(h, p);
        p += q[h];
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs2(h, u[x]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int p;
        scanf("%d%d", &p, &u[i]);
        if (p == 0)
            r = i;
        else
            a[p].push_back(i);
    }
    dfs(r);
    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}