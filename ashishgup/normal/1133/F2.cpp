#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 2e5 + 5;

typedef struct data
{
	int u, v, w, idx;

	data() {}
 
	data(int u, int v, int w, int idx) : u(u), v(v), w(w), idx(idx) {}
}edge;

int n, m, d, mn, node;
int connected;
int root[N], sz[N];
vector<pair<int, int> > g[N];
set<int> ng[N];
data edges[N];
int deg[N];
bool vis2[N];
vector<pair<int, int> > answer;

void init()
{
	for(int i=1;i<=n;i++)
	{
		root[i]=i;
		sz[i]=1;
	}
	connected=n;
}

int rt(int k)
{
	while(k!=root[k])
	{
		root[k]=root[root[k]];
		k=root[k];
	}
	return k;
}

void merge(int u, int v)
{
	int rt1=rt(u);
	int rt2=rt(v);

	if(rt1==rt2)
		return;

	connected--;

	if(sz[rt1]>sz[rt2])
		swap(rt1, rt2);

	sz[rt2]+=sz[rt1];
	sz[rt1]=0;
	root[rt1]=root[rt2];
}

void add_edge(int idx, int u, int v, int w)
{
	g[u].push_back({v, w});
	g[v].push_back({u, w});
	ng[v].insert(u);
	ng[u].insert(v);
	edges[idx]=edge(u, v, w, idx);
}

bool comp(data &d1, data &d2)
{
	return min(d1.u, d1.v) < min(d2.u, d2.v);
}	

int kruskalMST()
{	
	int cost=0;
	sort(edges+1, edges+m+1, comp);
	for(int i=1;i<=m;i++)
	{
		int u=edges[i].u, v=edges[i].v, w=edges[i].w;
		int rt1=rt(u), rt2=rt(v);
		if(rt1==rt2)
			continue;
		else if(d==0 && (u==1 || v==1))
			continue;
		else
		{
			answer.push_back({u, v});
			d -= (u==1 || v==1);
			cost += w;
			merge(rt1, rt2);
		}
	}
	return cost;
}

void dfs(int u)
{	
	if(vis2[u])
		return;
	if(ng[u].find(1) != ng[u].end())
		node = u;
	vis2[u] = 1;
	for(auto &it:g[u])
	{
		if(it.first==1)
			continue;
		dfs(it.first);
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>d;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		add_edge(i, u, v, 1);
		deg[u]++;
		deg[v]++;
	}
	if(d > deg[1])
	{
		cout<<"NO";
		return 0;
	}
	init();
	for(int i=2;i<=n;i++)
	{
		if(!vis2[i])
		{
			dfs(i);
			mn++;
			answer.push_back({1, node});
			merge(1, node);
		}
	}
	if(d < mn)
	{
		cout<<"NO";
		return 0;
	}
	d -= mn;
	cout<<"YES"<<endl;
	kruskalMST();
	for(auto &it:answer)
		cout<<it.first<<" "<<it.second<<endl;
	return 0;
}