#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

int N, M;
int g[MAXN][MAXN];
int row[MAXN], col[MAXN];
int a[MAXN], b[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", g[i] + j);
}

int calc(int val) {
	col[0] = val;
	for (int i = 0; i < N; i++)
		if (g[i][0] < val)
			return INF;
		else
			row[i] = g[i][0] - val;
	for (int i = 0; i < M; i++)
		if (g[0][i] < row[0])
			return INF;
		else
			col[i] = g[0][i] - row[0];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (row[i] + col[j] != g[i][j])
				return INF;
	int res = 0;
	for (int i = 0; i < N; i++)
		res += row[i];
	for (int j = 0; j < M; j++)
		res += col[j];
	return res;
}

void solve() {
	int sol = INF;
	for (int i = 0; i <= g[0][0]; i++) {
		int tmp = calc(i);
		if (tmp < sol) {
			memcpy(a, row, sizeof a);
			memcpy(b, col, sizeof b);
			sol = tmp;
		}
	}
	
	if (sol == INF) {
		puts("-1");
		return;
	}
	
	printf("%d\n", sol);
	for (int i = 0; i < N; i++)
		while (a[i]--)
			printf("row %d\n", i + 1);
	for (int i = 0; i < M; i++)
		while (b[i]--)
			printf("col %d\n", i + 1);
}

int main() {
	load();
	solve();
	return 0;
}