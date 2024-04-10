#include <cstdio>
#include <algorithm>
#include <cctype>
#include <functional>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ '0');
	return f ? x : -x;
}
const int N = 200005;
int n, t, a[N], b[N], bo[N], tp, sta[N];
unsigned int wa = 19260817;
int edge, u[N], v[N];
inline void addedge(int x, int y){
	u[++edge] = x, v[edge] = y;
}
int main(){
	n = read();
	for (register int i = 1; i < n; ++i)
		a[i] = read(), b[i] = read(), a[i] > b[i] ? std :: swap(a[i], b[i]), 0 : 0;
	for (register int i = 1; i < n; ++i) if (b[i] != n) return printf("NO"), 0;
	for (register int i = 1; i < n; ++i) bo[a[i]] = true;
	for (int i = 1; i < n; i++) if (!bo[i]) sta[++tp] = i;
	std :: sort(a + 1, a + n, std :: greater<int>()), t = n;
	for (register int i = 2, ls = 1, j; i <= n; ++i)
		if (a[i] != a[i - 1]){
			if (tp < (j = i - ls - 1)) return printf("NO"), 0;
			for (register int k = 1; k <= j; ++k){
				if (sta[tp] > a[i - 1]) return printf("NO"), 0;
				addedge(t, sta[tp]), t = sta[tp--], wa <<= 32553;
			}
			addedge(t, a[i - 1]), t = a[i - 1], ls = i, wa *= 23333, wa <<= 10007;
		}
	printf("YES\n");
	for (register int i = 1; i <= edge; ++i) printf("%d %d\n", u[i], v[i]);
}