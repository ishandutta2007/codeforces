#include <bits/stdc++.h>
const int N = 1000005, P = 998244353;
int n, f[N], g[N];
int check[N], p[N], d[N], e[N], tot = 0;
void sieve() {
	d[1] = 1, e[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (!check[i]) { p[++tot] = i; d[i] = 2; e[i] = 1; }
		for (int j = 1; j <= tot && i * p[j] <= n; j++) {
			check[i * p[j]] = 1;
			if (i % p[j] == 0) {
				e[i * p[j]] = e[i] + 1;
				d[i * p[j]] = d[i] / (e[i] + 1) * (e[i] + 2);
				break;
			} else {
				d[i * p[j]] = d[i] * 2;
				e[i * p[j]] = 1;
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	sieve();
	/*
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = 0;
		for (int j = 1; j <= i; j++)
			if (i % j == 0) f[i]++;
		for (int j = 1; j < i; j++)
			(f[i] += f[j]) %= P;
	}*/
	int ans = 0;
	// for (int i = 1; i <= 15; i++) printf("%d ", d[i]);
	for (int i = 1, sum = 0; i <= n; i++) {
		ans = (d[i] + sum) % P;
		(sum += ans) %= P;
	}
	printf("%d\n", ans);
	return 0;
}