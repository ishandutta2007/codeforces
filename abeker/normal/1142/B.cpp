#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int offset = 1 << 19;
const int INF = 0x3f3f3f3f;
const int LOG = 19;

int N, M, Q;
int inv[MAXN], a[MAXN];
int nxt[MAXN][LOG];
int lst[MAXN];
int tour[2 * offset];

void load() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		inv[x] = i;
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d", a + i);
		a[i] = inv[a[i]];
	}
}

int jmp(int x, int k) {
	for (int i = 0; i < LOG; i++)
		if (k >> i & 1)
			x = nxt[x][i];
	return x;
}

int query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from)
		return INF;
	if (lo >= from && hi <= to)
		return tour[x];
	int mid = (lo + hi) / 2;
	return min(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void solve() {
	memset(tour, INF, sizeof tour);
	for (int j = 0; j < LOG; j++)
		for (int i = 0; i < MAXN; i++)
			nxt[i][j] = M + 1;
			
	for (int i = 1; i <= N; i++)
		lst[i] = M + 1;
		
	for (int i = M; i; i--) {
		nxt[i][0] = lst[a[i] % N + 1];
		lst[a[i]] = i;
	}
	
	for (int j = 1; j < LOG; j++)
		for (int i = 1; i <= M; i++)
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];

	for (int i = 1; i <= M; i++)
		tour[i + offset] = jmp(i, N - 1);
	
	for (int i = offset - 1; i >= 0; i--)
		tour[i] = min(tour[2 * i], tour[2 * i + 1]);
	
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d", query(1, 0, offset, l, r + 1) <= r);
	}
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}