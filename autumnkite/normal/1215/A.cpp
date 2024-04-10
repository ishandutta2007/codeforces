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
int a1, a2, k1, k2, n, t;
int main(){
	a1 = read(), a2 = read(), k1 = read(), k2 = read(), n = read();
	printf("%d ", std :: max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1)));
	if (k1 < k2) std :: swap(k1, k2), std :: swap(a1, a2);
	t = std :: min(a2, n / k2);
	printf("%d\n", t + std :: min(a1, (n - k2 * t) / k1));
}