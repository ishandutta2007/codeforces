#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <set>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 100005
int n, a[N], d, c[N], now;
long long ans;
std :: multiset<int> S;
int main(){
	n = read(), now = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	d = read();
	for (register int i = 1; i <= n; ++i) c[i] = read();
	for (register int i = 1; i <= n; ++i){
		S.insert(c[i]);
		while (now < a[i] && !S.empty()) now += d, ans += *S.begin(), S.erase(S.begin());
		if (now < a[i]) return puts("-1"), 0;
	}
	printf("%lld\n", ans);
}