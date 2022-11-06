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


const int mod = 998244353;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;

	vector<ll> p2(n + 5, 1);
	for (int i = 1; i < p2.size(); ++i)
		p2[i] = p2[i - 1] * 2 % mod;

	ll ans = 0;
	ll difficulty = 0;
	for (int i = 1; i <= n; ++i) {

		ll c = i == n ? 1 : 2 * p2[n - i - 1] % mod;
		if (i <= n - 2)
			c += ((n - 1) - i) * p2[n - 2 - i] % mod;
		c %= mod;
		ll extra = 0;
		cin >> extra;
		difficulty = (difficulty + extra) % mod;
		ans += c * difficulty % mod;
		ans %= mod;
	}
	cout << ans;
	return 0;
}