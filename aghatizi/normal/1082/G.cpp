#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e3 + 20;
const int maxm = 4e3 + 20;
const ll inf = 1e18;	

template<int maxn , int maxm> struct Flow
{
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;
	G.n = n + m + 2 , G.m = 3 * m + n;

	ll sum = 0;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		G.add_edge(i + m , n + m + 1 , x);
	}

	for(int i = 0; i < m; i++)
	{
		int a , b , c;
		cin >> a >> b >> c;
		a-- , b--;

		G.add_edge(i , a + m , inf);
		G.add_edge(i , b + m , inf);
		G.add_edge(n + m , i , c);
		sum += c;
	}

	cout << sum - G.get_Flow(n + m , n + m + 1) << endl;
}