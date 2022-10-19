#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 35;
const int MAXM = 405;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int N;
int t[MAXN];
bool bio[MAXM][MAXM][MAXN][8];
bool f[MAXM][MAXM];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", t + i);
}

void dfs(int x, int y, int depth, int dir) {
	if (bio[x][y][depth][dir])
		return;
	bio[x][y][depth][dir] = true;
	if (depth == N) {
		f[x][y] = true;
		return;
	}
	for (int i = 0; i < t[depth]; i++) {
		if (i || depth)
			f[x][y] = true;
		x += dx[dir];
		y += dy[dir];
	}
	dfs(x, y, depth + 1, (dir + 7) % 8);
	dfs(x, y, depth + 1, (dir + 1) % 8);
}

int solve() {
	dfs(MAXM / 2, MAXM / 2, 0, 0); 
					
	int sol = 0;
	for (int i = 0; i < MAXM; i++)
		for (int j = 0; j < MAXM; j++)
			sol += f[i][j];
	
	return sol; 
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}