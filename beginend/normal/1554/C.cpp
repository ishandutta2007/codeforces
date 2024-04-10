#include<bits/stdc++.h>
using namespace std;

int n, m, bin[35];

void dfs(int d, int l, int r, int L, int R) {
	if (d == -1) {
		printf("%d\n", L);
		return;
	}
	if (n & bin[d]) {
		dfs(d - 1, l, r - bin[d], L, R - bin[d]);
	}
	else {
		if (r - l + 1 >= bin[d]) dfs(d - 1, L + bin[d], r, L + bin[d], R);
		else dfs(d - 1, l, r, L, R - bin[d]);
	}
}

int main() {
	int T; scanf("%d", &T);
	bin[0] = 1;
	for (int i = 1; i <= 30; i++) bin[i] = bin[i - 1] * 2;
	while (T--) {
		scanf("%d%d", &n, &m);
		dfs(29, 0, m, 0, bin[30] - 1);
	}
	return 0;
}