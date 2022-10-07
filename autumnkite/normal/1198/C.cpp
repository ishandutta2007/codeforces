#include <cstdio>
#include <cctype>
#include <algorithm>
#include <set>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 300005
#define M 500005
int T;
int n, m, x[M], y[M], ex[N], cnt, E[N];
int main(){
	T = read();
	while (T--){
		n = read(), m = read();
		for (register int i = 1; i <= m; ++i) x[i] = read(), y[i] = read();
		for (register int i = 1; i <= 3 * n; ++i) ex[i] = 1;
		cnt = 0;
		for (register int i = 1; i <= m; ++i)
			if (ex[x[i]] && ex[y[i]]){
				E[++cnt] = i, ex[x[i]] = ex[y[i]] = 0;
				if (cnt == n) break;
			}
		if (cnt == n){
			printf("Matching\n");
			for (register int i = 1; i <= n; ++i) printf("%d ", E[i]);
			putchar('\n');
		}
		else{
			printf("IndSet\n");
			cnt = 0;
			for (register int i = 1; cnt < n && i <= 3 * n; ++i)
				if (ex[i]) printf("%d ", i), ++cnt;
			putchar('\n');
		}
	}
}