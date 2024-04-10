#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define pii pair<int, int>

pii operator + (pii a, int x) {
	if (x > a.first) {
		a.second = a.first;
		a.first = x;
	} else if (x > a.second) {
		a.second = x;
	}
	return a;
}

pii operator + (pii a, pii b) {
	return a + b.first + b.second;
}

const int N = 1e6 + 5;

int n;
int a[N];
pii f[1 << 21];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		f[a[i]] = f[a[i]] + i;
	}
	int N = 1 << 21;
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < N; j++) {
			if (!((j >> i) & 1)) {
				f[j] = f[j] + f[j ^ (1 << i)];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n - 2; i++) {
		int tmp = 0, msk = 0;
		for (int b = 20; ~b; b--) {
			if ((a[i] >> b) & 1) {
				tmp |= 1 << b;
			} else if (f[msk | (1 << b)].second > i) {
				tmp |= 1 << b;
				msk |= 1 << b;
			}
		}
		ans = max(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}