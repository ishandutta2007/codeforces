#include <iostream>

#include <algorithm>

using namespace std;

const int N = 1000 * 1000 * 1000 + 7;
int a[100005];
int dp[100005];
int main()
{
	int n, m;
	double kooft;
	cin >> n;
	cin >> m;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		cin >> kooft;
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
	cout << n - ans;
	return 0;
}