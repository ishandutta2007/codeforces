#include <iostream>
using namespace std;

const int N = 1000 * 1000 + 5;
int n, q;

int a[N];
int b[N];
pair <int, pair <int, int> > seg[4 * N];
void update(int l, int r, int p, int t, int id = 1, int s = 0, int e = n) {
	if (r <= s || e <= l) {
		return;
	}
	if (l <= s && e <= r) {
		seg[id] = {t, {l, p}};
		return;
	}
	int md = (s + e) / 2;
	update(l, r, p, t, id * 2, s, md);
	update(l, r, p, t, id * 2 + 1, md, e);
} 
pair <int, pair <int, int> > get(int x, int id = 1, int s = 0, int e = n) {
	if (e <= x || x < s) {
		return {0, {0, 0}};
	}
	if (e - s == 1) {
		return seg[id];
	}
	int md = (s + e) / 2;
	pair <int, pair <int, int> > ans = seg[id];
	ans = max(ans, get(x, id *  2, s, md));
	ans = max(ans, get(x, id * 2 + 1, md, e));
	return ans;
}
int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= q; i++) {
		int qt;
		cin >> qt;
		if (qt == 1) {
			int x, y, k;
			cin >> x >> y >> k;
			x--;
			y--;
			update(y, y + k, x, i);
		}
		if (qt == 2) {
			int y;
			cin >> y;
			y--;
			pair <int, pair <int, int> > p = get(y);
			int t = p.first, l = p.second.first, x = p.second.second;
		//	cout << "73 " << t << " " << l << " " << x << endl;
			if (t == 0) {
				cout << b[y] << endl;
			}
			else {
				cout << a[y - l + x] << endl;
			}
		}
	}
	return 0;
}