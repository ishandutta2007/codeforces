#include <bits/stdc++.h>
using namespace std;
inline int Query(int h, int w, int i1, int j1, int i2, int j2) {
	printf("? %d %d %d %d %d %d\n", h, w, i1, j1, i2, j2);
	fflush(stdout);
	int t;
	scanf("%d", &t);
	return t;
}
inline vector<int> getp(int x) {
	vector<int> ret;
	for (int i = 2; i * i <= x; i++) if (x % i == 0) {
		while (x % i == 0) x /= i;
		ret.push_back(i);
	}
	if (x > 1) ret.push_back(x);
	return ret;
}
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	int a = n, b = m;
	auto vec = getp(n);
	for (int p : vec) {
		if (p == 2) {
			while (a % 2 == 0) {
				if (Query(a / 2, m, 1, 1, a / 2 + 1, 1)) {
					a /= 2;
				} else break;
			}
		} else {
			while (a % p == 0) {
				if (Query(a / p * (p / 2), m, 1, 1, a / p * (p / 2) + 1, 1)
				&& Query(a / p * (p / 2), m, 1, 1, a / p * (p / 2 + 1) + 1, 1)) {
					a /= p;
				} else break;
			}
		}
	}
	vec = getp(m);
	for (int p : vec) {
		if (p == 2) {
			while (b % 2 == 0) {
				if (Query(n, b / 2, 1, 1, 1, b / 2 + 1)) {
					b /= 2;
				} else break;
			}
		} else {
			while (b % p == 0) {
				if (Query(n, b / p * (p / 2), 1, 1, 1, b / p * (p / 2) + 1)
				&& Query(n, b / p * (p / 2), 1, 1, 1, b / p * (p / 2 + 1) + 1)) {
					b /= p;
				} else break;
			}
		}
	}
	a = n / a, b = m / b;
	int ca = 0, cb = 0;
	for (int i = 1; i <= a; i++) if (a % i == 0) ca++;
	for (int i = 1; i <= b; i++) if (b % i == 0) cb++;
	printf("! %d\n", ca * cb);
	fflush(stdout);
	return 0;
}