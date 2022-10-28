#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, m, k, s;
int a[N], vis[N], cost[105][N];
vector<int> g[N], goods[N], costs[N];

int32_t main()
{
    IOS;
    cin>>n>>m>>k>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        goods[a[i]].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }    
    for(int i=1;i<=k;i++)
    {
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        for(auto it:goods[i])
        {
            q.push(it);
            vis[it]=1;
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:g[node])
            {
                if(vis[it])
                    continue;
                vis[it]=1;
                cost[i][it]=cost[i][node]+1;
                q.push(it);
            }
        }
        for(int j=1;j<=n;j++)
        {
            costs[j].push_back(cost[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        sort(costs[i].begin(), costs[i].end());
        for(int j=0;j<s;j++)
        {
            ans+=costs[i][j];
        }
        cout<<ans<<" ";
    }
    return 0;
}