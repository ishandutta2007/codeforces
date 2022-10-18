#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

int bpow(int x, int n) {
	return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int w, h;
	cin >> w >> h;
	cout << bpow(2, w + h) << endl;
	return 0;
}