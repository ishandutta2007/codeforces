#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 5e5 + 5;

int uf[N], sz[N];

int find(int x) {
	return (uf[x] == x) ? (x) : (uf[x] = find(uf[x]));
}
void unit(int x, int y) {
	x = find(x), y = find(y);
	if (x ^ y) {
		uf[x] = y;
		sz[y] += sz[x];
	}
}

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		uf[i] = i, sz[i] = 1;
	for (int i = 1, x, y, ls; i <= m; i++) {
		scanf("%d", &x);
		if (!x) continue;
		scanf("%d", &ls);
		while (--x) {
			scanf("%d", &y);
			unit(y, ls);
			ls = y;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", sz[find(i)]);
	}
	return 0;
}