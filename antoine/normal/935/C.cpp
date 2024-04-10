#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <stack>

using namespace std;

double sq(double x) {
	return x*x;
}

void out(double x, double y, double r) {
	cout << fixed;
	cout << setprecision(10) << x << ' ' << y << ' ' << r;
	exit(0);
}

int main() {
	double R, x1, x2, y1, y2;
	cin >> R >> x1 >> y1 >> x2 >> y2;

	if (sq(x1 - x2) + sq(y1 - y2) >= sq(R))
		out(x1, y1, R);

	double x3, y3;
	if (x1 == x2 && y1 == y2) {
		x3 = x1 + R;
		y3 = y1;
	} else {
		double vx = x1 - x2;
		double vy = y1 - y2;
		double coeff = R / sqrt(sq(vx) + sq(vy));
		vx *= coeff;
		vy *= coeff;
		x3 = x1 + vx;
		y3 = y1 + vy;
	}

	double xm = (x2 + x3) / 2.0;
	double ym = (y2 + y3) / 2.0;
	double r = sqrt(sq(x2 - x3) + sq(y2 - y3)) / 2.0;

	out(xm, ym, r);
}