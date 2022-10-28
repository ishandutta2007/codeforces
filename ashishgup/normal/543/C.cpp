#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 20;
 
int n, m;
int dp[1 << N];
string s[N];
int a[N][N];
int sum[N][256], mx[N][256];
pair<int, int> cache2[N][256];
 
pair<int, int> get(int i, char ch)
{
	pair<int, int> &ans = cache2[i][ch];
	if(ans.second != 0)
		return ans;
	int sum = 0, mask = 0;
	for(int j = 0; j < n; j++)
	{
		if(s[j][i] == ch)
		{
			mask |= (1 << j);
			sum += a[j][i];
		}
	}
	ans = {sum, mask};
	return ans;
}
 
int work()
{
	for(int mask = (1 << n) - 2; mask >= 0; mask--)
	{
		int &ans = dp[mask];
		ans = 1e9;
		for(int i = 0; i < n; i++)
		{
			if(mask >> i & 1)
				continue;
			for(int j = 0; j < m; j++)
			{
				int cost1 = a[i][j] + dp[mask | (1 << i)];
				pair<int, int> p = get(j, s[i][j]);
				int cost2 = p.first - a[i][j] + dp[mask | (p.second)];
				ans = min(ans, min(cost1, cost2));
			}
		}
	}
	return dp[0];
}
 
int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	int ans = work();
	cout << ans;	
	return 0;
}