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
#include <ctime>

using namespace std;
typedef long long ll;

bool query(ll l, ll r) {
	static int qCnt = 0;
	assert(++qCnt <= 4500);
	assert(l <= r);
	cout << l << ' ' << r << endl;
	string res;
	cin >> res;
	if (res == "Yes") {
		if (l == r)
			exit(0);
		return true;
	}
	if (res == "No")
		return false;
	assert(false);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, k;
	cin >> n >> k;

	ll lo = 1, hi = n;
	for (;;) {
		const ll mid = (lo + hi) >> 1;

		const bool res = query(lo, mid);
		if (res)
			hi = mid;
		else
			lo = mid + 1;


		for (int i = 0; i < rand(); ++i)
			rand();

		lo = max(1LL, lo - k);
		hi = min(n, hi + k);
		if (hi - lo <= 50) {
			const ll idx = lo + (rand() * 3 + rand() + 1) % (hi - lo + 1);
			query(idx, idx);
			lo = max(1LL, lo - k);
			hi = min(n, hi + k);
		}
	}
	return 0;
}