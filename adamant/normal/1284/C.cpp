#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 3e5 + 42;

int F[maxn], U[maxn];
int fact(int n, int m) {
	if(U[n]) {
		return F[n];
	} else {
		U[n] = 1;
		return F[n] = n ? n * fact(n - 1, m) % m : 1;
	}
}

int bpow(int x, int n, int m) {
	return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : 1;
}

int inv(int x, int m) {
	return bpow(x, m - 2, m);
}

int nCr(int n, int r, int m) {
	return fact(n, m) * inv(fact(r, m), m) % m * inv(fact(n - r, m), m) % m;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for(int k = 1; k <= n; k++) {
		ans += (n - k + 1) * (n - k + 1) % m * inv(nCr(n, k, m), m) % m;
		ans %= m;
	}
	cout << ans * fact(n, m) % m << endl;
	return 0;
}