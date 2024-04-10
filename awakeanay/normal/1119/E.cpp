#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	
	long long a[n], s[n];
	for(int i = 0; i < n; i++)
	{
		std::cin >> a[i];
		s[i] = a[i];
		if(i) s[i] += s[i-1];
	}
	
	long long dp[n];
	dp[0] = a[0]/3;
	
	for(int i = 1; i < n; i++)
	{
		dp[i] = dp[i-1];
		dp[i] += std::min(a[i]/2, s[i-1] - 3*dp[i-1]);
		dp[i] += (a[i] - 2*std::min(a[i]/2, s[i-1] - 3*dp[i-1]))/3;
	}
	
	std::cout << dp[n-1];
	
	return 0;
}