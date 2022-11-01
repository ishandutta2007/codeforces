#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
char c[300];
char mp[55][55];
int sx, sy, ex, ey, cx, cy;
int main() {
	int n, m, i, j, k, sl, tt, cnt=0;
	int dir[4], stk[4];
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) scanf("%s", mp[i]);
	scanf("%s", c);
	sl = strlen(c);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (mp[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (mp[i][j] == 'E') {
				ex = i;
				ey = j;
			}
		}
	}
	for (i = 0; i < 24; i++) {
		for (j = 0; j < 4; j++) stk[j] = j;
		dir[0] = stk[i / 6];
		for (j = i / 6; j < 3; j++) stk[j] = stk[j + 1];
		dir[1] = stk[(i % 6) / 2];
		for (j = (i % 6) / 2; j < 2; j++) stk[j] = stk[j + 1];
		dir[2] = stk[i % 2];
		for (j = i % 2; j < 1; j++) stk[j] = stk[j + 1];
		dir[3] = stk[0];
		cx = sx;
		cy = sy;
		tt = 0;
		for (j = 0; j < sl; j++) {
			switch (dir[c[j] - '0']) {
			case 0:cx--;
				if (cx < 0) tt = -1;
				else if (mp[cx][cy] == '#') tt = -1;
				else if (mp[cx][cy] == 'E') tt = 1;
				break;
			case 1:cx++;
				if (cx >= n) tt = -1;
				else if (mp[cx][cy] == '#') tt = -1;
				else if (mp[cx][cy] == 'E') tt = 1;
				break;
			case 2:cy--;
				if (cy < 0) tt = -1;
				else if (mp[cx][cy] == '#') tt = -1;
				else if (mp[cx][cy] == 'E') tt = 1;
				break;
			case 3:cy++;
				if (cy >= m) tt = -1;
				else if (mp[cx][cy] == '#') tt = -1;
				else if (mp[cx][cy] == 'E') tt = 1;
				break;
			}
			if (tt != 0) break;
		}
		if (tt == 1) cnt++;
	}
	printf("%d", cnt);
}