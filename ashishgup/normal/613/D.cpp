#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;
const int LG=19;

int n, k, q, ans=0;
int tim=0;
int parent[LG][N];
int tin[N], tout[N], level[N], vertices[N], mark[N];
vector<int> g[N], tree[N];

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

bool isancestor(int u, int v) //Check if u is an ancestor of v
{
	return (tin[u]<=tin[v]) && (tout[v]<=tout[u]);
}

int dfs2(int k)
{
	vector<int> v;
	for(auto it:tree[k])
		v.push_back(dfs2(it));
	if(mark[k])
	{
		for(auto it:v)
			if(it>0)
				ans++;
		return 1;
	}
	else
	{
		int ct=0;
		for(auto it:v)
			ct+=it;
		if(ct>1)
		{
			ans++;
			return 0;
		}
		return ct;
	}
}

int work()
{
	for(int i=1;i<=k;i++)
		mark[vertices[i]]=1;
	bool adjacent=0;
	for(int i=1;i<=k;i++)
	{
		if(mark[parent[0][vertices[i]]])
		{
			adjacent=1;
			break;
		}
	}
	if(adjacent)
	{
		for(int i=1;i<=k;i++)
			mark[vertices[i]]=0;
		return -1;
	}
	sort(vertices+1, vertices+k+1, [](int a, int b)
	{
		return tin[a]<tin[b];
	});
	int idx=k;
	for(int i=1;i<idx;i++)
		vertices[++k]=LCA(vertices[i], vertices[i+1]);
	sort(vertices+1, vertices+k+1);
	k=unique(vertices+1, vertices+k+1) - vertices - 1;
	sort(vertices+1, vertices+k+1, [](int a, int b)
	{
		return tin[a]<tin[b];
	});
	stack<int> s;
	s.push(vertices[1]);
	for(int i=2;i<=k;i++)
	{
		while(!isancestor(s.top(), vertices[i]))
			s.pop();
		tree[s.top()].push_back(vertices[i]);
		s.push(vertices[i]);
	}
	ans=0;
	dfs2(vertices[1]);
	for(int i=1;i<=k;i++)
	{
		tree[vertices[i]].clear();
		mark[vertices[i]]=0;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0, 1);
	precompute();
	cin>>q;
	while(q--)
	{
		cin>>k;
		for(int i=1;i<=k;i++)
			cin>>vertices[i];
		cout<<work()<<endl;
	}
	return 0;
}