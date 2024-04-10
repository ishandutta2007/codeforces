#include<cstdio>
#include<algorithm>
using namespace std;
int n;
struct point {
	int x, y;
}w[50];
bool Include(int x, int by, int ey, int tx, int ty) {
	if (x == tx && by <= ty && ty <= ey)return true;
	return false;
}
int main() {
	int i, bx, by, d, j, k, l;
	scanf("%d", &n);
	n = 4 * n + 1;
	for (i = 0; i < n; i++) {
		scanf("%d%d", &w[i].x, &w[i].y);
	}
	for (i = 0; i <= 50; i++) {
		for (j = 0; j <= 50; j++) {
			for (l = 1; i + l <= 50 && j + l <= 50; l++) {
				int t1 = -1, c=0;
				for (k = 0; k < n; k++) {
					if (Include(i, j, j + l, w[k].x, w[k].y) || Include(i + l, j, j + l, w[k].x, w[k].y) || Include(j, i, i + l, w[k].y, w[k].x) || Include(j + l, i, i + l, w[k].y, w[k].x))continue;
					c++;
					t1 = k;
				}
				if (c == 1) {
					printf("%d %d\n", w[t1].x, w[t1].y);
					return 0;
				}
			}
		}
	}
}