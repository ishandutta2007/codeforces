#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e5 + 20;
const int mod = 1e9 + 7;

ll c[maxn];

int pw[maxn] , from[maxn] , to[maxn];

vector<int> edge[maxn] , adj[maxn];

bool visited[maxn];

void dfs(int v)
{
	visited[v] = 1;

	for(auto u : adj[v])
		if(!visited[u])
			dfs(u);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pw[0] = 1;
	for(int i = 1; i < maxn; i++)
		pw[i] = 2LL * pw[i - 1] % mod;

	int n , m , k;
	cin >> n >> m >> k;

	for(int i = 0; i < n; i++)
		cin >> c[i];

	vector<ll> cmp;
	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		cmp.pb(c[a] ^ c[b]);

		from[i] = a , to[i] = b;
	}

	sort(cmp.begin() , cmp.end());
	cmp.resize(unique(cmp.begin() , cmp.end()) - cmp.begin());

	for(int i = 0; i < m; i++)
	{
		int k = lower_bound(cmp.begin() , cmp.end() , c[from[i]] ^ c[to[i]]) - cmp.begin();

		edge[k].pb(i);
	}

	int res = 1LL * (pw[k] - (int)cmp.size() + mod) * pw[n] % mod;

	for(int i = 0; i < (int)cmp.size(); i++)
	{
		vector<int> vert;
		for(auto e : edge[i])
		{
			adj[from[e]].pb(to[e]);
			adj[to[e]].pb(from[e]);

			vert.pb(from[e]);
			vert.pb(to[e]);
		}

		sort(vert.begin() , vert.end());
		vert.resize(unique(vert.begin() , vert.end()) - vert.begin());

		int c = 0;
		for(auto v : vert)
			if(!visited[v])
				dfs(v) , c++;

		for(auto v : vert)
			visited[v] = 0 , adj[v].clear();

		res += 1LL * pw[c + n - (int)vert.size()];
		res %= mod;
	}

	cout << res << endl;

}