#include <iostream>

#include <vector>

using namespace std;

vector<int> adj[100005];
int mark[100005];
long long parts[100005];
int nparts = 1;
void dfs(int v)
{
	if(mark[v] != 0)
	{
		return ;
	}
	mark[v] = nparts;
	parts[nparts] ++;
	for(int i = 0; i < adj[v].size(); i ++)
	{
		dfs(adj[v][i]);
	}
}
int main()
{
	long long ans = 0;
	int n;
	cin >> n;
	for(int i = 1; i < n; i ++)
	{
		int x, y;
		string s;
		bool b = true;
		cin >> x;
		cin >> y;
		cin >> s;
		for(int j = 0; j < s.size(); j ++)
		{
			if(s[j] != '7' && s[j] != '4')
			{
				b = false;
			}
		}
		if(!b)
		{
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		if(mark[i] == 0)
		{
			dfs(i);
			nparts ++;
		}
	}
	for(int i = 1; i < nparts; i ++)
	{
		ans += parts[i] * (n - parts[i]) * (n - parts[i] - 1);
	}
	cout << ans << endl;
	return 0;
}