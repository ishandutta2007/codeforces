#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;
int n, m, t = 0;

vector <int> adj[N];
vector <int> qr[N];
int seg[N * 8];
int ad[N * 4];
int st[N];
int ft[N];
int ans[N];
bool mark[N];


/*void build(int id = 1, int s = 0, int e = n) {
	seg[id] = e - s;
	if (e - s == 1) {
		return;
	}
	int md = (s + e) / 2;
	build(id * 2, s, md);
	build(id * 2 + 1, md, e);
//	cout << "48 " << seg[id] << " " << s << " " << e << " " << seg[id] << endl;
}*/
void update(int l, int r, int x, int id = 1, int s = 0, int e = n) {
	if (e <= l || r <= s) {
		return;
	}
	if (l <= s && e <= r) {
	//	cout << "38 " << id << " " << x << endl;
		ad[id] += x;
		if (ad[id]) {
			seg[id] = e - s;
		}
		else {
			seg[id] = seg[id * 2] + seg[id * 2 + 1];
		}
		return;
	}
	int md = (s + e) / 2;
	update(l, r, x, id * 2, s, md);
	update(l, r, x, id * 2 + 1, md, e);
	if (!ad[id])
		seg[id] = seg[id * 2] + seg[id * 2 + 1];
	else {
		seg[id] = e - s;
	}
}

void pdfs(int v) {
//	cout << "41 " << v << endl;
	mark[v] = true;
	st[v] = t;
	t++;
	for (auto u : adj[v]) {
//		cout << "43 " << v << " " << u << endl;
		if (!mark[u]) {
			pdfs(u);
		}
	}
	ft[v] = t;
}
void dfs(int v) {
	mark[v] = true;
	for (auto u : qr[v]) {
		update(st[v], ft[v], 1);
		update(st[u], ft[u], 1);
	}
	update(st[v], st[v] + 1, 1);
/*	for (int i = 1; i <= 15; i++) {
		cout << "73 " << i << " " << ad[i] << " " << seg[i] << endl;
	}*/
	ans[v] = seg[1] - 1;	
	update(st[v], st[v] + 1, -1);
/*	for (int i = 1; i <= 15; i++) {
		cout << "73 " << i << " " << ad[i] << " " << seg[i] << endl;
	}*/
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs(u);
		}
	}
	for (auto u : qr[v]) {
		update(st[v], ft[v], -1);
		update(st[u], ft[u], -1);
	}	
}
int main() {
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
	//	cout << "48 " << u << " " << v << endl;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		qr[u].push_back(v);
		qr[v].push_back(u);
	}	
	pdfs(1);
	fill(mark, mark + n + 1, false);
//	build();
//	cout << seg[1] << endl;
/*	for (int i = 1; i <= n; i++) {
		cout << st[i] << " " << ft[i] << endl;
	}*/
	dfs(1);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}