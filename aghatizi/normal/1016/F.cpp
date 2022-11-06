#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

vector<int> adj[maxn];

int from[maxn] , to[maxn] , w[maxn];

ll d[2][maxn] , tmp[maxn];

bool has[maxn];

void dfs(int v , int k , int p = -1)
{
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(u != p)
		{
			d[k][u] = d[k][v] + w[e];
			dfs(u , k , v);
		}
	}
}

int main()
{
	int n , m;
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		scanf("%d%d%d", &a, &b, &w[i]);
		a-- , b--;

		adj[a].pb(i);
		adj[b].pb(i);

		from[i] = a , to[i] = b;
	}

	dfs(0 , 0);
	dfs(n - 1 , 1);

	// max(min(d[0][v] + d[1][u] , d[0][u] + d[1][v]))

	// d[0][v] - d[1][v] <= d[0][u] - d[1][u]

	vector<pair<ll , int> > shit;
	for(int i = 0; i < n; i++)
		tmp[i] = d[0][i] - d[1][i] , shit.pb({tmp[i] , i});

	sort(shit.begin() , shit.end());

	set<pair<ll , int> > st;

	ll mx = 0;
	for(auto ind : shit)
	{
		int v = ind.second;

		st.erase({d[0][v] , v});

		for(auto e : adj[v])
		{
			int u = from[e] ^ to[e] ^ v;

			if(has[u])
				st.erase({d[0][u] , u});
		}

		if(!st.empty())
			mx = max(mx , (st.rbegin() -> first) + d[1][v]);

		for(auto e : adj[v])
		{
			int u = from[e] ^ to[e] ^ v;

			if(has[u])
				st.insert({d[0][u] , u});
		}

		has[v] = 1;
		st.insert({d[0][v] , v});
	}

	for(int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);

		if(mx >= d[0][n - 1] - x)
			printf("%I64d\n", d[0][n - 1]);
		else
			printf("%I64d\n", mx + x);
	}
}