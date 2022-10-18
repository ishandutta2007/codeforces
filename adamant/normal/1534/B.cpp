#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mod = 1e9 + 7;

int add(int a, int b) {
	return (a + b) % mod;
}

int mul(int a,int b) {
	return a * b % mod;
}

int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}

int inv(int x) {
	return bpow(x, mod - 2);
}

int sub(int a, int b) {
	return (a + mod - b) % mod;
}

int dv(int a, int b) {
	return mul(a, inv(b));
}

const int maxn = 3e5 + 42;

void solve() {
	int n;
	cin >> n;
	int a[n + 2];
	a[0] = a[n + 1] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i + 1] < a[i] && a[i] > a[i - 1]) {
			int t = max(a[i + 1], a[i - 1]);
			ans += a[i] - t;
			a[i] = t;
		}
		ans += abs(a[i] - a[i - 1]);
	}
	ans += a[n];
	cout << ans << "\n";
}

signed main() {
	//ignore = freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}