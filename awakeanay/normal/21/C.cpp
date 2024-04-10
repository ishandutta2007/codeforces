#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	
	long sum = 0;
	int seq[N];
	for(int i = 0; i < N; i++)
	{
		std::cin >> seq[i];
		sum += seq[i];
	}
	
	if(sum % 3 != 0)
	{
		std::cout << 0;
		return 0;
	}
	
	long long dp[2][N];
	
	long runner = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < 2; j++)
			dp[j][i] = ((i > 0) ? dp[j][i-1] : 0);
		
		runner += seq[i];
		if(runner == sum/3)
			dp[0][i] = 1 + ((i > 0) ? dp[0][i-1] : 0);
		if(runner == sum*2/3)
			dp[1][i] = ((i > 0) ? dp[0][i-1] + dp[1][i-1] : 0);
	}
	
	std::cout << dp[1][N-2];
	
	return 0;
}