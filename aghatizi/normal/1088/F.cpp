#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e5 + 20;
const int maxb = 20;

vector<int> adj[maxn];

int a[maxn] , par[maxn][maxb];

void dfs(int v , int p = -1)
{
	for(auto u : adj[v])
		if(u != p)
		{
			par[u][0] = v;
			dfs(u , v);
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
		cin >> a[i];

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	int root = min_element(a , a + n) - a;
	par[root][0] = root;
	dfs(root);

	for(int j = 1; j < maxb; j++)
		for(int i = 0; i < n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];

	ll res = 0;
	for(int i = 0; i < n; i++)
		if(i != root)
		{
			ll mn = 1e15;
			for(int j = 0; j < maxb; j++)
				mn = min(mn , a[i] + a[par[i][j]] + 1LL * a[par[i][j]] * j);

			res += mn;
		}

	cout << res << endl;
}