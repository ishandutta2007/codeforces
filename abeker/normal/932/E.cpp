#include <bits/stdc++.h>
using namespace std;

const int MAXK = 5005;
const int MOD = 1e9 + 7;

int N, K;
int fact[MAXK], inv[MAXK];
int pre[MAXK];
int power[MAXK];

void load() {
	scanf("%d%d", &N, &K);
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
	if (k < 0 || n < k)
		return 0;
	return mul(fact[n], mul(inv[k], inv[n - k]));
}

int calc(int l) {
	int res = 0;
	for (int i = 0; i <= l; i++) {
		int tmp = mul(choose(l, i), power[i]);
		res = add(res, (l - i) % 2 ? -tmp : tmp);
	}
	return mul(res, pre[l]);
}

int solve() {
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= K; i++) {
		fact[i] = mul(fact[i - 1], i);
		inv[i] = pot(fact[i], MOD - 2);
	}
	
	for (int i = 0; i <= K; i++)
		power[i] = pot(i, K);
	
	int mini = min(N, K);
	for (int i = 1; i <= mini; i++) {
		pre[i] = inv[i];
		for (int j = 0; j < i; j++)
			pre[i] = mul(pre[i], N - j);
	}
	
	int sol = 0;
	for (int i = 1; i <= mini; i++)
		sol = add(sol, mul(calc(i), pot(2, N - i)));
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}