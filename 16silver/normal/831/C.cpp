#include <cstdio>
#include <algorithm>
using namespace std;
int a[2000], b[2000], r[2000], q[2000];
int srch(int x, int left, int right) {
	if (left == right) {
		if (b[left] == x) return left;
		else return -1;
	}
	int mid = (left + right) / 2;
	if (b[mid] == x) return mid;
	else if (b[mid] > x) {
		return srch(x, left, mid);
	}
	else {
		return srch(x, mid + 1, right);
	}
}
int main() {
	int n, k, i, j, st, idx, tmp, ans, qin = 0;
	scanf("%d %d", &k, &n);
	for (i = 0; i < k; i++) scanf("%d", &a[i]);
	for (i = 0; i < n; i++) scanf("%d", &b[i]);
	sort(b, b + n);
	for (i = 0; i < k; i++) {
		for (j = 0; j < n; j++) r[j] = 0;
		st = b[0];
		r[0] = 1;
		for (j = i; j > 0; j--) {
			st -= a[j];
			idx = srch(st, 0, n);
			if (idx != -1) {
				r[idx] = 1;
			}
		}
		st -= a[0];
		ans = st;
		st = b[0];
		for (j = i + 1; j < k; j++) {
			st += a[j];
			idx = srch(st, 0, n);
			if (idx != -1) {
				r[idx] = 1;
			}
		}
		tmp = 1;
		for (j = 0; j < n; j++) {
			if (r[j] == 0) {
				tmp = 0;
				break;
			}
		}
		if (tmp == 1) q[qin++] = ans;
	}
	sort(q, q + qin);
	ans = qin;
	for (i = 1; i < qin; i++) {
		if (q[i] == q[i - 1]) ans--;
	}
	printf("%d", ans);
}