#include <iostream>

#include <vector>

using namespace std;

int init[100005];
int goal[100005];
vector<int> adj[100005];
int mark[100005];
vector<int> ans;
void dfs(int v, int x, int y)
{
	mark[v] = 1;
	if((init[v] + goal[v] + x) % 2 == 1)
	{
		ans .push_back(v);
		x ++;
	}
	for(int i = 0; i < adj[v].size(); i ++)
	{
		if(mark[adj[v][i]] == 0)
		{
			dfs(adj[v][i], y, x);
		} 
	}
}
int main()
{
	int n;
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
		cin >> init[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		cin >> goal[i];
	}
	dfs(1, 0, 0);
	cout << ans.size();
	for(int i = 0; i < ans.size(); i ++)
	{
		cout << endl << ans[i];
	}
	return 0;
}