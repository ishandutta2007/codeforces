#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 205;

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

	tuple<long long, vector<vector<edge> > > max_flow(int source, int dest)
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

		return {max_flow, g};
	}
};

bool prime(int x) 
{
	if (x <= 1) return 0;
	if (!(x & 1)) return x == 2;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0)
			return false;
	return true;
}

int n, a[N];
vector<int> odds, evens;

void dfs(int node, vector<vector<edge> >& g, vector<bool>& v, vector<int>& table) 
{
	v[node] = true;
	table.push_back(node);
	for (edge e : g[node]) 
	{
		if (e.to == 0 or e.to == n + 1 or v[e.to] or e.flow == 0)
			continue;
		dfs(e.to, g, v, table);
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]&1)
			odds.push_back(i);
		else 
			evens.push_back(i);
	}
	PushRelabel flow(n+2);
	int odd=odds.size();
	for(int i=1;i<=odds.size();i++) 
		flow.addEdge(0, i, 2);
	for(int i=1;i<=evens.size();i++)
		flow.addEdge(odd+i, n+1, 2);
	for(int i=0;i<odds.size();i++) 
	{
		for(int j=0;j<evens.size();j++) 
		{
			if (prime(a[odds[i]] + a[evens[j]])) 
				flow.addEdge(1+i, 1+odds.size()+j, 1);
		}
	}
	auto ans = flow.max_flow(0, n + 1);
	if (odds.size() != evens.size() or get<0>(ans) != n) 
	{
		cout << "Impossible";
		return 0;
	}
	vector<vector<edge> > g = get<1>(ans);
	vector<bool> v(n+1, 0);
	vector<vector<int> > tables;
	for (int i = 1; i <= n; i++) 
	{
		if (!v[i]) 
		{
			vector<int> table;
			dfs(i, g, v, table);
			tables.push_back(table);
		}
	}
	cout<<tables.size()<<endl;
	for (vector<int> table : tables) 
	{
		cout<<table.size()<<" ";
		for (auto &it:table)
		{
			if(it<=odd)
				cout<<odds[it-1]<<" ";
			else
				cout<<evens[it-odd-1]<<" ";
		}
		cout<<endl;
	}
}