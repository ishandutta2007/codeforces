#include <iostream>

#include <vector>

using namespace std;

vector<int> adj[100005];
long long dp[100005];
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
	for(int i = 1; i <= n; i ++)
	{
		dp[i] ++;
		for(int j = 0; j < adj[i].size(); j ++)
		{
			if(adj[i][j] > i)
			{
				dp[adj[i][j]] = max(dp[adj[i][j]], dp[i]);
			}
		}
	}
	long long ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		long long x = (long long) adj[i].size();
		ans = max(ans, dp[i] * x);
		//cout << dp[i] << " ";
	}
	cout << ans;
	return 0;
}