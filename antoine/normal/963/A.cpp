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
#include <stack>

using namespace std;
typedef long long ll;

ll mod = (int)1e9 + 9;
ll modPow(ll x, ll k) {
	ll res = 1;
	for (x %= mod; k; k >>= 1) {
		if (k & 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
	}
	return res;
}

ll modInv(ll x) {
	return modPow(x, mod - 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n, a, b, k;
	cin >> n >> a >> b >> k;

	k = min(k, n + 1);
	vector<ll> s(k);
	for (int i = 0; i < k; ++i) {
		char c;
		cin >> c;
		s[i] = c == '+' ? 1 : mod-1;
	}

	
	while ((k << 1) < min(n, (ll)1e5)) {
		vector<ll> temp(s.begin(), s.end());
		s.insert(s.end(), temp.begin(), temp.end());
		k <<= 1;
	}
	
	ll dp = 0;
	for (int i = 0; i < k; ++i) {
		ll p = s[i];
		p = (p * modPow(a, n - i)) % mod;
		p = (p * modPow(b, i)) % mod;
		dp = (dp + p) % mod;
	}

	ll res = 0;
	for (ll i = 0; i <= n; i += k) {
		if (i + k <= n + 1) {
			res = (res + dp * modPow(b * modInv(a), i)) % mod;
		}
		else {
			for (; i <= n; ++i) {
				ll p = s[i % k];
				p = (p * modPow(a, n - i)) % mod;
				p = (p * modPow(b, i)) % mod;
				res = (res + p) % mod;
			}
			break;
		}
	}

	res %= mod;
	res += mod;
	res %= mod;
	cout << res;
	return 0;
}