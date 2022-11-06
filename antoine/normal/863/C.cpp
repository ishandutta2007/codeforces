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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	long long k;
	long long a, b;

	std::cin >> k >> a >> b;

	long long A[4][4];
	long long B[4][4];

	for (long long i = 1; i <= 3; ++i)
		for (long long j = 1; j <= 3; ++j)
			std::cin >> A[i][j];

	for (long long i = 1; i <= 3; ++i)
		for (long long j = 1; j <= 3; ++j)
			std::cin >> B[i][j];

	long long scoreA = 0;
	long long scoreB = 0;

	std::map<std::array<long long, 2>, std::array<long long, 3>> dp;

	while (k > 0) {
		//std::cout << "a, b = " << a << ' ' << b << '\n';
		if (dp.count({ a, b })) {
			//std::cout << "already memo\n";
			auto val = dp[{a, b}];
			long long cycles = k / (val[0] - k);
			dp.clear();
			if (cycles > 0) {
				k -= cycles * (val[0] - k);
				scoreA += cycles * (scoreA - val[1]);
				scoreB += cycles * (scoreB - val[2]);
				continue;
			}
		}
		//std::cout << "a, b = " << a << ' ' << b << '\n';
		dp[{a, b}] = { k, scoreA, scoreB };
		if (a != b) {
			if ((a == 3 && b == 2) || (a == 2 && b == 1) || (a == 1 && b == 3)) {
				++scoreA;
				//std::cout << "A wins\n";
			}
			else {
				++scoreB;
				//std::cout << "B wins\n";
			}
		}
		long long newA = A[a][b];
		long long newB = B[a][b];
		a = newA;
		b = newB;
		--k;
	}
	std::cout << scoreA << ' ' << scoreB;
	return 0;
}