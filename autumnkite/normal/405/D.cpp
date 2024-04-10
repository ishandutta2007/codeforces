#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
void print(int x){
	int cnt = 0, num[25];
	while (x) num[++cnt] = x % 10, x /= 10;
	for (; cnt; --cnt) putchar(num[cnt] + '0');
}
#define N 1000005
int S, n, a[N], b[N], cnt, c[N], x[N];
int main(){
	S = 1000000, n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read(), c[a[i]] = i;
	for (register int i = 1; i <= (S >> 1); ++i)
		if (!c[i] && !c[S - i + 1]) x[++cnt] = i;
	for (register int i = 1; i <= n; ++i){
		if (b[i]) continue;
		if (!c[S - a[i] + 1]) b[i] = S - a[i] + 1;
		else b[i] = x[cnt], b[c[S - a[i] + 1]] = S - x[cnt] + 1, --cnt;
	}
	print(n), putchar('\n');
	for (register int i = 1; i <= n; ++i) print(b[i]), putchar(' ');
}