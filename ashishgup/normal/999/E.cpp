#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5005;

int n, m, s, ans=0, grp=0; //grp stores the number of SCCs
vector<int> g[N], newg[N], rg[N], todo;
int comp[N], indeg[N]; 
bool vis[N];
vector<int> gr[N];

void dfs(int k)
{
	vis[k]=1;
	for(auto it:g[k])
	{
		if(!vis[it])
			dfs(it);
	}
	todo.push_back(k);
}

void dfs2(int k, int val)
{
	comp[k]=val;
	for(auto it:rg[k])
	{
		if(comp[it]==-1)
			dfs2(it, val);
	}
}

void sccAddEdge(int from, int to)
{
	g[from].push_back(to);
	rg[to].push_back(from);
}

void scc()
{
	for(int i=1;i<=n;i++)
		comp[i]=-1;

	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
			dfs(i);
	}

	reverse(todo.begin(), todo.end());

	for(auto it:todo)
	{
		if(comp[it]==-1)
		{
			dfs2(it, ++grp);
		}
	}
}

void newdfs(int k)
{
	if(vis[k])
		return;
	vis[k]=1;
	for(auto it:newg[k])
		newdfs(it);
}

int32_t main()
{
	IOS;
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		sccAddEdge(u, v);
	}
	scc();
	for(int i=1;i<=n;i++)
	{
		for(auto it:g[i])
		{
			if(comp[i]!=comp[it])
			{
				newg[comp[i]].push_back(comp[it]);
				indeg[comp[it]]++;
			}
		}
	}
	memset(vis, 0, sizeof(vis));
	newdfs(comp[s]);
	for(int i=1;i<=grp;i++)
	{
		if(!vis[i] && !indeg[i])
		{
			ans++;
			newdfs(i);
		}
	}
	cout<<ans;
	return 0;   
}