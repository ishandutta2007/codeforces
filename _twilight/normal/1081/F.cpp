#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 303;

int n, m;
int sum[N];

int ask(int l, int r) {
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

int cur;
void rev(int l, int r, int d) {
	assert((((r - l) & 1) == (n & 1)));
	int rt, re = ((d == 0) ? (r & 1) : (l & 1));
	int msk = 0;
	do {
		rt = ask(l, r);
		if (((rt - cur) & 1) == re) {
			msk ^= 1;
		} else {
			msk ^= 2;
		}
		cur = rt;
	} while (msk ^ 1);
}

int main() {
	scanf("%d%d", &n, &m);
	cur = m;
	if (n == 1) {
		printf("! %d\n", m);;
		return 0;
	} else if (n & 1) {
		sum[n] = m;
		for (int i = 2; i < n; i++) {
			rev(i - 1, i, 0);
			sum[i] = (m - cur) + i;
			assert(!(sum[i] & 1));
			sum[i] >>= 1;
			rev(i - 1, i, 0);
		}
		rev(2, 3, 1);
		sum[1] = (m + cur) - n + 1;
		assert(!(sum[1] & 1));
		sum[1] >>= 1;
	} else {
		sum[n] = m;
		for (int i = 1; i < n; i++) {
			rev(i, i, 0);
			sum[i] = (m - cur) + i;
			assert(!(sum[i] & 1));
			sum[i] >>= 1;
			rev(i, i, 0);
		}
	}
	putchar('!');
	putchar(' ');
	for (int i = 1; i <= n; i++) {
		putchar('0' + (sum[i] - sum[i - 1]));
	}
	return 0;
}