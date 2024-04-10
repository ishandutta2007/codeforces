#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e6 + 5;

int n, m;
int d[N];
boolean odd[N];
int uf[N], sz[N];

int find(int x) {
	return (uf[x] ^ x) ? (uf[x] = find(uf[x])) : (x);
}
void unit(int x, int y) {
	x = find(x), y = find(y);
	if (x ^ y) {
		uf[y] = x;
		sz[x] += sz[y];
	}
	sz[x]++;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		uf[i] = i, odd[i] = false;	
	}
	unit(1, 1);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		d[u] ^= 1, d[v] ^= 1;
		unit(u, v);
	}
	int cnt_odd = 0, ec = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i]) {
			cnt_odd++;
			odd[find(i)] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (find(i) == i && sz[i] && !odd[i]) {
			ec++;
		}
	}
	if (!cnt_odd) {
		printf("%d\n", (ec == 1) ? (0) : (ec));
	} else {
		printf("%d\n", (cnt_odd >> 1) + ec);
	}
	return 0;
}