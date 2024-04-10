#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=4e5+5;

typedef struct data
{
	int u, v, w, idx;

	data() {}
 
	data(int u, int v, int w, int idx) : u(u), v(v), w(w), idx(idx) {}
}edge;

int n, m;
pair<int, int> a[N];
int connected;
int root[N], sz[N];
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
	int idx=1;
	for(int i=1;i<=m;i++)
	{	
		int u=edges[i].u, v=edges[i].v, w=edges[i].w;
		int rt1=rt(u), rt2=rt(v);
		if(rt1==rt2)
			continue;
		else
		{
			cost+=w;
			merge(rt1, rt2);
		}
	}
	return cost;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1, a+n+1);
	for(int i=1;i<=m;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		add_edge(i, u, v, w);
	}
	for(int i=m+1;i<=m+n-1;i++)
		add_edge(i, a[1].second, a[i-m+1].second, a[1].first+a[i-m+1].first);
	m+=n-1;
	cout<<kruskalMST();
	return 0;
}