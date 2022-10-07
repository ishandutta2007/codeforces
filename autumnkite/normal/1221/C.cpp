#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int T, a, b, c, t;
int main(){
	T = read();
	while (T--){
		a = read(), b = read(), c = read();
		t = std :: min(std :: min(a, b), c);
		a -= t, b -= t, c -= t;
		if (a > b) std :: swap(a, b);
		b = std :: min(b, a << 1);
		printf("%d\n", t + (a + b) / 3);
	}
}