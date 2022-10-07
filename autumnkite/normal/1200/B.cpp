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
#define N 105
int T, n, m, k, h[N];
void solve(){
	n = read(), m = read(), k = read();
	for (register int i = 1; i <= n; ++i) h[i] = read();
	for (register int i = 1; i < n; ++i){
		int tmp = std :: max(h[i + 1] - k, 0);
		m += h[i] - tmp;
		if (m < 0) return printf("NO\n"), void(0);
	}
	printf("YES\n");
}
int main(){
	T = read();
	while (T--) solve();
}