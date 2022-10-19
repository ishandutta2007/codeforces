#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 100;
const int MOD = 1e9 + 7;
const int LOG = 20;

int p[MAXN];
int pot[MAXN];
int choose[MAXN][LOG];

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	return x;
}

void init() {
	for (int i = 2; i < MAXN; i++)
		if (!p[i])
			for (int j = i; j < MAXN; j += i)
				if (!p[j])
					p[j] = i;
	
	pot[0] = 1;
	for (int i = 1; i < MAXN; i++)
		pot[i] = mul(pot[i - 1], 2);
	
	choose[0][0] = 1;
	for (int i = 1; i < MAXN; i++) {
		choose[i][0] = 1;
		for (int j = 1; j <= min(LOG - 1, i); j++)
			choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
	}
}

int solve(int x, int y) {
	int res = pot[y - 1];
	while (x > 1) {
		int tmp = p[x], exp = 0;
		for (; !(x % tmp); x /= tmp)
			exp++;
		res = mul(res, choose[exp + y - 1][exp]);
	}
	return res;
}

int main() {
	init();
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", solve(x, y));
	}
	return 0;
}