#include <bits/stdc++.h>
using namespace std;

int D, M;

inline int add(int x, int y) {
	x += y;
	if (x >= M)
		return x - M;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % M;
}

int solve() {
	int sol = 0, prod = 1;
	for (int i = 0; (1 << i) <= D; i++) {
		sol = add(sol, mul(prod, min(D + 1, 1 << i + 1) - (1 << i)));
		prod = mul(prod, (1 << i) + 1);
	}
	return sol;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &D, &M);
		printf("%d\n", solve());
	}
	return 0;
}