#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int N, K;
int w[MAXN];
int fact[MAXN], inv[MAXN];

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", w + i);
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

int choose(int n, int k) {
	return mul(fact[n], mul(inv[k], inv[n - k]));
}

int stirling(int n, int k) {
	int res = 0;
	for (int i = 0; i <= k; i++) {
		int tmp = mul(choose(k, i), pot(i, n));
		res = add(res, (k - i) % 2 ? -tmp : tmp);
	}
	return mul(res, inv[k]);
}

int solve() {
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = mul(fact[i - 1], i);
		inv[i] = pot(fact[i], MOD - 2);
	}
		
	int sol = 0;
	for (int i = 0; i < N; i++)
		sol = add(sol, w[i]);
	
	return mul(sol, add(stirling(N, K), mul(N - 1, add(stirling(N - 2, K - 1), mul(K, stirling(N - 2, K))))));
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}