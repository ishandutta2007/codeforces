#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 3e4 + 10;

bitset <maxn> emp;

bitset <maxn> seg[4 * maxn];

bitset <maxn> get (int id, int L, int R, int l, int r) {
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) >> 1;
	if (mid >= r)
		return get (2 * id + 0, L, mid, l, r);
	if (mid <= l)
		return get (2 * id + 1, mid, R, l, r);
	return (get (2 * id + 0, L, mid, l, mid) | get (2 * id + 1, mid, R, mid, r));
}

int a[maxn], b[maxn], c[maxn], d[maxn], f[maxn];

void build (int id, int L, int R) {
	if (L + 1 == R) {
		seg[id][c[L]] = 1;
		return;
	}
	int mid = (L + R) >> 1;
	build (2 * id + 0, L, mid);
	build (2 * id + 1, mid, R);
	seg[id] = (seg[2 * id + 0] | seg[2 * id + 1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	scanf ("%d%d", &n, &m);

	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++)
		f[i] = (f[i - 1] + f[i - 2]) % m;

	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
		b[i] = a[i];
	}
	sort (b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
		c[i] = lower_bound (b + 1, b + n + 1, a[i]) - b - 1;
	for (int i = 1; i <= n; i++)
		d[c[i]] = a[i];
	build (1, 1, n + 1);
	int q;
	scanf ("%d", &q);
	for (int i = 1; i <= q; i++) {
		int l, r;
		scanf ("%d%d", &l, &r);
		int ans = 0;
		int tmp = 1;
		bitset <maxn> p = get (1, 1, n + 1, l, r + 1);
		for (int i = 0; i < n; i++)
			if (p[i] == 1)
				ans = (1ll * ans + 1ll * d[i] * f[tmp ++]) % m;
		printf ("%d\n", ans);
	}
}