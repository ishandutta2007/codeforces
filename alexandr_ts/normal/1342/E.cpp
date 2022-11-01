#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <type_traits>
#include <queue>
#include <cassert>
#include <utility>
#include <functional>
#include <typeinfo>
#include <set>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>
#include <ostream>
#include <iterator>
#include <new>
#include <cstdlib>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <array>
#include <variant>
#include <any>
#include <experimental/filesystem>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <string_view>
#include <exception>

#define debug(x) cout << #x << " is " << (x) << endl;

using namespace std;

using ll = long long;

const ll MOD = 998244353;
const int N = 1e6 + 10;

ll fac[N], bfac[N];

ll pw(ll x, int n) {
	if (!n) return 1;
	if (n % 2) 
		return pw(x, n - 1) * x % MOD;
	ll tmp = pw(x, n / 2);
	return tmp * tmp % MOD;
}

void prec() {
	bfac[0] = fac[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = fac[i - 1] * i % MOD;	
		bfac[i] = pw(fac[i], MOD - 2);
	}

}

ll cnk(int n, int k) {
	return fac[n] * bfac[k] % MOD * bfac[n - k] % MOD;
}

void solve() {
	int n, k;
	cin >> n >> k;
	int t = n - k;
	prec();

	if (k >= n) {
		cout << 0 << endl;
		return;
	}
	if (k == 0) {
		cout << fac[n] << endl;	
		return;
	}
	
	ll ans = 2 * cnk(n, t) % MOD;
	ll sum = 0;
	for (int i = 0; i < t; ++i) {
		ll cur = pw(t - i, n) * cnk(t, i);
		if (i % 2) {
			sum -= cur;	
		} else {
			sum += cur;	
		}
		sum %= MOD;
		if (sum < 0) sum += MOD;
	}
	cout << ans * sum % MOD << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	for (int i = 1; i <= t; ++i) {
		solve();	
	}
}