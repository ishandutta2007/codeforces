#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const char ds[4] = {'R', 'L', 'U', 'D'};
int vx, vy, sx, sy, bad[N][N], dist[N][N], fr[N][N], lab[N][N];
pair<int, int> lst[N][N];
int minx = N, maxx = -1, miny = N, maxy = -1;
string ans;
inline void Move(int k) {
	vx += dx[k];
	vy += dy[k];
	int nx = sx + dx[k], ny = sy + dy[k];
	if (nx >= 0 && nx < N && ny >= 0 && ny < N && bad[nx][ny]) {
	} else {
		sx = nx, sy = ny;
	}
	ans += ds[k];
}
inline void BFS(int tx, int ty) {
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int> > que;
	dist[tx][ty] = 0;
	que.emplace(tx, ty);
	while (!que.empty()) {
		int x, y;
		tie(x, y) = que.front(); que.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !bad[nx][ny] && dist[nx][ny] == -1) {
				dist[nx][ny] = dist[x][y] + 1;
				fr[nx][ny] = k;
				que.emplace(nx, ny);
			}
		}
	}
}
void solve2() {
	int tx = sx, ty = sy;
	deque<pair<int, int> > tv;
	while (tx != vx || ty != vy) {
		lab[tx][ty] = 1;
		tv.emplace_back(tx, ty);
		int d = fr[tx][ty];
		tx += dx[d ^ 1];
		ty += dy[d ^ 1];
	}
	reverse(tv.begin(), tv.end());
	for (int i = 0; i < (int)tv.size(); i++) lst[tv[i].first][tv[i].second] = (i ? tv[i - 1] : make_pair(vx, vy));
	function<void(int, int, int, int)> Go = [&](int x1, int y1, int x2, int y2) {
		for (int k = 0; ; k++) {
			if (x2 == x1 + dx[k] && y2 == y1 + dy[k]) {
				Move(k);
				if (!lab[sx][sy]) {
					lab[sx][sy] = 1;
					lst[sx][sy] = tv.back();
					tv.push_back(make_pair(sx, sy));
				} else {
					while (make_pair(sx, sy) != tv.back()) {
						lab[tv.back().first][tv.back().second] = 0;
						tv.pop_back();
					}
				}
				return;
			}
		}
	};
	while (vx != sx || vy != sy) {
		tie(tx, ty) = tv.front();
		Go(vx, vy, tx, ty);
		lab[tx][ty] = 0;
		tv.pop_front();
	}
}
void solve1() {
	int tx = N - 1, ty = N - 1;
	vector<int> tv;
	while (tx != vx || ty != vy) {
		int d = fr[tx][ty];
		tx += dx[d ^ 1];
		ty += dy[d ^ 1];
		tv.push_back(d);
	}
	reverse(tv.begin(), tv.end());
	for (int d : tv) Move(d);
	for (int i = 0; i < N * 20; i++) {
		Move(0);
		Move(2);
	}
	if (sx < N && sy < N) {
		BFS(sx, sy);
		tx = N - 1, ty = N - 1;
		tv.clear();
		while (tx != sx || ty != sy) {
			int d = fr[tx][ty];
			tx += dx[d ^ 1];
			ty += dy[d ^ 1];
			tv.push_back(d);
		}
		reverse(tv.begin(), tv.end());
		for (int d : tv) Move(d);
		for (int i = 0; i < N * 20; i++) {
			Move(0);
			Move(2);
		}
	}
	if (vx < sx) {
		int fy;
		for (fy = 0; fy < N; fy++) if (bad[minx][fy]) break;
		while (sx > minx - 1) Move(1);
		while (sy > fy) Move(3);
		while (vx < sx) Move(0);
	} else if (vx > sx) {
		int fy;
		for (fy = 0; fy < N; fy++) if (bad[maxx][fy]) break;
		while (sx > maxx + 1) Move(1);
		while (sy > fy) Move(3);
		while (vx > sx) Move(1);
	}
	while (min(vy, sy) < N) Move(2);
	while (min(vx, sx) < N) Move(0);
	if (vy < sy) {
		int fx;
		for (fx = 0; fx < N; fx++) if (bad[fx][miny]) break;
		while (sy > miny - 1) Move(3);
		while (sx > fx) Move(1);
		while (vy < sy) Move(2);
	} else if (vy > sy) {
		int fx;
		for (fx = 0; fx < N; fx++) if (bad[fx][maxy]) break;
		while (sy > maxy + 1) Move(3);
		while (sx > fx) Move(1);
		while (vy > sy) Move(3);
	}
}
int main() {
	int m;
	scanf("%d%d%d%d%d", &vx, &vy, &sx, &sy, &m);
	vx += 102;
	vy += 102;
	sx += 102;
	sy += 102;
	if (!m) {
		puts("-1");
		return 0;
	}
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x += 102;
		y += 102;
		bad[x][y] = 1;
		minx = min(minx, x);
		maxx = max(maxx, x);
		miny = min(miny, y);
		maxy = max(maxy, y);
	}
	BFS(vx, vy);
	if (dist[sx][sy] == -1) {
		puts("-1");
		return 0;
	}
	if (dist[N - 1][N - 1] != -1) {
		solve1();
		puts(ans.c_str());
		return 0;
	}
	solve2();
	puts(ans.c_str());
	return 0;
}