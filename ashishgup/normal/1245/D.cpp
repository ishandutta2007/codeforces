#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int M = 2e3 + 5;
const int N = M * M + M;

typedef struct data
{
	int u, v, w, idx;

	data() {}
 
	data(int u, int v, int w, int idx) : u(u), v(v), w(w), idx(idx) {}
}edge;

int n, m, L, R;
int x[M], y[M], c[M], k[M];
int connected;
int root[M], sz[M];
vector<pair<int, int> > g[M];
data edges[N];

void init()
{
	for(int i=1;i<=n+1;i++)
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

void kruskalMST()
{	
	init();
	int cost=0;
	sort(edges+1, edges+m+1, comp);
	set<int> s;
	vector<pair<int, int> > out;
	for(int i=1;i<=m;i++)
	{
		int u=edges[i].u, v=edges[i].v, w=edges[i].w;
		int rt1=rt(u), rt2=rt(v);
		if(rt1==rt2)
			continue;
		else
		{
			if(u == n + 1)
				s.insert(v);
			else if(v == n + 1)
				s.insert(u);
			else
				out.push_back({u, v});
			cost+=w;
			merge(rt1, rt2);
		}
	}
	cout << cost << endl;
	cout << s.size() << endl;
	for(auto &it:s)
		cout << it << " ";
	cout << endl;
	cout << out.size() << endl;
	for(auto &it:out)
		cout << it.first << " " << it.second << endl;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	for(int i = 1; i <= n; i++)
		cin >> k[i];
	int extra = n + 1;
	int idx = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			++idx;
			add_edge(idx, i, j, (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]));
		}
	}
	L = idx + 1;
	for(int i = 1; i <= n; i++)
	{
		++idx;
		add_edge(idx, extra, i, c[i]);
	}
	R = idx;
	m = idx;
	kruskalMST();
	return 0;
}