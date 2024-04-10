#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

//Works for negative costs, but does not work for negative cycles
//Complexity: O(min(E^2 *V log V, E logV * flow))

struct edge
{
	int to, flow, cap;
	double cost;
	int rev;
};

struct MinCostMaxFlow
{
	int nodes;
	vector<int> curflow, prevedge, prevnode, q;
	vector<double> pot, prio;
	vector<bool> inqueue;
	vector<vector<edge> > graph;
	MinCostMaxFlow() {}

	MinCostMaxFlow(int n): nodes(n), prio(n, 0), curflow(n, 0),
	prevedge(n, 0), prevnode(n, 0), q(n, 0), pot(n, 0), inqueue(n, 0), graph(n) {}

	void addEdge(int source, int to, int capacity, double cost)
	{
		edge a = {to, 0, capacity, cost, (int)graph[to].size()};
		edge b = {source, 0, 0, -cost, (int)graph[source].size()};
		graph[source].push_back(a);
		graph[to].push_back(b);
	}

	void bellman_ford(int source, vector<double> &dist)
	{
		fill(dist.begin(), dist.end(), 1e9);
		dist[source] = 0;
		int qt=0;
		q[qt++] = source;
		for(int qh=0;(qh-qt)%nodes!=0;qh++)
		{
			int u = q[qh%nodes];
			inqueue[u] = false;
			for(auto &e : graph[u])
			{
				if(e.flow >= e.cap)
					continue;
				int v = e.to;
				double newDist = dist[u] + e.cost;
				if(dist[v] > newDist)
				{
					dist[v] = newDist;
					if(!inqueue[v])
					{
						inqueue[v] = true;
						q[qt++ % nodes] = v;
					}
				}
			}
		}
	}

	pair<int, double> minCostFlow(int source, int dest, int maxflow)
	{
		bellman_ford(source, pot);
		int flow = 0;
		double flow_cost = 0;
		while(flow < maxflow)
		{
			priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > q;
			q.push({0, source});
			fill(prio.begin(), prio.end(), INT_MAX);
			prio[source] = 0;
			curflow[source] = INT_MAX;
			while(!q.empty())
			{
				double d = q.top().first;
				int u = q.top().second;
				q.pop();
				if(d != prio[u])
					continue;
				for(int i=0;i<graph[u].size();i++)
				{
					edge &e=graph[u][i];
					int v = e.to;
					if(e.flow >= e.cap)
						continue;
					double newPrio = prio[u] + e.cost + pot[u] - pot[v];
					if(prio[v] > newPrio)
					{
						prio[v] = newPrio;
						q.push({newPrio, v});
						prevnode[v] = u;
						prevedge[v] = i;
						curflow[v] = min(curflow[u], e.cap - e.flow);
					}
				}
			}
			if(prio[dest] == INT_MAX)
				break;
			for(int i=0;i<nodes;i++)
				pot[i]+=prio[i];
			int df = min(curflow[dest], maxflow - flow);
			flow += df;
			for(int v=dest;v!=source;v=prevnode[v])
			{
				edge &e = graph[prevnode[v]][prevedge[v]];
				e.flow += df;
				graph[v][e.rev].flow -= df;
				flow_cost += df * e.cost;
			}
		}
		return {flow, flow_cost};
	}
};

const int N=405;

int n;
int x[N], y[N];

double dist(int i, int j)
{
	double xdiff=x[j]-x[i];
	double ydiff=y[j]-y[i];
	return sqrtl(xdiff*xdiff + ydiff*ydiff);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	MinCostMaxFlow flow(2*n+2);
	for(int i=1;i<=n;i++)
	{
		flow.addEdge(0, i, 2, 0);
		flow.addEdge(i+n, 2*n+1, 1, 0);
		for(int j=1;j<=n;j++)
		{
			if(y[i]<=y[j])
				continue;
			flow.addEdge(i, j+n, 1, dist(i, j));
		}
	}
	pair<int, double> ans=flow.minCostFlow(0, 2*n+1, 1e9);
	if(ans.first!=n-1)
		cout<<"-1";
	else
		cout<<fixed<<setprecision(12)<<ans.second;
	return 0;
}