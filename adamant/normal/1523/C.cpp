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
	vector<int> levs;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] == 1) {
			levs.push_back(1);
		} else {
			while(levs.back() + 1 != a[i]) {
				levs.pop_back();
			}
			levs.back()++;
		}
		for(size_t i = 0; i < levs.size(); i++) {
			cout << levs[i] << ".\n"[i + 1 == levs.size()];
		}
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