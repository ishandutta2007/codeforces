#include <iostream>

#include <vector>

using namespace std;

vector<int> adj[200005];
int color[200005];
void dfs(int v, int c1)
{
	int clr = 1;
	for(int i = 0; i < adj[v].size(); i ++)
	{
		while(clr == color[v] || clr == c1)
		{
			clr ++;
		}
		if(color[adj[v][i]] == 0)
		{
			color[adj[v][i]] = clr;
			dfs(adj[v][i], color[v]);
			clr ++;
		}
	}
}
int main()
{
	int n, maxi = 0;
	cin >> n;
	for(int i = 1; i < n; i ++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i <= n; i ++)
	{
		maxi = max(maxi, (int) adj[i].size());
	}
	maxi ++;
	cout << maxi << endl;
	color[1] = 1;
	dfs(1, 0);
	for(int i = 1; i <= n; i ++)
	{
		cout << color[i] << " ";
	}
	return 0;
}