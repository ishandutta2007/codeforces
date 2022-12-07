#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, w;
int odw[200001];
vector <int> v[200001];

void dfs(int x, int p, int d)
{
    odw[x]=1;
    if(v[x].size()==2)
    {
        if(v[x][0]==p)
        {
            if(d>=3)
            {
                ++w;
            }
        }
        else
        {
            if(v[x][1]==p)
            {
                if(d>=3)
                {
                    ++w;
                }
            }
        }
        if(odw[v[x][0]]==0)
        {
            dfs(v[x][0], p, d+1);
        }
        if(odw[v[x][1]]==0)
        {
            dfs(v[x][1], p, d+1);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=n; ++i)
    {
        if(odw[i]==0)
        {
            dfs(i, i, 1);
        }
    }
    printf("%d", w);
    return 0;
}