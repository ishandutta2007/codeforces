#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;
 
struct edge
{
	int to, flow, cap, cost, rev;
};

struct MinCostMaxFlow
{
	int nodes;
	vector<int> prio, curflow, prevedge, prevnode, q, pot;
	vector<bool> inqueue;
	vector<vector<edge> > graph;
	MinCostMaxFlow() {}

	MinCostMaxFlow(int n): nodes(n), prio(n, 0), curflow(n, 0),
	prevedge(n, 0), prevnode(n, 0), q(n, 0), pot(n, 0), inqueue(n, 0), graph(n) {}

	void addEdge(int source, int to, int capacity, int cost)
	{
		edge a = {to, 0, capacity, cost, (int)graph[to].size()};
		edge b = {source, 0, 0, -cost, (int)graph[source].size()};
		graph[source].push_back(a);
		graph[to].push_back(b);
	}

	void bellman_ford(int source, vector<int> &dist)
	{
		fill(dist.begin(), dist.end(), INT_MAX);
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
				int newDist = dist[u] + e.cost;
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

	pair<int, int> minCostFlow(int source, int dest, int maxflow)
	{
		bellman_ford(source, pot);
		int flow = 0;
		int flow_cost = 0;
		while(flow < maxflow)
		{
			priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
			q.push({0, source});
			fill(prio.begin(), prio.end(), INT_MAX);
			prio[source] = 0;
			curflow[source] = INT_MAX;
			while(!q.empty())
			{
				int d = q.top().first;
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
					int newPrio = prio[u] + e.cost + pot[u] - pot[v];
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

int n, cur;
int b[N], pseudo[26][N], pseudo2[26][N], idx[N];
char s[N];
map<char, int> freq;

int32_t main()
{
	IOS;
	cin >> n;
	cur = n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		freq[s[i]]++;
	}
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	for(int i = 1, j = n; i <= j; i++, j--)
	{
		for(int k = 0; k <= 25; k++)
		{
			pseudo[k][i] = pseudo[k][j]  = ++cur;
			pseudo2[k][i] = pseudo2[k][j] = ++cur;
		}
	}
	int source = 0;
	for(int i = 0; i <= 25; i++)
		idx[i] = ++cur;
	int sink = ++cur;
	MinCostMaxFlow flow(cur + 5);
	for(int i = 0; i <= 25; i++)
	{
		char ch = (char) (i + 'a');
		flow.addEdge(0, idx[i], freq[ch], 0);
		for(int j = 1; j <= n; j++)
		{
			flow.addEdge(idx[i], pseudo[i][j], 100, 0);
			int gain = 0;
			if(s[j] - 'a' == i)
				gain = b[j];
			flow.addEdge(pseudo2[i][j], j, 1, -gain);
			if(j <= n / 2)
				flow.addEdge(pseudo[i][j], pseudo2[i][j], 1, 0);
		}
	}
	for(int i = 1; i <= n; i++)
		flow.addEdge(i, sink, 1, 0);
	pair<int, int> ans = flow.minCostFlow(source, sink, 1e5);
	cout << abs(ans.second);
	return 0;
}