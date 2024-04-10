#include <bits/stdc++.h>

const int N = 2005, INF = 0x3f3f3f3f, P = 1000000007;

int n, m, L;
int mx, X[N];
int my, Y[N];

struct Node {
	int x, y, c;

	bool operator < (const Node &rhs) const {
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
} a[N];

std::vector<int> p[N];

int top, sta[N];

std::vector<int> add[N], del[N];

int l[N];

struct TNode {
	int mx, cnt, cmx;
	long long sum;

	TNode() {}
	TNode(int v, int len) {
		mx = v, cnt = len, cmx = -INF, sum = 1ll * len * v;
	}
};

TNode operator + (const TNode &A, const TNode &B) {
	TNode res;
	res.sum = A.sum + B.sum;
	res.cmx = std::max(A.cmx, B.cmx);
	if (A.mx == B.mx) {
		res.mx = A.mx;
		res.cnt = A.cnt + B.cnt;
	} else if (A.mx > B.mx) {
		res.mx = A.mx;
		res.cnt = A.cnt;
		res.cmx = std::max(res.cmx, B.mx);
	} else {
		res.mx = B.mx;
		res.cnt = B.cnt;
		res.cmx = std::max(res.cmx, A.mx);
	}
	return res;
}

struct SegmentTree {
	static const int N = ::N << 2;

	TNode val[N];
	int tag[N];

	void build(int u, int l, int r) {
		tag[u] = INF;
		if (l == r) {
			val[u] = TNode(INF, X[l] - X[l - 1]);
			return;
		}
		int mid = (l + r) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		val[u] = val[u << 1] + val[u << 1 | 1];
	}

	void chmin(int u, int v) {
		if (val[u].mx <= v) {
			return;
		}
		tag[u] = v;
		if (val[u].cmx < v) {
			val[u].sum -= 1ll * (val[u].mx - v) * val[u].cnt;
			val[u].mx = v;
			return;
		}
	}

	void down(int u) {
		chmin(u << 1, tag[u]);
		chmin(u << 1 | 1, tag[u]);
		tag[u] = INF;
	}

	void modify(int u, int l, int r, int L, int R, int v) {
		if (val[u].mx <= v) {
			return;
		}
		if (L <= l && r <= R && val[u].cmx < v) {
			chmin(u, v);
			return;
		}
		int mid = (l + r) >> 1;
		down(u);
		if (L <= mid) {
			modify(u << 1, l, mid, L, R, v);
		}
		if (R > mid) {
			modify(u << 1 | 1, mid + 1, r, L, R, v);
		}
		val[u] = val[u << 1] + val[u << 1 | 1];
	}

	long long query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return val[u].sum;
		}
		int mid = (l + r) >> 1;
		down(u);
		if (R <= mid) {
			return query(u << 1, l, mid, L, R);
		} else if (L > mid) {
			return query(u << 1 | 1, mid + 1, r, L, R);
		} else {
			return query(u << 1, l, mid, L, R) + query(u << 1 | 1, mid + 1, r, L, R);
		}
	}
} T;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m >> L;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i].x >> a[i].y >> a[i].c;
		X[++mx] = a[i].x;
		Y[++my] = a[i].y;
	}
	X[0] = -1, X[++mx] = L;
	Y[0] = -1, Y[++my] = L;
	std::sort(X + 1, X + 1 + mx);
	mx = std::unique(X + 1, X + 1 + mx) - X - 1;
	std::sort(Y + 1, Y + 1 + my);
	my = std::unique(Y + 1, Y + 1 + my) - Y - 1;
	for (int i = 1; i <= n; ++i) {
		a[i].x = std::lower_bound(X + 1, X + 1 + mx, a[i].x) - X;
		a[i].y = std::lower_bound(Y + 1, Y + 1 + my, a[i].y) - Y;
	}

	int ans = 0;
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		p[a[i].c].push_back(i);
	}

	for (int up = 1; up <= my; ++up) {
		for (int i = 1; i <= mx; ++i) {
			add[i].clear();
			del[i].clear();
		}
		T.build(1, 1, mx);
		for (int c = 1; c <= m; ++c) {
			top = 0;
			for (int i = 0; i < (int)p[c].size(); ++i) {
				int id = p[c][i];
				if (a[id].y >= up) {
					continue;
				}
				if (i + 1 < (int)p[c].size() && a[p[c][i + 1]].y < up && a[p[c][i + 1]].x == a[id].x) {
					continue;
				}
				if (top) {
					del[a[id].x].push_back(a[sta[top]].x);
				} else {
					del[a[id].x].push_back(0);
				}
				while (top && a[sta[top]].y <= a[id].y) {
					add[a[id].x].push_back(sta[top]);
					--top;
				}
				if (top) {
					l[id] = a[sta[top]].x;
				} else {
					l[id] = 0;
				}
				sta[++top] = id;
			}
			if (top) {
				del[mx].push_back(a[sta[top]].x);
			} else {
				del[mx].push_back(0);
			}
			while (top) {
				add[mx].push_back(sta[top]);
				--top;
			}
		}
		for (int i = mx; i; --i) {
			for (int v : add[i]) {
				if (l[v] < mx) {
					T.modify(1, 1, mx, l[v] + 1, mx, Y[a[v].y] + 1);
				}
			}
			for (int v : del[i]) {
				if (v < mx) {
					T.modify(1, 1, mx, v + 1, mx, 0);
				}
			}
			ans = (ans + T.query(1, 1, mx, 1, i) % P * (X[i] - X[i - 1]) % P * (Y[up] - Y[up - 1])) % P;
		}
	}
	std::cout << ans << "\n";
}