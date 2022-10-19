#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> pii;

const int MAXN = 105;
const ld eps = 1e-7;

int N;
int x[MAXN], y[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", x + i, y + i);
}

template <typename T>
T dist(T x1, T y1, T x2, T y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int ccw(int p, int q, int r) {
	return x[p] * (y[q] - y[r]) + x[q] * (y[r] - y[p]) + x[r] * (y[p] - y[q]);
}

pii bisector(ld x1, ld y1, ld x2, ld y2) {
	ld k = (x1 - x2) / (y2 - y1);
	ld l = (y1 + y2) / 2 - k * (x1 + x2) / 2;
	return {k, l};
}

pii intersect(pii p, pii q) {
	ld x1 = (q.second - p.second) / (p.first - q.first);
	ld y1 = p.first * x1 + p.second;
	return {x1, y1};
}

pii center(int x1, int y1, int x2, int y2, int x3, int y3) {
	if (y1 == y2) {
		swap(x1, x3);
		swap(y1, y3);
	}
	else if (y1 == y3) {
		swap(x1, x2);
		swap(y1, y2);
	}
	return intersect(bisector(x1, y1, x2, y2), bisector(x1, y1, x3, y3));
}

bool check(pii p, ld d) {
	for (int i = 0; i < N; i++)
		if (sqrt(dist((ld)x[i], (ld)y[i], p.first, p.second)) + eps < d)
			return false;
	return true;
}

ld solve() {
	ld sol = -1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			for (int k = 0; k < j; k++) {
				int a = dist(x[i], y[i], x[j], y[j]);
				int b = dist(x[j], y[j], x[k], y[k]);
				int c = dist(x[k], y[k], x[i], y[i]);
				if (a + b > c && b + c > a && c + a > b) {
					ld radius = sqrt((ld)a) * sqrt((ld)b) * sqrt((ld)c) / (2 * abs(ccw(i, j, k)));
					pii O = center(x[i], y[i], x[j], y[j], x[k], y[k]);
					if (check(O, radius))
						sol = max(sol, radius);
				}
			}	
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++) {
			int tmp = dist(2 * x[i], 2 * y[i], x[i] + x[j], y[i] + y[j]);
			bool pos = false, neg = false;
			for (int k = 0; k < N; k++)
				if (k != i && k != j && dist(2 * x[k], 2 * y[k], x[i] + x[j], y[i] + y[j]) == tmp) {
					pos |= ccw(i, j, k) > 0;
					neg |= ccw(i, j, k) < 0;
				}
			if (pos && neg) {
				ld radius = sqrt((ld)tmp) / 2;
				if (check({(ld)(x[i] + x[j]) / 2, (ld)(y[i] + y[j]) / 2}, radius))
					sol = max(sol, radius);
			}
		}
	
	return sol;
}

int main() {
	load();
	printf("%Lf\n", solve());
	return 0;
}