#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, p[N], par[N];
long long a[N], b[N], res[N], size[N], now = 0;

int find (int x) {
	return par[x] == x ? x : par[x] = find(par[x]);
}

void merge (int x, int y) {
	int u = find(x), v = find(y);
	size[u] += size[v];
	par[v] = u;
	now = max(now, size[u]);
}

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
	for (int i = 1; i <= n; ++i) scanf("%d", p + i);

	for (int i = 1; i <= n; ++i) par[i] = i;
	memset(b, -1, sizeof b);

	for (int i = n; i >= 1; --i) {
		res[i] = now;
		int pos = p[i];

		b[pos] = a[pos], size[pos] += a[pos];
		now = max(now, b[pos]);
		
		if (pos > 1 and b[pos - 1] != -1) merge(pos, pos - 1);
		if (pos < n and b[pos + 1] != -1) merge(pos, pos + 1);
	}

	for (int i = 1; i <= n; ++i) printf("%lld\n", res[i]);
    return 0;
}