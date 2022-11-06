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

void getDivisors(const ll &x, vector<ll> &res) {
	int max_i = 1;
	for (ll i = 1; i*i <= x; ++i)
		if (x%i == 0) {
			res.push_back(i);
			max_i = i;
			if (i % 100000000 == 0)
				cerr << "ii\n";
		}
	assert((ll)max_i * max_i <= x);
	for (int i = max_i; i >= 1; --i)
		if (x % i == 0 && x / i >= res.back())
			res.push_back(x / i);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll a, b;
	cin >> a >> b;
	const ll sum = a + b;

	vector<ll> da, db, dab;
	getDivisors(a, da);
	getDivisors(b, db);
	getDivisors(sum, dab);
	reverse(dab.begin(), dab.end());

	ll ans = (ll)1e18;
	for (const ll &W : dab) {
		const ll H = sum / W;
		if (W < H) break;

		while (da.back() > W)
			da.pop_back();
		while (db.back() > W)
			db.pop_back();

		if (a / da.back() <= H || b / db.back() <= H)
			ans = min(ans, (W + H) << 1);
	}
	cout << ans << '\n';
	return 0;
}