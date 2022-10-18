#include <bits/stdc++.h>

using namespace std;

const int maxN = 100500;
vector<int> e[maxN];

char used[maxN];

void dfs(int v, int p = -1)
{
    used[v] = true;
    for (int u: e[v])
    {
        if (u != p)
        {
            assert(!used[u]);
            dfs(u, v);
        }
    }
}

vector<int> bfs(int n, int s)
{
    deque<int> q;
    q.push_back(s);
    
    vector<int> d(n, -1);
    d[s] = 0;
    
    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();
        
        for (int u: e[v])
            if (d[u] == -1)
            {
                d[u] = d[v] + 1;
                q.push_back(u);
            }
    }
    
    return d;
}

void addEdge(int i, int j)
{
    printf("%d %d\n", i + 1, j + 1);
    e[i].push_back(j);
    e[j].push_back(i);
}

bool solve(int n, int d, int h)
{
    if (d > 2 * h) return false;
    if (h == 1 && d == 1)
    {
        if (n != 2)
            return false;
        
        addEdge(0, 1);
        return true;
    }
    
    // d > 1
    
    // print h path
    for (int i = 0; i < h; i++)
        addEdge(i, i + 1);
    
    // print d path; d - h <= h
    for (int i = 0; i < d - h; i++)
        addEdge(i == 0 ? 0 : i + h, 1 + h + i);
    
    // add remaining edges
    if (d != h)
    {
        for (int i = 1 + d; i < n; i++)
            addEdge(0, i);
    }
    else
    {
        for (int i = 1 + d; i < n; i++)
            addEdge(h - 1, i);
    }
    
#if 0
    vector<int> g = bfs(n, 0);
    int idx = max_element(g.begin(), g.end()) - g.begin();
    vector<int> g2 = bfs(n, idx);
    int idx2 = max_element(g2.begin(), g2.end()) - g2.begin();
#endif
    
#if 0
    printf("params %d height %d, diameter %d\n", n, h, d);
    printf("height %d, diameter %d\n", g[idx], g2[idx2]);
    for (int i = 0; i < n; i++) used[i] = false;
    dfs(0);
    assert(h == g[idx]);
    assert(d == g2[idx2]);
#endif
    
    return true;
}

int main()
{
#if 0
    while (true)
    {
        int n = rand() % 4 + 2;
        int d = rand() % (n - 1) + 1;
        int h = rand() % d + 1;
        
        for (int i = 0; i < maxN; i++) e[i].clear();
        solve(n, d, h);
    }
#endif
    
    int n, d, h;
    scanf("%d %d %d", &n, &d, &h);
    
    if (!solve(n, d, h))
        printf("-1\n");
    
    return 0;
}