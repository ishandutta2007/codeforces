#include <iostream>
using namespace std;

const int N = 500 * 1000 + 5;
int n, q, cnt;

int a[N];
int seg[N * 4];

int bmm(int x, int y) {
	if (y == 0) {
		return x;
	}
	return bmm(y, x % y);
} 
void update(int p, int x, int id = 1, int s = 0, int e = n) {
	if (e <= p || p < s) {
		return;
	}
	if (e - s == 1) {
		seg[id] = x;
		return;
	}
	int md = (s + e) / 2;
	update(p, x, id * 2, s, md);
	update(p, x, id * 2 + 1, md, e);
	seg[id] = bmm(seg[id * 2], seg[id * 2 + 1]);
//	cout << "48 " << p << " " << id << " " << s << " " << e << " " << seg1[id] << " " << seg2[id] << endl;
}
void get(int l, int r, int x, int id = 1, int s = 0, int e = n) {
	if (e <= l || r <= s || cnt > 1 || seg[id] % x == 0) {
		return;
	}
	if (l <= s && e <= r) {
		if (e - s != 1 && seg[id * 2] % x != 0 && seg[id * 2 + 1] % x != 0) {
			cnt = 2;
			return;
		}
	//	if (seg[id] % x != 0) {
			if (cnt != 0) {
				cnt++;
			//	return;
			}
			if (e - s == 1) {
				cnt++;
				return;
			}
	//	}
//		if (e - s == 1) {
//			return;
//		}
	}
	int md = (s + e) / 2;
	get(l, r, x, id * 2, s, md);
	get(l, r, x, id * 2 + 1, md, e);

}
int main() {
	ios :: sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		update(i, a[i]);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int qt;
		cin >> qt;
		if (qt == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			l--;
			cnt = 0;
			get(l, r, x);
		//	cout << "73 " << get(l, r).first << " " << get(l, r).second << endl;
			if (cnt > 1) {
				cout << "NO" << '\n';
			}
			else {
				cout << "YES" << '\n';
			}
		}
		else {
			int p, x;
			cin >> p >> x;
			p--;
			update(p, x);
		}
	}
	return 0;
}