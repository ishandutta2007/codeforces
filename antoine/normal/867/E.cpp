#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <array>
#include <queue>
#include <functional>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N;
	std::cin >> N;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	long long ans = 0;
	while(--N >= 0) {
		int p;
		std::cin >> p;
		if (!pq.empty() && pq.top() <= p) {
			ans += (p - pq.top());
			pq.pop();
			pq.push(p);
		}
		pq.push(p);
	}
	std::cout << ans << '\n';
	return 0;
}