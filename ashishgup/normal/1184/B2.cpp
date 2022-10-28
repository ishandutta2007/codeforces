#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

struct edge
{
	int from, to, cap, flow, index;
	edge(int from, int to, int cap, int flow, int index):
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel
{
	int n;
	vector<vector<edge> > g;
	vector<long long> excess;
	vector<int> height, active, count;
	queue<int> Q;

	PushRelabel(int n):
		n(n), g(n), excess(n), height(n), active(n), count(2*n) {}

	void addEdge(int from, int to, int cap)
	{
		g[from].push_back(edge(from, to, cap, 0, g[to].size()));
		if(from==to)
			g[from].back().index++;
		g[to].push_back(edge(to, from, 0, 0, g[from].size()-1));
	}

	void enqueue(int v)
	{
		if(!active[v] && excess[v] > 0)
		{
			active[v]=true;
			Q.push(v);
		}
	}

	void push(edge &e)
	{
		int amt=(int)min(excess[e.from], (long long)e.cap - e.flow);
		if(height[e.from]<=height[e.to] || amt==0)
			return;
		e.flow += amt;
		g[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		enqueue(e.to);
	}

	void relabel(int v)
	{
		count[height[v]]--;
		int d=2*n;
		for(auto &it:g[v])
		{
			if(it.cap-it.flow>0)
				d=min(d, height[it.to]+1);
		}
		height[v]=d;
		count[height[v]]++;
		enqueue(v);
	}

	void gap(int k)
	{
		for(int v=0;v<n;v++)
		{
			if(height[v]<k)
				continue;
			count[height[v]]--;
			height[v]=max(height[v], n+1);
			count[height[v]]++;
			enqueue(v);
		}
	}

	void discharge(int v)
	{
		for(int i=0; excess[v]>0 && i<g[v].size(); i++)
			push(g[v][i]);
		if(excess[v]>0)
		{
			if(count[height[v]]==1)
				gap(height[v]);
			else
				relabel(v);
		}
	}

	long long max_flow(int source, int dest)
	{
		count[0] = n-1;
		count[n] = 1;
		height[source] = n;
		active[source] = active[dest] = 1;
		for(auto &it:g[source])
		{
			excess[source]+=it.cap;
			push(it);
		}

		while(!Q.empty())
		{
			int v=Q.front();
			Q.pop();
			active[v]=false;
			discharge(v);
		}

		long long max_flow=0;
		for(auto &e:g[source])
			max_flow+=e.flow;

		return max_flow;
	}
};

const int N = 1005;

int n, m;
int s, b, k, h;
int x[N], a[N], f[N], y[N], d[N];
vector<pair<int, int> > in[N];
vector<int> out[N];
int dist[N][N];

void FloydWarshall()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
}


int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j)
				dist[i][j] = 1e9; 
	PushRelabel flow(2005);
	int src = 0;
	int dest = 2003;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		dist[u][v] = dist[v][u] = 1;
	}
	cin >> s >> b >> k >> h;
	for(int i = 1; i <= s; i++)
	{
		flow.addEdge(0, i, 1);
		cin >> x[i] >> a[i] >> f[i];	
	}
	for(int i = 1; i <= b; i++)
	{
		flow.addEdge(i + 1000, dest, 1);
		cin >> y[i] >> d[i];
	}
	FloydWarshall();
	for(int i = 1; i <= s; i++)
	{
		for(int j = 1; j <= b; j++)
		{
			if(dist[x[i]][y[j]] <= f[i] && a[i] >= d[j])
			{
				flow.addEdge(i, 1000 + j, 1);
			}
		}
	}
	int ans = flow.max_flow(src, dest);
	ans *= k;
	ans = min(ans, s * h);
	cout << ans;
	return 0;
}