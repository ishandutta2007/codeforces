#include <iostream>
using namespace std;

const int N = 1000 * 1000 + 5;
int n, q;
string t;

int seg[N * 4][7];
bool b[N * 4];
void mrg(int id, int s, int e) {
	int md = (s + e) / 2;
	seg[id][0] = seg[id * 2][0] + seg[id * 2 + 1][0];
	seg[id][1] = seg[id * 2][1] + seg[id * 2 + 1][1];
	seg[id][2] = max(seg[id * 2][0] + seg[id * 2 + 1][2], seg[id * 2][2] + seg[id * 2 + 1][1]);
	seg[id][3] = max(seg[id * 2][1] + seg[id * 2 + 1][3], seg[id * 2][3] + seg[id * 2 + 1][0]);
	if (b[id]) {
		swap(seg[id][0], seg[id][1]);
		swap(seg[id][2], seg[id][3]);
	}
}
void build(int id = 1, int s = 0, int e = n) {
	if (e - s == 1) {
		if (t[s] == '7') {
			seg[id][1] = 1;
		}
		else {
			seg[id][0] = 1;
		}
		seg[id][2] = seg[id][3] = 1;
		return;
	}
	int md = (s + e) / 2;
	build(id * 2, s, md);
	build(id * 2 + 1, md, e);
	mrg(id, s, e);
}
void update(int l, int r, int id = 1, int s = 0, int e = n) {
	if (e <= l || r <= s) {
		return;
	}
	if (l <= s && e <= r) {
		b[id] ^= 1;
		swap(seg[id][0], seg[id][1]);
		swap(seg[id][2], seg[id][3]);
		return;
	}
	int md = (s + e) / 2;
	update(l, r, id * 2, s, md);
	update(l, r, id * 2 + 1, md, e);
	mrg(id, s, e);
}
int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> q;
	cin >> t;
	build();
	for (int i = 0; i < q; i++) {
		string qt;
		cin >> qt;
	//	cout << qt << endl;
		if (qt.size() == 5) {
			cout << seg[1][2] << '\n';
		}
		else {
			int l, r;
			cin >> l >> r;
			l--;
			update(l, r);
		}
	}
	build();
}