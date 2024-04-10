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
int T;
long long n;
long long calc1(long long x){
	long long l = 1, r, res = 0, k = 1;
	while (l <= x){
		r = std :: min(l * 10 - 1, x);
		res += k * ((r - l + 1) * x - (l + r) * (r - l + 1) / 2);
		l *= 10, ++k;
	}
	return res;
}
long long get1(long long x){
	long long l = 1, r = 2e9, md, ans = 0;
	while (l <= r){
		md = (l + r) >> 1;
		if (calc1(md) >= x) r = md - 1, ans = md;
		else l = md + 1;
	}
	return ans;
}
long long calc2(long long x){
	long long l = 1, r, res = 0, k = 1;
	while (l <= x){
		r = std :: min(l * 10 - 1, x);
		res += k * (r - l + 1);
		l *= 10, ++k;
	}
	return res;
}
long long get2(long long x){
	long long l = 1, r = 2e9, md, ans = 0;
	while (l <= r){
		md = (l + r) >> 1;
		if (calc2(md) >= x) r = md - 1, ans = md;
		else l = md + 1;
	}
	return ans;
}
void solve(){
	n = read();
	n -= calc1(get1(n) - 1);
	long long p = get2(n);
	n = calc2(p) - n;
	for (register int i = 1; i <= n; ++i) p /= 10;
	printf("%d\n", p % 10);
}
int main(){
	T = read();
	while (T--) solve();
}