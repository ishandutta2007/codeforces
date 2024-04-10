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
#define N 1005
int n;
std :: pair<int, int> a[N];
long long ans;
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i)
		a[i] = std :: make_pair(-read(), i);
	std :: sort(a + 1, a + 1 + n);
	for (register int i = 1; i <= n; ++i) ans += -a[i].first * (i - 1) + 1;
	printf("%lld\n", ans);
	for (register int i = 1; i <= n; ++i) printf("%d ", a[i].second);
}