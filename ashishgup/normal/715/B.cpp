#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1005;

int n, m, L, src, dest;
bool vis[N];
long long dist[N];
vector<int> g[N], wt[N];
vector<pair<int, int> > pairs;

void dijkstra()
{
    for(int i=0;i<n;i++)
        dist[i]=1e10;
    dist[src]=0;
    set<pair<int, int> > s;
    s.insert({0, src});
    while(!s.empty())
    {
        auto x=*(s.begin());
        s.erase(x);
        vis[x.second]=1;
        for(int i=0;i<g[x.second].size();i++)
        {
            int it=g[x.second][i];
            int w=wt[x.second][i];
            if(dist[it] > dist[x.second] + w)
            {
                s.erase({dist[it], it});
                dist[it]=dist[x.second] + w;
                s.insert({dist[it], it});
            }
        }
    }
}

int32_t main()
{
    IOS;
    cin>>n>>m>>L>>src>>dest;
    for(int i=1;i<=m;i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        if(w)
        {
            g[u].push_back(v);
            g[v].push_back(u);
            wt[u].push_back(w);
            wt[v].push_back(w);
        }
        else
            pairs.push_back({u, v});
    }
    dijkstra();
    if(dist[dest]<L)
    {
        cout<<"NO";
        return 0;
    }
    for(auto it:pairs)
    {
        int u=it.first, v=it.second;
        g[u].push_back(v);
        g[v].push_back(u);
        wt[u].push_back(1);
        wt[v].push_back(1);
        dijkstra();
        long long curdist=dist[dest];
        long long diff=0;
        if(curdist<L)
        {
            diff=L-curdist;
            wt[u].pop_back();
            wt[u].push_back(diff+1);
            wt[v].pop_back();
            wt[v].push_back(diff+1);
        }
    }
    dijkstra();
    if(dist[dest]>L)
        cout<<"NO";
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<g[i].size();j++)
            {
                if(g[i][j]>i)
                    cout<<i<<" "<<g[i][j]<<" "<<wt[i][j]<<endl;
            }
        }
    }
    return 0;
}