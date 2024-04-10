#include <cstdio>
#include <vector>

using namespace std;

vector < vector < int > > g;
int n;
int m;
int pows[100005];
bool used[100005];
int visited = 0;
int ones = 0;
int twos = 0;

void dfs(int v)
{
    used[v] = 1;
    visited++;
    for (int i = 0; i < g[v].size(); i++)
    {
        if (!used[g[v][i]])
            dfs(g[v][i]);
    }
}

int main()
{
    scanf("%d %d\n", &n, &m);
    g.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        pows[a]++;
        pows[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int onei;
    int star = -1;
    for (int i = 0; i < n; i++)
    {
        if (pows[i] == 1)
        {
            ones++;
            onei = i;
        }
        else if (pows[i] == 2)
        {
            twos++;
        }
        else if (pows[i] == n-1)
        {
            star = i;
        }
    }
    
    if (twos == n)
    {
        dfs(0);
        if (visited == n && m == n)
            printf("ring topology");
        else
            printf("unknown topology");
    }
    else if (twos == (n-2) && ones == 2)
    {
        dfs(onei);
        if (visited == n && m == (n-1))
            printf("bus topology");
        else
            printf("unknown topology");
    }
    else if (ones == (n-1) && star != -1)
    {
        if (g[star].size() == (n-1) && m == (n-1))
            printf("star topology");
        else
            printf("unknown topology");
    }
    else
            printf("unknown topology");
}