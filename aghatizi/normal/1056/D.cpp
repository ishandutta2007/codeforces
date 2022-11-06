#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxb = 20;

vector<int> adj[maxn];

int sz[maxn];

void plant(int v)
{
	for(auto u : adj[v])
	{
		plant(u);
		sz[v] += sz[u];
	}

	if(adj[v].empty())
		sz[v]++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i < n; i++)
	{
		int p;
		cin >> p;
		p--;

		adj[p].pb(i);
	}

	plant(0);

	sort(sz , sz + n);
	for(int i = 0; i < n; i++)
		cout << sz[i] << " ";
	cout << endl;
}