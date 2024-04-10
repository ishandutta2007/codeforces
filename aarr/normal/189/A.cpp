#include <iostream>

using namespace std;

int dp[4005];
int main()
{
	int n, a, b, c;
	cin >> n;
	cin >> a;
	cin >> b;
	cin >> c;
	dp[a] = 1;
	dp[b] = 1;
	dp[c] = 1;
	for(int i = 1; i <= n; i ++)
	{
		if(i != a && i != b && i != c)
		{
			dp[i] = -1000000;
		}
		if(i > a)
		{
			dp[i] = max(dp[i], dp[i - a] + 1);
		}
		if(i > b)
		{
			dp[i] = max(dp[i], dp[i - b] + 1);
		}
		if(i > c)
		{
			dp[i] = max(dp[i], dp[i - c] + 1);
		}
	}
	cout << dp[n];
	return 0;
}