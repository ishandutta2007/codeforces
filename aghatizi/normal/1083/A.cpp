#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

vector<int> adj[maxn];

ll mx[maxn] , res;

int from[maxn] , to[maxn] , w[maxn] , t[maxn];

void dfs(int v , int p = -1)
{
	mx[v] = t[v];
	res = max(res , (ll)t[v]);

	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(u != p)
		{
			dfs(u , v);
			mx[u] -= w[e];

			res = max(res , mx[v] + mx[u]);
			mx[v] = max(mx[v] , mx[u] + t[v]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> t[i];

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b >> w[i];
		a-- , b--;

		adj[a].pb(i);
		adj[b].pb(i);

		from[i] = a , to[i] = b;
	}

	dfs(0);
	cout << res << endl;
}