#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3005;

int n;
pair<int, int> edges[N];
int vis[N], vis2[N], vis3[N], level[N], ans[N], parent[N];
queue<int> q;
vector<pair<int, int> > g[N];

void dfs(int k, int par, int lvl)
{
    vis[k]=1;
    parent[k]=par;
    level[k]=lvl;
    for(auto it:g[k])
    {
        if(vis[it.first])
            continue;
        vis2[it.second]=1;
        dfs(it.first, k, lvl+1);
    }
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {   
        int u, v;
        cin>>u>>v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        edges[i].first=u;
        edges[i].second=v;
    }  
    dfs(1, 0, 1);
    for(int i=1;i<=n;i++)
    {
        if(!vis2[i])
        {
            int u=edges[i].first;
            int v=edges[i].second;
            if(level[u]>level[v])
                swap(u, v);
            int cur=v;
            while(true)
            {
                q.push(cur);
                vis3[cur]=1;
                if(cur==u)
                    break;
                cur=parent[cur];
            }
        }
    }
    memset(level, 0, sizeof(level));
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        for(auto it:g[k])
        {
            if(vis3[it.first])
                continue;
            vis3[it.first]=1;
            level[it.first]=level[k]+1;
            q.push(it.first);
        }
    }
    for(int i=1;i<=n;i++)
        cout<<level[i]<<" ";
    return 0;
}