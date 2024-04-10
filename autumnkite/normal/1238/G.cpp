#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <map>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 500005
int n, c;
struct node{
	int t, a, b;
	bool operator < (const node &rhs) const {
		return t < rhs.t;
	}
}a[N];
long long ans;
void solve(){
	n = read(), a[n + 1].t = read(), c = read(), a[0].a = read();
	a[0].t = a[0].b = a[n + 1].a = a[n + 1].b = 0;
	for (register int i = 1; i <= n; ++i) a[i].t = read(), a[i].a = read(), a[i].b = read();
	std :: sort(a + 1, a + 1 + n);
	std :: map<int, int> M;
	ans = 0, M[0] = a[0].a;
	int s = a[0].a;
	for (register int i = 1; i <= n + 1; ++i){
		int t = a[i].t - a[i - 1].t;
		s -= t;
		while (t && M.begin() != M.end()){
			auto it = M.begin();
			if (t >= it -> second) t -= it -> second, ans += 1ll * it -> first * it -> second, M.erase(it);
			else it -> second -= t, ans += 1ll * it -> first * t, t = 0;
		}
		if (t) return printf("-1\n"), void(0);
		M[a[i].b] += a[i].a, s += a[i].a;
		while (s > c){
			auto it = --M.end();
			if (s - c >= it -> second) s -= it -> second, M.erase(it);
			else it -> second -= s - c, s = c;
		}
	}
	printf("%lld\n", ans);
}
int main(){
	int T = read();
	while (T--) solve();
}