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

const ll MaxN = (ll)3e5 + 9;

ll currR;
vector<pair<ll, ll>> updates[MaxN];

struct Range {
	ll l, r, k;
	Range(const ll l, const ll r, const ll k) : l(l), r(r), k(k) {
		updates[currR].emplace_back(k, r - l);
	}

	~Range() {
		updates[currR].emplace_back(k, l - r);
	}

	bool operator<(const Range &other) const {
		return l != other.l ? l < other.l : r < other.r;
	}
};

void addRange(set<Range> &ranges, ll l, ll r) {
	auto it = ranges.lower_bound(Range(l, l, 0));
	while (it != ranges.end() && it->r <= r)
		it = ranges.erase(it);
	if (it != ranges.end() && it->l < r) {
		ranges.emplace(r, it->r, it->k);
		it = ranges.erase(it);
	}
	if (it != ranges.begin() && (--it)->r > l) {
		ranges.emplace(it->l, l, it->k);
		if (it->r > r)
			ranges.emplace(r, it->r, it->k);
		ranges.erase(it);
	}
	ranges.emplace(l, r, currR);
}

ll n;

ll __cs[MaxN], __acs[MaxN];

pair<ll, ll> f(const ll M) {
	pair<ll, ll> res = { 0, 0LL };

	static ll diff[MaxN];

	fill(diff, diff + MaxN, 0);
	fill(__cs, __cs + MaxN, 0);
	fill(__acs, __acs + MaxN, 0);


	ll cs = 0, acs = 0; // [1 ... i]

	for (ll i = 0, j = 1; j <= n; ++j) {
		for (const pair<ll, ll> &u : updates[j]) {
			
			auto update = [&](const ll k, const ll x) {
				diff[k] += x;
				if (k <= i) {
					cs += x;
					// assert(cs <= (ll)1e9 - 1);
					acs += x * (i - k + 1LL);
					
				}
			};

			update(1, u.second);
			update(u.first + 1, -u.second);
		}

		for (; i + 1 <= j; ++i) {
			const ll _cs = cs + diff[i + 1];
			// assert(_cs <= (ll)1e9);
			assert(i == 0 || cs >= _cs);
			if (_cs < M) break;
			acs += (cs = _cs);
			// assert(cs <= (ll)1e9 - 1);
		}
		res.first += i;
		res.second += acs;
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll k;
	cin >> n >> k;

	set<Range> ranges;

	for(currR = 1; currR <= n; ++currR) {
		ll a, b;
		cin >> a >> b;
		addRange(ranges, a, b);
	}
	

	ll lo = 0;
	ll hi = (ll)1e9;
	while (lo < hi) {
		const ll mid = (lo + hi + 1) >> 1;
		if (f(mid).first >= k)
			lo = mid;
		else
			hi = mid - 1;
	}

	assert(lo == hi);
	const pair<ll, ll> res = f(lo);
	assert(res.first >= k && f(lo + 1).first < k);
	const ll ans = res.second - ll(res.first - k) * lo;
	cout << ans << '\n';
	return 0;
}