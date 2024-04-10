#include <bits/stdc++.h>

using namespace std;

struct fen {
	int n = 200000, t[200000];
	void upd(int id, int x) {
		for(int i = id; i < n; i |= i + 1) t[i] += x;
	}
	int get(int id) {
		int ret = 0;
		for(int i = id; i >= 0; i &= i + 1, i--) ret += t[i];
		return ret;
	}
};

fen to, te;
int n, q, a[200000];
vector<int> g[200000];
int sz, dep[200000];
int pos[200000], hi[200000];

void dfs(int v, int p) {
	hi[v] = pos[v] = sz++;
	for(int to : g[v])
		if(to != p)
			dep[to] = dep[v] + 1, dfs(to, v), hi[v] = max(hi[v], hi[to]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v); g[v].push_back(u);
	}
	dfs(0, -1);
	while(q--) {
		int tp, v; cin >> tp >> v; v--;
		if(tp == 1) {
			int val; cin >> val;
			if(dep[v] % 2) {
				to.upd(pos[v], val);
				to.upd(hi[v] + 1, -val);
				te.upd(pos[v], -val);
				te.upd(hi[v] + 1, val);
			} else {
				te.upd(pos[v], val);
				te.upd(hi[v] + 1, -val);
				to.upd(pos[v], -val);
				to.upd(hi[v] + 1, val);
			}
		} else {
			cout << a[v] + (dep[v] % 2 ? to.get(pos[v]) : te.get(pos[v])) << '\n';
		}
	}
}