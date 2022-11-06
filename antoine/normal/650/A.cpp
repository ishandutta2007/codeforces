#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_map>

long long choose2(long long n) {
	return n*(n - 1) / 2;
}

long long f(std::unordered_map<long long, int> pts) {
	long long ans = 0;
	for (auto x : pts)
		ans += choose2(x.second);
	return ans;
}

int main() {
	std::unordered_map<long long, int> ptsX;
	std::unordered_map<long long, int> ptsY;
	std::unordered_map<long long, int> ptsXY;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		std::cin >> x >> y;
		ptsX[x]++;
		ptsY[y]++;
		ptsXY[(x + 2000000000)*3000000000+y]++;
	}
	long long ans = f(ptsX) + f(ptsY) - f(ptsXY);
	std::cout << ans;
	return 0;
}