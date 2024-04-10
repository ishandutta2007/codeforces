#include <bits/stdc++.h>

using namespace std;
const int N=100001;

vector<int> v[N];
vector<bool> vis(N,0);
vector<int> tin(N,-1),low(N,-1);
int timer=0;
bool ok=1;
set<pair<int,int> > s;

void dfs(int e,int p)
{
    vis[e]=1;
    tin[e]=low[e]=timer++;
    for(int to:v[e])
    {
        if(to==p) continue;
        if(vis[to]) low[e]=min(low[e],tin[to]);
        else
        {
            dfs(to,e);
            low[e]=min(low[e],low[to]);
            if(low[to]>tin[e]) ok=0;
        }
    }
}

void dfsSolve(int e,int p)
{
    vis[e]=1;
    for(int to:v[e])
    {
        if(to==p) continue;
        if(s.find(make_pair(min(e,to),max(e,to)))==s.end())
        {
            printf("%d %d\n",e,to);
            s.insert(make_pair(min(e,to),max(e,to)));
        }
        if(!vis[to]) dfsSolve(to,e);
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,-1);
    if(ok)
    {
        fill(vis.begin(),vis.end(),0);
        dfsSolve(1,-1);
    }
    else printf("0\n");
    return 0;
}