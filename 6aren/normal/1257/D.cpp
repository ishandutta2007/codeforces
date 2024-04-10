#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 200005;

int n, m, beg, it[4 * N], bit[N], a[N];
ii h[N];

void updateBit(int k, int val) {
	for (int i = k; i <= m; i += (i & (-i))) {
		bit[i] = max(bit[i], val);
	}
}

int getBit(int k) {
	int res = 0;
	for (int i = k; i > 0; i -= (i & (-i))) {
		res = max(bit[i], res);
	}
	return res;
}

void build(int k, int l, int r) {
	if (l == r) {
		it[k] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * k, l, mid);
	build(2 * k + 1, mid + 1, r);
	it[k] = max(it[2 * k], it[2 * k + 1]);
}

int getMax(int k, int l, int r, int u, int v) {
	if (l > v || r < u) return 0;
	if (l >= u && r <= v) return it[k];
	int mid = (l + r) / 2;
	int mx1 = getMax(2 * k, l, mid, u, v);
	int mx2 = getMax(2 * k + 1, mid + 1, r, u, v);
	return max(mx1, mx2);
}

bool check(int k) {
	int mx = getMax(1, 1, n, beg, k);
	ii v = {-mx, 1000000000};
	int u = upper_bound(h + 1, h + m + 1, v) - h - 1;
	mx = getBit(u);
	if (mx >= k - beg + 1) return 1;
	else return false;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int ntest;
	cin >> ntest;
	while (ntest--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		build(1, 1, n);
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> h[i].x >> h[i].y;
			h[i].x = -h[i].x;
		}
		h[m + 1] = {0, 0};
		sort(h + 1, h + m + 1);
		for (int i = 1; i <= m; i++) {
			bit[i] = 0;
		}
		for (int i = 1; i <= m; i++) {
			updateBit(i, h[i].y);
		}
		int cur = 0;
		int day = 0;
		while (cur != n) {
			beg = cur + 1;
			int l = beg;
			int r = n;
			int en = 0;
			while (r  - l > 1) {
				int mid = (l + r) / 2;
				if (check(mid)) {
					l = mid;
				} else {
					r = mid;
				}
			}
			for (int i = r; i >= l; i--) {
				if (check(i)) {en = i; break;}
			}
			if (en == 0) {
				day = -1;
				break;
			}
			cur = en;
			day++;
		}
		cout << day << '\n';
	}
	return 0;
}