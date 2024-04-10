#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int v[1010][1010];
struct point {
	int x, y;
	point operator -(const point &p)const {
		return { x - p.x,y - p.y };
	}
	int SZ() {
		return abs(x) + abs(y);
	}
}A, B, C;
void Paint(point a, point b) {
	int i, j;
	int bx = min(a.x, b.x), ex = max(a.x, b.x);
	int by = min(a.y, b.y), ey = max(a.y, b.y);
	for (i = bx; i <= ex; i++) {
		for (j = by; j <= ey; j++) {
			if (i == a.x || j == b.y)v[i][j] = 1;
		}
	}
}
int main() {
	scanf("%d%d", &A.x, &A.y);
	scanf("%d%d", &B.x, &B.y);
	scanf("%d%d", &C.x, &C.y);
	int i, j, Mn = 1e9, px, py;
	for (i = 0; i <= 1000; i++) {
		for (j = 0; j <= 1000; j++) {
			point t = { i,j };
			int s = (t - A).SZ() + (t - B).SZ() + (t - C).SZ();
			if (Mn > s)Mn = s, px = i, py = j;
		}
	}
	printf("%d\n", Mn + 1);
	point t = { px,py };
	Paint(t, A);
	Paint(t, B);
	Paint(t, C);
	for (i = 0; i <= 1000; i++)for (j = 0; j <= 1000; j++)if (v[i][j])printf("%d %d\n", i, j);
}