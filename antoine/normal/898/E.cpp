#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <deque>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<int> V;

	int zc = 0;
	int zcne = 0;

	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		long long lo = sqrt(a);
		std::vector<long long> grp = { lo - 2, lo - 1, lo, lo + 1, lo + 2 };
		for (auto &&x : grp)
			x *= x;
		int cost = 1000000000;
		for (auto &&x : grp)
			cost = std::min((long long)cost, std::abs(a - x));
		if (cost == 0) {
			++zc;
			if (a)
				++zcne;
		}
		else
			V.push_back(cost);
	}
	std::sort(V.rbegin(), V.rend());

	long long ans = 0;
	if (zc >= n / 2) {
		while (zc > n / 2) {
			if (zcne > 0) {
				--zcne;
				++ans;
			}
			else {
				++ans;
				++ans;
			}

			--zc;
		}
	}
	else {
		for (; zc != n / 2; ++zc) {
			ans += V.back();
			V.pop_back();
		}
	}
	std::cout << ans;
	return 0;
}