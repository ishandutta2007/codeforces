#include <iostream>

#include <vector>

using namespace std;

int part[300005];
vector<int> adj1[300005];
vector<pair <int, int> > adj2[300005];
int mark[300005];
int mark2[300005];
pair<int, int> direction[300005];
void dfs(int v)
{
	if(mark[v] == 1)
	{
		return ;
	}
	mark[v] = 1;
	for(int i = 0; i < adj1[v].size(); i ++)
	{
		dfs(adj1[v][i]);
	}
	for(int i = 0; i < adj2[v].size(); i ++)
	{
		if(direction[adj2[v][i].second].first == 0)
		{
			direction[adj2[v][i].second].first = v;
			dfs(adj2[v][i].first);
		}
	}
}
void dfs2(int v)
{
	if(mark2[v] == 1)
	{
		return ;
	}
	mark2[v] = 1;
	for(int i = 0; i < adj1[v].size(); i ++)
	{
		dfs2(adj1[v][i]);
	}
	for(int i = 0; i < adj2[v].size(); i ++)
	{
		if(direction[adj2[v][i].second].first == 0)
		{
			direction[adj2[v][i].second].first = adj2[v][i].first;
		}
	}
}
int main()
{
	int n, m, s, n2 = 1, ns = 0;
	cin >> n;
	cin >> m;
	cin >> s;
	for(int i = 0; i < m; i ++)
	{
		int x, y, z;
		cin >> z;
		cin >> x;
		cin >> y;
		if(z == 1)
		{
			adj1[x].push_back(y);
		}
		else
		{
			direction[n2].second = x;
			adj2[x].push_back({y, n2});
			adj2[y].push_back({x, n2});
			n2 ++;
		}
	}
	dfs(s);
	for(int i = 1; i <= n; i ++)
	{
		if(mark[i] == 1)
		{
			ns ++;
		}
	}
	cout << ns << endl;
	for(int i = 1; i < n2; i ++)
	{
		//cout << direction[i].first << " " << direction[i].second << endl;
		if(direction[i].first == direction[i].second)
		{
			cout << "+";
		}
		else
		{
			cout << "-";
		}
	}
	cout << endl;
	ns = 0;
	for(int i = 1; i < n2; i ++)
	{
		direction[i].first = 0;
	}
	dfs2(s);
	for(int i = 1; i <= n; i ++)
	{
		if(mark2[i] == 1)
		{
			ns ++;
		}
	}
	cout << ns << endl;
	for(int i = 1; i < n2; i ++)
	{
		//cout << direction[i].first << " ";
		if(direction[i].first == direction[i].second)
		{
			cout << "+";
		}
		else
		{
			cout << "-";
		}
	}
	return 0;
}