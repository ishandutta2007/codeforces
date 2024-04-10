#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
long long read(){
	register long long x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 100005
int n;
long long k, a[N], sum[N];
bool check(int x){
	for (register int i = 1, j = 1; i <= n; ++i){
		while (j <= n && a[j] - a[i] <= x) ++j;
		if (a[i] * (i - 1) - sum[i - 1] + sum[n] - sum[j - 1] - (a[i] + x) * (n - j + 1) <= k) return 1;
	}
	for (register int i = 1, j = 1; i <= n; ++i){
		while (a[i] - a[j] > x) ++j;
		if ((a[i] - x) * (j - 1) - sum[j - 1] + sum[n] - sum[i] - a[i] * (n - i) <= k) return 1;
	}
	return 0;
}
int main(){
	n = read(), k = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	std :: sort(a + 1, a + 1 + n);
	for (register int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	int l = 0, r = a[n] - a[1], md, ans = 0;
	while (l <= r) if (check(md = (l + r) >> 1)) r = md - 1, ans = md; else l = md + 1;
	printf("%d\n", ans);
}