#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
vector<int> a[N];

int d[N];
void dfs0(int x, int p)
{
    d[x] = a[x].size() + 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        d[x] = max(d[x], d[h] + (int)a[x].size() - 1);
    }
}

int ans;
void dfs(int x, int p, int dp)
{
    multiset<int> s;
    if (dp)
        s.insert(dp);
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        s.insert(d[h]);
    }
    if (s.size() == 1)
    {
        ans = max(ans, (*(--s.end())) + (int)a[x].size() - 1);
    }
    else
    {
        ans = max(ans, (*(--s.end())) + (*(--(--s.end()))) + (int)a[x].size() - 3);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        s.erase(s.find(d[h]));
        if (!s.empty())
            dfs(h, x, *(--s.end()) + a[x].size() - 1);
        else
            dfs(h, x, 1);
        s.insert(d[h]);
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        a[i].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    if (n == 1)
    {
        printf("1\n");
        return;
    }
    dfs0(1, 1);
    ans = 0;
    dfs(1, 1, 0);
    printf("%d\n", ans);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}