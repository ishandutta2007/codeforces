#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;



const int N = 1005, M = 500 * 1000 + 5;
int n, m, q;


int st[M], ed[M], w[M];
vector <pair <int, int> > seg[M * 4];
int par[N];
int c[N];
vector <pair <int, int> > vec;

pair <int, int> get_par(int v) {
	if (par[v] == v) {
		return {v, 0};
	}
	pair <int, int> p = get_par(par[v]);
	par[v] = p.first, c[v] ^= p.second;
	return {par[v], c[v]};
}

void build(int id = 1, int s = 0, int e = m) {
	vector <pair <int, int> > vec;
	for (int i = s; i < e; i++) {
		vec.push_back({-w[i], i});
		par[st[i]] = st[i], par[ed[i]] = ed[i];
		c[st[i]] = 0, c[ed[i]] = 0;
	}
	sort(vec.begin(), vec.end());
	for (auto p : vec) {
		int u = st[p.second], v = ed[p.second];
	//	cout << "72 " << p.second << " " << u << " " << v << endl;
		pair <int, int> p1 = get_par(u), p2 = get_par(v);
		if (p1.first == p2.first && p1.second == p2.second) {
			seg[id].push_back(p);
			break;
		}
		if (p1.first != p2.first) {
			seg[id].push_back(p);
			par[p1.first] = p2.first;
			c[p1.first] = p1.second ^ p2.second ^ 1;
		}
	}
	if (e - s == 1) {
		return;
	}
	vec.clear();
	int md = (s + e) / 2;
	build(id * 2, s, md);
	build(id * 2 + 1, md, e);
}
void get(int l, int r, int id = 1, int s = 0, int e = m) {
	if (r <= s || e <= l) {
		return;
	}
	if (l <= s && e <= r) {
		for (auto p : seg[id]) {
			vec.push_back(p);
		}
		return;
	}
	int md = (s + e) / 2;
	get(l, r, id * 2, s, md);
	get(l, r, id * 2 + 1, md, e);
}


int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		cin >> st[i] >> ed[i] >> w[i];
		w[i]++;
	}
	build();
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		vec.clear();
		iota(par, par + n + 1, 0);
		fill(c, c + n + 1, 0);
	//	for (int j = 1; j <= n; j++) {
	//		cout << "71 " << j << " " << par[j] << " " << c[j] << endl;
	//	}
		get(l, r);
		sort(vec.begin(), vec.end());
		int ans = 0;
		for (auto p : vec) {
			int u = st[p.second], v = ed[p.second];
		//	cout << "73 " << p.second << " " << u << " " << v << endl;
			pair <int, int> p1 = get_par(u), p2 = get_par(v);
			if (p1.first == p2.first && p1.second == p2.second) {
				ans = -p.first;
				break;
			}
			if (p1.first != p2.first) {
				par[p1.first] = p2.first;
				c[p1.first] = p1.second ^ p2.second ^ 1;
			}
		}
		cout << ans - 1 << '\n';
	}
	return 0;
}