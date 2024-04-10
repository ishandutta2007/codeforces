#include <iostream>

#include <vector>

using namespace std;

vector<int> adj[1005];
pair<int, int> a[1005];
int mark[1005];
vector<int> part[1005];
int nparts = 1;
int dp[1005][1005];
void dfs(int v)
{
	if(mark[v] != 0)
	{
		return ;
	}
	mark[v] = nparts;
	for(int i = 0; i < adj[v].size(); i ++)
	{
		dfs(adj[v][i]);
	}
}
int main()
{
	int n, m, w;
	cin >> n;
	cin >> m;
	cin >> w;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i].first;
	}
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i].second;
	}
	for(int i = 1; i <= m; i ++)
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
		part[mark[i]].push_back(i);
	}
	for(int i = 1; i < nparts; i ++)
	{
		for(int j = 1; j <= w; j ++)
		{
			dp[i][j] = dp[i - 1][j];
			int x = 0, b = 0;
			for(int k = 0; k < part[i].size(); k ++)
			{
				//cout << part[i][k] << " ";
				x += a[part[i][k]].first;
				b += a[part[i][k]].second;
				if(j - a[part[i][k]].first >= 0)
				{
					//cout << a[part[i][k]].first << " " << a[part[i][k]].second << endl;
					dp[i][j] = max(dp[i][j], dp[i - 1][j - a[part[i][k]].first] + a[part[i][k]].second);
				}
			}
			//cout << endl;
			//cout << x << " " << b << endl;
			//cout << dp[i][j] << endl;
			if(j - x >= 0)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + b);
			}
		}
		//cout << endl;
	}
	int ans = 0;
	for(int i = 0; i <= w; i ++)
	{
		ans = max(ans, dp[nparts - 1][i]);
	}
	cout << ans;
	return 0;
}