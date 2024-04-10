#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

class LinkCutTree {
private:
	struct Vertex {
		int left, right, parent;
		bool revert;
		int size;
		int64_t value, result, delta;

		Vertex()
			: left(-1), right(-1), parent(-1), revert()
			, size(1), value(), result(), delta() {}
	};

	vector<Vertex> t;

	bool isRoot(int x) const {
		int p = t[x].parent;
		return p == -1 || (t[p].left != x && t[p].right != x);
	}

	int64_t getValue(int x) const {
		return t[x].value + t[x].delta;
	}

	int64_t getResult(int x) const {
		return t[x].result + t[x].delta * t[x].size;
	}

	void push(int x) {
		if (t[x].revert) {
			if (t[x].left != -1)
				t[t[x].left].revert = !t[t[x].left].revert;
			if (t[x].right != -1)
				t[t[x].right].revert = !t[t[x].right].revert;
			swap(t[x].left, t[x].right);
			t[x].revert = false;
		}
		t[x].value = getValue(x);
		t[x].result = getResult(x);
		if (t[x].left != -1)
			t[t[x].left].delta += t[x].delta;
		if (t[x].right != -1)
			t[t[x].right].delta += t[x].delta;
		t[x].delta = 0;
	}

	void keep(int x) {
		t[x].size = 1;
		t[x].result = getValue(x);
		if (t[x].left != -1) {
			t[x].size += t[t[x].left].size;
			t[x].result += getResult(t[x].left);
		}
		if (t[x].right != -1) {
			t[x].size += t[t[x].right].size;
			t[x].result += getResult(t[x].right);
		}
	}

	void rotate(int x) {
		int p = t[x].parent;
		int g = t[p].parent;
		push(p), push(x);
		if (g != -1) {
			if (t[g].left == p)
				t[g].left = x;
			else if (t[g].right == p)
				t[g].right = x;
		}
		t[x].parent = g;
		if (t[p].left == x) {
			t[p].left = t[x].right;
			if (t[p].left != -1)
				t[t[p].left].parent = p;
			t[x].right = p;
		}
		else {
			t[p].right = t[x].left;
			if (t[p].right != -1)
				t[t[p].right].parent = p;
			t[x].left = p;
		}
		t[p].parent = x;
		keep(p), keep(x);
	}

	void splay(int x) {
		while (!isRoot(x)) {
			int p = t[x].parent;
			if (!isRoot(p)) {
				int g = t[p].parent;
				bool zigzig = (x == t[p].left) == (p == t[g].left);
				rotate(zigzig ? p : x);
			}
			rotate(x);
		}
		push(x);
	}

	int expose(int x) {
		int c = -1;
		for (int y = x; y != -1; y = t[y].parent) {
			splay(y);
			t[y].right = c;
			keep(y);
			c = y;
		}
		splay(x);
		return c;
	}

public:
	LinkCutTree(int n) : t(n) {}

	void evert(int x) {
		expose(x);
		t[x].revert = !t[x].revert;
	}

	int root(int x) {
		expose(x);
		while (t[x].left != -1) {
			x = t[x].left;
			push(x);
		}
		expose(x);
		return x;
	}

	int parent(int x) {
		expose(x);
		if (t[x].left == -1)
			return -1;
		x = t[x].left;
		push(x);
		while (t[x].right != -1) {
			x = t[x].right;
			push(x);
		}
		return x;
	}

	bool path(int x, int y) {
		if (x == y)
			return true;
		expose(x), expose(y);
		return t[x].parent != -1;
	}

	void link(int x, int y) {
		if (path(x, y))
			return;
		evert(x);
		t[x].parent = y;
	}

	void cut(int x) {
		expose(x);
		if (t[x].left == -1)
			return;
		t[t[x].left].parent = -1;
		t[x].left = -1;
	}

	int lca(int x, int y) {
		if (!path(x, y))
			return -1;
		expose(y);
		return expose(x);
	}

	int depth(int x) {
		expose(x);
		if (t[x].left == -1)
			return 0;
		return t[t[x].left].size;
	}

	int distance(int x, int y) {
		int l = lca(x, y);
		if (l == -1)
			return -1;
		return depth(x) + depth(y) - depth(l) * 2;
	}

	int64_t query(int x, int y) { // root := y
		if (!path(x, y))
			return 0;
		evert(y), expose(x);
		return t[x].result;
	}

	void update(int x, int y, int64_t value) { // root := y
		if (!path(x, y))
			return;
		evert(y), expose(x);
		t[x].delta += value;
	}
};

struct Node {
	int lo, cnt, add;
};

