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
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;

	char curr = 'a';
	int res = 0;
	sort(s.begin(), s.end());
	while (k--) {
		auto it = lower_bound(s.begin(), s.end(), curr);
		if (it == s.end()) {
			cout << -1;
			return 0;
		}
		res += *it - 'a' + 1;
		curr = *it + 2;
	}
	cout << res;
	return 0;
}