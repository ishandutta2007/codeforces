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
#define N 100005
int n, x, y, a[N];
int main(){
	n = read(), x = read(), y = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	for (register int i = 1; i <= n; ++i){
		bool flag = 1;
		for (register int j = i - 1; j && j >= i - x; --j)
			if (a[j] < a[i]){ flag = 0; break; }
		for (register int j = i + 1; j <= i + y && j <= n; ++j)
			if (a[j] < a[i]){ flag = 0; break; }
		if (flag) return printf("%d\n", i), 0;
	}
}