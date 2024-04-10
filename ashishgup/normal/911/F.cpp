#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;
const int LG = log2(N) + 1;

int n;
int tim=0;
int parent[LG][N];
int tin[N], tout[N], level[N];
vector<int> g[N];

struct data
{
	int a, b, c;
	int dist; 
};

void dfs(int k, int par, int lvl)
{
	tin[k]=++tim;
	parent[0][k]=par;
	level[k]=lvl;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, lvl+1);
	}
	tout[k]=tim;
}

int walk(int u, int h)
{
	for(int i=LG-1;i>=0;i--)
	{
		if((h>>i) & 1)
			u = parent[i][u];
	}
	return u;
}

void precompute()
{
	for(int i=1;i<LG;i++)
		for(int j=1;j<=n;j++)
			if(parent[i-1][j])
				parent[i][j]=parent[i-1][parent[i-1][j]];
}

int LCA(int u, int v)
{
	if(level[u]<level[v])
		swap(u,v);
	int diff=level[u]-level[v];
	for(int i=LG-1;i>=0;i--)
	{
		if((1<<i) & diff)
		{
			u=parent[i][u];
		}
	}
	if(u==v)
		return u;
	for(int i=LG-1;i>=0;i--)
	{
		if(parent[i][u] && parent[i][u]!=parent[i][v])
		{
			u=parent[i][u];
			v=parent[i][v];
		}
	}
	return parent[0][u];
}

int dist(int u, int v)
{
	return level[u] + level[v] - 2 * level[LCA(u, v)];
}

int node, mx;

void dfs1(int u, int par, int dist)
{
	if(dist > mx)
	{
		node = u;
		mx = dist;
	}
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs1(it, u, dist + 1);
	}
}

bool comp(data &d1, data &d2)
{
	return d1.dist > d2.dist;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1, 1);
	precompute();
	mx = -1;
	int u, v;
	dfs1(1, 0, 0);
	mx = -1;
	u = node;
	dfs1(u, 0, 0);
	v = node;
	vector<data> ans, diam;
	int val = 0;
	for(int i = 1; i <= n; i++)
	{
		if(dist(i, u) + dist(i, v) == dist(u, v) && dist(i, u) != 0)
		{
			struct data cur;
			cur.a = u;
			cur.b = i;
			cur.c = i;
			cur.dist = dist(i, u);
			val += cur.dist;
			diam.push_back(cur);
		}
		else if(dist(i, u) + dist(i, v) > dist(u, v))
		{
			struct data cur;
			int node = u;
			if(dist(i, v) > dist(i, u))
				node = v;
			cur.a = node;
			cur.b = i;
			cur.c = i;
			cur.dist = dist(i, node);
			val += cur.dist;
			ans.push_back(cur);
		}
	}
	sort(ans.begin(), ans.end(), comp);
	sort(diam.begin(), diam.end(), comp);
	cout << val << endl;
	for(auto &it:ans)
		cout << it.a << " " << it.b << " " << it.c << endl;
	for(auto &it:diam)
		cout << it.a << " " << it.b << " " << it.c << endl;
	return 0;
}