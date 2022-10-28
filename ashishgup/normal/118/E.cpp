#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, s, grp=0; //grp stores the number of SCCs
vector<int> g[N], undirG[N], rg[N], todo;
int comp[N], sizecomp[N]; 
bool vis[N], checkSCC[N];
set<pair<int, int> > taken;
vector<pair<int, int> > ans;

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
	sizecomp[val]++;
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

	memset(vis, 0, sizeof(vis));

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

void undirdfs(int k)
{
	if(vis[k])
		return;
	vis[k]=1;
	for(auto it:undirG[k])
	{
		int u=k, v=it;
		if(taken.find({u, v})==taken.end())
		{
			sccAddEdge(u, v);
			taken.insert({u, v});
			taken.insert({v, u});
		}
		undirdfs(it);
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		undirG[u].push_back(v);
		undirG[v].push_back(u);
	}
	undirdfs(1);
	scc();
	if(grp==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(auto it:g[i])
			{
				cout<<i<<" "<<it<<endl;
			}
		}
	}
	else
	{
		cout<<"0";
	}
	return 0;   
}