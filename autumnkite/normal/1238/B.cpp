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
int T, n, r, a[100005], d, ans;
void solve(){
	n = read(), r = read(), d = ans = 0;
	for (register int i = 1; i <= n; ++i) a[i] = read();
	std :: sort(a + 1, a + 1 + n);
	while (n && a[n] > d){
		++ans, --n;
		while (a[n] == a[n + 1]) --n;
		d += r;
	}
	printf("%d\n", ans);
}
int main(){
	T = read();
	while (T--) solve();
}