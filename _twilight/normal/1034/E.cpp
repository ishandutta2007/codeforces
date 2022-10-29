#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ull unsigned long long

const int N = 1 << 21;

int n;
int c[N];
ull a[N], b[N];
char buf[N + 3];

void fwt(ull* f, int n) {
	int m = 1 << n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((j >> i) & 1) {
				f[j] += f[j ^ (1 << i)];
			}
		}
	}
}

void ifwt(ull* f, int n) {
	int m = 1 << n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((j >> i) & 1) {
				f[j] -= f[j ^ (1 << i)];
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	int N = 1 << n;
	for (int i = 1; i < N; i++) {
		c[i] = c[i >> 1] + ((i & 1) << 1);
	}
	scanf("%s", buf);
	for (int i = 0; i < N; i++) {
		a[i] = ((ull) (buf[i] - '0')) << c[i]; 
	}
	scanf("%s", buf);
	for (int i = 0; i < N; i++) {
		b[i] = ((ull) (buf[i] - '0')) << c[i]; 
	}
	fwt(a, n);
	fwt(b, n);
	for (int i = 0; i < N; i++) {
		a[i] *= b[i];
	}
	ifwt(a, n);
	for (int i = 0; i < N; i++) {
		buf[i] = '0' + ((a[i] >> c[i]) & 3);
	}
	buf[N] = 0;
	puts(buf);
	return 0;
}