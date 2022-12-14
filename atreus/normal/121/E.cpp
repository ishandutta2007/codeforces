#include <bitset>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#define prime first
#define alpha second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;

int a[maxn], nex[maxn];

class node {
public:
	int min;
	int number_of_min;
	int sum;
	int lazy;
};

node seg[4 * maxn];

void pull (int id) {
	int L = 2 * id + 0, R = 2 * id + 1;
	if (seg[L].min > seg[R].min)
		swap (L, R);
	seg[id].min = seg[L].min;
	seg[id].number_of_min = seg[L].number_of_min + (seg[L].min == seg[R].min) * seg[R].number_of_min;
}

void change (int, int, int, int, int, int, int, int);

void propagate (int id, int L, int R, int x) {
	if (seg[id].lazy == 0)
		return;
	int mid = (L + R) >> 1;
	change (2 * id + 0, L, mid, L, mid, seg[id].lazy, x, 0);
	change (2 * id + 1, mid, R, mid, R, seg[id].lazy, x, 0);
	seg[id].lazy = 0;
}

int get (int id, int L, int R, int l, int r, int x = 0) {
	x += seg[id].sum;
	if (L == l and R == r)
		return (seg[id].min == 0) * seg[id].number_of_min;
	
	propagate (id, L, R, x);
	
	int mid = (L + R) >> 1, ret = 0;
	if (mid > l)
		ret += get (2 * id + 0, L, mid, l, min (mid, r));
	if (mid < r)
		ret += get (2 * id + 1, mid, R, max (l, mid), r);
	return ret;
}

void change (int id, int L, int R, int l, int r, int d, int x = 0, int val = 0) {
	x += seg[id].sum;
	if (L == l and R == r) {
		if (seg[id].min >= d) {
			seg[id].min -= d;
			seg[id].sum += val;
			seg[id].lazy += d;
			return;
		}
		if (L + 1 == R) {
			seg[id].sum += d;
			seg[id].min = nex[x + a[L] + d];
			return;
		}
	}

	propagate (id, L, R, x);

	int mid = (L + R) >> 1;
	if (mid > l)
		change (2 * id + 0, L, mid, l, min (mid, r), d, x, val);
	if (mid < r)
		change (2 * id + 1, mid, R, max (l, mid), r, d, x, val);
	pull (id);
}

void build (int id, int L, int R) {
	if (L + 1 == R) {
		seg[id].min = nex[a[L]];
		seg[id].number_of_min = 1;
		return;
	}
	int mid = (L + R) >> 1;
	build (2 * id + 0, L, mid);
	build (2 * id + 1, mid, R);
	pull (id);
}

bool lucky (int x) {
	while (x > 0) {
		int p = x % 10;
		if (p != 7 and p != 4)
			return 0;
		x /= 10;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	int last = 44444;
	for (int i = 10000; i >= 1; i--) {
		if (lucky (i))
			last = i;
		nex[i] = last - i;
	}

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	build (1, 0, n);

	for (int i = 0; i < q; i++) {
		string s;
		cin >> s;
		if (s == "count") {
			int l, r;
			cin >> l >> r;
			l --;
			cout << get (1, 0, n, l, r) << '\n';
		}
		else {
			int l, r, d;
			cin >> l >> r >> d;
			l --;
			change (1, 0, n, l, r, d, 0, d);
		}
	}
}