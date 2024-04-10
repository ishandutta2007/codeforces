#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;
 
int n;
int a[N];
map<int, int> m;
int dp[N][N * N];
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	if(m.size() <= 2)
	{
		cout << n;
		return 0;
	}
	dp[0][0] = 1;
	for(auto &it:m)
	{
		int f = it.second;
		for(int i = n; i >= 1; i--)
		{
			for(int j = 10000; j >= 0; j--)
			{
				for(int k = 1; k <= min(f, i) && k * it.first <= j; k++)
				{
					dp[i][j] += dp[i - k][j - k * it.first];
					dp[i][j] = min(dp[i][j], (int)1e9);
				}
			}
		}
	}
	int ans = 0;
	for(auto &it:m)
	{
		int f = it.second;
		for(int i = 1; i <= f; i++)
			if(dp[i][i * it.first] == 1)
				ans = max(ans, i);
	}
	cout << ans;
	return 0;
}