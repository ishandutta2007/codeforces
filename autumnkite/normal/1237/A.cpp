#include <cstdio>
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
int n, s;
int main(){
	n = read(), s = 0;
	for (register int i = 1; i <= n; ++i){
		int x = read();
		if ((x & 1) == 0){ printf("%d\n", x / 2); continue; }
		x = (x - 1) / 2;
		if (s) ++x, --s; else ++s;
		printf("%d\n", x);
	}
}