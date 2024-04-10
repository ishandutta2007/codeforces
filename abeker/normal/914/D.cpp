#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int offset = 1 << 19;

int N, Q;
int a[MAXN];
int t[2 * offset];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

void update(int x, int val) {
	x += offset;
	t[x] = val;
	for (x /= 2; x; x /= 2)
		t[x] = __gcd(t[2 * x], t[2 * x + 1]);
}

int query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from)
		return 0;
	if (lo >= from && hi <= to)
		return t[x];
	int mid = (lo + hi) / 2;
	return __gcd(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

int get(int x, int lo, int hi, int left, int val) {
	if (hi <= left)
		return -1;
	if (lo >= left) {
		if (!(t[x] % val))
			return -1;
		while (x < offset)
			x = 2 * x + !(t[2 * x] % val);
		return x - offset;
	}
	int mid = (lo + hi) / 2;
	int tmp = get(2 * x, lo, mid, left, val);
	if (tmp != -1)
		return tmp;
	return get(2 * x + 1, mid, hi, left, val);
}

bool good(int l, int r, int x) {
	int pos = get(1, 0, offset, l, x);
	if (pos >= r || pos == -1)
		return true;
	return !(query(1, 0, offset, pos + 1, r + 1) % x);
}

void solve() {
	for (int i = 1; i <= N; i++)
		t[i + offset] = a[i];
	for (int i = offset - 1; i >= 0; i--)
		t[i] = __gcd(t[2 * i], t[2 * i + 1]);
		
	scanf("%d", &Q);
	while (Q--) {
		int type, l, r, x;
		scanf("%d%d%d", &type, &l, &r);
		if (type == 1) {
			scanf("%d", &x);
			puts(good(l, r, x) ? "YES" : "NO");
		}
		else
			update(l, r);
	}
}

int main() {
	load();
	solve();
	return 0;
}