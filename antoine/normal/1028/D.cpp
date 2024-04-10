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

const int mod = 1e9 + 7;

bool bef(const set<ll> &s1, const set<ll> &s2) {
	return s1.empty() || s2.empty() || *s1.cbegin() < *s2.crbegin();
}

ll f() {

	int n;
	cin >> n;
	set<ll> buys, sells, unknown;
	ll ans = 1;
	while (n--) {
		string type;
		ll p;
		cin >> type >> p;
		if (type == "ADD") {
			if (!buys.empty() && p <= *buys.rbegin())
				buys.insert(p);
			else if (!sells.empty() && p >= *sells.begin())
				sells.insert(p);
			else
				unknown.insert(p);
		}
		else if (type == "ACCEPT") {
			if (!buys.empty() && p <= *buys.rbegin()) {
				if (p != *buys.rbegin()) return 0;
				buys.erase(prev(buys.end()));
				sells.insert(unknown.begin(), unknown.end());
			}
			else if (!sells.empty() && p >= *sells.begin()) {
				if (p != *sells.begin()) return 0;
				sells.erase(sells.begin());
				buys.insert(unknown.begin(), unknown.end());
			}
			else {
				auto it = unknown.find(p);
				if (it == unknown.end()) return 0;
				ans = (ans << 1) % mod;
				it = unknown.erase(it);
				sells.insert(it, unknown.end());
				buys.insert(unknown.begin(), it);
			}
			unknown.clear();
		}
		else
			assert(false);
		// assert(bef(buys, unknown));
		// assert(bef(unknown, sells));
		// assert(bef(buys, sells));
	}

	ans *= unknown.size() + 1;
	ans %= mod;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout << f() << '\n';
	return 0;
}