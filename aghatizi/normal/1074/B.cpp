#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;

vector<int> adj[maxn];

int par[maxn];

bool is[maxn] , hide[maxn];

void dfs(int v , int p = -1)
{
	for(auto u : adj[v])
		if(u != p)
			par[u] = v , dfs(u , v);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while(T--)
	{
		memset(hide , 1 , sizeof hide);
		memset(par , -1 , sizeof par);
		memset(is , 0 , sizeof is);

		for(int i = 0; i < maxn; i++)
			adj[i].clear();

		int n;
		cin >> n;

		for(int i = 0; i < n - 1; i++)
		{
			int a , b;
			cin >> a >> b;
			a-- , b--;

			adj[a].pb(b);
			adj[b].pb(a);
		}

		int k1;
		cin >> k1;

		int root = -1;
		for(int i = 0; i < k1; i++)
		{
			int x;
			cin >> x;
			x--;

			hide[x] = 0;
			root = x;
		}
		dfs(root);

		int k2;
		cin >> k2;
		for(int i = 0; i < k2; i++)
		{
			int x;
			cin >> x;
			x--;

			is[x] = 1;
			root = x;
		}

		cout << "B " << root + 1 << endl;
		cin >> root;
		root--;

		while(hide[root])
			root = par[root];

		int tmp = root;
		cout << "A " << root + 1 << endl;
		cin >> root;
		root--;

		int res = -1;
		if(is[root])
			res = tmp + 1;

		cout << "C " << res << endl;
	}
}