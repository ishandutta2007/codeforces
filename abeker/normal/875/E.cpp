#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N, s1, s2;
int x[MAXN];

void load() {
	scanf("%d%d%d", &N, &s1, &s2);
	for (int i = 0; i < N; i++)
		scanf("%d", x + i);
}

bool range(int pos, int d, int lo, int hi) {
	return abs(pos - lo) <= d && abs(pos - hi) <= d;
}

bool check(int dist) {
	int mn = x[N - 1], mx = x[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		if (range(x[i], dist, mn, mx)) 
			mn = mx = x[i];
		mn = min(mn, x[i]);
		mx = max(mx, x[i]);
	}
	return range(s1, dist, mn, mx) || range(s2, dist, mn, mx);
}

int solve() {
	int lo = abs(s1 - s2), hi = 1e9;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (check(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}