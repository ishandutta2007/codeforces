#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

typedef struct data
{
	int u, v, w, idx;

	data() {}
 
	data(int u, int v, int w, int idx) : u(u), v(v), w(w), idx(idx) {}
}edge;

int n, m;
int connected;
int a[N], root[N], sz[N];
vector<pair<int, int> > g[N];
data edges[N];

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
	edges[idx]=edge(u, v, w, idx);
}

bool comp(data &d1, data &d2)
{
	return d1.w < d2.w;
}	

int kruskalMST()
{	
	init();
	int cost=0;
	sort(edges+1, edges+m+1, comp);
	for(int i=m;i>=1;i--)
	{
		int u=edges[i].u, v=edges[i].v, w=edges[i].w;
		int rt1=rt(u), rt2=rt(v);
		if(rt1==rt2)
			continue;
		else
		{
			cost+=w * sz[rt1] * sz[rt2] * 2;
			merge(rt1, rt2);
		}
	}
	return cost;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		int w=min(a[u], a[v]);
		add_edge(i, u, v, w);
	}
	double answer=kruskalMST();
	answer/=n;
	answer/=(n-1);
	cout<<fixed<<setprecision(12)<<answer;
	return 0;
}