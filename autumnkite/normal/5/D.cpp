#include <cstdio>
#include <cmath>
double a, vm, m, d, vd;
double l, r, mid, t1, t2, v1, x1, x2, t, v;
bool check(double t1){
	double v1 = a * t1, x1 = a * t1 * t1 / 2;
	if (v1 <= vd) return true;
	double x2 = (vd * vd - v1 * v1) / (-2 * a);
	return x1 + x2 <= d;
}
int main(){
	scanf("%lf%lf%lf%lf%lf", &a, &vm, &m, &d, &vd);
	l = 0, r = vm / a;
	for (register int i = 1; i <= 100; ++i)
		if (check(mid = (l + r) / 2)) t1 = l = mid; else r = mid;
	v1 = a * t1, x1 = a * t1 * t1 / 2;
	if (x1 >= d) t = sqrt(2 * d / a), v = a * t;
	else if (v1 <= vd) v = v1, t = t1 + (d - x1) / v1;
	else v = vd, x2 = (v1 * v1 - v * v) / (2 * a), t2 = (v1 - v) / a, t = t1 + t2 + (d - x1 - x2) / v1;
	m -= d;
	v1 = sqrt(2 * a * m + v * v);
	if (v1 <= vm) t += (v1 - v) / a;
	else t1 = (vm - v) / a, x1 = v * t1 + a * t1 * t1 / 2, t += t1 + (m - x1) / vm;
	printf("%.15lf", t);
	return 0;
}