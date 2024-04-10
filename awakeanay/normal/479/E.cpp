#include <iostream>
#include <cstdio>
#define mod 1000000007

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n, a, b, k;
	std::cin >> n >> a >> b >> k;
	
	long long int dp[2][n];
	long long int sum[2][n];
	
	n = (a > b) ? (n - b + 1) : b;
	a = abs(a-b);
	b = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(i != a)
			dp[0][i] = 0;
		else
			dp[0][i] = 1;
		
		sum[0][i] = dp[0][i] + ((i > 0) ? sum[0][i-1] : 0);
	}
	
	int l; int r;
	for(int i = 1; i <= k; i++)
	{
		l = i%2; r = 1-l;
		dp[l][0] = 0; sum[l][0] = 0;
		for(int j = 1; j < n; j++)
		{
			int m = j/2 + 1;
			dp[l][j] = (sum[r][n-1] - sum[r][m-1] - dp[r][j] + mod)%mod;
			sum[l][j] = (dp[l][j] + sum[l][j-1] + mod)%mod;
		}
	}
	
	std::cout << sum[l][n-1] << std::endl;
	
	return 0;
}