#include <cstdio>
#include <algorithm>
void print(long long x){
	if (x == 0) return putchar('0'), void(0);
	int cnt = 0, d[25];
	for (x < 0 ? x = -x, putchar('-') : 0; x; x /= 10) d[++cnt] = x % 10;
	while (cnt) putchar(d[cnt] ^ '0'), --cnt;
}
int n, a[1000005];
long long k, ans;
int main(){
	scanf("%d%lld", &n, &k), ans = 1ll * n * (n + 1) >> 1;
	if (k < ans) return puts("-1"), 0;
	k -= ans;
	if (k > 1ll * n / 2 * (n - n / 2)) k = 1ll * n / 2 * (n - n / 2);
	for (register int i = 1; i <= n; ++i) a[i] = i;
	for (register int i = 1; i <= (n >> 1); ++i){
		int j = std :: min(n - i + 1ll, i + k);
		k -= j - i, ans += j - i, std :: swap(a[i], a[j]);
	}
	print(ans), putchar('\n');
	for (register int i = 1; i <= n; ++i) print(i), putchar(" \n"[i == n]);
	for (register int i = 1; i <= n; ++i) print(a[i]), putchar(" \n"[i == n]);
}