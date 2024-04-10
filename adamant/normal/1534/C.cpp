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

const int maxn = 5e5 + 42;

int par[maxn];

int get(int v) {
	return v == par[v] ? v : par[v] = get(par[v]);
}

int uni(int a, int b) {
	a = get(a);
	b = get(b);
	if(a == b) {
		return 0;
	} else {
		par[a] = b;
		return 1;
	}
}

void solve() {
	int n;
	cin >> n;
	iota(par, par + n, 0);
	int a[n], b[n];
	int G[n][2];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		G[a[i]][0] = i;
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
		G[b[i]][1] = i;
	}
	int ans = n;
	for(int i = 0; i < n; i++) {
		ans -= uni(G[i][1], G[i][0]);
	}
	cout << bpow(2, ans) << "\n";
}

signed main() {
	//ignore = freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}