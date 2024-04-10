#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int N, M;
int a[MAXN], b[MAXN];

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
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	for (int i = 0; i < N; i++)
		scanf("%d", b + i);
}

int solve() {
	int inv = pot(M, MOD - 2);
	int sol = 0, prod = 1;
	for (int i = 0; i < N; i++) 
		if (a[i] && b[i]) {
			if (a[i] == b[i])
				continue;
			if (a[i] > b[i])
				sol = add(sol, prod);
			break;
		}
		else if (a[i]) {
			sol = add(sol, mul(prod, mul(a[i] - 1, inv)));
			prod = mul(prod, inv);
		}
		else if (b[i]) {
			sol = add(sol, mul(prod, mul(M - b[i], inv)));
			prod = mul(prod, inv);
		}
		else {
			sol = add(sol, mul(mul(M - 1, (MOD + 1) / 2), mul(prod, inv)));
			prod = mul(prod, inv);
		}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}