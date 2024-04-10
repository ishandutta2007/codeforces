#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;
int n, q;

int a[N];
long long seg1[N * 4];
int seg2[N * 4];

void update2(int x, int id = 1, int s = 0, int e = n) {
//	cout << "72 " << x << " " << a[x] << " " << id << endl;
	if (x < s || e <= x) {
		return;
	}
	if (e - s == 1) {
		seg1[id] = seg2[id] = a[x];
		return;
	}
	int md = (s + e) / 2;
	update2(x, id * 2, s, md);
	update2(x, id * 2 + 1, md, e);
	seg1[id] = seg1[id * 2] + seg1[id * 2 + 1];
	seg2[id] = max(seg2[id * 2], seg2[id * 2 + 1]);
}
void update1(int l, int r, int mod, int id = 1, int s = 0, int e = n) {
//	cout << "74 " << s << " " << e << " " << id << " " << seg2[id] << endl;
	if (r <= s || e <= l || seg2[id] < mod) {
		return;
	}
	if (e - s == 1) {
		a[s] %= mod;
		update2(s);
		return;
	}
	int md = (s + e) / 2;
	update1(l, r, mod, id * 2, s, md);
	update1(l, r, mod, id * 2 + 1, md, e);
}
long long get(int l, int r, int id = 1, int s = 0, int e = n) {
	if (r <= s || e <= l) {
		return 0;
	}
	if (l <= s && e <= r) {
		return seg1[id];
	}
	int md = (s + e) / 2;
	long long ans = get(l, r, id * 2, s, md);
	ans += get(l, r, id * 2 + 1, md, e);
	return ans;
}
int main() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		update2(i);
	}
	for (int i = 0; i < q; i++) {
		int qt;
		cin >> qt;
	//	cout << "71 " << qt << endl;
		if (qt == 1) {
			int l, r;
			cin >> l >> r;
			l--;
			cout << get(l, r) << '\n';
		}
		if (qt == 2) {
			int l, r, mod;
			cin >> l >> r >> mod;
			l--;
			update1(l, r, mod);
		}
		if (qt == 3) {
			int k, x;
			cin >> k >> x;
			k--;
			a[k] = x;
			update2(k);
		}
	}
	return 0;
}