#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <functional>

long long n, k;
long long a[300001];
long long finalPos[300001];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	
	int lastInserted = 0;
	long long ans = 0;
	
	std::priority_queue<std::pair<long long, long long>> pq;
	for (int minute = k + 1; minute <= k + n; ++minute) {
		while (lastInserted < minute && lastInserted < n) {
			++lastInserted;
			pq.push({ a[lastInserted], lastInserted });
		}
		ans += (long long)(minute - pq.top().second) * pq.top().first;
		finalPos[pq.top().second] = minute;
		pq.pop();
	}

	std::cout << ans << '\n';
	for (int i = 1; i <= n; ++i) {
		if (i != 1)
			std::cout << ' ';
		std::cout << finalPos[i];
	}
	return 0;
}