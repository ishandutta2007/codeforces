// :(

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

const int MAXN = 25000;
const double EPS = 1e-10, INF = 1e15;

int x[MAXN], y[MAXN], dx[MAXN], dy[MAXN], s[MAXN], n;
double vx[MAXN], r[MAXN];

void minimize(double &a, double b) { a = (a < b ? a : b); }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d %d %d", &x[i], &y[i], &dx[i], &dy[i], &s[i]);
		r[i] = s[i] / sqrt(dx[i] * dx[i] + dy[i] * dy[i]);
		vx[i] = dx[i] * r[i];
	}

	double ans = INF;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			int detA = dx[j] * dy[i] - dx[i] * dy[j];
			if (detA == 0) {
				if ((x[i] - x[j]) * dy[i] != (y[i] - y[j]) * dx[i]) continue;
				if (((x[i] - x[j]) ^ dx[j]) >= 0) minimize(ans, (x[i] - x[j]) / vx[j]);
				if (((x[j] - x[i]) ^ dx[i]) >= 0) minimize(ans, (x[j] - x[i]) / vx[i]);
				if (vx[i] != vx[j]) {
					double val = (x[i] - x[j]) / (vx[j] - vx[i]);
					if (val > 0) minimize(ans, val); 
				}
			} else {
				double val1 = 1.0 * ((x[i] - x[j]) * dy[j] - (y[i] - y[j]) * dx[j]) / detA;
				double val2 = 1.0 * ((x[i] - x[j]) * dy[i] - (y[i] - y[j]) * dx[i]) / detA;
				if (val1 >= 0 && val2 >= 0) minimize(ans, max(val1 / r[i], val2 / r[j]));
			}
		}
	}

	if (ans == INF) puts("No show :(");
	else printf("%.20f\n", ans);
}