#include<cstdio>
#include<algorithm>
#include<cmath>
#define N_ 101000
using namespace std;
struct point {
	long double x, y;
	point operator - (const point &p)const {
		return { x - p.x,y - p.y };
	}
	point operator + (const point &p)const {
		return { x + p.x,y + p.y };
	}
	point operator *(const long double &k)const {
		return { x*k,y*k };
	}
	long double Mul(const point &p)const {
		return x * p.x + y * p.y;
	}
	point Rotate() {
		return { y,-x };
	}
	long double SZ() {
		return sqrtl(x*x + y * y);
	}
}A, B, w[N_];
long double R[N_];
void Input(point &p) {
	scanf("%Lf%Lf", &p.x, &p.y);
}
int n;
bool Inside(point a, long double r1, point &b, long double r2) {
	long double d = (b - a).SZ();
	if (r2 - r1 >= d || r1 - r2 >= d)return true;
	return false;
}
bool Outside(point a, long double r1, point &b, long double r2) {
	long double d = (b - a).SZ();
	if (r2 + r1 < d)return true;
	return false;
}
struct Range {
	long double b, e;
	bool operator<(const Range &p)const {
		return b < p.b;
	}
}P[N_];
int main() {
	int i, j;
	Input(A);
	Input(B);
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		Input(w[i]);
		scanf("%Lf", &R[i]);
	}
	point v = ((B - A)* (1.0L / (B - A).SZ())).Rotate();
	point M = (A + B)*0.5L;
	long double d = (A - M).SZ();
	for (i = 1; i <= n; i++) {
		int chk;
		if ((w[i] - M).Mul(v) > 0) {
			chk = 1;
		}
		else {
			chk = -1;
		}
		long double b = -1e13, e = 1e13, mid;
		long double bb, ee;
		for (j = 0; j < 80; j++) {
			mid = (b + e)*0.5;
			if (Inside(M + v * mid, sqrtl(mid*mid + d * d), w[i], R[i])) {
				ee = mid;
				if (chk == 1)e = mid;
				else b = mid;
			}
			else {
				if (chk == 1)b = mid;
				else e = mid;
			}
		}
		b = -1e13, e = 1e13;
		for (j = 0; j < 80; j++) {
			mid = (b + e)*0.5;
			if (Outside(M + v * mid, sqrtl(mid*mid + d * d), w[i], R[i])) {
				bb = mid;
				if (chk == 1)b = mid;
				else e = mid;
			}
			else {
				if (chk == 1)e = mid;
				else b = mid;
			}
		}
		if (bb > ee)swap(bb, ee);
		P[i] = { bb,ee };
	}
	sort(P+1, P + n+1);
	long double res = max(-P[1].b,0.0L);
	long double b = P[1].b, e = P[1].e;
	for (i = 1; i <= n; i++) {
		if (P[i].b <= 0 && P[i].e >= 0)break;
	}
	if (i == n + 1)res = 0.0;
	for (i = 2; i <= n; i++) {
		if (e < P[i].b) {
			if (res > abs(e))res = abs(e);
			if (res > abs(P[i].b))res = abs(P[i].b);
			b = P[i].b;
		}
		e = max(e, P[i].e);
	}
	if (res > abs(e))res = abs(e);
	printf("%.10Lf\n", sqrtl(res*res+ d * d));
}