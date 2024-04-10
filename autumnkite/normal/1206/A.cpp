#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 105
int n, m, a[N], b[N];
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	m = read();
	for (register int i = 1; i <= m; ++i) b[i] = read();
	std :: nth_element(a + 1, a + n, a + 1 + n);
	std :: nth_element(b + 1, b + m, b + 1 + m);
	printf("%d %d\n", a[n], b[m]);
}