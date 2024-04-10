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
int n, cnt, b[100005], e[125][125], dis[125][125];
long long a[100005];
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	for (register int i = 0; i < 60; ++i){
		int s = 0;
		for (register int j = 1; j <= n; ++j)
			if (a[j] >> i & 1) ++s;
		if (s >= 3) return printf("3\n"), 0;
		if (s == 1) continue;
		int x = 0, y = 0;
		for (register int j = 1; j <= n; ++j)
			if (a[j] >> i & 1) if (!x) x = j; else y = j;
		if (!b[x]) b[x] = ++cnt;
		if (!b[y]) b[y] = ++cnt;
		e[b[x]][b[y]] = e[b[y]][b[x]] = 1;
	}
	n = cnt;
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= n; ++j)
			if (!e[i][j]) e[i][j] = 1e8;
	memcpy(dis, e, sizeof dis);
	int ans = 1e8;
	for (register int k = 1; k <= n; ++k){
		for (register int i = 1; i < k; ++i)
			if (e[i][k] < 1e8)
				for (register int j = i + 1; j < k; ++j)
					if (e[j][k] < 1e8 && dis[i][j] < 1e8)
						ans = std :: min(ans, e[i][k] + e[j][k] + dis[i][j]);
		for (register int i = 1; i <= n; ++i)
			if (k != i)
				for (register int j = 1; j <= n; ++j)
					if (k != j && i != j)
						dis[i][j] = std :: min(dis[i][j], dis[i][k] + dis[k][j]);
	}
	if (ans == 1e8) printf("-1\n"); else printf("%d\n", ans);
}