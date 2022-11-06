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

	ll n, m, k;
	cin >> n >> m >> k;
	if (k > n + m - 2) {
		cout << -1;
		return 0;
	}
	ll ans = 0;
	for (int i = 1; (i - 1) *(i - 1) <= n && i <= k + 1; ++i)
		ans = max(ans, (n / i) * (m / (k + 2 - i)));
	for (int i = (ll)sqrt(n); i >= 1; --i) {
		ll lo = 1;
		ll hi = (ll)k + 1;
		while (lo < hi) {
			ll mid = (lo + hi + 1) / 2;
			if (n / mid >= i)
				lo = mid;
			else
				hi = mid - 1;
		}
		ans = max(ans, (n / lo) * (m / (k + 2 - lo)));
	}
	cout << ans;
	return 0;
}