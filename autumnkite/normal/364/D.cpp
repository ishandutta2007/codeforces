#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
long long read(){
	register long long x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 1000005
int n, cnt;
long long a[N], b[N], c[N], p[N], ans;
long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}
void solve(int x){
	for (register int i = 1; i <= n; ++i) b[i] = gcd(a[i], a[x]);
	cnt = 0;
	for (register int i = 1; 1ll * i * i <= a[x]; ++i)
		if (a[x] % i == 0)
			p[++cnt] = i, 1ll * i * i < a[x] ? p[++cnt] = a[x] / i : 0;
	std :: sort(p + 1, p + 1 + cnt);
	cnt = std :: unique(p + 1, p + 1 + cnt) - p - 1;
	for (register int i = 1; i <= n; ++i)
		++c[std :: lower_bound(p + 1, p + 1 + cnt, b[i]) - p];
	for (register int i = 1; i <= cnt; ++i)
		if (p[i] > ans)
			for (register int j = i + 1; j <= cnt; ++j)
				if (p[j] % p[i] == 0) c[i] += c[j];
	for (register int i = 1; i <= cnt; c[i] = 0, ++i)
		if (2 * c[i] >= n) ans = std :: max(ans, p[i]);
}
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	ans = 0;
	for (register int i = 1; i <= 10; ++i)
		solve((1ll * rand() * (RAND_MAX + 1) + rand()) % n + 1);
	printf("%lld\n", ans);
}