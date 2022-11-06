#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; std::cin >> n;
	std::vector<string> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	std::sort(v.begin(), v.end(), [](const string &s, const string &t) {
		return s + t < t + s;
	});

	std::string res = "";
	for (auto && u : v) {
		res += u;
	}

	std::cout << res << std::endl;
	return 0;
}