#include <iostream>
#include <vector>
using namespace std;


const int N = 400 * 1000 + 5;
int n, q, t = 1;

long long seg[N * 4];
int st[N], ft[N];
bool mark[N * 4];
int a[N];
int c[N];
vector <int> adj[N];

void dfs(int v) {
	st[v] = t;
	a[t] = v;
	t++;
	for (auto u : adj[v]) {
		if (!st[u]) {
			dfs(u);
		}
	}
	ft[v] = t;
}

void shift(int id) {
	if (mark[id]) {
		seg[id * 2] = seg[id * 2 + 1] = seg[id];
		mark[id] = false;
		mark[id * 2] = true;
		mark[id * 2 + 1] = true;		
	}
}

void update(int l, int r, int c, int id = 1, int s = 1, int e = n + 1) {
	if (r <= s || e <= l) {
		return;
	}
	if (l <= s && e <= r) {
	//	cout << "71 " << id << " " << s << " " << e << endl;
		mark[id] = true;
		seg[id] = 1ll << c;
		return;
	}
	shift(id);
	int md = (s + e) / 2;
	update(l, r, c, id * 2, s, md);
	update(l, r, c, id * 2 + 1, md, e);
	if (!mark[id]) {
		seg[id] = seg[id * 2] | seg[id * 2 + 1];
	}
}
long long get(int l, int r, int id = 1, int s = 1, int e = n + 1) {
	if (r <= s || e <= l) {
		return 0;
	}
	if (l <= s && e <= r) {
	//	cout << "74 " << id << " " << seg[id] << endl;
		return seg[id];
	}
	shift(id);
	int md = (s + e) / 2;
	long long ans = get(l, r, id * 2, s, md) | get(l, r, id * 2 + 1, md, e);
	if (!mark[id]) {
		seg[id] = seg[id * 2] | seg[id * 2 + 1];
	}
//	cout << "73 " << id << " " << s << " " << e << " " << ans << endl;
	return ans;
}

int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
//		cout << "72 " << i << " " << st[i] << " " << ft[i] << endl;
		update(i, ft[a[i]], c[a[i]]);
	}
//	for (int i = 1; i <= n * 4; i++) {
//		cout << "75 " << i << " " << seg[i] << " " << mark[i] << endl;
//	}
	for (int i = 0; i < q; i++) {
		int qt, v;
		cin >> qt >> v;
		if (qt == 1) {
			int c;
			cin >> c;
			update(st[v], ft[v], c);
		}
		else {
			long long ans = get(st[v], ft[v]);
			cout << __builtin_popcountll(ans) << '\n';
		}
	}
	return 0;
}