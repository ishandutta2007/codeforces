#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
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
typedef long double ld;
typedef pair<int,int> pii;
const int mod = (int)1e9 + 7;
const int maxn = 1e5 + 100;
const int inf = (int)1e9;

string s;
int n, q, sz = 26;

int seg[4 * maxn][30], lazy[4 * maxn][30];

void propagate (int, int, int, int);

ll get (int id, int L, int R, int l, int r, int alp) {
	if (L == l and R == r)
		return seg[id][alp];

	propagate (id, L, R, alp);

	int mid = (L + R) / 2;
	ll ret = 0;
	if (mid > l)
		ret += get (2 * id + 0, L, mid, l, min (mid, r), alp);
	if (mid < r)
		ret += get (2 * id + 1, mid, R, max (l, mid), r, alp);
	return ret;
}

void change (int id, int L, int R, int l, int r, int alp, int val) {
	if (L == l and R == r) {
		seg[id][alp] = (R - L) * val;
		lazy[id][alp] = val;
		return;
	}

	propagate (id, L, R, alp);

	int mid = (L + R) / 2;
	if (mid > l)
		change (2 * id + 0, L, mid, l, min (mid, r), alp, val);
	if (mid < r)
		change (2 * id + 1, mid, R, max (l, mid), r, alp, val);
	seg[id][alp] = seg[2 * id + 0][alp] + seg[2 * id + 1][alp];
}

void propagate (int id, int L, int R, int alp) {
	if (lazy[id][alp] == -1)
		return;
	int mid = (L + R) / 2;
	change (2 * id + 0, L, mid, L, mid, alp, lazy[id][alp]);
	change (2 * id + 1, mid, R, mid, R, alp, lazy[id][alp]);
	lazy[id][alp] = -1;
}

void build (int id, int L, int R) {
	if (L + 1 == R) {
		seg[id][s[L] - 'a'] ++;
		return;
	}
	int mid = (L + R) / 2;
	build (2 * id + 0, L, mid);
	build (2 * id + 1, mid, R);
	for (int i = 0; i < sz; i++)
		seg[id][i] = seg[2 * id + 0][i] + seg[2 * id + 1][i];
}

void dibagger () {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sz; j++) {
			if (get (1, 1, n + 1, i, i + 1, j))
				cout << char(j + 'a');
		}
	}
	cout << endl;
}

int main(){ 
	ios::sync_with_stdio(false);
	memset (lazy, -1, sizeof lazy);
	cin >> n >> q >> s;
	s = " " + s;
	build (1, 1, n + 1);
	for (int i = 1; i <= q; i++) {
		int l, r, type;
		cin >> l >> r >> type;
		r ++;
		if (type == 1) {
			int cnt = 0;
			for (int j = 0; j < sz; j++) {
				int ted = get (1, 1, n + 1, l, r, j);
				if (!ted)
					continue;
				change (1, 1, n + 1, l, r, j, 0);
				change (1, 1, n + 1, l + cnt, l + cnt + ted, j, 1);
				cnt += ted;
			}
		}
		else {
			int cnt = 0;
			for (int j = sz - 1; j >= 0; j--) {
				int ted = get (1, 1, n + 1, l, r, j);
				if (!ted)
					continue;
				change (1, 1, n + 1, l, r, j, 0);
				change (1, 1, n + 1, l + cnt, l + cnt + ted, j, 1);
				cnt += ted;
			}
		}
//		dibagger();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sz; j++) {
			if (get (1, 1, n + 1, i, i + 1, j))
				cout << char(j + 'a');
		}
	}
	cout << endl;
}