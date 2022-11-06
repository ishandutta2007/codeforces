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

ll t;

ll f(ll * first, ll * last) {
	if (first + 1 == last)
		return 0;

	ll * mid = first + (last - first) / 2;
	ll ans = f(first, mid) + f(mid, last);

	for (auto it1 = first, it2 = mid; it1 != mid; ++it1) {
		while (it2 < last && *it2 < t + *it1) ++it2;
		ans += it2 - mid;
	}


	inplace_merge(first, mid, last);
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n >> t;

	static ll a[(int)2e5 + 1];

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	partial_sum(a, a + n + 1, a);

	const ll ans = f(a, a + n + 1);
	cout << ans << endl;
	return 0;
}