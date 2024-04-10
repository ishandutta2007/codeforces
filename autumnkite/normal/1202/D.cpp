#include <cstdio>
int T, n, cnt, a[105];
int get(int n){
	int res = 1;
	while ((res * (res - 1) >> 1) <= n) ++res;
	return res - 1;
}
void solve(){
	scanf("%d", &n), cnt = 0;
	while (n > 0) a[++cnt] = get(n), n -= a[cnt] * (a[cnt] - 1) >> 1;
	for (register int i = 1; i < cnt; ++i) a[i] -= a[i + 1];
	putchar('1');
	for (register int i = cnt; i; --i){
		for (register int j = 1; j <= a[i]; ++j) putchar('3');
		putchar('7');
	}
	putchar('\n');
}
int main(){
	scanf("%d", &T);
	while (T--) solve();
}