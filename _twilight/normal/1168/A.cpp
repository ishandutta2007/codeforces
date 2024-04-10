#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e5 + 5;

int n, m;
int a[N];

boolean check(int mid) {
	int l = 0;
	for (int i = 1; i <= n; i++) {
		int L = (a[i] + mid) % m;
		if (a[i] <= L) {
			if (L < l) {
				return false;
			}
			l = max(l, a[i]);
		} else {
			if (L < l) {
				l = max(l, a[i]);
			}
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	int l = 0, r = m - 1, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	printf("%d\n", r + 1);
	return 0;
}