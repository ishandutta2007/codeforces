#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 998244353;

int N;
int fact[MAXN], inv[MAXN];

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

void load() {
	scanf("%d", &N);
}

int choose(int n, int k) {
	if (k < 0 || n < k)
		return 0;
	return mul(fact[n], mul(inv[k], inv[n - k]));
}

int solve() {
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = mul(fact[i - 1], i);
		inv[i] = pot(fact[i], MOD - 2);
	}
	
	int sol = 1;
	for (int k = 1; k < N; k++)
		sol = add(sol, mul(N - k, mul(mul(k, choose(N, k + 1)), fact[N - k - 1])));
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}