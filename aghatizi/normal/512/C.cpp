#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e2 + 20;
const int maxm = maxn * maxn + 20;

template<int maxn , int maxm> struct Flow
{
	static const ll inf = 1e18;
	int from[maxm * 2] , to[maxm * 2] , id , d[maxn];
	ll cap[maxm * 2];
	int n , m;
	vector<int> adj[maxn] , AdjBfs[maxn];

	Flow(int n_ = 0 , int m_ = 0)
	{
		n = n_ , m = m_;
		memset(from , 0 , sizeof from);
		memset(to , 0 , sizeof to);
		memset(cap , 0 , sizeof cap);
		memset(d , 0 , sizeof d);
		id = 0;
	}

	void add_edge(int v , int u , ll c)
	{
		adj[v].pb(id);
		from[id] = v , to[id] = u , cap[id] = c;
		id++;

		adj[u].pb(id);
		from[id] = u , to[id] = v , cap[id] = 0;
		id++;
	}

	bool bfs(int S , int T)
	{
		queue<int> q;
		memset(d , 63 , sizeof d);
		d[S] = 0;
		q.push(S);

		for(int i = 0; i < n; i++)
			AdjBfs[i].clear();

		while(!q.empty())
		{
			int v = q.front();
			q.pop();

			for(auto e : adj[v])
			{
				int u = to[e];

				if(cap[e] && d[u] > d[v] + 1)
				{
					d[u] = d[v] + 1;
					q.push(u);
					AdjBfs[v].pb(e);
				}
				else if(cap[e] && d[u] == d[v] + 1)
					AdjBfs[v].pb(e);
			}
		}

		return (d[T] < maxn);
	}

	ll dfs(int v , int T , ll flow = inf)
	{
		if(v == T || !flow)
			return flow;

		ll res = 0;
		for(int i = 0; i < (int)AdjBfs[v].size(); i++)
		{
			int e = AdjBfs[v][i] , u = to[e];
			if(cap[e])
			{
				ll x = dfs(u , T , min(flow , cap[e]));
				flow -= x , cap[e] -= x , cap[e ^ 1] += x;
				res += x;
			}

			if(!cap[e])
				swap(AdjBfs[v][i] , AdjBfs[v].back()) , AdjBfs[v].pop_back();
		}

		return res;
	}

	ll get_Flow(int S , int T)
	{
		ll res = 0;
		while(bfs(S , T))
			res += dfs(S , T);

		return res;
	}
};

Flow<maxn , maxm> G;

int a[maxn];
vector<int> x[2] , adj[maxn] , tmp;
vector<vector<int>> ans;
bool visited[maxn];

bool is_prime(int p)
{
	for(int i = 2; i * i <= p; i++)
		if(p % i == 0)
			return 0;
	return 1;
}

void dfs(int v)
{
	visited[v] = 1;
	tmp.pb(v);
	
	for(auto u : adj[v])
		if(!visited[u])
			dfs(u);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i] , x[a[i]&1].pb(i);

	if(x[0].size() != x[1].size())
		return cout << "Impossible" << endl , 0;

	int S = n , T = S + 1;

	G.n = n + 2;
	for(auto i : x[0])
		for(auto j : x[1])
			if(is_prime(a[i] + a[j]))
				G.add_edge(i , j , 1);

	for(auto i : x[0])
		G.add_edge(S , i , 2);
	for(auto i : x[1])
		G.add_edge(i , T , 2);

	if(G.get_Flow(S , T) != n)
		return cout << "Impossible" << endl , 0;

	for(int i = 0; i < G.id; i += 2)
		if(G.from[i] != S && G.to[i] != T && !G.cap[i])
		{
			adj[G.from[i]].pb(G.to[i]);
			adj[G.to[i]].pb(G.from[i]);
		}

	for(int i = 0; i < n; i++)
		if(!visited[i])
		{
			tmp.clear();
			dfs(i);
			ans.pb(tmp);
		}

	cout << ans.size() << endl;
	for(auto x : ans)
	{
		cout << x.size() << " ";
		for(auto y : x)
			cout << y + 1 << " ";
		cout << endl;
	}
}