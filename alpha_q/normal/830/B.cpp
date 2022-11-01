#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

set <int> p[N];
int n, a[N], b[N], c[N], f[N];

void update (int p, int v) {
	while (p < N) f[p] += v, p += p & -p;
}

int pref (int p) {
	int sum = 0;
	while (p > 0) sum += f[p], p -= p & -p;
	return sum;
}

int range (int l, int r) {
	if (l > r) return 0;
	return pref(r) - pref(l - 1);
}

int get (int l, int r) {
	if (l <= r) return range(l, r);
	return range(l, n) + range(1, r);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		p[a[i]].insert(i);
		b[i] = a[i];
		update(i, 1);
	}
	sort(b + 1, b + n + 1);
	int at = 0;
	for (int i = 1; i <= n; ++i) {
		int num = b[i];
		auto it = p[num].lower_bound(at);
		if (it == p[num].end()) {
			it = p[num].begin();
		}
		c[i] = at = *it;
		p[num].erase(it);
		// cout << c[i] << " ";
	}
	// cout << endl;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += (long long) get(c[i - 1] + 1, c[i]);
		update(c[i], -1);
	}
	printf("%lld\n", ans);
	return 0;
}