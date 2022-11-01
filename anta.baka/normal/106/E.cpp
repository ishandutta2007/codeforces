#include <bits/stdc++.h>

using namespace std;

const int co = 65;

int n, x[100], y[100], z[100];

double yl, yr;
double zl, zr;

inline double know_xyz(double X, double Y, double Z) {
	double res = 0;
	for(int i = 0; i < n; i++)
		res = max(res, (X - x[i]) * (X - x[i]) + (Y - y[i]) * (Y - y[i]) + (Z - z[i]) * (Z - z[i]));
	return res;
}

inline double know_xy(double X, double Y) {
	zl = -10000, zr = 10000;
	for(int a = 0; a < co; a++) {
		double zll = zl + (zr - zl) / 3;
		double zrr = zl + 2 * (zr - zl) / 3;
		if(know_xyz(X, Y, zll) < know_xyz(X, Y, zrr))
			zr = zrr;
		else
			zl = zll;
	}
	return know_xyz(X, Y, zl);
}

inline double know_x(double X) {
	yl = -10000, yr = 10000;
	for(int a = 0; a < co; a++) {
		double yll = yl + (yr - yl) / 3;
		double yrr = yl + 2 * (yr - yl) / 3;
		if(know_xy(X, yll) < know_xy(X, yrr))
			yr = yrr;
		else
			yl = yll;
	}
	return know_xy(X, yl);
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i] >> z[i];
	double xl = -10000, xr = 10000;
	for(int a = 0; a < co; a++) {
		double xll = xl + (xr - xl) / 3;
		double xrr = xl + 2 * (xr - xl) / 3;
		if(know_x(xll) < know_x(xrr))
			xr = xrr;
		else
			xl = xll;
	}
	know_x(xl);
	know_xy(xl, yl);
	cout.precision(6);
	cout << fixed << xl << ' ' << fixed << yl << ' ' << fixed << zl;
}