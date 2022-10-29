#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int n, d, b;
int a[N], ra[N];

boolean check(int mid) {
	for (int i = 1; i <= n; i++)
		ra[i] = a[i];
	int hn = (n + 1) >> 1;
	int p = 1;
	for (int i = mid + 1; i <= hn; i++) {
		int r = b, dlt;
		while (r) {
			if (p <= i || (1ll * i * d >= p - i)) {
				dlt = min(r, ra[p]);
				r -= dlt;
				ra[p] -= dlt;
			} else if (p > i) {
				break;
			}
			if (!ra[p])
				p++;
		}
		if (r) {
			return false;
		}
	}
	p = n;
	for (int i = n - mid; i > hn; i--) {
		int r = b, dlt;
		while (r) {
			if (p >= i || (1ll * (n - i + 1) * d >= i - p)) {
				dlt = min(r, ra[p]);
				r -= dlt;
				ra[p] -= dlt;
			} else if (p < i) {
				break;
			}
			if (!ra[p])
				p--;
		}
		if (r) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d%d%d", &n, &d, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	int l = 0, r = n >> 1, mid;
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