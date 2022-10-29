#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int Mod = 998244353;

int add(int a, int b) {
	return ((a += b) >= Mod) ? (a - Mod) : (a);
}

int sub(int a, int b) {
	return ((a -= b) < 0) ? (a + Mod) : (a);
}

int mul(int a, int b) {
	return (a * 1ll * b) % Mod;
}

const int N = 1e6 + 5;

int n;

inline void init() {
	scanf("%d", &n);
}

int fac[N];

inline void solve() {
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = mul(fac[i - 1], i);
	int ans = fac[n];
	for (int i = n - 1, cof = 1; i > 1; i--) {
		cof = mul(i + 1, cof);
		ans = add(ans, mul(cof, sub(fac[i], 1)));
	}
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}