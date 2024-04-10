#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k, grp = 0;
int p[N], q[N];
vector<int> g[N], rg[N], todo;
int comp[N], indeg[N]; 
bool vis[N];
vector<int> gr[N], contains[N];
set<int> newg[N];

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
	comp[k] = val;
	contains[val].push_back(k);
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
		if(comp[it] == -1)
		{
			dfs2(it, ++grp);
		}
	}
}

int cache[N], letter[N];
int cur = 1;

int dfsLong(int u)
{
	int &ans = cache[u];
	if(ans != -1)
		return ans;
	if(!newg[u].size())
		ans = cur++;
	for(auto &it:newg[u])
		ans = max(ans, 1 + dfsLong(it));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	for(int i = 1; i <= n; i++)
		cin >> q[i];
	for(int i = 2; i <= n; i++)
	{
		sccAddEdge(p[i - 1], p[i]);
		sccAddEdge(q[i - 1], q[i]);
	}
	scc();
	for(int i=1;i<=n;i++)
	{
		for(auto it:g[i])
		{
			if(comp[i]!=comp[it])
			{
				newg[comp[i]].insert(comp[it]);
				indeg[comp[it]]++;
			}
		}
	}
	int mx = 0;
	for(int i = 1; i <= grp; i++)
	{
		int cur = dfsLong(i);
		mx = max(mx, cur);
	}	
	if(grp < k)
	{
		cout << "NO";
		return 0;
	}
	for(int i = 1; i <= grp; i++)
	{
		for(auto &it:contains[i])
			letter[it] = min(26LL, dfsLong(i));
	}	
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++)
		cout << (char)(26 - letter[i] + 'a');
	return 0;		
}