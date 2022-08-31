#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	
	int N;
	std::cin >> N;
	
	std::string A;
	std::cin >> A;
	
	long long dp[N+1][N+1];
	long long pow[N+1];
	
	std::string s[N+1][N+1];
	
	pow[0] = 1;
	for(int i = 1; i <= N; i++)
		pow[i] = 10 * pow[i-1];
	
	long long compare;
	
	for(int i = N; i >= 0; i--)
	{
		for(int j = N; j >= 0; j--)
		{
			dp[i][j] = 0; s[i][j] = "";
			if(i < N)
			{
				compare = (A.at(i+j) - '0')*pow[N-i-1] + dp[i+1][j];
				if(compare >= dp[i][j])
				{
					dp[i][j] = compare;
					s[i][j] = "H" + s[i+1][j];
				}
			}
			
			if(j < N)
			{
				compare = (A.at(i+j) - '0')*pow[N-j-1] + dp[i][j+1];
				if(compare >= dp[i][j])
				{
					dp[i][j] = compare;
					s[i][j] = "M" + s[i][j+1];
				}
			}
		}
	}
	
	std::cout << s[0][0];
	
	return 0;
}