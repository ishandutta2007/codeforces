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

int sumF(const string &s) {
	return accumulate(s.begin(), s.end(), 0, [](const int acc, const char c) {
		return c == '(' ? acc + 1 : acc - 1;
	});
}

bool valid(const string &s, const int sum) {
	int temp = 0;
	for (char c : s) {
		if (c == '(')
			++temp;
		else if (--temp < (sum >= 0 ? 0 : sum))
			return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	map<int, int> occ;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		const int sum = sumF(s);
		if (valid(s, sum))
			++occ[sum];
	}
	ll ans = 0;
	for (auto &&x : occ) {
		if (x.first >= 0)
			break;
		ans += (ll)x.second * occ[-x.first];
	}
	ans += (ll)occ[0] * occ[0];
	cout << ans;
	return 0;
}