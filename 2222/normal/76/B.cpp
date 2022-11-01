#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 100000, H = 200000;

int n, m, h, a[H], b[N];
int adj[N][3], q[N];

bool dfs(int x) {
	for (int *y = adj[x]; ~*y; ++y)
		if (a[*y] < 0 || b[x] + 1 == b[a[*y]] && dfs(a[*y])) {
			a[*y] = x;
			return true;
		}
	b[x] = 0;
	return false;
}

void addedge(int i, int j) {
	if (abs(a[i] - b[j]) == q[i])
		adj[i][adj[i][0] >= 0] = h;
}

int main() {
	scanf("%d%d%*d%*d", &n, &m);
	if (m == 0) {
		printf("%d\n", n);
		return 0;
	}
	for (int i = 0; i < n; ++i) 
		scanf("%d", a + i);
	for (int i = 0, j = 0; j < m; ++j) 
		scanf("%d", b + j);
	for (int i = 0, j = 0; i < n; ++i) {
		adj[i][0] = adj[i][1] = adj[i][2] = -1;
		for (; j + 1 < m && b[j + 1] <= a[i]; ++j);
		q[i] = abs(a[i] - b[j]);
		if (j + 1 < m) q[i] = min(q[i], abs(a[i] - b[j + 1]));
	}
	for (int i = 0, j = 0; j < m; ++j) {
		for (; i + 1 < n && a[i + 1] <= b[j]; ++i);
		addedge(i, j);
		if (i + 1 < n && a[i] != b[j]) {
			if (a[i] + a[i + 1] == b[j] * 2)
				++h;
			addedge(i + 1, j);
		}
		++h;
	}
	memset(a, -1, h * sizeof(int));
	int *e = q;
	for (int i = 0; i < n; ++i) 
		for (int *j = adj[i]; ; ++j) {
			if (*j < 0) {
				*e++ = i;
				break;
			}
			if (a[*j] < 0) {
				a[*j] = i;
				break;
			}
		}
	for (int *q0, *q1; ; ) {
		q0 = q;
		q1 = e;
		memset(b, 0, n * sizeof(int));
		for (int *i = q0; i != q1; ++i)
			b[*i] = 1;
		for (int x, y, d; q0 != q1; ) {
			x = *q0++;
			d = b[x] + 1;
			for (int *i = adj[x]; ~*i; ++i) {
				y = a[*i];
				if ((~y) && b[y] == 0) {
					b[y] = d;
					*q1++ = y;
				}
			}
		}
		bool ok = true;
		for (int *i = e; i-- != q; )
			if (b[*i] && dfs(*i)) {
				*i = *--e;
				ok = false;
			}
		if (ok) break;
	}
	printf("%d\n", e - q);
	return 0;
}