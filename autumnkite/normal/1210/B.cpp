#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
long long read(){
	register long long x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 7005
int n, ex[N];
long long a[N], b[N], ans;
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	for (register int i = 1; i <= n; ++i) b[i] = read();
	for (register int i = 1; i <= n; ++i){
		bool flag = 0;
		for (register int j = 1; j <= n; ++j)
			if (i != j && a[i] == a[j]){ flag = 1; break; }
		if (!flag) continue;
		for (register int j = 1; j <= n; ++j)
			if ((a[j] & a[i]) == a[j]) ex[j] = 1;
	}
	for (register int i = 1; i <= n; ++i)
		if (ex[i]) ans += b[i];
	printf("%lld\n", ans);
}