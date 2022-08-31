#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	
	std::vector<int> seq;
	int last = -1;
	for(int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		if(x != last)
		{
			seq.push_back(x);
			last = x;
		}
	}
	n = seq.size();
	
	int dp[n][n];
	for(int i = 0; i < n; i++)
	{
		dp[i][i] = 0;
		if(i < n-1) dp[i][i+1] = 1;
	}
	
	for(int j = 2; j < n; j++)
	{
		for(int i = 0; j + i < n; i++)
		{
			int k = i+j;
			dp[i][k] = std::min(dp[i][k-1], dp[i+1][k]) + 1;
			if(seq[i] == seq[k])
				dp[i][k] = std::min(dp[i][k], dp[i+1][k-1] + 1);
			//std::cout << i << " " << k << ' ' << dp[i][k] << std::endl;
		}
	}
	
	std::cout << dp[0][n-1];
	
	return 0;
}