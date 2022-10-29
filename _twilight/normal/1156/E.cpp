#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 3;

int n, ans;
int a[N], b[N], mx[N];

void dividing(int l, int r) {
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	mx[mid] = a[mid];
	for (int i = mid - 1; i >= l; i--) {
		mx[i] = max(mx[i + 1], a[i]);
	}
	mx[mid + 1] = a[mid + 1];
	for (int i = mid + 2; i <= r; i++) {
		mx[i] = max(mx[i - 1], a[i]);
	}
	for (int i = mid; i >= l; i--) {
		int x = b[mx[i] - a[i]];
		if (x > mid && x <= r && mx[x] < mx[i])
			ans++;
	}
	for (int i = mid + 1; i <= r; i++) {
		int x = b[mx[i] - a[i]];
		if (x >= l && x <= mid && mx[x] < mx[i])
			ans++;
	}
	dividing(l, mid);
	dividing(mid + 1, r);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		b[a[i]] = i;
	}
	dividing(1, n);
	printf("%d\n", ans);
	return 0;
}