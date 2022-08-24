#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

vector <int> g[N];
bool u[N];

vector <int> cur;

void dfs(int v, int pr)
{
    cur.push_back(v);
    u[v] = 1;
    for (auto to : g[v])
    {
        if (!u[to])
        {
            dfs(to, v);
        }
    }
    if (pr != -1)
    {
        cur.push_back(pr);
    }
}

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    int kek = cur.size();
    int res = 2 * n / k + bool(2 * n % k);
    int it = k;
    int i = 0;
    while (it--)
    {
        int en = min(i + res, kek);
        if (en <= i)
        {
            printf("%d %d\n", 1, 1);
            continue;
        }
        printf("%d ", en - i);
        for (int j = i; j < en; j++)
        {
            printf("%d ", cur[j]);
        }
        puts("");
        i += res;
    }
}