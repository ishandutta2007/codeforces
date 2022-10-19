#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 155;
const int MOD = 1000000007;

int N, M;
int dp[2][2][MAXN][MAXN];
int nxt[2][2][MAXN][MAXN];

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)	
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

void load() {
	scanf("%d%d", &N, &M);
}

void calc_sum(int mat[MAXN][MAXN]) {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			mat[i][j] = add(add(mat[i - 1][j], mat[i][j - 1]), add(mat[i][j], -mat[i - 1][j - 1]));
}

int get(int k, int l, int x1, int y1, int x2, int y2) {
	return add(add(dp[k][l][x2][y2], dp[k][l][x1 - 1][y1 - 1]), -add(dp[k][l][x1 - 1][y2], dp[k][l][x2][y1 - 1]));
}

void output() {
	for (int k = 0; k < 2; k++)
		for (int l = 0; l < 2; l++)
			for (int i = 1; i <= N; i++)
				for (int j = i; j <= N; j++)
					printf("k l i j dp %d %d %d %d %d\n", k, l, i, j, dp[k][l][i][j]);
	puts("");
}

int solve() {
	int sol = 0;
	for (int it = 0; it < M; it++) {		
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				calc_sum(dp[i][j]);
		
		for (int i = 1; i <= N; i++)
			for (int j = i; j <= N; j++) 
				if (it) {
					nxt[0][0][i][j] = get(0, 0, i, i, j, j);
					nxt[0][1][i][j] = add(get(0, 0, i, j + 1, j, N), get(0, 1, i, j, j, N));
					nxt[1][0][i][j] = add(get(0, 0, 1, i, i - 1, j), get(1, 0, 1, i, i, j)); 
					nxt[1][1][i][j] = add(add(get(1, 1, 1, j, i, N), get(0, 0, 1, j + 1, i - 1, N)), add(get(0, 1, 1, j, i - 1, N), get(1, 0, 1, j + 1, i, N)));
				}
				else 
					nxt[0][0][i][j] = 1;
			
		for (int k = 0; k < 2; k++)
			for (int l = 0; l < 2; l++)
				for (int i = 1; i <= N; i++)
					for (int j = i; j <= N; j++)
						sol = add(sol, mul(nxt[k][l][i][j], M - it));
		
		memcpy(dp, nxt, sizeof dp);
	}
					
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}