#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ld long double

const int maxn = 8e2 + 20;
const int maxm = maxn * maxn + 20;
const ll inf = 1e18;	

ld cost[maxm] , d[maxn] , res;
int x[maxn] , y[maxn] , id , par[maxn] , flow , from[maxm] , to[maxm] , cap[maxm];

vector<int> adj[maxn];

bool is_in[maxn];

ld dist(int i , int j)
{
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

void add_edge(int a , int b , int c , ld val)
{
	adj[a].pb(id);
	from[id] = a , to[id] = b , cost[id] = val , cap[id] = c , id++;
	adj[b].pb(id);
	from[id] = b , to[id] = a , cost[id] = -val , cap[id] = 0 , id++;
}

bool spfa(int S , int T)
{
	queue<int> q;
	fill(d , d + maxn , inf);
	memset(is_in , 0 , sizeof is_in);

	d[S] = 0;
	q.push(S);
	is_in[S] = 1;


	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		is_in[v] = 0;

		for(auto e : adj[v])
		{
			int u = to[e];

			if(cap[e] > 0 && d[u] > d[v] + cost[e])
			{
				d[u] = d[v] + cost[e];
				par[u] = e;
				if(!is_in[u])
					q.push(u) , is_in[u] = 1;
			}
		}
	}

	if(d[T] < inf / 10)
	{
		int mn = 1e9 , tmpT = T;
		while(T != S)
		{
			mn = min(mn , cap[par[T]]);
			T = from[par[T]];
		}

		T = tmpT;
		flow += mn;
		while(T != S)
		{
			cap[par[T]] -= mn , cap[par[T] ^ 1] += mn;
			res += mn * cost[par[T]];
			T = from[par[T]];
		}
		return 1;
	}
	else
		return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(y[i] > y[j])
				add_edge(i * 2 , j * 2 + 1 , 1 , dist(i , j));

	int S = n * 2 , T = S + 1;
	for(int i = 0; i < n; i++)
	{
		add_edge(S , i * 2 , 2 , 0);
		add_edge(i * 2 + 1 , T , 1 , 0);
	}

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	for(int i = 0; i <= T; i++)
		shuffle(adj[i].begin() , adj[i].end() , rng);

	while(spfa(S , T));
	if(flow < n - 1)
		return cout << -1 << endl , 0;

	cout << fixed << setprecision(20) << res << endl;
}