Node comb(Node a, Node b) {
	a.add = b.add = 0;
	if (a.lo < b.lo) {
		return a;
	}
	if (b.lo < a.lo) {
		return b;
	}
	a.cnt += b.cnt;
	return a;
}

vector<Node> t;

const int inf = 1e9 + 100;

void build(int v, int l, int r) {
	if (l == r) {
		t[v] = { 0, 1, 0 };
	}
	else {
		int m = (l + r) >> 1;
		build(v * 2 + 1, l, m);
		build(v * 2 + 2, m + 1, r);
		t[v] = comb(t[v * 2 + 1], t[v * 2 + 2]);
	}
}

void push(int v) {
	if (t[v].add) {
		int x = t[v].add;
		t[v].add = 0;
		t[v * 2 + 1].add += x;
		t[v * 2 + 1].lo += x;
		t[v * 2 + 2].add += x;
		t[v * 2 + 2].lo += x;
	}
}

void upd(int v, int l, int r, int l1, int r1, int x) {
	if (r < l1 || r1 < l) {
		return;
	}
	if (l1 <= l && r <= r1) {
		t[v].add += x;
		t[v].lo += x;
		return;
	}
	push(v);
	int m = (l + r) >> 1;
	upd(v * 2 + 1, l, m, l1, r1, x);
	upd(v * 2 + 2, m + 1, r, l1, r1, x);
	t[v] = comb(t[v * 2 + 1], t[v * 2 + 2]);
}

Node get(int v, int l, int r, int l1, int r1) {
	if (r < l1 || r1 < l) {
		return { inf, 0, 0 };
	}
	if (l1 <= l && r <= r1) {
		return t[v];
	}
	push(v);
	int m = (l + r) >> 1;
	auto u1 = get(v * 2 + 1, l, m, l1, r1);
	auto u2 = get(v * 2 + 2, m + 1, r, l1, r1);
	return comb(u1, u2);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pii> a(n * m);
	vector<vi> pos(n, vi(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			--x;
			a[x] = { i, j };
			pos[i][j] = x;
		}
	}
	ll ans = 0;
	LinkCutTree lct(n * m);
	vector<vector<bool>> used(n, vector<bool>(m, false));
	t.resize(4 * n * m);
	build(0, 0, n * m - 1);
	const int di[] = { 0, 0, 1,-1 };
	const int dj[] = { 1,-1, 0, 0 };
	auto can_take = [&](int i, int j) {
		for (int w = 0; w < 4; w++) {
			int ii = i + di[w];
			int jj = j + dj[w];
			if (0 <= ii && ii < n && 0 <= jj && jj < m && used[ii][jj]) {
				for (int q = w + 1; q < 4; q++) {
					int iii = i + di[q];
					int jjj = j + dj[q];
					if (0 <= iii && iii < n && 0 <= jjj && jjj < m && used[iii][jjj]) {
						if (lct.path(ii * m + jj, iii * m + jjj)) {
							return false;
						}
					}
				}
			}
		}
		return true;
	};
	for (int i = 0, j = -1; i < n * m; i++) {
		while (j + 1 < n * m && can_take(a[j + 1].first, a[j + 1].second)) {
			j++;
			int pred = (j ? get(0, 0, n * m - 1, j - 1, j - 1).lo : 0);
			upd(0, 0, n * m - 1, j, j, pred + 1);
			used[a[j].first][a[j].second] = true;
			for (int w = 0; w < 4; w++) {
				int ii = a[j].first + di[w];
				int jj = a[j].second + dj[w];
				if (0 <= ii && ii < n && 0 <= jj && jj < m && used[ii][jj]) {
					lct.link(a[j].first * m + a[j].second, ii * m + jj);
					upd(0, 0, n * m - 1, j, j, -1);
				}
			}
		}
		auto data = get(0, 0, n * m - 1, i, j);
		if (data.lo == 1) {
			ans += data.cnt;
		}
		used[a[i].first][a[i].second] = false;
		upd(0, 0, n * m - 1, i, j, -1);
		for (int w = 0; w < 4; w++) {
			int ii = a[i].first + di[w];
			int jj = a[i].second + dj[w];
			if (0 <= ii && ii < n && 0 <= jj && jj < m && used[ii][jj]) {
				upd(0, 0, n * m - 1, pos[ii][jj], j, 1);
				if (lct.parent(ii * m + jj) == a[i].first * m + a[i].second) {
					lct.cut(ii * m + jj);
				}
				else {
					lct.cut(a[i].first * m + a[i].second);
				}
			}
		}
	}
	cout << ans;
}