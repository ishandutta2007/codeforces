#include <iostream>
#include <vector>
using namespace std;

const int N = 500 * 1000 + 5;
int t = 0, n;

vector <int> adj[N];
int st[N];
int ft[N];
bool mark[N];
int a[4 * N];
int b[4 * N];

void update1(int l, int r, int x, int id = 1, int s = 0, int e = n) {
	if (l <= s && e <= r) {
		a[id] = x;
		return;
	}
	if (e <= l || r <= s) {
		return;
	}
	int md = (s + e) / 2;
	update1(l, r, x, id * 2, s, md);
	update1(l, r, x, id * 2 + 1, md, e);
}
void update2(int p, int x, int id = 1, int s = 0, int e = n) {
	if (e <= p || p < s) {
		return;
	}
	if (e - s == 1) {
		b[id] = x;
		return;
	}
	int md = (s + e) / 2;
	update2(p, x, id * 2, s, md);
	update2(p, x, id * 2 + 1, md, e);
	b[id] = max(b[id * 2], b[id * 2 + 1]);
}
int get1(int p, int id = 1, int s = 0, int e = n) {
	if (e <= p || p < s) {
		return 0;
	}
	if (e - s == 1) {
		return a[id];
	}
	int md = (s + e) / 2;
	int ans = max(get1(p, id * 2, s, md), get1(p, id * 2 + 1, md, e));
	ans = max(ans, a[id]);
	return ans;
	
}
int get2(int l, int r, int id = 1, int s = 0, int e = n) {
	if (e <= l || r <= s) {
		return 0;
	}
	if (l <= s && e <= r) {
		return b[id];
	}
	int md = (s + e) / 2;
	return max(get2(l, r, id * 2, s, md), get2(l, r, id * 2 + 1, md, e));
}
void dfs(int v) {
	mark[v] = true;
	st[v] = t;
	t++;
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs(u);
		}
	}
	ft[v] = t;
}
int main() {
	ios :: sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int qt, v;
		cin >> qt >> v;
		if (qt == 1) {
			update1(st[v], ft[v], i);
		}
		if (qt == 2) {
			update2(st[v], i);
		}
		if (qt == 3) {
			int x = get1(st[v]);
			int y = get2(st[v], ft[v]);
			if (y >= x) {
				cout << 0 << '\n';
			}
			else {
				cout << 1 << '\n';
			}
		}
	}
	return 0;
}