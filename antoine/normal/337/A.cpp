

#include <iostream>

int dp[50];

int main() {
	//in
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		std::cin >> dp[i];
	}
	
	//sort
	for(int i = 0; i + 1 < m; ++i)
		for(int j = i + 1; j < m; ++j) {
			if(dp[i] > dp[j]) {
				int temp = dp[i];
				dp[i] = dp[j];
				dp[j] = temp;
			}
		}
	
	int min = dp[n - 1] - dp[0];
	for(int i = 1; i + n - 1 < m; ++i) {
		int m = dp[i + n - 1] - dp[i];
		if(m < min)
			min = m;
	}
	
	std::cout << min;
}