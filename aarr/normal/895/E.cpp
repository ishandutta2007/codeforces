#include <iostream>
#include <iomanip>
using namespace std;

const int N = 100 * 1000 + 5;
int n, q;

int a[N];
long double seg[N * 4], laz1[N * 4], laz2[N * 4];

inline void act(int id, int s, int e, long double mul, long double ad) {
	seg[id] *= mul;
	laz1[id] *= mul;
	laz2[id] *= mul;
	laz2[id] += ad;
	seg[id] += ad * (e - s);
}

inline void shift(int id, int s, int e) {
	int md = (s + e) / 2;
	act(id * 2, s, md, laz1[id], laz2[id]);
	act(id * 2 + 1, md, e, laz1[id], laz2[id]);
	laz2[id] = 0;
	laz1[id] = 1;
}


void update(int l, int r, long double mul, long double ad, int id = 1, int s = 0, int e = n) {
//	cout << "71 " << l << " " << r << " " << mul << " " << ad << endl;
	if (r <= s || e <= l) {
		return;
	}
	if (l <= s && e <= r) {
		act(id, s, e, mul, ad);
		return;
	}
	shift(id, s, e);
	int md = (s + e) / 2;
	update(l, r, mul, ad, id * 2, s, md);
	update(l, r, mul, ad, id * 2 + 1, md, e);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];

}

long double get(int l, int r, int id = 1, int s = 0, int e = n) {
	if (e <= l || r <= s) {
		return 0;
	}
	if (l <= s && e <= r) {
		return seg[id];
	}
	shift(id, s, e);
	int md = (s + e) / 2;
	long double ans = get(l, r, id * 2, s, md) + get(l, r, id * 2 + 1, md, e);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
	return ans;
}

int main() {
	cin >> n >> q;
	fill(laz1, laz1 + n * 4, 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		update(i, i + 1, 1, a[i]);

	}
	cout << fixed << setprecision(7);
	for (int i = 0; i < q; i++) {
		int qt;
		cin >> qt;
		if (qt == 1) {
			int l1, r1, l2, r2;
			cin >> l1 >> r1 >> l2 >> r2;
			l1--, l2--;
			long double s1 = get(l1, r1), s2 = get(l2, r2);
			update(l1, r1, (long double) (r1 - l1 - 1) / (r1 - l1), (long double) ((long double) s2 / (r1 - l1)) / (r2 - l2));
			update(l2, r2, (long double) (r2 - l2 - 1) / (r2 - l2), (long double) ((long double) s1 / (r1 - l1)) / (r2 - l2));

		}
		else {
			int l, r;
			cin >> l >> r;
			l--;
			cout << get(l, r) << '\n';
		}

		//for (int j = 1; j <= 7; j++) {
	//		cout << "72 " << i << " " << j << " " << seg[j] << " " << laz1[i] << " " << laz2[j] << endl;
	//	}

	}
	return 0;
}