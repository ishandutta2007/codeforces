#include <bits/stdc++.h>
using namespace std;
const int N = 200005, INF = 1000000009;

int n, m, xx, yy;
vector<int> a[N];

int q;
bool c[N];
void dfs(int x, int y)
{
    c[x] = true;
    ++q;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == y)
            continue;
        if (!c[h])
            dfs(h, y);
    }
}

void solv()
{
    scanf("%d%d%d%d", &n, &m, &xx, &yy);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    q = 0;
    for (int i = 1; i <= n; ++i)
        c[i] = false;
    dfs(xx, yy);
    int q1 = n - q - 1;
    q = 0;
    for (int i = 1; i <= n; ++i)
        c[i] = false;
    dfs(yy, xx);
    int q2 = n - q - 1;
    printf("%lld\n", (q1 * 1LL * q2));
    for (int i = 1; i <= n; ++i)
        a[i].clear();
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}