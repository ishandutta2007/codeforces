#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N = 500 * 1000 + 5;
int n, q;

map <int, int> mp;
int a[N];
int b[N];
int seg[N * 4];
int ans[N];
pair <pair <int, int>, int> t[N]; 

void update(int p, int val, int id = 1, int s = 1, int e = n + 1) {
	if (e <= p || p < s) {
		return;
	}
	if (e - s == 1) {
		seg[id] = val;
		return;
	}
	int md = (s + e) / 2;
	update(p, val, id * 2, s, md);
	update(p, val, id * 2 + 1, md, e);
	seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
int get(int l, int r, int id = 1, int s = 1, int e = n + 1) {
	if (r <= s || e <= l) {
		return N;
	}
	if (l <= s && e <= r) {
		return seg[id];
	}
	int md = (s + e) / 2;
	return min(get(l, r, id * 2, s, md), get(l, r, id * 2 + 1, md, e));
}
int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n * 4; i++) {
		seg[i] = N;
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		t[i] = {{r, l}, i};
	}
	sort(t, t + q);
	int x = 1;
	for (int i = 0; i < q; i++) {
		while (t[i].first.first >= x) {
			int y = mp[a[x]];
			if (y != 0) {
				update(y, x - y);
			}
			mp[a[x]] = x;
			x++;
		}
	//	cout << i << " " << x << endl;
		ans[t[i].second] = get(t[i].first.second, t[i].first.first + 1);
	}
	for (int i = 0; i < q; i++) {
		if (ans[i] == N)
			cout << -1 << '\n';
		else
			cout << ans[i] << '\n';
	}
	return 0;
}