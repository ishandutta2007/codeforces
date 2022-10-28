#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

//Push-Relabel Algorithm for Flows - Gap Heuristic, Complexity: O(V^3)
//To obtain the actual flow values, look at all edges with capacity > 0
//Zero capacity edges are residual edges

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

const int N=205;

int n, m;
int a[N], b[N];
int ans[N][N];
vector<int> g[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	PushRelabel flow(2*n+2);
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;	
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int reqd1=0, reqd2=0;
	for(int i=1;i<=n;i++)
	{
		reqd1+=a[i];
		reqd2+=b[i];
		flow.addEdge(0, i, a[i]);
		flow.addEdge(i, i+n, 1e5);
		flow.addEdge(i+n, 2*n+1, b[i]);
		for(auto j:g[i])
			flow.addEdge(i, j+n, 1e5);
	}
	int maxflow=flow.max_flow(0, 2*n+1);
	if(reqd1==reqd2 && reqd1==maxflow)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<=2*n+1;i++)
		{
			for(auto &e:flow.g[i])
			{
				if(e.cap!=0 && e.to>n && e.to-n!=i)
				{
					ans[i][e.to-n]=e.flow;
					ans[i][i]-=e.flow;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					ans[i][j]+=a[i];
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else
		cout<<"NO";
	return 0;
}