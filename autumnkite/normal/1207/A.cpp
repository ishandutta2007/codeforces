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
int T, b, p, f, h, c, ans;
int main(){
	T = read();
	while (T--){
		b = read() >> 1, p = read(), f = read(), h = read(), c = read();
		if (h < c) std :: swap(h, c), std :: swap(p, f);
		ans = std :: min(p, b) * h + std :: min(f, b - std :: min(p, b)) * c;
		printf("%d\n", ans);
	}
}