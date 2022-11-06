#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int c[maxn] , a[maxn] , par[maxn];

vector<int> adj[maxn];

bool visited[maxn];

int mn;

void dfs(int v , int pe = -1)
{
	visited[v] = 1;

	for(auto e : adj[v])
		if(e != pe)
		{
			int u = a[e] ^ e ^ v;

			if(!visited[u])
			{
				par[u] = v;
				dfs(u , e);
			}
			else if(mn > maxn)
			{
				int w = v;

				mn = c[v];

				while(w != u)
				{
					w = par[w];
					mn = min(mn , c[w]);
				}
			}
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(par , -1 , sizeof par);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> c[i];

	for(int i = 0; i < n; i++)
	{
		cin >> a[i] , a[i]--;

		adj[i].pb(i);
		adj[a[i]].pb(i);
	}

	int res = 0;

	for(int i = 0; i < n; i++)
		if(!visited[i])
		{
			mn = 1e9;

			dfs(i);

			res += mn;
		}

	cout << res << endl;
}