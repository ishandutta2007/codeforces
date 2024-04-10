#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 5e5 + 5;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;
int a[maxn], Maxn, n, seg[4 * maxn];
pair <pii, int> lad[maxn];

void change (int id, int L, int R, int idx, int val) {
	if (L + 1 == R) {
		seg[id] = val;
		return;
	}
	int mid = (L + R) / 2;
	if (mid > idx)
		change (2 * id + 0, L, mid, idx, val);
	else
		change (2 * id + 1, mid, R, idx, val);
	seg[id] = max (seg[2 * id + 0], seg[2 * id + 1]);
}

int get (int id, int L, int R, int l, int r) {
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) / 2, ret = 0;
	if (mid > l)
		ret = max (ret, get (2 * id + 0, L, mid, l, min (mid, r)));
	if (mid < r)
		ret = max (ret, get (2 * id + 1, mid, R, max (l, mid), r));
	return ret;
}

void compress () {
	vector <int> cmp;
	for (int i = 1; i <= n; i++)
		cmp.PB (lad[i].F.F);
	sort (cmp.begin(), cmp.end());
	cmp.resize (unique (cmp.begin(), cmp.end()) - cmp.begin());
	for (int i = 1; i <= n; i++)
		lad[i].F.F = lower_bound (cmp.begin(), cmp.end(), lad[i].F.F) - cmp.begin() + 1;
	cmp.clear();

	for (int i = 1; i <= n; i++)
		cmp.PB (lad[i].F.S);
	sort (cmp.begin(), cmp.end());
	cmp.resize (unique (cmp.begin(), cmp.end()) - cmp.begin());
	for (int i = 1; i <= n; i++)
		lad[i].F.S = lower_bound (cmp.begin(), cmp.end(), lad[i].F.S) - cmp.begin() + 1;
	cmp.clear();
	
	for (int i = 1; i <= n; i++)
		cmp.PB (lad[i].S);
	sort (cmp.begin(), cmp.end());
	cmp.resize (unique (cmp.begin(), cmp.end()) - cmp.begin());
	for (int i = 1; i <= n; i++)
		lad[i].S = lower_bound (cmp.begin(), cmp.end(), lad[i].S) - cmp.begin() + 1;

	for (int i = 1; i <= n; i++) {
		Maxn = max (Maxn, max (lad[i].F.F, max (lad[i].F.S, lad[i].S)));
	}
}

bool compare (pair <pii, int> fi, pair <pii, int> se) {
	if (fi.F.F != se.F.F)
		return fi.F.F > se.F.F;
	if (fi.F.S != se.F.S)
		return fi.F.S < se.F.S;
	return fi.S < se.S;
}

int main() {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &lad[i].F.F);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &lad[i].F.S);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &lad[i].S);

	compress ();

	sort (lad + 1, lad + n + 1, compare);

	int ans = 0;
	lad[0].F.F = lad[1].F.F;
	for (int i = 1; i <= n; i++) {
		int x = lad[i].F.S, y = lad[i].S;
		if (get (1, 1, Maxn + 2, x + 1, Maxn + 2) > y)
			ans ++;
		if (a[x] < y) {
			change (1, 1, Maxn + 2, x, y);
			a[x] = y;
		}
	}
	printf ("%d\n", ans);
}