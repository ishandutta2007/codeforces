#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e6 + 20;

vector<int> adj[maxn];

int from[maxn] , to[maxn] , e , ver;

bool visited[maxn] , is[maxn];

void dfs(int v)
{
	visited[v] = 1;

	e += adj[v].size();
	ver++;

	for(auto u : adj[v])
		if(!visited[u])
			dfs(u);
}

int main()
{
	int m;
	scanf("%d", &m);

	vector<int> cmp;
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &from[i], &to[i]);

		cmp.pb(from[i]);
		cmp.pb(to[i]);
	}

	sort(cmp.begin() , cmp.end());
	cmp.resize(unique(cmp.begin() , cmp.end()) - cmp.begin());

	int n = cmp.size();

	for(int i = 0; i < m; i++)
	{
		from[i] = lower_bound(cmp.begin() , cmp.end() , from[i]) - cmp.begin();
		to[i] = lower_bound(cmp.begin() , cmp.end() , to[i]) - cmp.begin();

		adj[to[i]].pb(from[i]);
		adj[from[i]].pb(to[i]);
	}

	for(int i = n - 1; i >= 0; i--)
		if(!visited[i])
		{
			e = ver = 0;
			dfs(i);

			e /= 2;

			if(e > ver)
				return cout << -1 << endl , 0;
			if(e == ver - 1)
				is[i] = 1;
		}

	int tmp = n - 1;

	while(is[tmp])
		tmp--;

	cout << cmp[tmp] << endl;

}