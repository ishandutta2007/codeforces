#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int N, M;
int fact[MAXN], inv[MAXN];

void load() {
	scanf("%d%d%*d%*d", &N, &M);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
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

int inverse(int x) {
	return pot(x, MOD - 2);
}

int choose(int n, int k) {
	if (k < 0 || n < k)
		return 0;
	return mul(fact[n], mul(inv[k], inv[n - k]));
}

int edges(int k) {
	return mul(choose(M - 1, k - 2), pot(M, N - k));
}

int trees(int k) {
	return mul(mul(choose(N - 1, k - 1), pot(N, N - k)), fact[k]);
}

int solve() {
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = mul(fact[i - 1], i);
		inv[i] = inverse(fact[i]);
	}
	
	int sol = 0;
	for (int i = 2; i <= N; i++) 
		sol = add(sol, mul(edges(i), trees(i)));
	
	return mul(sol, inverse(mul(N, N - 1)));
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}