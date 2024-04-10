#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
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

int main() {
	int N, M, A;
	scanf("%d%d%d", &N, &M, &A);
	int b, prv = 0, ans = 1;
	while (M--) {
		scanf("%d", &b);
		ans = mul(ans, mul(add(pot(A, 2 * (b - prv)), pot(A, b - prv)), (MOD + 1) / 2));
		prv = b;
	}
	printf("%d\n", mul(ans, pot(A, N - 2 * b)));
	return 0;
}