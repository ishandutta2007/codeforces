#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
const int maxm = 1e6 + 10;

int fac[maxm];
map<int,ll> mp;

int power(int b) {
	if (b == 0)
		return 1;
	int r = power(b / 2);
	r = 1LL * r * r % mod;
	if (b & 1)
		r = (r + r) % mod;
	return r;
}

int get(ll x) {
	x %= mod;
	return 1LL * x * (x + 1) % mod * power(mod - 2) % mod;
}

int getRangeSum(ll l, ll r) {
	return (get(r) - get(l - 1) + mod) % mod;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	fac[0] = 1;
	for (int i = 1; i <= 1e6; i++)
		fac[i] = 1LL * fac[i - 1] * i % mod;
	int n;
	cin >> n;
	ll m = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x - 1]++;
		if (x != 1)
			mp[-(x - 1)]++;
		m += x;
	}
	int sum = 0, num = 1;
	while (!mp.empty()) {
		pair<int,ll> it = *(--mp.end());
		if (it.first < 0)
			break;
		mp.erase(it.first);
		if (it.first == 0) {
			num = 1LL * num * fac[it.second] % mod;
			continue;
		}
		sum = (sum + 1LL * it.first * getRangeSum(m - it.second + 1, m) % mod) % mod;
		m -= it.second;
		num = 1LL * num * fac[it.second] % mod;
		if (it.first >= 2)
			mp[it.first - 2] += it.second;
	}
	m = 1;
	while (!mp.empty()) {
		pair<int,ll> it = *mp.begin();
		mp.erase(it.first);
		if (it.first >= 0)
			break;
		sum = (sum + 1LL * it.first * getRangeSum(m, m + it.second - 1) % mod) % mod;
		sum = (sum + mod) % mod;
		m += it.second;
		num = 1LL * num * fac[it.second] % mod;
		mp[it.first + 2] += it.second;
	}
	cout << sum << " " << num << '\n';
}