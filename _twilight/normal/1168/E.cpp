#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1 << 12;

int n, m;
int _p[N], _q[N];
int p[N], q[N], a[N], b[N];

void adjust(int i, int j, int x, int& t, int& nx) {
	if ((a[i] ^ x) == (p[j] ^ q[j])) {
		t = -1, nx = 0;
		swap(p[i], p[j]), swap(_p[p[i]], _p[p[j]]);
		swap(q[i], q[j]), swap(_q[q[i]], _q[q[j]]);
		assert((p[i] ^ q[i]) == (a[i] ^ x));
		assert((p[j] ^ q[j]) == (a[j] ^ x));
		a[i] ^= x, a[j] ^= x;
		return;
	}
	if ((a[j] ^ x) == (q[i] ^ p[j])) {
		t = -1, nx = 0;
		swap(q[i], q[j]);
		swap(_q[q[i]], _q[q[j]]);
		assert((p[i] ^ q[i]) == (a[i] ^ x));
		assert((p[j] ^ q[j]) == (a[j] ^ x));
		a[i] ^= x, a[j] ^= x;
		return;
	}
	if ((a[i] ^ x) == (p[j] ^ q[i])) {
		t = -1, nx = 0;
		swap(p[i], p[j]);
		swap(_p[p[i]], _p[p[j]]);
		assert((p[i] ^ q[i]) == (a[i] ^ x));
		assert((p[j] ^ q[j]) == (a[j] ^ x));
		a[i] ^= x, a[j] ^= x;
		return;
	}
	t = _p[q[i] ^ a[i] ^ x];
//	assert(t != j);
	nx = p[i] ^ q[j] ^ a[t];
	swap(p[i], p[t]), swap(_p[p[i]], _p[p[t]]);
	swap(q[j], q[t]), swap(_q[q[j]], _q[q[t]]);
	assert((p[i] ^ q[i]) == (a[i] ^ x));
	a[i] ^= x;
	a[j] = p[j] ^ q[j];
	a[t] = p[t] ^ q[t];
}

int main() {
	scanf("%d", &m);
	n = 1 << m;
	for (int i = 0; i < n; i++) {
		p[i] = _p[i] = q[i] = _q[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", b + i);
		sum ^= b[i];
	}
	if (sum) {
		puts("Fou");
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		int x = i, y = i + 1, d = a[i] ^ b[i], ny, nd;
		while (d) {
			adjust(x, y, d, ny, nd);
			x = ny;
			d = nd;
		}
	}
	puts("Shi");
	for (int i = 0; i < n; i++) {
		printf("%d ", p[i]);
	}
	putchar('\n');
	for (int i = 0; i < n; i++) {
		printf("%d ", q[i]);
	}
	putchar('\n');
	return 0;
}