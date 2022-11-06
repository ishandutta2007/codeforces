#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)
#define rep(i, a, b) for (register int i = a, end = b; i <= end; ++i)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; --i)

inline int read() {
	int w = 0, f = 1; char c;
	while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
	while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
	return w * f;
}

const int maxk = 20 + 5;
const int maxn = 100000 + 5;

int e[maxk][maxk];
char s[maxn];
int n, k;
int f[1<<maxk];

int main() {
	n = read(), k = read();
	scanf("%s", s);
	rep(i, 1, strlen(s)-1) {
		int u = s[i]-'a', v = s[i-1]-'a';
		e[u][v]++, e[v][u]++;
	}
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	rep(S, 0, (1<<k)-1) {
		int cnt = 0;
		rep(i, 0, k-1) cnt += (bool)(S&(1<<i));
		rep(i, 0, k-1) if (S&(1<<i)) {
			int _S = S^(1<<i), tot = f[_S];
			rep(j, 0, k-1)
				if (_S & (1<<j)) tot += e[i][j] * cnt;
				else if (i != j) tot -= e[i][j] * cnt;
			chkmin(f[S], tot);
		}
	}
	printf("%d", f[(1<<k)-1]);

	return 0;
}