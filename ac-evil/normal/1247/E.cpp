#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)

const int maxn = 2000 + 5;
const int P = 1000000007;

inline void inc(int &a, int b) {
	a += b;
	if (a >= P) a -= P;
}

int N, M;

struct BIT {
#define lb(x) (x&(-x))
	int C[maxn];
	void add(int i, int v) {
		for (; i <= max(M, N); i += lb(i)) C[i] = ((ll)C[i] + P + v) % P;
	}
	int query(int i) {
		int res = 0;
		for (; i; i -= lb(i)) inc(res, C[i]);
		return res;
	}
	void modify(int l, int r, int v) {
		add(l, v); add(r+1, -v);
	}
} f[maxn], g[maxn];

char Map[maxn][maxn];
int wty[maxn][maxn], hzy[maxn][maxn];

char getc() {
	char c = getchar();
	while (c != '.' && c != 'R') c = getchar();
	return c;
}

int main() {
	scanf("%d%d", &N, &M);
	rep(i, 1, N)
		rep(j, 1, M)
			Map[i][j] = getc();

	if (N == 1 && M == 1) { printf("%d", Map[1][1] == '.'); return 0; }

	rep(i, 1, N) {
		wty[i][M] = 0;
		repd(j, M-1, 1)
			wty[i][j] = wty[i][j+1] + (Map[i][j+1] == 'R');
	}
	rep(i, 1, M) {
		hzy[N][i] = 0;
		repd(j, N-1, 1)
			hzy[j][i] = hzy[j+1][i] + (Map[j+1][i] == 'R');
	}

	f[1].modify(1, 1, 1);
	g[1].modify(1, 1, 1);
	rep(i, 1, N)
		rep(j, 1, M) {
			// N-hzy[i][j]+1, M-wty[i][j]+1
			if (j < M-wty[i][j])
				f[i].modify(j+1, M-wty[i][j], g[j].query(i));
			if (i < N-hzy[i][j])
				g[j].modify(i+1, N-hzy[i][j], f[i].query(j));
		}

	printf("%d", (f[N].query(M) + g[M].query(N)) % P);

	return 0;
}