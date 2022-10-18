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
	int w[n], h[n];
	map<int, int> W, H;
	map<int, map<int, int>> WH;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> w[i] >> h[i];
		if(w[i] == h[i]) {
			ans += W[w[i]] + H[h[i]] - WH[w[i]][h[i]];
		} else {
			ans += W[w[i]] + H[h[i]] - WH[w[i]][h[i]];
			ans += W[h[i]] + H[w[i]] - WH[h[i]][w[i]];
			ans -= WH[w[i]][w[i]] + WH[h[i]][h[i]];
		}
		W[w[i]]++;
		H[h[i]]++;
		WH[w[i]][h[i]]++;
	}
	cout << ans << "\n";
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