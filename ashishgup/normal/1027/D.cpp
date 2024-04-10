#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, ans=0, grp=0;
int a[N], c[N], outdeg[N];
vector<int> g[N], newg[N], store[N], rg[N], todo;
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
	store[val].push_back(k);
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

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sccAddEdge(i, a[i]);
	}
	scc();
	for(int i=1;i<=n;i++)
	{
		for(auto it:g[i])
		{
			if(comp[i]!=comp[it])
				outdeg[comp[i]]++;
		}
	}
	for(int i=1;i<=grp;i++)
	{
		if(!outdeg[i])
		{
			int val=1e18;
			for(auto &it:store[i])
				val=min(val, c[it]);
			ans+=val;
		}
	}
	cout<<ans;
	return 0;
}