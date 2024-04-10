#include<cstdio>
#include<algorithm>
using namespace std;
struct point {
	long long x, y;
	int ck, num;
	point operator -(const point &p)const {
		return { x - p.x,y - p.y,ck,num };
	}
	bool operator <(const point &p)const {
		if ((x > 0 || (x == 0 && y > 0)) != (p.x > 0 || (p.x == 0 && p.y > 0)))return (x > 0 || (x == 0 && y > 0));
		return y * p.x < p.y*x;
	}
}w[310], P[610];
int n, A[310][310][310], B[310][310][310];
long long ccw(point a, point b, point c) {
	return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}
int main() {
	int i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld%lld", &w[i].x, &w[i].y);
	}
	for (i = 1; i <= n; i++) {
		int cnt = 0;
		for (j = 1; j <= n; j++) {
			if (j != i) {
				P[cnt] = w[j] - w[i];
				P[cnt].num = j, P[cnt].ck = 0;
				cnt++;
				P[cnt] = w[i] - w[j];
				P[cnt].num = j, P[cnt].ck = 1;
				cnt++;
			}
		}
		sort(P, P + cnt);
		for (j = 0; j < cnt; j++) {
			int c = 0;
			for (k = 0; k < cnt; k++) {
				int t = (j + k) % cnt;
				if (!P[t].ck)c++;
				if (P[t].ck == P[j].ck) {
					if (P[j].ck == 0)A[i][P[j].num][P[t].num] = c;
					else B[i][P[j].num][P[t].num] = c;
				}
			}
		}
	}
	long long r1 = 0, r2 = 0;
	int s = 0;
	for (i = 1; i <= n; i++) {
		for (j = i+1; j <= n; j++) {
			for (k = i+1; k <= n; k++) {
				if (i == j || i == k || j == k)continue;
				if (ccw(w[i], w[j], w[k]) <= 0)continue;
				int t = A[i][j][k] + B[i][j][k] + A[j][k][i] + B[j][k][i] + A[k][i][j] + B[k][i][j] - n - 3;
				t /= 2;
				r1 += t * (t - 1) / 2;
				r2 += t * (A[i][j][k] - t - 2);
				r2 += t * (A[j][k][i] - t - 2);
				r2 += t * (A[k][i][j] - t - 2);
			}
		}
	}
	r2 /= 2;
	long long res = 1ll * n*(n - 1)*(n - 2)*(n - 3)*(n - 4) / 120;
	printf("%lld\n", res-r1 - r2);
}