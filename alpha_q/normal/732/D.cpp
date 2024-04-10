#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

bitset <N> vis;
int n, m;
long long d[N], a[N];

bool check (int last) {
	vis.reset();
	vis[0] = 1;

	long long want = 0;
	for (int i = last; i >= 1; --i) {
		if (vis[a[i]]) {
			if (want > 0) --want;
		} else {
			want += d[a[i]];
			vis[a[i]] = 1; 
		}
	}

	for (int i = 1; i <= m; ++i)
		if (!vis[i]) return 0;

	return want == 0;
}

int main (int argc, char const *argv[]) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
	for (int i = 1; i <= m; ++i) scanf("%lld", d + i);

	int lo = 1, hi = n, it = 30;

	while (it--) {
		int last = lo + hi >> 1;
		if (check(last)) hi = last; 
		else lo = last + 1;
	}

	if (lo >= 1 and lo <= n) printf("%d\n", lo);
	else puts("-1");
    return 0;
}