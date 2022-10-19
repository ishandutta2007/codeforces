#include <bits/stdc++.h>
using namespace std;

const int MAXK = 1e5 + 5;
const int MOD = 1e9 + 9;

int N, A, B, K;
char s[MAXK];

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

int inv(int x) {
	return pot(x, MOD - 2);
}

void load() {
	scanf("%d%d%d%d%s", &N, &A, &B, &K, s);	
}

int solve() {
	N++;
	int div = mul(B, inv(A));
	int base = pot(div, K);
	if (base == 1)
		base = N / K;
	else
		base = mul(add(pot(base, N / K), -1), inv(add(base, -1)));
	
	int sol = 0;
	for (int i = 0; i < K; i++) 
		sol = add(sol, s[i] == '+' ? pot(div, i) : -pot(div, i));
	
	return mul(sol, mul(base, pot(A, N - 1)));
}

int main() {
	load();
	printf("%d\n", solve());	
	return 0;
}