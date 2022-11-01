#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1007;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

char c[MAXN][MAXN];
int dis[MAXN][MAXN];
queue <pair <int, int> > q;


int main() {
	int n, m, sx, sy, xme, yme;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
			dis[i][j] = MAXN * MAXN;
			if (c[i][j] == 'E') {
				sx = i;
				sy = j;
			}
			if (c[i][j] == 'S') {
				xme = i;
				yme = j; 
			}
		}
	}
	dis[sx][sy] = 0;
	q.push({sx, sy});
	while (q.size()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && c[xx][yy] != 'T' && dis[xx][yy] == MAXN * MAXN) {
				dis[xx][yy] = dis[x][y] + 1;
				q.push({xx, yy});
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		//	cout << dis[i][j] << " ";
			if (c[i][j] >= '0' && c[i][j] <= '9' && dis[i][j] <= dis[xme][yme]) {
				ans += c[i][j] - '0';
			}
		}
	//	cout << endl;
	}
	cout << ans;
	return 0;
}