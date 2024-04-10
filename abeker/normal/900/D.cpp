#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int X, Y;

void load() {
	scanf("%d%d", &X, &Y);
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

int solve() {
	if (Y % X)
		return 0;
	
	Y /= X;
	
	if (Y == 1)
		return 1;
	
	vector <int> p;
	int memo = Y;
	for (int i = 2; i * i <= Y; i++) {
		if (Y % i)
			continue;
		p.push_back(i);
		while (!(Y % i))
			Y /= i;
	}
	if (Y > 1)
		p.push_back(Y);
	
	int sz = p.size();
	int sol = 0;
	for (int i = 0; i < 1 << sz; i++) {
		int prod = 1, cnt = 0;
		for (int j = 0; j < sz; j++) 
			if (i >> j & 1) {
				prod *= p[j];
				cnt ^= 1;
			}
		sol = add(sol, cnt ? -pot(2, memo / prod - 1) : pot(2, memo / prod - 1));
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}