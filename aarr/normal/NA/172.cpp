#include <iostream>

#include <vector>

using namespace std;

vector <pair <int, int> > adj[105];
int mark[105][105];
void dfs(int x, int y, int c)
{
	mark[c][x] = y;
	for(int i = 0; i < adj[x].size(); i ++)
	{
		if(adj[x][i].second == c && mark[c][adj[x][i].first] == 0)
		{
			dfs(adj[x][i].first, y, c);
		}
	}
}
int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	for(int i = 0; i < m; i ++)
	{
		int x, y, z;
		cin >> x;
		cin >> y;
		cin >> z;
		adj[x].push_back({y, z});
		adj[y].push_back({x, z});
	}
	for(int i = 1; i <= m; i ++)
	{
		int nc = 1;
		for(int j = 1; j <= n; j ++)
		{
			if(mark[i][j] == 0)
			{
				dfs(j, nc, i);
				nc ++;
			}
		}
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i ++)
	{
		int s = 0;
		int x, y;
		cin >> x;
		cin >> y;
		for(int j = 0; j <= m; j ++)
		{
			if(mark[j][x] == mark[j][y] && mark[j][x] != 0)
			{
				s ++;
			}
		}
		cout << s << endl;
	}
	return 0;
}