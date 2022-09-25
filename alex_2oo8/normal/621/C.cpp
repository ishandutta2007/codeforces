#include<bits/stdc++.h>

using namespace std;

const int MX = 100000;

int l[MX], r[MX];

long double f(int k, int p) {
	return (long double)(r[k] - l[k] + 1 - r[k] / p + (l[k] - 1) / p) / (r[k] - l[k] + 1);
}

int main() {
	int n, p;
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) scanf("%d %d", l + i, r + i);
	
	long double ans = 0.0;
	for (int i = 0; i < n; i++) ans += 2000 * (1.0 - f(i, p) * f((i + 1) % n, p));
	
	printf("%.12f\n", (double)ans);
	
	return 0;
}