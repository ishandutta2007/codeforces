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

const int mod = (int)1e9 + 7;

const int MaxFact = (int)2e5;
int fact[MaxFact + 1];
int factInv[MaxFact + 1];

int modPow(ll n, int k) {
	ll res = 1;
	for (n %= mod; k; k >>= 1) {
		if (k & 1)
			res = res * n % mod;
		n = n * n % mod;
	}
	return (int)res;
}

int modInv(int x) {
	return modPow(x, mod - 2);
}

int choose(int n, int k) {
	if (k < 0 || k > n) return 0;
	return (int)((ll)fact[n] * factInv[k] % mod * factInv[n - k] % mod);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fact[0] = factInv[0] = 1;
	for (int i = 1; i <= MaxFact; ++i) {
		fact[i] = ((ll)fact[i - 1] * i % mod);
		factInv[i] = modInv(fact[i]);
	}

	int h, w, n;
	cin >> h >> w >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
		--v[i].first, --v[i].second;
	}
	sort(v.begin(), v.end());
	v.emplace_back(h - 1, w - 1);
	vector<ll> dp(n + 1);
	for (int i = 0; i <= n; ++i) {
		dp[i] = choose(v[i].first + v[i].second, v[i].first);
		for (int j = 0; j < i; ++j) {
			const int a = v[i].first - v[j].first;
			const int b = v[i].second - v[j].second;
			if (a < 0 || b < 0) continue;
			dp[i] = (dp[i] - choose(a + b, a) * dp[j]) % mod;
		}
	}
	cout << (dp.back() % mod + mod) % mod;
	return 0;
}