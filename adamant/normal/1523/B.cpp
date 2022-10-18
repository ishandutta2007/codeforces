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
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << 3 * n << "\n";
	for(int i = 0; i < n; i += 2) {
		cout << "1 " << i + 1 << ' ' << i + 2 << "\n"; // a, b -> a + b, b
		cout << "2 " << i + 1 << ' ' << i + 2 << "\n"; // a + b, b -> a + b, -a
		cout << "1 " << i + 1 << ' ' << i + 2 << "\n"; // b, -a
		cout << "2 " << i + 1 << ' ' << i + 2 << "\n"; // b, -a -> b, -a-b
		cout << "1 " << i + 1 << ' ' << i + 2 << "\n"; // b, -a-b -> -a, -a-b
		cout << "2 " << i + 1 << ' ' << i + 2 << "\n"; // -a, -a-b, -a, -b
	}
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