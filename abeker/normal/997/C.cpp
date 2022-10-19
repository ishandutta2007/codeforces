#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;
const int mod = 998244353;

int N;
int fact[MAXN], inv[MAXN];
int pot[MAXN];
int choose[MAXN];

void load() {
	scanf("%d", &N);
}

inline int add(int x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
	else if (x < 0)
		x += mod;
	return x;
}

inline int mul(int x, int y) {
	return (ll)x * y % mod;
}

int power(int x, ll y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

int solve() {
	fact[0] = inv[0] = pot[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = mul(fact[i - 1], i);
		inv[i] = power(fact[i], mod - 2);
		pot[i] = mul(pot[i - 1], 3);
	}
	
	for (int i = 0; i <= N; i++)
		choose[i] = mul(fact[N], mul(inv[i], inv[N - i]));
	
	int sol = 0;
	for (int i = 1; i <= N; i++) {
		int tmp = mul(choose[i], power(3, (ll)N * (N - i) + i));
		sol = add(sol, i % 2 ? mul(2, tmp) : -mul(2, tmp));
	}
	
	for (int i = 0; i < N; i++) {
		int tmp = mul(choose[i], add(power(add(1, -pot[i]), N), -power(-pot[i], N)));
		sol = add(sol, i % 2 ? mul(3, tmp) : -mul(3, tmp)); 
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}