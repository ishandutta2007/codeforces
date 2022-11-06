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
	int n;
	std::cin >> n;
	std::vector<int> ans;
	if (n % 4 == 2)
		ans.push_back(2);
	if (n % 4 == 3)
		ans.push_back(3);
	for (int i = n % 4 + 1; i <= n; ++i) {
		if ((n - i) % 4 == 0 || (n - i) % 4 == 3)
			ans.push_back(i);
	}
	std::cout << (n % 4 == 0 || n % 4 == 3 ? 0 : 1) << '\n' << ans.size();
	for (auto &&x : ans)
		cout << ' ' << x;
	return 0;
}