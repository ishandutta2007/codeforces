#include <iostream>

#include <vector>

using namespace std;

vector<int> adj[55];
int nparts = 1;
vector<int> parts[55];
int mark[55];
void dfs(int v)
{
	mark[v] = nparts;
	parts[nparts].push_back(v);
	for(int i = 0; i < adj[v].size(); i ++)
	{
		if(mark[adj[v][i]] == 0)
		{
			dfs(adj[v][i]);
		}
	}
}
int main()
{
	int n, m;
	long long ans = 1;
	cin >> n;
	cin >> m;
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i <= n; i ++)
	{
		if(mark[i] == 0)
		{
			dfs(i);
			nparts ++;
		}
	}
	for(int i = 1; i < 55; i ++)
	{
		for(int j = 1; j < parts[i].size(); j ++)
		{
			ans *= 2;
			//cout << parts[i][j] << " ";
		}
		//cout << endl;
	}
	cout << ans;
	return 0;
}