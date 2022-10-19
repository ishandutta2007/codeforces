#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n;
vector<int> a[N];

vector<int> v;
void dfs(int x, int p)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
    v.push_back(x);
    for (int i = (int)a[x].size() - 1; i >= 0; --i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        v.push_back(h);
    }
}

int l[N], r[N];
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
    v.push_back(1);
    for (int i = 0; i < v.size(); ++i)
    {
        if (l[v[i]] == 0)
            l[v[i]] = i + 1;
        else
            r[v[i]] = i + 1;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", l[i], r[i]);
    printf("\n");
    return 0;
}