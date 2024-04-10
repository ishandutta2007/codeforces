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

using namespace std;
typedef long long ll;

ll ceil(ll a, ll b) {
	return (a + b - 1) / b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	ll n, k, M, D, ans = 0;
	cin >> n >> k >> M >> D;

	for (int d = 1; d <= D; ++d) {
		ll lo = 1, hi = M;
		while (lo < hi) {
			ll mid = (lo + hi + 1) >> 1;
			if (ceil(n / mid, k) < d)
				hi = mid - 1;
			else
				lo = mid;
		}
		if (ceil(n / lo, k) <= D)
			ans = max(ans, ceil(n / lo, k)*lo);
	}
	cout << ans;
	return 0;
}