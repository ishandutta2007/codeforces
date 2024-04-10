#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;

int add(int a, int b) {
	return (a + b) % mod;
}
int sub(int a, int b) {
	return (a - b + mod) % mod;
}
int mul(int a, int b) {
	return a * b % mod;
}
int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2)  : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

int fact[maxn];

int F(int n) {
	return fact[n] ? fact[n] : fact[n] = n ? mul(F(n - 1), n) : 1;
}
int nCr(int n, int r) {
	return r < 0 || n - r < 0 ? 0 : mul(F(n), mul(inv(F(r)), inv(F(n - r))));
}

void solve() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	auto good = [&](int i) {
		return mul(nCr(n - (i - 1) * (k - 1), i), F(i));
	};
	auto total = [&](int i) {
		return mul(n - (i - 1), good(i - 1));
	};
	int prob = 1;
	for(int i = 2; i <= n; i++) {
		int nprob = mul(good(i), inv(total(i)));
		ans = add(ans, mul(i,  mul(prob, sub(1, nprob))   ));
		prob = mul(prob, nprob);
	}
	cout << ans << "\n";
}

signed main() {
	//ignore = freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}