#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; i--)
#define ll long long
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)

inline int read() {
	int w = 0, f = 1; char c;
	while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
	while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
	return w * f;
}

int N, M;
int e[8][8];
int col[8], b[7];
int ans = 0;

int check() {
	int cnt = 0;
	int tag[7][7];
	memset(tag, 0, sizeof(tag));
	rep(i, 1, N)
		rep(j, i+1, N)
			if (e[i][j]) tag[min(col[i], col[j])][max(col[i], col[j])] = 1;
	rep(i, 1, 6)
		rep(j, i, 6)
			cnt += tag[i][j];
	return cnt;
}

void dfs(int dep) {
	if (dep > N) {
		chkmax(ans, check());
		return;
	}
	for (register int i = 1; i <= 6; i++) {
		col[dep] = i;
		dfs(dep+1);
		col[dep] = 0;
	}
}

int main() {
	N = read(), M = read();
	rep(i, 1, M) {
		int u = read(), v = read();
		e[u][v] = e[v][u] = 1;
	}

	dfs(1);

	printf("%d", ans);

	return 0;
}