#include <bits/stdc++.h>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int mod = (int)1e9 + 7;
const int maxn = 5e6 + 4;
const ll inf = 1e18;

class node {
	public:
		int lc;
		int rc;
		int len;
		int rig;
		int lef;
		bool per;
		node () {
		    lc = 0, rc = 0, len = 0, rig = 0, lef = 0, per = 0;
		}
};

node seg[maxn];

int newint = 1;

node merge(node fi, node se){
	node ret;
	ret.per = fi.per and se.per;
	ret.lef = (fi.per) ? fi.lef + se.lef : fi.lef;
	ret.rig = (se.per) ? se.rig + fi.rig : se.rig;
	ret.len = max(fi.rig + se.lef, max(fi.len, se.len));
	return ret;
}

node get (int id, int L, int R, int l, int r) {
	if (L == l and R == r) {
		return seg[id];
	}
	int mid = (L + R) >> 1;
	if (r <= mid)
		return get (seg[id].lc, L, mid, l, r);
	if (l >= mid)
		return get (seg[id].rc, mid, R, l, r);
	return merge (get (seg[id].lc, L, mid, l, mid), get (seg[id].rc, mid, R, mid, r));
}

int change (int id, int L, int R, int idx) {
	int ID = newint ++;
	if (L + 1 == R) {
		seg[ID].len = seg[ID].rig = seg[ID].lef = seg[ID].per = 1;
		return ID;
	}
	int mid = (L + R) >> 1;
	seg[ID].lc = seg[id].lc, seg[ID].rc = seg[id].rc;
	if (mid > idx) 
		seg[ID].lc = change (seg[id].lc, L, mid, idx);
	else 
		seg[ID].rc = change (seg[id].rc, mid, R, idx);
	int l = seg[ID].lc, r = seg[ID].rc;
	seg[ID] = merge (seg[seg[ID].lc], seg[seg[ID].rc]);
	seg[ID].lc = l, seg[ID].rc = r;
	return ID;
}

void build (int id, int L, int R) {
	if (L + 1 == R) {
	    seg[id].per = 0;
		return;
	}
	int mid = (L + R) >> 1;
	seg[id].lc = newint;
	build (newint ++, L, mid);
	seg[id].rc = newint;
	build (newint ++, mid, R);
}

pii a[100005];
int r[100005];

int main (){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].F;
		a[i].S = i;
	}
	sort (a, a + n, greater <pair <int, int> >());

	int root = newint ++;
	build (root, 0, n);
	for (int i = 0; i < n; i++)
		root = r[i] = change (root, 0, n, a[i].S);
	if (newint >= maxn)
		return cout << "WRONG" << endl, 0;
	
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int L, R, w;
		cin >> L >> R >> w;
		L --;
		int hi = n, lo = -1;
		while (hi - lo > 1) {
			int mid = (hi + lo) >> 1;
			node check = get (r[mid], 0, n, L, R);
			if (check.len >= w)
				hi = mid;
			else
				lo = mid;
		}
		cout << a[hi].F << endl;
	}
}