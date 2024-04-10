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
#define N 300005
#define P 998244353
int n, ans, cnt, sum, fac[N];
struct node{
	int x, y;
	bool operator < (const node &rhs) const {
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
}a[N];
bool cmp(node a, node b){
	return a.y < b.y;
}
bool check(){
	for (register int i = 1; i < n; ++i)
		if (a[i].y > a[i + 1].y) return 0;
	return 1;
}
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i].x = read(), a[i].y = read();
	fac[0] = 1;
	for (register int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	ans = fac[n];
	std :: sort(a + 1, a + 1 + n, cmp);
	cnt = 1, sum = 1;
	for (register int i = 2; i <= n; ++i)
		if (a[i].y == a[i - 1].y) ++cnt;
		else sum = 1ll * sum * fac[cnt] % P, cnt = 1;
	sum = 1ll * sum * fac[cnt] % P;
	ans = (ans - sum + P) % P;
	std :: sort(a + 1, a + 1 + n);
	cnt = 1, sum = 1;
	for (register int i = 2; i <= n; ++i)
		if (a[i].x == a[i - 1].x) ++cnt;
		else sum = 1ll * sum * fac[cnt] % P, cnt = 1;
	sum = 1ll * sum * fac[cnt] % P;
	ans = (ans - sum + P) % P;
	if (check()){
		cnt = 1, sum = 1;
		for (register int i = 2; i <= n; ++i)
			if (a[i].x == a[i - 1].x && a[i].y == a[i - 1].y) ++cnt;
			else sum = 1ll * sum * fac[cnt] % P, cnt = 1;
		sum = 1ll * sum * fac[cnt] % P;
	}
	else sum = 0;
	ans = (ans + sum) % P;
	printf("%d\n", ans);
}