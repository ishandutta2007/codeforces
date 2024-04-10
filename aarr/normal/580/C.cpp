#include <iostream>

#include <vector>

using namespace std;

vector<int> adj[100005];
int mark[100005];
int a[100005];
int ans = 0, n, m;
void dfs(int v, int k)
{
	mark[v] = 1;
	if(a[v] == 1)
	{
		k ++;
	}
	else
	{
		if(k <= m)
		{
			k = 0;
		}
	}
	if(k <= m && (int) adj[v].size() == 1 && v != 1)
	{
		//cout << v << " "  << k << " " << 72 << endl;
		ans ++;
	}
	for(int i = 0; i < adj[v].size(); i ++)
	{
		if(mark[adj[v][i]] == 0)
		{
			dfs(adj[v][i], k);
		}
	}
}
int main()
{
	cin >> n;
	cin >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 1; i < n; i ++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}