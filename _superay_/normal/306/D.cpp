#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-3;
inline int dcmp(double x) {
	return x < -EPS ? -1 : x > EPS;
}
inline bool inrange(double x, double l, double r) {
	return dcmp(x - l) >= 0 && dcmp(x - r) <= 0;
}
int n;
double len[105];
int main() {
	scanf("%d", &n);
	if (n <= 4) { puts("No solution"); return 0; }
	while (true) {
		double tx = 0, ty = 0;
		for (int i = 0; i < n - 2; i++) {
			double dx = cos(PI * 2 / n * i), dy = sin(PI * 2 / n * i);
			len[i] = 1.0 * rand() / RAND_MAX * 100 + 100;
			tx -= dx * len[i], ty -= dy * len[i];
		}
		double dx1 = cos(PI * 2 / n * (n - 2)), dy1 = sin(PI * 2 / n * (n - 2));
		double dx2 = cos(PI * 2 / n * (n - 1)), dy2 = sin(PI * 2 / n * (n - 1));
		len[n - 2] = (dy2 * tx - dx2 * ty) / (dx1 * dy2 - dx2 * dy1);
		len[n - 1] = (-dy1 * tx + dx1 * ty) / (dx1 * dy2 - dx2 * dy1);
		if (!inrange(len[n - 2], 1, 1000)) continue;
		if (!inrange(len[n - 1], 1, 1000)) continue;
		int fnd = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) if (!dcmp(len[i] - len[j])) fnd = 1;
		if (fnd) continue;
		tx = ty = 0;
		for (int i = 0; i < n; i++) {
			printf("%.10lf %.10lf\n", tx, ty);
			double dx = cos(PI * 2 / n * i), dy = sin(PI * 2 / n * i);
			tx += dx * len[i], ty += dy * len[i];
		}
		assert(!dcmp(tx) && !dcmp(ty));
		break;
	}
	return 0;
}