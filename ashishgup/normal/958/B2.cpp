#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, maxdist=0, node=1;
priority_queue<int> fin;
vector<int> g[N];

int dfs(int k, int par, int dist)
{
    if(dist>maxdist)
    {
        maxdist=dist;
        node=k;
    }
    for(auto it:g[k])
    {
        if(it==par)
            continue;
        dfs(it, k, dist+1);
    }
}

int dfs2(int k, int par)
{
    priority_queue<int> pq;
    pq.push(0);
    for(auto it:g[k])
    {
        if(it==par)
            continue;
        pq.push(dfs2(it, k) + 1);
    }
    int store=pq.top();
    pq.pop();
    while(!pq.empty())
    {
        fin.push(pq.top());
        pq.pop();
    }
    if(k==node)
    {
        fin.push(store);
    }
    return store;
}

int32_t main()
{
    IOS;
    cin>>n;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n-1;i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1, 1);
    dfs2(node, node);
    int ans=1;
    cout<<ans<<" ";
    for(int k=2;k<=n;k++)
    {
        ans+=fin.top();
        fin.pop();
        cout<<ans<<" ";
    }
    return 0;
}