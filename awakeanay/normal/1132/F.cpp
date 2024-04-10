#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	
	char seq[n];
	for(int i = 0; i < n; i++)
		std::cin >> seq[i];
		
	int dp[n][n];
	for(int i = 0; i < n; i++)
	{
		dp[i][i] = 1;
		if(i > 0) dp[i][i-1] = 0;
	}
	
	for(int k = 1; k < n; k++)
	{
		for(int i = 0; i + k < n; i++)
		{
			int l = i + k;
			dp[i][l] = std::min(dp[i][l-1], dp[i+1][l]) + 1;
			
			for(int j = i; j < l; j++)
			{
				if(seq[j] == seq[l])
					dp[i][l] = std::min(dp[i][j] + dp[j+1][l-1], dp[i][l]);
			}
		}
	}
	
	std::cout << dp[0][n-1];
	
	return 0;
}