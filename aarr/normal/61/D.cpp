#include <iostream>

#include <vector>

using namespace std;

vector< pair <int, int> > adj[100005];
int mark[100005];
int dfs(int v)
{
	mark[v] = 1;
	int x = 0;
	for(int i = 0; i < adj[v].size(); i ++)
	{
		if(mark[adj[v][i].first] == 0)
		{
			x = max(x, dfs(adj[v][i].first) + adj[v][i].second);
		}
	}
	return x;
}
int main()
{
	long long n, s = 0;
	cin >> n;
	for(int i = 1; i < n; i ++)
	{
		int x, y, z;
		cin >> x;
		cin >> y;
		cin >> z;
		adj[x].push_back({y, z});
		adj[y].push_back({x, z});
		s += z;
	}
	cout << s * 2 - dfs(1);
	return 0;
}