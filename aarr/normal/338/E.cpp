#include <iostream>
#include <algorithm>
using namespace std;

const int N = 150 * 1000 + 5;
int n, m, h, ans;

int b[N], a[N];
int seg1[N * 4], seg2[N * 4];

void build(int id = 1, int s = 0, int e = n) {
	if (e - s == 1) {
		seg2[id] = seg1[id] = -n + s;
		return;
	}
	int md = (s + e) / 2;
	build(id * 2, s, md);
	build(id * 2 + 1, md, e);
	seg1[id] = min(seg1[id * 2], seg1[id * 2 + 1]);
}

void update(int l, int r, int val, int id = 1, int s = 0, int e = n) {
	if (r <= s || e <= l) {
		return;
	}
	if (l <= s && e <= r) {
		seg1[id] += val;
		seg2[id] += val;
		return;
	}
	int md = (s + e) / 2;
	update(l, r, val, id * 2, s, md);
	update(l, r, val, id * 2 + 1, md, e);
	seg1[id] = min(seg1[id * 2], seg1[id * 2 + 1]) + seg2[id];
}

int main() {
	cin >> m >> n >> h;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i] *= -1;
	}
	sort(b, b + n);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	build();
//	cout << seg1[3] << endl;
	for (int i = 0; i < n; i++) {
		int x = upper_bound(b, b + n + 1, - (h - a[i])) - b;
//		cout << "72 " << x << endl;
		update(0, x, 1);
	}
//	for (int j = 1; j <= 3; j++) {
//		cout << "71 " << j << " " << seg1[j] << " " << seg2[j] << endl;
//	}
	if (seg1[1] == 0) {
		ans++;
	}
	for (int i = n; i < m; i++) {
		int x = upper_bound(b, b + n, - (h - a[i])) - b;
		int y = upper_bound(b, b + n, - (h - a[i - n])) - b;
		update(0, y, -1);
		update(0, x, 1);
//		cout << "73 " << seg1[1] << endl;
		if (seg1[1] == 0) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}