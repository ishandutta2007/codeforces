#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, cnt=0;
int a[N], parent[N], ans[N], vis[N];
vector<pair<int, int> > g[N];

void dfs(int k, int par)
{
	parent[k]=par;
	for(auto it:g[k])
	{
		if(it.first==par)
			continue;
		ans[it.first]=max(ans[it.first], ans[k] + it.second);
		dfs(it.first, k);
	}
}

void dfs2(int k)
{
	if(vis[k])
		return;
	vis[k]=1;
	cnt++;
	for(auto it:g[k])
	{
		if(it.first==parent[k])
			continue;
		dfs2(it.first);
	}
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    for(int i=2;i<=n;i++)
    {
    	int u=i;
    	int v;
    	cin>>v;
    	int w;
    	cin>>w;
    	g[u].push_back({v, w});
    	g[v].push_back({u, w});
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++)
    {
    	if(ans[i]>a[i])
    		dfs2(i);
    }
    cout<<cnt;
    return 0;
}