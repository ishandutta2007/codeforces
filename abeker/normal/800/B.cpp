#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define max3(a, b, c) max(a, max(b, c))

typedef long double ld;

const int MAXN = 1005;

int N;
int x[MAXN], y[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", x + i, y + i);
}

ld dist(int a, int b) {
	return sqrt((ld)(x[a] - x[b]) * (x[a] - x[b]) + (ld)(y[a] - y[b]) * (y[a] - y[b]));
}

ld calc(int a, int b, int c) {
	ld area = abs((ld)x[a] * (y[b] - y[c]) + (ld)x[b] * (y[c] - y[a]) + (ld)x[c] * (y[a] - y[b])) / 2;
	return area / max3(dist(a, b), dist(b, c), dist(c, a));
}

ld solve() {
	ld sol = 1e18;
	for (int i = 0; i < N; i++) {
		int j = (i + 1) % N;
		for (int k = 0; k < N; k++)
			if (k != i && k != j)
				sol = min(sol, calc(i, j, k));
	}
	return sol;
}

int main() {
	load();
	printf("%.10Lf\n", solve());
	return 0;
}