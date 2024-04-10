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
	cin.tie(0), cout.tie(0);


	const ll Inf = 1LL << 40;

	vector<ll> cost(1 << 3, Inf);


	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll x;
		string s;
		cin >> x >> s;
		int mask = 0;
		for (char c : s)
			mask |= 1 << (c - 'A');
		for (int m = 0; m < cost.size(); ++m)
			if ((m & mask) == m)
				cost[m] = min(cost[m], x);
	}

	ll ans = cost[7];
	ans = min(ans, cost[1] + cost[2] + cost[4]);
	ans = min(ans, cost[1] + cost[2 | 4]);
	ans = min(ans, cost[2] + cost[1 | 4]);
	ans = min(ans, cost[4] + cost[1 | 2]);


	cout << (ans >= Inf ? -1 : ans);
	return 0;
}