#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e3 + 5;
const int MAXP = 10;
const int INF = 0x3f3f3f3f;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int N, M, P;
int speed[MAXN];
char mat[MAXN][MAXN];
int dist[MAXP][MAXN][MAXN];
queue <pii> Q[MAXP];
int ans[MAXP];

void load() {
	scanf("%d%d%d", &N, &M, &P);
	for (int i = 0; i < P; i++)
		scanf("%d", speed + i);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
}

bool ok(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < M && mat[x][y] == '.';
}

bool bfs(int x, int limit) {
	while (!Q[x].empty()) {
		pii curr = Q[x].front();
		if (dist[x][curr.first][curr.second] == limit)
			break;
		Q[x].pop();
		for (int i = 0; i < 4; i++) {
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];
			if (ok(nx, ny)) {
				dist[x][nx][ny] = dist[x][curr.first][curr.second] + 1;
				mat[nx][ny] = (char)(x + '1');
				Q[x].push({nx, ny});
				ans[x]++;
			}
		}
	}
	return !Q[x].empty();
}

void solve() {
	memset(dist, INF, sizeof dist);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (isdigit(mat[i][j])) {
				int who = mat[i][j] - '1';
				dist[who][i][j] = 0;
				Q[who].push({i, j});
				ans[who]++;
			}
			
	for (int it = 1; ; it++) {
		bool ok = false;
		for (int i = 0; i < P; i++)
			ok |= bfs(i, it * speed[i]);
		if (!ok)
			break;
	}
	
	for (int i = 0; i < P; i++)
		printf("%d ", ans[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}