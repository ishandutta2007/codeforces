

#include <iostream>


int a, b, c;

int dp[4001];

int f(int n) {
	if(n == 0)
		return 0;
	if(n < 0)
		return -1;
	if(dp[n] != -1)
		return dp[n];
	int m = std::max(f(n-a), std::max(f(n-b), f(n-c)));
	return dp[n] = (m < 0 ? -2 : m + 1);
}

int main() {
	for(int i = 0; i < 4001; ++i)
		dp[i] = -1;
	int n; std::cin >> n >> a >> b >> c;
	std::cout << f(n);
}