#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int g[MAXN];
int cnt[MAXN][15];

int f(int x) {
	int res = 1;
	for (; x; x /= 10)
		if (x % 10)
			res *= x % 10;
	return res;
}

void init() {
	for (int i = 1; i < MAXN; i++) {
		g[i] = i < 10 ? i : g[f(i)];
		if (i >= 10)
			assert(f(i) < i);
	}
	
	for (int i = 1; i < MAXN; i++)
		for (int j = 1; j < 10; j++)
			cnt[i][j] = cnt[i - 1][j] + (g[i] == j);
}

int main() {
	init();
	
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", cnt[r][k] - cnt[l - 1][k]);
	}
	
	return 0;
}