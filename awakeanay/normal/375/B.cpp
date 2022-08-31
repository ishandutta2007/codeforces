#include <iostream>
#include <cstdio>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n, m;
	std::cin >> n >> m;
	
	int dp[m+1][m];
	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			dp[i][j] = 0;
		}
	}
	
	char input;
	int last;
	
	for(int i = 0; i < n; i++)
	{
		last = -1;
		for(int j = 0; j < m; j++)
		{
			std::cin >> input;
			if(input == '1')
			{
				if(last == -1)
				{
					dp[1][j]++;
					last = j;
				}
				else
					dp[j-last+1][j]++;
			}
			else
				last = -1;
		}
	}
	
	int dp2[m+1][m];
	int answer = 0;
	for(int i = m-1; i >= 0; i--)
	{
		for(int j = m; j >= 0; j--)
		{
			dp2[j][i] = dp[j][i] + ((j < m) ? dp2[j+1][i] : 0);
			answer = std::max(dp2[j][i]*j, answer);
		}
	}
	
	std::cout << answer;
	
	return 0;
}