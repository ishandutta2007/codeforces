#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	int x = 0, f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n, m, a[N], fr[N], ed[N], pos;
struct ST{
	int Log[N], mx[N][25];
	void init(){
		Log[1] = 0;
		for (register int i = 2; i <= n; ++i) Log[i] = Log[i >> 1] + 1;
		for (register int i = 1; i <= n; ++i) mx[i][0] = a[i];
		for (register int j = 1; j <= Log[n]; ++j)
			for (register int i = 1; i + (1 << j) - 1 <= n; ++i)
				mx[i][j] = std :: min(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
	}
	int query(int l, int r){
		if (l > r) return 0;
		int t = Log[r - l + 1];
		return std :: min(mx[l][t], mx[r - (1 << t) + 1][t]);
	}
}T;
int main(){
	n = read(), m = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	for (register int i = 1; i <= n; ++i) !a[i] ? a[i] = m + 1 : 0;
	T.init();
	for (register int i = 1; i <= n; ++i) !fr[a[i]] ? fr[a[i]] = i : 0;
	for (register int i = n; i; --i) !ed[a[i]] ? ed[a[i]] = i : 0;
	for (register int i = 1; i <= m; ++i)
		if (fr[i] < ed[i] && fr[i] && ed[i]){
			int mn = T.query(fr[i], ed[i]);
			if (mn < i) return printf("NO"), 0;
		}
	for (register int i = 1; i <= n; ++i) a[i] == m + 1 ? a[i] = 0, pos = i : 0;
	if (!fr[m]) if (pos) a[pos] = m; else return printf("NO"), 0; else;
	for (register int i = 2; i <= n; ++i) if (!a[i]) a[i] = a[i - 1];
	for (register int i = n - 1; i; --i) if (!a[i]) a[i] = a[i + 1];
	printf("YES\n");
	for (register int i = 1; i <= n; ++i) printf("%d ", a[i]);
}