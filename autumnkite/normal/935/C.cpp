#include <bits/stdc++.h>

const double eps = 1e-9;

int R, Ox, Oy, Cx, Cy;

double dist(double sx, double sy, double tx, double ty) {
	return sqrt(1ll * (tx - sx) * (tx - sx) + 1ll * (ty - sy) * (ty - sy));
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cout.setf(std::ios::fixed);
	std::cout.precision(12);

	std::cin >> R >> Ox >> Oy >> Cx >> Cy;
	double d = dist(Ox, Oy, Cx, Cy);
	if (d > R - eps) {
		std::cout << Ox << " " << Oy << " " << R << "\n";
		return 0;
	}
	double x, y;
	if (d < eps) {
		x = 1.0 * R / 2, y = 0;
	} else {
		x = 1.0 * (Ox - Cx) / d * (d + R) / 2;
		y = 1.0 * (Oy - Cy) / d * (d + R) / 2;
	}
	std::cout << Cx + x << " " << Cy + y << " " << (d + R) / 2 << "\n";
}