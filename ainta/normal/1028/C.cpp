#include<cstdio>
#include<algorithm>
#define SZ 524288
using namespace std;
struct Tree {
	int IT[SZ + SZ];
	void Put(int a, int b) {
		a += SZ;
		IT[a] = b;
		while (a != 1) {
			a >>= 1;
			IT[a] = max(IT[a * 2], IT[a * 2 + 1]);
		}
	}
	int Max(int b, int e) {
		int r = -2e9;
		b += SZ, e += SZ;
		while (b <= e) {
			r = max(r,max(IT[b], IT[e]));
			b = (b + 1) >> 1, e = (e - 1) >> 1;
		}
		return r;
	}
}P[4];
int n;
int main() {
	int i, j,bx,by,ex,ey;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &bx, &by, &ex, &ey);
		P[0].Put(i, bx);
		P[0].Put(i+n, bx);
		P[1].Put(i, by);
		P[1].Put(i + n, by);
		P[2].Put(i, -ex);
		P[2].Put(i + n, -ex);
		P[3].Put(i, -ey);
		P[3].Put(i + n, -ey);
	}
	for (i = 0; i < n; i++) {
		bx = P[0].Max(i, i + n - 2);
		by = P[1].Max(i, i + n - 2);
		ex = -P[2].Max(i, i + n - 2);
		ey = -P[3].Max(i, i + n - 2);
		if (bx <= ex && by <= ey) {
			printf("%d %d\n", bx, by);
			return 0;
		}
	}
}