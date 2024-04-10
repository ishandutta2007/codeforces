#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 100005;
const ld eps = 1e-9;

int N, P;
int a[MAXN], b[MAXN];

void load() {
	scanf("%d%d", &N, &P);
	for (int i = 0; i < N; i++)
		scanf("%d%d", a + i, b + i);
}

bool check(ld t) {
	ld tot = 0;
	for (int i = 0; i < N; i++)
		tot += max(t * a[i] - b[i], (ld)0) / P;
	return tot <= t;
}

ld solve() {
	ll sum = 0;
	for (int i = 0; i < N; i++)
		sum += a[i];
	if (sum <= P) 
		return -1;
	ld lo = 0, hi = 1e18;
	for (int i = 0; i < 100; i++) {
		ld mid = (lo + hi) / 2;
		if (check(mid))
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}

int main() {
	load();
	printf("%.10Lf\n", solve());
	return 0;
}