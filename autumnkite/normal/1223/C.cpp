#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
long long read(){
	register long long x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n, a[N], p1, p2, p3;
long long q1, q2, q3, k;
bool check(int x){
	long long s = 0;
	int t3 = x / q3;
	for (register int i = 1; i <= t3; ++i) s += a[i] * p3;
	int t2 = x / q2;
	for (register int i = t3 + 1; i <= t2; ++i) s += a[i] * p2;
	int t1 = x / q1 + t2 - t3;
	for (register int i = t2 + 1; i <= t1; ++i) s += a[i] * p1;
	return s >= k;
}
void solve(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read() / 100;
	p1 = read(), q1 = read(), p2 = read(), q2 = read(), k = read();
	if (p1 > p2) std :: swap(p1, p2), std :: swap(q1, q2);
	p3 = p1 + p2, q3 = q1 * q2 / std :: __gcd(q1, q2);
	std :: sort(a + 1, a + 1 + n), std :: reverse(a + 1, a + 1 + n);
	int l = 1, r = n, md, ans = -1;
	while (l <= r) if (check(md = (l + r) >> 1)) r = md - 1, ans = md; else l = md + 1;
	printf("%d\n", ans);
}
int main(){
	int T = read();
	while (T--) solve();
}