#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e3 + 5;
const int INF = 0x3f3f3f3f;

const int dx[] = {0,  0, 1, -1};
const int dy[] = {1, -1, 0,  0};

int N, M, R, C, X, Y;
char mat[MAXN][MAXN];
int dist[MAXN][MAXN];
deque <pii> Q;

void load() {
	scanf("%d%d%d%d%d%d", &N, &M, &R, &C, &X, &Y);
	for (int i = 1; i <= N; i++)
		scanf("%s", mat[i] + 1);
}

bool ok(int x, int y) {
	return x > 0 && y > 0 && x <= N && y <= M && mat[x][y] == '.';
}

int solve() {
	memset(dist, INF, sizeof dist);
	Q.push_back({R, C});
	dist[R][C] = 0;
	
	while (!Q.empty()) {
		pii curr = Q.front();
		Q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];
			if (!ok(nx, ny))
				continue;
			int tmp = dist[curr.first][curr.second] + !i;
			if (tmp < dist[nx][ny]) {
				if (i) 
					Q.push_front({nx, ny});
				else 
					Q.push_back({nx, ny});
				dist[nx][ny] = tmp;
			}
		}
	}
	
	int sol = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			sol += dist[i][j] <= min(X + j - C, Y);
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}