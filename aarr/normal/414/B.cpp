#include <iostream>

using namespace std;

const int N = 1000 * 1000 * 1000 + 7;
int dp[2005][2005];
int main()
{
	int n, k;
	cin >> n;
	cin >> k;
	for(int j = 1; j <= n; j ++)
	{
		dp[1][j] = 1;
	}
	for(int i = 2; i <= k; i ++)
	{
		for(int j = 1; j <= n; j ++)
		{
			dp[i][j] = 0;
			for(int k = 1;  j * k <= n; k ++)
			{
				dp[i][j] += dp[i - 1][k * j];
				dp[i][j] = dp[i][j] % N;
			}
		}
	}
	int x = 0;
	for(int j = 1; j <= n; j ++)
	{
		x += dp[k][j];
		x = x % N;
	}
	cout << x;
	return 0;
}