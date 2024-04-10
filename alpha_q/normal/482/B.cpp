#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m, a[32][N], q[N][4], tree[N << 1];

void init (void) {
	for (int i = n - 1; i; --i) tree[i] = tree[i << 1] & tree[i << 1 | 1];
}

int query (int l, int r) {
	--l; int sum = (1 << 30) - 1;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) sum &= tree[l++];
		if (r & 1) sum &= tree[--r];
	}
	return sum;
}

int main (int argc, char const *argv[]) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", q[i] + 1, q[i] + 2, q[i]);
		for (int j = 0; j <= 30; ++j) {
			if (q[i][0] & (1 << j)) {
				++a[j][q[i][1] - 1];
				--a[j][q[i][2]];
			}
		} 
	} 

	for (int j = 0; j <= 30; ++j) {
		for (int i = 1; i < n; ++i) a[j][i] += a[j][i - 1];
	}

	for (int i = 0; i < n; ++i) {
		tree[n + i] = 0;
		for (int j = 0; j <= 30; ++j) {
			if (a[j][i] > 0) tree[n + i] += (1 << j);
		}
	}

	init();

	for (int i = 0; i < m; ++i) {
		if (query(q[i][1], q[i][2]) != q[i][0]) {
			printf("NO\n");
			return 0;			 
		} 
	}

	printf("YES\n");
	for (int i = 0; i < n; ++i) printf("%d ", tree[n + i]);
	puts("");
	return 0;
}