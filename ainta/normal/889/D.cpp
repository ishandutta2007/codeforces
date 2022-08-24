#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n, res;
struct point {
	long long x, y;
	point operator + (const point &p)const {
		return { x + p.x, y + p.y };
	}
	point operator - (const point &p)const {
		return { x - p.x, y - p.y };
	}
	point operator *(const int &k)const {
		return { x*k,y*k };
	}
	point operator /(const int &k)const {
		return { x/k,y/k };
	}
	bool operator ==(const point &p)const {
		return x == p.x && y == p.y;
	}
	bool operator<(const point &p)const {
		return x != p.x ? x < p.x : y < p.y;
	}
	point Rotate() {
		return { y,-x };
	}
}w[2010], M, tw[2010];
map<point, int>Map;
int tn, nn;
long long ccw(point a, point b, point c) {
	return (b.x - a.x)/nn*(c.y - a.y) - (b.y - a.y)/nn*(c.x - a.x);
}
long long U[2010];
long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}
void Make(point &a) {
	if (a.x < 0 || (a.x == 0 && a.y < 0)) {
		a.x = -a.x;
		a.y = -a.y;
	}
	long long g = gcd(abs(a.x), abs(a.y));
	a.x /= g, a.y /= g;
}
int main() {
	int i, j;
	scanf("%d", &n);
	nn = n;
	for (i = 1; i <= n; i++) {
		scanf("%lld%lld", &w[i].x, &w[i].y);
		w[i].x *= 2, w[i].y *= 2;
		M.x += w[i].x, M.y += w[i].y;
		w[i].x *= n, w[i].y *= n;
	}
	for (i = 1; i <= n; i++) {
		if (w[i] == M)continue;
		tw[++tn] = w[i];
	}
	n = tn;
	for (i = 1; i <= tn; i++)w[i] = tw[i];
	int cc = 0, chk = 0;
	for (i = 1; i <= n; i++){
		int ck = 0;
		for (j = 1; j <= n; j++) {
			if (w[i] + w[j] == M * 2)ck = 1;
		}
		point tp = (w[i] - M).Rotate();
		Make(tp);
		Map[tp]++;
		tp = tp.Rotate();
		Make(tp);
		Map[tp]++;
		if (ck) {
			cc++;
			continue;
		}
		if (chk)continue;
		for (j = i + 1; j <= n; j++) {

			if (w[i] + w[j] == M * 2) continue;
			else {
				point MM = (w[i] + w[j]) / 2;
				point tp = (MM - M).Rotate();
				Make(tp);
				Map[tp]++;
				tp = tp.Rotate();
				Make(tp);
				Map[tp]++;
			}
		}
		chk = 1;
	}
	if (cc == n) {
		printf("-1\n");
		return 0;
	}
	for (auto &tp : Map) {
		point a = tp.first;
		for (i = 1; i <= n; i++) {
			U[i] = w[i].x / nn * a.x + w[i].y / nn * a.y;
		}
		sort(U + 1, U + n + 1);
		int chk = 0;
		for (i = 1; i <= n; i++) {
			if (U[i] + U[n + 1 - i] != U[1] + U[n])chk = 1;
		}
		if (!chk)res++;
	}
	printf("%d\n", res);
}