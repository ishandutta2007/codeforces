#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

int n;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n;
	std::stack<int> sta;
	for (int i = 0; i < n; ++i) {
		int L;
		std::cin >> L;
		while (!sta.empty() && sta.top() >= i - L)
			sta.pop();
		sta.push(i);
	}
	std::cout << sta.size();
	return 0;
}