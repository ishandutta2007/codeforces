#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	
	int dp[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			char in;
			std::cin >> in;
			if(in == 'X')
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	
	int count = 0;
	for(int i = 1; i < n-1; i++)
	{
		for(int j = 1; j < n-1; j++)
		{
			if(dp[i][j] && dp[i-1][j-1] && dp[i+1][j-1] && dp[i+1][j+1] && dp[i-1][j+1])
				count++;
		}
	}
	
	std::cout << count;
	return 0;
}