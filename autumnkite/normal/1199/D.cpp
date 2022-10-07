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
#define N 1000005
int n, q, a[N], last[N], suf[N];
struct query{
	int op, x, p;
}Q[N];
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read(), last[i] = 0;
	q = read();
	for (register int i = 1; i <= q; ++i){
		Q[i].op = read();
		if (Q[i].op == 1) Q[i].p = read(), Q[i].x = read(), last[Q[i].p] = i;
		else Q[i].x = read();
	}
	for (register int i = q; i; --i)
		if (Q[i].op == 2) suf[i] = std :: max(suf[i + 1], Q[i].x);
		else suf[i] = suf[i + 1];
	for (register int i = 1; i <= n; ++i){
		int x = suf[last[i] + 1];
		if (!last[i]) x = std :: max(x, a[i]);
		else x = std :: max(x, Q[last[i]].x);
		printf("%d ", x);
	}
}