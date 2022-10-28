#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

typedef struct data
{
	int u, v, w, idx;

	data() {}
 
	data(int u, int v, int w, int idx) : u(u), v(v), w(w), idx(idx) {}
}edge;

int n, m, Q, cur = 0;
int connected;
int root[N], sz[N], ans[N];
vector<pair<int, int> > g[N];
data edges[N];
pair<int, int> q[N];

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

int nC2(int x)
{
	return x * (x - 1) / 2;
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

	cur -= nC2(sz[rt1]);
	cur -= nC2(sz[rt2]);
	cur += nC2(sz[rt1] + sz[rt2]);
	
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
	int idx = 1;
	for(int i=1;i<=m;i++)
	{
		while(idx <= Q && q[idx].first < edges[i].w)
		{
			ans[q[idx].second] = cur;
			idx++;
		}
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
	while(idx <= Q)
	{
		ans[q[idx].second] = cur;
		idx++;
	}
	return cost;
}

int32_t main()
{
	IOS;
	cin >> n >> Q;
	m = n - 1;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v, w;;
		cin >> u >> v >> w;
		add_edge(i, u, v, w);
	}
	for(int i = 1; i <= Q; i++)
	{
		cin >> q[i].first;
		q[i].second = i;
	}
	sort(q + 1, q + Q + 1);
	kruskalMST();
	for(int i = 1; i <= Q; i++)
		cout << ans[i] << " ";
	return 0;
}