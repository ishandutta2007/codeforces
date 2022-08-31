#include<cstdio>
char p[60][60], q[110];
int n, m, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 }, dir[4], res;
int sx, sy, ex, ey;
bool Pos() {
	int i;
	int x = sx, y = sy;
	for (i = 0; q[i]; i++) {
		int d = dir[q[i] - '0'];
		x += dx[d], y += dy[d];
		if (x == ex && y == ey)return true;
		if (p[x][y] != '.')return false;
	}
	return false;
}
void DFS(int pv, int mask) {
	int i;
	if (pv == 4) {
		if (Pos())res++;
		return;
	}
	for (i = 0; i < 4; i++) {
		if ((mask >> i) & 1)continue;
		dir[pv] = i;
		DFS(pv + 1, mask | (1 << i));
	}
}
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%s", p[i] + 1);
		for (j = 1; j <= m; j++) {
			if (p[i][j] == 'S') {
				p[i][j] = '.';
				sx = i, sy = j;
			}
			if (p[i][j] == 'E') {
				p[i][j] = '.';
				ex = i, ey = j;
			}
		}
	}
	scanf("%s", q);
	DFS(0, 0);
	printf("%d\n", res);
}