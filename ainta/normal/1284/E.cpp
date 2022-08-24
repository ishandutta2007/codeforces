#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 524288
using namespace std;
int n;
long long res;
struct point {
	long long x, y;
	point operator -(const point &p)const {
		return { x - p.x,y - p.y };
	}
	bool operator <(const point &p)const {
		if ((x > 0 || (x == 0 && y > 0)) != (p.x > 0 || (p.x == 0 && p.y > 0))) return x > 0 || (x == 0 && y > 0);
		return y * p.x < p.y*x;
	}
}w[3010], P[3010], OO;
int ccw(point a, point b, point c) {
	long long t = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
	return t > 0 ? 1 : t < 0 ? -1 : 0;
}
int cnt;
int main() {
	int i, j, k, l;
	OO.x = OO.y = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld%lld", &w[i].x, &w[i].y);
	}
	for (i = 0; i < n; i++) {
		cnt = 0;
		for (j = 0; j < n; j++) {
			if (i != j)P[cnt++] = w[j] - w[i];
		}
		sort(P, P + cnt);
		int pv = 0;
		long long s = 1ll * cnt*(cnt - 1)*(cnt - 2) / 6;
		for (j = 0; j < cnt; j++) {
			while (pv < j + cnt && ccw(OO, P[j], P[pv%cnt]) >= 0)pv++;
			int c = max(pv - j - 1,0);
			s -= c * (c - 1) / 2;
		}
		res += s;
	}
	printf("%lld\n", res*(n-4)/2);
}