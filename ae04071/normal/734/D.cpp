#include <stdio.h>

struct Piece
{
	char type;
	int y, x;
};

const int dy[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
const int dx[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };

int n;
int y, x;

bool vis[8];
int dist[8];
Piece mini[8];
int idx[8];
Piece p[500000];

inline int ABS(int a) {
	return(a < 0) ? -a : a;
}

int main()
{
	scanf("%d", &n);
	scanf("%d %d", &x, &y);

	for (int i = 0; i < n; i++) {
		scanf(" %c %d %d", &p[i].type, &p[i].x, &p[i].y);
	}
	
	for (int i = 0; i < 8; i++) {
		dist[i] = 2016147541;
		idx[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		if (x == p[i].x && y < p[i].y) {
			int d = ABS(p[i].y - y);
			if (dist[0] > d) {
				dist[0] = d;
				mini[0] = p[i];
				idx[0] = i;
			}
		}
		else if (x == p[i].x && y > p[i].y) {
			int d = ABS(p[i].y - y);
			if (dist[1] > d) {
				dist[1] = d, mini[1] = p[i];
				idx[1] = i;
			}
		}
		else if (y == p[i].y && x < p[i].x) {
			int d = ABS(p[i].x - x);
			if (dist[2] > d) {
				dist[2] = d, mini[2] = p[i];
				idx[2] = i;
			}
		}
		else if (y == p[i].y && x > p[i].x) {
			int d = ABS(p[i].x - x);
			if (dist[3] > d) {
				dist[3] = d, mini[3] = p[i];
				idx[3] = i;
			}
		}
		else if (x > p[i].x && y < p[i].y && (ABS(p[i].y - y) == ABS(p[i].x - x))) {
			int d = ABS(p[i].y - y);
			if (dist[4] > d) {
				dist[4] = d, mini[4] = p[i];
				idx[4] = i;
			}
		}
		else if (x < p[i].x && y < p[i].y && (ABS(p[i].y - y) == ABS(p[i].x - x))) {
			int d = ABS(p[i].y - y);
			if (dist[5] > d) {
				dist[5] = d, mini[5] = p[i];
				idx[5] = i;
			}
		}
		else if (x > p[i].x && y > p[i].y && (ABS(p[i].y - y) == ABS(p[i].x - x))) {
			int d = ABS(p[i].y - y);
			if (dist[6] > d) {
				dist[6] = d, mini[6] = p[i];
				idx[6] = i;
			}
		}
		else if (x < p[i].x && y > p[i].y && (ABS(p[i].y - y) == ABS(p[i].x - x))) {
			int d = ABS(p[i].y - y);
			if (dist[7] > d) {
				dist[7] = d, mini[7] = p[i];
				idx[7] = i;
			}
		}
	}

	bool flag = false;
	for (int i = 0; i < 8; i++) {
		if (idx[i] == -1) continue;
		if (i < 4 && (mini[i].type == 'R' || mini[i].type == 'Q')) {
			flag = true;
		}
		if (i >= 4 && (mini[i].type == 'Q' || mini[i].type == 'B')) {
			flag = true;
		}
	}
	if (flag)printf("YES");
	else printf("NO");

	return 0;
}