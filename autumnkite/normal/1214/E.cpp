#include <cstdio>
#include <cctype>
#include <algorithm>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int n, cnt, id[100005];
std :: pair<int, int> d[100005];
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) d[i].first = -read(), d[i].second = i;
	std :: sort(d + 1, d + 1 + n);
	for (register int i = 1; i <= n; ++i){
		if (i < n) printf("%d %d\n", 2 * d[i].second - 1, 2 * d[i + 1].second - 1);
		int x = i - d[i].first - 1;
		if (x <= n) printf("%d %d\n", 2 * d[x].second - 1, 2 * d[i].second);
		else printf("%d %d\n", id[x - n], 2 * d[i].second);
		if (x - n == cnt) id[++cnt] = 2 * d[i].second;
	}
}