/*
Author: AwakeAnay
Date: 04/02/2020
Time: 20:19:49
*/

#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;
	
	std::vector<int> ans(n, 0);
	std::vector<int> best(26, 0);
	int max = 0;

	for(int i = 0; i < n; i++) {
		int k = s[i]-'a';
		best[k] = std::max(best[k], 1);
		for(int j = k+1; j < 26; j++)
			best[k] = std::max(best[k], best[j]+1);
		ans[i] = best[k];
		max = std::max(max, best[k]);
	}
	
	std::cout << max << std::endl;
	for(int i = 0; i < n; i++)
		std::cout << ans[i] << " ";
	std::cout << std::endl;

	return 0;
}