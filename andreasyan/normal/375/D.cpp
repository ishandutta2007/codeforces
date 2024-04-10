#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int s;
struct ban
{
    int i;
    int v, k;
    int l, r;
};
bool operator<(const ban& a, const ban& b)
{
    if ((a.l / s) < (b.l / s))
        return true;
    if ((a.l / s) > (b.l / s))
        return false;
    return a.r < b.r;
}

int n, m;
int c[N];
vector<int> a[N];
ban b[N];

int tin[N], tout[N], ti;
void dfs(int x, int p)
{
    tin[x] = ++ti;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
    tout[x] = ti;
}
int u[N];

int q[N];
int ans[N];

void ave(int x)
{
    ++q[x];
    ++ans[q[x]];
}

void han(int x)
{
    --ans[q[x]];
    --q[x];
}

int yans[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; ++i)
        u[tin[i]] = i;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &b[i].v, &b[i].k);
        b[i].i = i;
        b[i].l = tin[b[i].v];
        b[i].r = tout[b[i].v];
    }
    s = sqrt(n);
    sort(b + 1, b + m + 1);
    int l = 1, r = 0;
    for (int i = 1; i <= m; ++i)
    {
        int ll = b[i].l;
        int rr = b[i].r;
        while (r < rr)
        {
            ++r;
            ave(c[u[r]]);
        }
        while (l > ll)
        {
            --l;
            ave(c[u[l]]);
        }
        while (r > rr)
        {
            han(c[u[r]]);
            --r;
        }
        while (l < ll)
        {
            han(c[u[l]]);
            ++l;
        }
        yans[b[i].i] = ans[b[i].k];
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", yans[i]);
    return 0;
}