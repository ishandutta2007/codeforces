#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
map<int, int> vis;
map<int, vector<int> > g;

void dfs(int k)
{
    if(vis[k])
        return;
    vis[k]=1;
    cout<<k<<" ";
    for(auto it:g[k])
        dfs(it);
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(auto it:g)
    {
        if(it.second.size()==1)
        {
            dfs(it.first);
            return 0;
        }
    }
    return 0;
}