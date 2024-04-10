#include <bits/stdc++.h>

using namespace std;

const int maxN = 100500;

vector<int> e[maxN];
int color[maxN];

bool dfs(int v, int c = 1)
{
    color[v] = c;
    
    for (int u: e[v])
        if (!color[u])
        {
            if (!dfs(u, 3 - color[v]))
                return false;
        }
        else if (color[u] != 3 - color[v])
        {
            return false;
        }

    return true;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    bool fail = false;
    for (int i = 0; i < n; i++)
        if (!color[i])
        {
            if (!dfs(i))
            {
                fail = true;
                break;
            }
        }
        
    if (fail)
    {
        printf("-1\n");
        return 0;
    }
    
    vector<int> covers[2];
    for (int i = 0; i < n; i++)
        covers[color[i] - 1].push_back(i);
    
    for (int t = 0; t < 2; t++)
    {
        printf("%d\n", covers[t].size());
        for (int x: covers[t])
            printf("%d ", x + 1);
        printf("\n");
    }
    
    return 0;
}