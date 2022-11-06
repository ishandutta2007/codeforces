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

map<ll, int> occ;

bool f(ll x) {
	for (ll p2 = 1ll << 31; p2 >= 1; p2 >>= 1) {
		int cnt = occ.count(p2 - x) ? occ.at(p2 - x) : 0; // occ[p2 - x];
		if (cnt >= 2 || (cnt == 1 && p2 - x != x))
			return true;
	}
	return false;
}

int  main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (ll i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		++occ[x];
	}
	int ans = 0;
	for (auto &&x : occ) {
		if (!f(x.first)) {
			ans += x.second;
		}
	}
	cout << ans;
	return 0;
}