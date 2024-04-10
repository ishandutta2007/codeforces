#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300005;
vector<array<int,2>> v[N];
vector<int> edge(N,0); //id of edge connecting i with its parent in the DFS-tree
vector<bool> bridge(N,0);
vector<int> depth(N,0);
vector<int> low(N,0);
vector<int> g[N];
vector<int> idx(N,0); //id of vertex in bridge-tree
int icnt=1;

void dfs(int a,int p=0)
{
    depth[a]=depth[p]+1;
    low[a]=depth[a];
    for(auto [to,id]:v[a])
    {
        if(depth[to]>0)
        {
            if(to!=p) low[a]=min(low[a],depth[to]);
            continue;
        }
        edge[to]=id;
        dfs(to,a);
        low[a]=min(low[a],low[to]);
    }
    if(low[a]==depth[a]) bridge[edge[a]]=1;
}

void gen(int a)
{
    idx[a]=icnt;
    for(auto [to,id]:v[a])
    {
        if(idx[to]!=0||bridge[id]==1) continue;
        gen(to);
    }
}

array<int,2> solve(int src) //i,d
{
    vector<int> d(N,-1);
    queue<int> q;
    q.push(src);
    d[src]=0;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int to:g[a])
        {
            if(d[to]!=-1) continue;
            d[to]=d[a]+1;
            q.push(to);
        }
    }
    int x=src;
    for(int i=1;i<N;i++) if(d[i]>d[x]) x=i;
    return {x,d[x]};
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<array<int,2>> edges(m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back({b,i});
        v[b].push_back({a,i});
        edges[i]={a,b};
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        if(idx[i]==0)
        {
            gen(i);
            icnt++;
        }
    }
    for(int i=0;i<m;i++)
    {
        auto [a,b]=edges[i];
        if(bridge[i]==1)
        {
            g[idx[a]].push_back(idx[b]);
            g[idx[b]].push_back(idx[a]);
        }
    }
    int src=solve(1)[0];
    printf("%d\n",solve(src)[1]);
    return 0;
}