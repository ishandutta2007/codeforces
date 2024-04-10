#include <iostream>

#include <vector>

using namespace std;
int man[2005];
vector <int> adj[2005];
int dfs(int v)
{
	int s = 0;
	for(int i = 0; i < adj[v].size(); i ++)
	{
		int x = dfs(adj[v][i]);
		s = max(s, x);
	}
	return s + 1;
}
int main()
{
	int n, s = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> man[i];
		if(man[i] != -1)
		{
			adj[man[i]].push_back(i);
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		if(man[i] == -1)
		{
			int x = dfs(i);
			s = max(s, x);
		}
	}
	cout << s;
	return 0;
}