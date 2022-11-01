#include <bits/stdc++.h>
using namespace std;

const int N = 1000 * 1000 + 5, inf = 2000 * 1000 * 1000 + 7;

pair <int, int> a[N];
pair <int, int> b[N];
pair <pair <int, int>, int> c[N];
int d[N];
int seg[N * 4];
int seg2[N * 4];

void build(int id = 1, int s = 0, int e = N) {
	if (e - s == 1) {
		seg[id] = d[s];
		return;
	}
	int md = (s + e) / 2;
	build(id * 2, s, md);
	build(id * 2 + 1, md, e);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	
}

void update(int l, int r, int p, int id = 1, int s = 0, int e = N) {
	if (e <= l || r <= s) {
		return;
	}
	if (l <= s && e <= r) {
		seg2[id] += p;
		seg[id] += p;
		return;
	}
	int md = (s + e) / 2;
	update(l, r, p, id * 2, s, md);
	update(l, r, p, id * 2 + 1, md, e);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]) + seg2[id];
}
int get(int l, int r, int f = 0, int id = 1, int s = 0, int e = N) {
	if (e <= l || r <= s) {
		return -inf;
	}
	f += seg2[id];
	if (l <= s && e <= r) {
		return seg[id] + f;
	}
	int md = (s + e) / 2;
	int ans = get(l, r, f, id * 2, s, md);
	ans = max(ans, get(l, r, f, id * 2 + 1, md, e));
	ans = max(ans, seg[id] + f);
	return ans;
}
int main() {
	ios :: sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i].first >> b[i].second;
	}
	for (int i = 0; i < q; i++) {
		cin >> c[i].first.first >> c[i].first.second >> c[i].second;
	}
	sort(a, a + n);
	sort(c, c + q);
	fill(d, d + N, -inf);
	for (int i = 0; i < m; i++) {
		d[b[i].first] = max(d[b[i].first], -b[i].second);
	}
	build();
//	for (int i = 0; i < 25; i++) {
	//	cout << "71 " << i << " " << seg[i] << endl;
//	}
	int t = 0, ans = -inf;
	for (int i = 0; i < n; i++) {
		while (t < q && c[t].first.first < a[i].first) {
		//	cout << c[t].first.first << " " << c[t].first.second << endl;
			update(c[t].first.second + 1, N, c[t].second);
			t++;
		}
	//	cout << "48 " << get(0, a[i].first) << endl;
		ans = max(ans, get(0, N) - a[i].second);
	}
	cout << ans;
	return 0;
}