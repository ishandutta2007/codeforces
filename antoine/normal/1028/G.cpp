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

const ll M = 10004205361450474;
ll dp[6][(int)1e4 + 1];
ll f(const int q, const ll x) { return q == 5 ? M : dp[q][min(x, (ll)1e4)]; }

int query(const vector<ll> &v) {
	cout << v.size() << '\n';
	for (auto &&x : v)
		cout << x << ' ';
	cout << endl;
	int res;
	cin >> res;
	if (res == -1) exit(0);
	if (res == -2) assert(false);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int q = 1; q < 5; ++q) {
		for (int l = 1; l <= (ll)1e4; ++l) {
			ll r = l;
			for (int rep = 0; rep <= l; ++rep)
				r += dp[q - 1][min(r, (ll)1e4)] + 1;
			dp[q][l] = r - l - 1;
		}
	}


	cerr << "Precomp Done\n";

	ll lo = 1, hi = M;
	for (int q = 5;; --q) {
		assert(lo <= hi && q > 0);

		const ll l = min(lo, (ll)1e4);
		ll r = l;
		vector<ll> v;

		for (int rep = 0; rep < l; ++rep) {
			r += f(q - 1, r) + 1;
			assert(r <= (ll)1e18);

			ll num = min(M, r - 1 - l + lo);
			if (!v.empty() && num == v.back()) break;
			assert(v.empty() || num > v.back());
			v.push_back(num);
		}

		const int i = query(v);
		if (i < v.size())
			hi = v[i] - 1;
		if (i - 1 >= 0)
			lo = v[i - 1] + 1;
	}

	return 0;
}