#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int n, hn, l, r, mid;

int _query(int p) {
	int x;
	printf("? %d\n", p);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
int query(int p) {
	return _query(p + hn) - _query(p); 
}
void answer(int p) {
	printf("! %d\n", p);
	fflush(stdout);
	exit(0);
}


int main() {
	scanf("%d", &n);
	hn = n >> 1, l = 2, r = hn;
	int x = query(1), y;
	if (!x) {
		answer(1);
	}
	while (l <= r) {
		mid = (l + r) >> 1;
		y = query(mid);
		if (!y) {
			answer(mid);
		}
		if (1ll * x * y > 0) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	answer(-1);
	return 0;
}