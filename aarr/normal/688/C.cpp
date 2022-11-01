#include <iostream>

#include <vector>

using namespace std;

vector<int> adj[100005];
int mark[100005];
vector<int> p;
vector<int> q;
bool b = true;
int dfs(int v, int c)
{
	mark[v] = c;
	if(c == 1)
	{
		p.push_back(v);
	}
	else
	{
		q.push_back(v);
	}
	for(int i = 0; i < adj[v].size(); i ++)
	{
		if(mark[adj[v][i]] == c)
		{
			b = false;
		}
		if(mark[adj[v][i]] == 0)
		{
			dfs(adj[v][i], 3 - c);
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
		int x, y;
		cin >> x;
		cin >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i<= n; i ++)
	{
		if(mark[i] == 0)
		{
			dfs(i, 1);
		}
	}
	if(b)
	{
		cout << (int) p.size() << endl;
		for(int i = 0; i < p.size(); i ++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
		cout << (int) q.size() << endl;
		for(int i = 0; i < q.size(); i ++)
		{
			cout << q[i] << " ";
		}
	}
	else
	{
		cout << -1;
	}
	return 0;
}