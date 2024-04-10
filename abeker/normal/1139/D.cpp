#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int N;
int prime[MAXN];

void load() {
	scanf("%d", &N);
}

inline void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
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

int calc(int x) {
	int cnt = 0;
	for (int y = x; y > 1; cnt ^= 1) {
		int t = prime[y];
		y /= t;
		if (!(y % t))
			return 0;
	}
	int res = mul(N / x, pot(N - N / x, MOD - 2));
	return cnt ? res : -res;
}

int solve() {
	for (int i = 2; i <= N; i++)
		if (!prime[i])
			for (int j = i; j <= N; j += i)
				if (!prime[j])
					prime[j] = i;
	
	int sol = 1;
	for (int i = 2; i <= N; i++) 
		add(sol, calc(i));
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}