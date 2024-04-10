#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

int n, z;
int a[N];

int main() {
	scanf("%d%d", &n, &z);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + n + 1);
	int l = 0, r = (n >> 1), mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		boolean good = true;
		for (int i = 1; i <= mid && good; i++)
			good = (a[i] + z <= a[n - mid + i]);
		if (good) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("%d\n", l - 1);
	return 0;
}