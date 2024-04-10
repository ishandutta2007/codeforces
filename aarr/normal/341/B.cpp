#include <iostream>

#include <algorithm>

using namespace std;

const int N = 1000 * 1000 * 1000 + 7;
int a[100005];
int dp[100005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	dp[0] = -1;
	for(int i = 1; i <= n; i ++)
	{
		dp[i] = N;
	}
	for(int i = 0; i < n; i ++)
	{
		int x = upper_bound(dp, dp + n + 1, a[i]) - dp;
		dp[x] = a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(dp[i] < N)
		{
			ans = i;
		}
	}
	cout << ans;
	return 0;
}