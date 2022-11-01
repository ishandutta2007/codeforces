#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;
int n, q;

int a[N];
int b[N];
int lt[N];
int prv[N];
int seg1[N * 4];
int seg2[N * 4];
vector <pair <int, int> > vec[N];
int ans[N];

void update(int p, int x, int id = 1, int s = 1, int e = n + 1) {
	if (p < s || e <= p) {
		return;
	}
	if (e - s == 1) {
		seg1[id] = x;
		seg2[id] = b[p];
		return;
		
	}
	int md = (s + e) / 2;
	update(p, x, id * 2, s, md);
	update(p, x, id * 2 + 1, md, e);
	seg1[id] = seg1[id * 2] + seg1[id * 2 + 1];
	seg2[id] = min(seg2[id * 2], seg2[id * 2 + 1]);
}
pair <int, int> get(int l, int r, int id = 1, int s = 1, int e = n + 1) {
	if (e <= l || r <= s) {
		return {0, N};
	}
	if (l <= s && e <= r) {
		return {seg1[id], seg2[id]};
	}
	int md = (s + e) / 2;
	pair <int, int> p1 = get(l, r, id * 2, s, md), p2 = get(l, r, id * 2 + 1, md, e), p;
	p.first = p1.first + p2.first;
	p.second = min(p1.second, p2.second);
	return p;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		prv[i] = lt[a[i]];
		lt[a[i]] = i;
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		vec[r].push_back({l, i});
	}
	//for (int i = 1; i <= n; i++) {
	//	cout << i << " " << prv[i] << endl;
	//}
	fill(seg2, seg2 + n * 4 + 1, N);
	fill(b, b + n + 1, N);
	for (int i = 1; i <= n; i++) {
		int x = prv[i], y = 0;
		if (x != 0) {
			y = prv[x];
		}
		if (x != 0 && y != 0) {
			if (i - x == x - y) {
				b[i] = b[x];
			}
			else {
				b[i] = y;
			}
		}
		else {
			b[i] = 0;
 		}
		update(i, 1);
		if (x != 0) {
			b[x] = N;
			update(prv[i], 0);
		}
	//	for (int j = 1; j <= n; j++) {
	///		cout << "73 " << i << " " << j << " " << b[j] << endl;
	//	}
		for (auto p : vec[i]) {
			int l = p.first, f = p.second;
			pair <int, int> t = get(l, i + 1);
		//	cout << l << " " << i << " " << f << " " << t.first << " " << t.second << endl;
			ans[f] = t.first;
			if (t.second >= l) {
				ans[f]++;
			}
		}
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}