#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 3e5 + 5, M = 1e4 + 5, Mod = 1e9 + 7;
const int B = 1e9;

int add(int a, int b) {
	return ((a += b) >= Mod) ? (a - Mod) : (a);
}
int sub(int a, int b) {
	return ((a -= b) < 0) ? (a + Mod) : (a); 
}

int T1[N << 1], T2[N << 1];

int n, m = 1;
int w[1234];
char buf[M];
int *dp0, *dp1;
int a[N], b[N], c[N];

void get_number() {
	int l = strlen(buf + 1);
	int *x = w + 1, y = 1;
	for (char *p = buf + l; p != buf; p--) {
		*x = *x + y * (*p - '0');
		if ((y *= 10) == B) {
			y = 1, x++, m++;
		}
	}
	if (m > 1 && !w[m]) {
		--m;
	}
}

int main() {
	scanf("%d", &n);
	a[1] = 1;
	for (int i = 2; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
	}
	scanf("%s", buf + 1);
	get_number();
	for (int i = 1; i <= n; i++) {
		if (a[i] > 1) {
			ll r = 0;
			for (int *x = w + m; x != w; x--) {
				r = r * B + *x;
				*x = r / a[i];
				r %= a[i];
			}
			c[i] = r;
			while (m > 1 && !w[m])
				m--;
		}
	}
	if (m > 1 || a[1] > 600000) {
		puts("0");
		return 0;
	}
	dp0 = T1, dp1 = T2;
	dp1[0] = 1;
	int sz = 0, nsz;
	for (int i = 1; i <= n && a[i] == 1; i++) {
		sz += b[i];
	}
	for (int l = 1, r = 1; l <= n; l = r, sz = nsz) {
		while (a[++r] == 1);
		swap(dp0, dp1);
		for (int i = l; i < r; i++) {
			int sum = 0;
			for (int j = 0; j < b[i]; j++) {
				sum = add(sum, dp0[sz - j]);
			}
			for (int j = sz; ~j; j--) {
				int old = dp0[j];
				if (j >= b[i]) {
					sum = add(sum, dp0[j - b[i]]);
				}
				dp0[j] = sum;
				sum = sub(sum, old);
			}
		}
		if (a[r]) {
			nsz = sz / a[r] + b[r];
			for (int j = r; a[++j] == 1; nsz += b[j]);
			memset(dp1, 0, (nsz + 1) << 2);
			for (int i = c[r], x = 0; i <= sz; i += a[r], x++) {
				dp1[x] = add(dp1[x], dp0[i]);
			}
		} else {
			printf("%d\n", dp0[w[1]]);
		}
	}
	return 0;
}