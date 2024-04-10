#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 700;
const int rad = 1000;

ll Max[4 * maxn], Sum[4 * maxn], lazy[4 * maxn], a[maxn];

void calculate (int id) {
	Max[id] = max (Max[2 * id + 0], Max[2 * id + 1]);
	Sum[id] = Sum[2 * id + 0] + Sum[2 * id + 1];
}

void propagate (int, int, int);

ll get (int id, int L, int R, int l, int r) {
	if (L == l and R == r)
		return Sum[id];
	
	propagate (id, L, R);

	int mid = (L + R) >> 1;
	ll ret = 0;
	if (mid > l)
		ret += get (2 * id + 0, L, mid, l, min (mid, r));
	if (mid < r)
		ret += get (2 * id + 1, mid, R, max (l, mid), r);
	return ret;
}

void update (int id, int L, int R, int l, int r, int x) {
	if (Max[id] < x)
		return;
	
	if (lazy[id] != -1) {
		lazy[id] %= x;
		Max[id] %= x;
		Sum[id] = (R - L) * Max[id];
		return;
	}

	if (L + 1 == R) {
		Sum[id] %= x;
		Max[id] %= x;
		return;
	}

	propagate (id, L, R);

	int mid = (L + R) >> 1;
	if (mid > l)
		update (2 * id + 0, L, mid, l, min (mid, r), x);
	if (mid < r)
		update (2 * id + 1, mid, R, max (l, mid), r, x);
	calculate (id);
}

void change (int id, int L, int R, int l, int r, int x) {
	if (L == l and R == r) {
		Sum[id] = (R - L) * x;
		Max[id] = x;
		lazy[id] = x;
		return;
	}
	
	propagate (id, L, R);

	int mid = (L + R) >> 1;
	if (mid > l)
		change (2 * id + 0, L, mid, l, min (mid, r), x);
	if (mid < r)
		change (2 * id + 1, mid, R, max (l, mid), r, x);
	calculate (id);
}

void propagate (int id, int L, int R) {
	if (lazy[id] == -1)
		return;
	int mid = (L + R) >> 1;
	change (2 * id + 0, L, mid, L, mid, lazy[id]);
	change (2 * id + 1, mid, R, mid, R, lazy[id]);
	lazy[id] = -1;
}

void build (int id, int L, int R) {
	if (L + 1 == R) {
		Max[id] = a[L];
		Sum[id] = a[L];
		return;
	}
	int mid = (L + R) >> 1;
	build (2 * id + 0, L, mid);
	build (2 * id + 1, mid, R);
	calculate (id);
}

int main() {	
	ios_base::sync_with_stdio (false);
	memset (lazy, -1, sizeof lazy);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	build (1, 0, n);
	for (int i = 0; i < m; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r;
			cin >> l >> r;
			cout << get (1, 0, n, l - 1, r) << '\n';
		}
		else if (type == 2) {
			int l, r, x;
			cin >> l >> r >> x;
			update (1, 0, n, l - 1, r, x);
		}
		else {
			int idx, x;
			cin >> idx >> x;
			change (1, 0, n, idx - 1, idx, x);
		}
	}
}