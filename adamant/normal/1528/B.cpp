#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 998244353;
const int maxn = 1e5 + 42;

int add(int a, int b) {
	return (a + b) % mod;
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

void solve() {
	int n;
	cin >> n;
	int divs[n + 1];
	memset(divs, 0, sizeof divs);
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j += i) {
			divs[j]++;
		}
	}
	int d[n + 1];
	d[1] = 1;
	for(int i = 2; i <= n; i++) {
		d[i] = add(divs[i], add(mul(2, d[i - 1]), mod - divs[i - 1]));
	}
	cout << d[n] << "\n";
}

signed main() {
	//ignore = freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;//cin >> t;
	while(t--) {
		solve();
	}
}