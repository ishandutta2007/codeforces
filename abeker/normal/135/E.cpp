#include <bits/stdc++.h>
using namespace std;

const int MAXK = 1e6 + 5;
const int MOD = 1e9 + 7;

int K, W;
int fact[MAXK], inv[MAXK];

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	if (x < 0)
		return x + MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)	
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

void load() {
	scanf("%d%d", &K, &W);
}

int choose(int n, int k) {
	return k < 0 || n < k ? 0 : mul(fact[n], inv[n - k]);
}

int calc(int len, int diff) {
	int both = 2 * diff - len;
	if (both > 0)
		return mul(pot(choose(K - both, len - diff), 2), choose(K, both));
	return mul(pot(choose(K, diff), 2), pot(K, -both));
}

int solve() {
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= K; i++) {
		fact[i] = mul(fact[i - 1], i);
		inv[i] = pot(fact[i], MOD - 2);
	}
	
	int sol = 0;
	for (int i = 1; i <= K; i++) 
		sol = add(sol, add(calc(W + i, i), -calc(W + i, i + 1)));
		
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}