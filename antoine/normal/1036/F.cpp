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

vector<pair<int, int>> getFactorization(int x) {
	vector<pair<int, int>> v;
	for (int i = 2; i*i <= x; ++i)
		if (x%i == 0) {
			v.emplace_back(i, 1);
			for (x /= i; x%i == 0; x /= i)
				v.back().second++;
		}
	if (x != 1)
		v.emplace_back(x, 1);
	return v;
}

ll llPow(const ll x, int n) {
	if (pow(x, n) >= 3e18)
		return 1LL << 61;

	ll res = 1;
	while (n--)
		res *= x;
	return res;
}

ll nthRoot(const ll x, const int n) {
	ll res = (ll)pow(x, 1.0 / n);
	assert(res >= 0);
	while (llPow(res, n) > x)
		--res;
	while (llPow(res + 1, n) <= x)
		++res;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	// cout << nthRoot(1LL << 60, 60) << endl;

	vector<pair<int, bool>> v;

	for (int i = 1; i <= 60; ++i) {
		const vector<pair<int, int>> &&divs = getFactorization(i);
		if (any_of(divs.begin(), divs.end(), [](const pair<int, int> &p) {
			return p.second != 1;
		})) continue;
		v.emplace_back(i, divs.size() & 1 ? true : false);
	}

	int T;
	cin >> T;
	while (T--) {
		ll n;
		cin >> n;

		const ll ans = accumulate(v.begin(), v.end(), 0LL, [&n](const ll acc, const pair<int, bool> &x) {
			return acc + max(0LL, nthRoot(n, x.first) - 1) * (x.second ? -1 : 1);
		});

		cout << ans << '\n';
	}

	return 0;
};