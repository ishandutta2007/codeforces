#include <bits/stdc++.h>

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

const int maxn = 1e3 + 5;

int g[maxn], n, m;
int t[maxn], l[maxn], r[maxn];

int main() {
	n = read(), m = read();
	memset(g, 0, sizeof(g));
	rep(i, 0, m-1)
		t[i] = read(), l[i] = read(), r[i] = read();
	rep(x, 0, m-1)
		if (t[x])
			rep(i, l[x]+1, r[x]) g[i] = t[x];
	rep(x, 0, m-1)
		if (!t[x]) {
			int flag = 1;
			rep(i, l[x]+1, r[x])
				if (!g[i]) flag = 0;
			if (flag) {
				printf("NO");
				return 0;
			}
		}


	g[1] = 100000;
	rep(i, 2, n) g[i] = g[i-1] + (g[i] ? 1 : -1);
	printf("YES\n");
	rep(i, 1, n) printf("%d ", g[i]);

	return 0;
}