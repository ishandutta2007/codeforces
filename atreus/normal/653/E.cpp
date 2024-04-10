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
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef unsigned long long ull;
const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;
const ll inf = (1ll << 62);
const int sq = 500;

int a[maxn], seg[4 * maxn];

int merge (int fi, int se) {
	if (a[fi] < a[se])
		return fi;
	return se;
}

int get (int id, int L, int R, int l, int r) {
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) >> 1;
	int f1 = 0, f2 = 0;
	if (mid > l)
		f1 = get (2 * id + 0, L, mid, l, min (mid, r));
	if (mid < r)
		f2 = get (2 * id + 1, mid, R, max (l, mid), r);
	return merge (f1, f2);
}

void change (int id, int L, int R, int idx, int val) {
	if (L + 1 == R) {
		seg[id] = idx;
		return;
	}
	int mid = (L + R) >> 1;
	if (mid > idx)
		change (2 * id + 0, L, mid, idx, val);
	else
		change (2 * id + 1, mid, R, idx, val);

	seg[id] = merge (seg[2 * id + 0], seg[2 * id + 1]);
}

void build (int id, int L, int R) {
	seg[id] = R - 1;
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	build (2 * id + 0, L, mid);
	build (2 * id + 1, mid, R);
}

vector <int> g[maxn];

int main() {	
	ios_base::sync_with_stdio (false);
	int n, m, k;
	cin >> n >> m >> k;
	int d1 = n - 1;
	for (int i = 1; i <= m; i++) {
		int v, u;
		cin >> v >> u;
		g[v].PB (u);
		g[u].PB (v);
		if (min (v, u) == 1)
			d1 --;
	}
	
	if (d1 < k)
		return cout << "impossible" << endl, 0;
	
	a[0] = n + 1;
	build (1, 1, n + 1);
	int com = 0;
	for (int i = 2; i <= n; i++) {
		int idx = get (1, 1, n + 1, 2, n + 1);
		if (a[idx] == i - 2) {
			com ++;
			if (i > 2 and a[1] == i - 2)
				return cout << "impossible" << endl, 0;
			a[1] = i - 2;
			change (1, 1, n + 1, 1, i - 2);
		}
		for (auto j : g[idx]) {
			a[j] ++;
			change (1, 1, n + 1, j, a[j]);
		}
		a[idx] = n + 1;
		change (1, 1, n + 1, idx, n + 1);
	}
	if (a[1] == n - 1)
		return cout << "impossible" << endl, 0;
	if (com > k)
		return cout << "impossible" << endl, 0;
	
	cout << "possible" << endl;
}