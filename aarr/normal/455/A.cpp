#include <iostream>

using namespace std;

long long a[100005];
long long dp[100005];
int main()
{
	int n;
	cin >> n;
	int m = 0;
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		a[x] ++;
		m = max(m, x);
	}
	dp[1] = a[1];
	dp[2] = max(a[2] * 2, a[1]);
	for(int i = 3; i <= m; i ++)
	{
		dp[i] = max(dp[i - 2] + (a[i] * i), dp[i - 1]);
	}
	cout << dp[m];
	return 0;
}