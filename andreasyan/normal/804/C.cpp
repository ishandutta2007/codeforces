#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 300005;

int n, m;
vector<int> v[N];
vector<int> a[N];

int c[N];
void dfs(int x, int p)
{
    set<int> s;
    for (int i = 0; i < v[x].size(); ++i)
    {
        int y = v[x][i];
        if (c[y])
            s.insert(c[y]);
    }
    int z = 1;
    for (int i = 0; i < v[x].size(); ++i)
    {
        int y = v[x][i];
        if (c[y])
            continue;
        while (s.find(z) != s.end())
            ++z;
        c[y] = z;
        s.insert(z);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int x;
            scanf("%d", &x);
            v[i].push_back(x);
        }
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (!c[i])
            c[i] = 1;
        ans = max(ans, c[i]);
    }
    printf("%d\n", ans);
    for (int i = 1; i <= m; ++i)
        printf("%d ", c[i]);
    printf("\n");
    return 0;
}