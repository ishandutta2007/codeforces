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

ll modPow(ll n, ll k) {
	n %= mod;
	k %= mod - 1;
	ll res = 1;
	for (; k; k >>= 1) {
		if (k & 1)
			res = res * n % mod;
		n = n * n % mod;
	}
	return res;
}

ll inv(ll n) {
	return modPow(n, mod - 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin >> n;

	static ll fact[(int)1e6 + 1];
	fact[0] = 1;
	for (int i = 1; i <= n; ++i)
		fact[i] = fact[i - 1] * i % mod;

	ll res = modPow(modPow(3, n) - 3, n);
	for (int i = 1; i <= n; ++i) {
		const ll sign = i & 1 ? -1 : 1;
		const ll nCi = fact[n] * inv(fact[i]) % mod * inv(fact[n - i]) % mod;
		res += sign * nCi % mod * (modPow(3, i) - 3) % mod * modPow(3, n*(n - i)) % mod;
		res += sign * nCi % mod * 3 * modPow(modPow(3, n - i) - 1, n) % mod;
	}
	res = modPow(3, n*n) - res;
	cout << (res % mod + mod) % mod;
	return 0;
}