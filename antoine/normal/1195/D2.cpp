#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = 998244353;

int len(const ll x) {
	string s = to_string(x);
	return (int) s.size();
}

ll fR(const ll x, int len2) {
	const string s = to_string(x);

	ll sum = 0;
	ll p10 = 1;
	for (int j = (int) s.size() - 1; j >= 0; --j) {
		(sum += (s[j] - '0') * p10) %= mod;
		(p10 *= 10) %= mod;
		if (len2 > 0) {
			len2--;
			(p10 *= 10) %= mod;
		}
	}
	return sum;
}

ll fL(const ll x, int len2) {
	const string s = to_string(x);

	ll sum = 0;
	ll p10 = 1;

	if (len2 > 0) {
		len2--;
		(p10 *= 10) %= mod;
	}
	for (int j = (int) s.size() - 1; j >= 0; --j) {
		(sum += (s[j] - '0') * p10) %= mod;
		(p10 *= 10) %= mod;
		if (len2 > 0) {
			len2--;
			(p10 *= 10) %= mod;
		}
	}
	return sum;
}

ll f(const int x, const int len2) {
	return (fL(x, len2) + fR(x, len2)) % mod;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;
	sort(a.begin(), a.end());

	map<int, int> occ;
	for (const int x : a)
		++occ[len(x)];

	ll ans = 0;
	for (const int x : a)
		for (auto e : occ)
			(ans += f(x, e.first) * e.second) %= mod;

	cout <<(ans%mod+mod)%mod;
	return 0;
}