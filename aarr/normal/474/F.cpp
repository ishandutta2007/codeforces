#include <iostream>
using namespace std;


const int N = 100 * 1000 + 5;
int n;

int a[N];
int seg[N * 4];
int cnt[N * 4];

int bmm(int x, int y) {
	if (y == 0)
		return x;
	return bmm(y, x % y);
}
void build(int id = 1, int s = 0, int e = n) {
	if (e - s == 1) {
		seg[id] = a[s];
		cnt[id] = 1;
		return;
	}
	int md = (s + e) / 2;
	build(id * 2, s, md);
	build(id * 2 + 1, md, e);
	int x = seg[id * 2], y = seg[id * 2 + 1];
	int z = bmm(x, y);
	seg[id] = z;
	if (z == x) {
		cnt[id] += cnt[id * 2];
	}
	if (z == y) {
		cnt[id] += cnt[id * 2 + 1];
	}
}
pair <int, int> get(int l, int r, int id = 1, int s = 0, int e = n) {
	if (e <= l || r <= s) {
		return {0, 0};
	}
	if (l <= s && e <= r) {
		return {seg[id], cnt[id]};
	}
	int md = (s + e) / 2;
	pair <int, int> p1 = get(l, r, id * 2, s, md);
	pair <int, int> p2 = get(l, r, id * 2 + 1, md, e);
	int z = bmm(p1.first, p2.first);
	int ans = 0;
	if (z == p1.first) {
		ans += p1.second;
	}
	if (z == p2.first) {
		ans += p2.second;
	}
	return {z, ans};
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	build();
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		cout << r - l - get(l, r).second << endl;
	}
	return 0;
}