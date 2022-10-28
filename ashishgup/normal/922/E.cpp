#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e3 + 5;
const int M = 1e4 + 5;
 
int n, w, b, x;
int c[N], cost[N];
int dp[N][M];
int inf = -1e15;
 
int32_t main()
{
	IOS;
	cin >> n >> w >> b >> x;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	for(int i = 1; i <= n; i++)
		cin >> cost[i];
	dp[0][0] = w;
	for(int i = 1; i <= 1e4; i++)
		dp[0][i] = -1e15;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= 10000; j++)
		{
			dp[i][j] = -1e15;
			for(int k = 0; k <= min(j, c[i]); k++)
			{
				int capacity = min(dp[i - 1][j - k] + x, w + (j - k) * b); 
				if(capacity - cost[i] * k >= 0)
					dp[i][j] = max(dp[i][j], capacity - cost[i] * k);
			}
		}	
	}
	for(int i = 1e4; i >= 0; i--)
	{
		if(dp[n][i] >= 0)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}