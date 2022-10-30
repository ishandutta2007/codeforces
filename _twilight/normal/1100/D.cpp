#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int cnt_black = 666, N = 999, center = 500;

int sx, sy, dx, dy;
boolean occupy[N + 1][N + 1];
int x[cnt_black + 1], y[cnt_black + 1];

void Move(int nx, int ny) {
	assert(1 <= nx && nx <= N);
	assert(1 <= ny && ny <= N);
	assert(sx - 1 <= nx && nx <= sx + 1);
	assert(sy - 1 <= ny && ny <= sy + 1);
	assert(!occupy[nx][ny]);
	occupy[sx][sy] = false;
	occupy[nx][ny] = true;
	sx = nx, sy = ny;
	printf("%d %d\n", sx, sy);
	fflush(stdout);
	
	int id, bx, by;
	scanf("%d%d%d", &id, &bx, &by);
	if (id <= 0) {
		exit(0);
	}
	occupy[x[id]][y[id]] = false;
	occupy[bx][by] = true;
	x[id] = bx, y[id] = by;
}

int main() {
	scanf("%d%d", &sx, &sy);
	occupy[sx][sy] = true;
	for (int i = 1; i <= cnt_black; i++) {
		scanf("%d%d", x + i, y + i);
		occupy[x[i]][y[i]] = true;
	}

	while (sx != center || sy != center) {
		int nx = sx + -(sx > center) + (sx < center);
		int ny = sy + -(sy > center) + (sy < center);
		if (occupy[nx][ny]) {
			Move(sx, ny);
		} else {
			Move(nx, ny);
		}
	}

	int cnt[] = {0, 0, 0, 0};
	for (int i = 1; i <= cnt_black; i++) {
		if (x[i] < center && y[i] < center) {
			cnt[0]++;
		} else if (x[i] < center && y[i] > center) {
			cnt[1]++;
		} else if (x[i] > center && y[i] < center) {
			cnt[2]++;
		} else if (x[i] > center && y[i] > center) {
			cnt[3]++;
		}
	}

	if (cnt[0] <= cnt[1] && cnt[0] <= cnt[2] && cnt[0] <= cnt[3]) {
		dx = 1, dy = 1;
	} else if (cnt[1] <= cnt[0] && cnt[1] <= cnt[2] && cnt[1] <= cnt[3]) {
		dx = 1, dy = -1;
	} else if (cnt[2] <= cnt[0] && cnt[2] <= cnt[1] && cnt[2] <= cnt[3]) {
		dx = -1, dy = 1;
	} else if (cnt[3] <= cnt[0] && cnt[3] <= cnt[1] && cnt[3] <= cnt[2]) {
		dx = -1, dy = -1;
	}

	while (true) {
		int nx = sx + dx, ny = sy + dy;
		if (occupy[nx][ny]) {
			Move(sx, ny);
		} else {
			Move(nx, ny);
		}
	}
	return 0;
}