#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int n, m;
char s[1000005];
int a[1000005], b[1000005], c[1000005];
char S[1000005];
void con(int *x, int *y){
	for (register int i = 0; i < n; ++i) b[i] = x[y[i]];
	for (register int i = 0; i < n; ++i) x[i] = b[i];
}
void qpow(int *x, int y){
	for (register int i = 0; i < n; ++i) c[i] = i;
	for (; y; y >>= 1, con(x, x)) if (y & 1) con(c, x);
	for (register int i = 0; i < n; ++i) x[i] = c[i];
}
int main(){
	scanf("%s", s), n = strlen(s);
	m = read();
	while (m--){
		int k = read(), d = read(), len = 0, pos = 0, tmp = n - k + 1;
		for (register int i = 0; i < n; ++i) a[i] = i;
		for (register int i = 0; i < k; ++i) b[len++] = a[i];
		for (register int i = 0; i < d; ++i)
			for (register int j = i; j < len; j += d)
				a[pos++] = b[j];
		for (register int i = 0; i < n; ++i) c[i] = (i + 1) % n;
		con(a, c);
		qpow(a, tmp);
		for (register int i = 0; i < n; ++i) c[i] = (i - tmp + n) % n;
		con(a, c);
		for (register int i = 0; i < n; ++i) S[i] = s[a[i]];
		printf("%s\n", S);
		for (register int i = 0; i < n; ++i) s[i] = S[i];
	}
}