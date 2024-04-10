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

	int c1 = 0, c2 = 0, n;
	std::cin >> n;
	for (; n > 0; --n) {
		int a;
		std::cin >> a;
		c1 += a == 1;
		c2 += a == 2;
	}

	int ans = std::min(c1, c2);
	c1 -= ans;
	c2 -= ans;
	std::cout << ans + c1 / 3;
	return 0;
}