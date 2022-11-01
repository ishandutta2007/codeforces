#include <bits/stdc++.h>
using namespace std;

const int N = 1005, inf = N * N;
int n, m, t;

int a[N][N];
int dis[N][N];
queue <pair <int, int> > q;
bool mark[N][N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool val(int x, int y) {
	if (x > n || x <= 0) {
		return false;
	}
	if (y > m || y <= 0) {
		return false;
	}
	return true;
}

int main() {
	ios :: sync_with_stdio(false);
	bool b = false;
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (val(x, y) && a[x][y] == a[i][j]) {
					mark[i][j] = true;
					b = true;
				}
				if (mark[i][j]) {
					q.push({i, j});
					dis[i][j] = 0;
				}
				else {
					dis[i][j] = inf;
				}
			}
		}
	}
	if (!b) {
		for (int i = 0; i < t; i++) {
			long long x, y, z;
			cin >> x >> y >> z;
			cout << a[x][y] << '\n';
		}
		return 0;
	}
	while (q.size()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int j = 0; j < 4; j++) {
			int xp = x + dx[j], yp = y + dy[j];
			if (val(xp, yp) && dis[xp][yp] == inf) {
				dis[xp][yp] = dis[x][y] + 1;
				q.push({xp, yp});
			}
		}
	}
/*	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << i << " " << j << " " << mark[i][j] << " " << dis[i][j] << endl;
		}
	}*/
	for (int i = 0; i < t; i++) {
		int x, y;
		long long z;
		cin >> x >> y >> z;
	//	if (a[x][y] == 0) {
			if (dis[x][y] > z) {
				cout << a[x][y];
			}
			else {
				cout << (a[x][y] ^ ((z - dis[x][y]) % 2));
			}
	//	}
	//	else {
	/*		if (dis[x][y] > z) {
				cout << 1;
			}
			else {
				cout << 1 - z % 2;
			}			
		}*/
		cout << '\n';
	}
	return 0;
}