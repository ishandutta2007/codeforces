#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

int n;
int ans = 1e9;
int a[N], b[N], t[N];

boolean check(int s) {
	for (int i = 2; i <= n; i++) {
		if (t[i] >= s + i - 1) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d", &n);
	int pn = -1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
		if (b[i]) {
			t[b[i]] = i;
		}
		if (b[i] == 1) {
			pn = i;
		}
	}
	boolean flag = (pn != -1);
	for (int i = pn; i <= n && flag; i++) {
		flag =  (b[i] == i - pn + 1);
	}
	int s = n - pn + 1;
	for (int i = s + 1; i <= n && flag; i++) {
		if (t[i] >= i - s) {
			flag = false;
		}
	}
	if (flag) {
		ans = pn - 1;
	}
	int l = t[1] + 1, r = n, mid = (l + r) >> 1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	ans = min(ans, r + n);
	printf("%d\n", ans);
	return 0;
}