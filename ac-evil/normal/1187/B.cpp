#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define re register
#define rep(i, a, b) for (re int i = a; i <= b; ++i)
#define repd(i, a, b) for (re int i = a; i >= b; --i)
#define For(i, a, b, s) for (re int i = a; i <= b; s)
#define maxx(a, b) a = max(a, b)
#define minn(a, b) a = min(a, b)
#define LL long long
#define INF (1 << 30)

inline int read() {
	int w = 0, f = 1; char c = getchar();
	while (!isdigit(c)) f = c == '-' ? -1 : f, c = getchar();
	while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ '0'), c = getchar();
	return w * f;
}

const int maxn = 2e+5 + 5;

int n, T;
char c[maxn], t[maxn];

int f[26], g[maxn][21], h[26];
#define idx(c) (c - 'a')

int main() {
	scanf("%d", &n);
	scanf("%s", c);
	scanf("%d", &T);
	rep(i, 0, 25) f[i] = n+1;
	repd(i, n-1, 0) g[i][0] = f[idx(c[i])], f[idx(c[i])] = i;
	rep(x, 1, 20)
		rep(i, 0, n-1)
			g[i][x] = g[g[i][x-1]][x-1];
	while (T--) {
		scanf("%s", t);
		int lent = strlen(t), ans = 0;
		rep(i, 0, lent-1) h[idx(t[i])]++;
		rep(i, 0, 25)
			if (h[i] <= n && h[i]) {
				int res = f[i]; h[i]--;
				for (register int x = 0; h[i]; x++, h[i]>>=1)
					if (h[i] & 1) res = g[res][x];
				ans = max(ans, res);
			}
		printf("%d\n", ans+1);
	}

	return 0;
}