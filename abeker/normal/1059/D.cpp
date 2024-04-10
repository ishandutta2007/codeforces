#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int MAXN = 1e5 + 5;
const int ITER = 200;

int N;
int x[MAXN], y[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", x + i, y + i);
}

ld f(ld val) {
	ld res = -1e18;
	for (int i = 0; i < N; i++)
		res = max(res, (val - x[i]) * (val - x[i]) / y[i] + y[i]);
	return res / 2;
}

ld solve() {
	bool pos = false, neg = false;
	for (int i = 0; i < N; i++) {
		pos |= y[i] > 0;
		neg |= y[i] < 0;
	}
	
	if (pos && neg)
		return -1;
	
	if (neg)
		for (int i = 0; i < N; i++)
			y[i] *= -1;
	
	ld lo = -1e9, hi = 1e9;
	for (int i = 0; i < ITER; i++) {
		ld l = (2 * lo + hi) / 3;
		ld r = (lo + 2 * hi) / 3;
		if (f(l) < f(r))
			hi = r;
		else
			lo = l;
	}
	
	return f((lo + hi) / 2);
}

int main() {
	load();
	printf("%.10Lf\n", solve());
	return 0;
}