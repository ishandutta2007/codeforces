#include <cstdio>
#include <cctype>
#include <algorithm>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 400005
int n, I, k, K, a[N], ans;
int main(){
	n = read(), I = read();
	k = 8 * I / n, K = 1;
	for (register int i = 1; i <= k; ++i)
		if (K * 2 > n){ K = n; break; }
		else K *= 2;
	for (register int i = 1; i <= n; ++i) a[i] = read();
	std :: sort(a + 1, a + 1 + n), a[0] = -1;
	int j = 1, s = 0;
	while (s < K - 1 && j <= n){
		++j;
		while (j <= n && a[j] == a[j - 1]) ++j;
		++s;
	}
	ans = n;
	for (register int i = 1; i <= n; ++i)
		if (a[i] != a[i - 1]){
			if (j <= n) ++j;
			while (j <= n && a[j] == a[j - 1]) ++j;
			ans = std :: min(ans, (i - 1) + (n - j + 1));
		}
	printf("%d\n", ans);
}