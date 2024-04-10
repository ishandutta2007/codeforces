#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

vector<int> adj[maxn];

bool visited[maxn];

ll tmp;

void dfs(int v)
{
	visited[v] = 1;

	for(auto u : adj[v])
	{
		if(u % v == 0)
			tmp += u / v;
		else
			tmp += v / u;

		if(!visited[u])
			dfs(u);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 2; i <= n; i++)
		for(int j = 2 * i; j <= n; j += i)
			adj[i].pb(j) , adj[j].pb(i);

	ll res = 0;
	for(int i = 2; i <= n; i++)
		if(!visited[i])
		{
			tmp = 0;
			dfs(i);

			res = max(res , tmp * 2);
		}

	cout << res << endl;
}