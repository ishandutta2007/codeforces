#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

template <typename T>
void smin(T& a, T b) {
	(a > b) ? (a = b) : (0);
}

typedef class Point {
	public:
		int x, y;
		
		Point(int x = 0, int y = 0) : x(x), y(y) {		}
		
		boolean operator < (Point b) const {
			return (x ^ b.x) ? (x < b.x) : (y < b.y);
		}
} Point;

typedef class Segment {
	public:
		int l, r;
		
		Segment(int l = 0, int r = 0) : l(l), r(r) {	}
		
		boolean in(int x) {
			return x >= l && x <= r;
		}
		boolean empty() {
			return l > r;
		}
		Segment operator & (Segment b) {
			return Segment(max(l, b.l), min(r, b.r));
		}
		int distance(int x) {
			int ret = 0;
			if (x < l) {
				ret = l - x;
			} else if (x > r) {
				ret = x - r;
			}
			return ret;
		}
} Segment;

typedef class Node {
	public:
		int x, yl, yr;
		
		Node() {	}
		
		Segment y_seg() {
			return Segment(yl, yr);
		}
} Node;

typedef class Position {
	public:
		Segment s, c;
		int dist;
		
		Position() {	}
		Position(Segment s) : s(s), c(s), dist(0) {		}
		
		int value(int x) {
			return dist + c.distance(x);
		}
		
		int pos_s(int x) {
			if (s.empty()) {
				return s.l;
			}
			if (x < s.l) {
				return s.l;
			}
			if (x > s.r) {
				return s.r;
			}
			return x;
		}
		
		Position operator + (Segment b) {
			Position rt;
			if (s.empty()) {
				rt.s = s;
			} else {
				rt.s = s & b;
				if (rt.s.empty()) {
					rt.s.r = -1;
					if (b.l > s.r) {
						rt.s.l = s.r;
					} else {
						rt.s.l = s.l;
					}
				}
			}
			rt.dist = dist + 1;
			rt.c = c & b;
			if (rt.c.empty()) {
				if (b.l > c.r) {
					rt.dist += b.l - c.r;
					rt.c = Segment(b.l, b.l);
				} else {
					rt.dist += c.l - b.r;
					rt.c = Segment(b.r, b.r);
				}
			}
			return rt;
		}
} Position;

typedef class Event {
	public:
		int t, y, d, op;
		
		Event() {	}
		Event(int t, int y, int d, int op) : t(t), y(y), d(d), op(op) {	}
		
		boolean operator < (Event b) const {
			return t < b.t;
		}
} Event;


const int N = 3e5 + 5;

int n, m, q, cnt_q;
int ans[N];
Node nodes[N];
boolean vis[N];
vector<int> G[N];
int n_id[N], q_id[N];
map<Point, int> mp_idx;
vector<Point> qry[N], mdf[N];	// first: y, second: t

int fen1[N], fen2[N];

inline void init() {
	scanf("%d", &n);
	for (int i = 1, x, y; i <= n; i++) {
		scanf("%d%d", &x, &y);
		mp_idx[Point(x, y)] = i;
	}
	Point last(-1, -1);
	int last_id = 0;
	for (auto& par : mp_idx) {
		const Point& p = par.first;
		if (p.x == last.x && p.y == last.y + 1) {
			n_id[par.second] = last_id;
			nodes[last_id].yr = p.y;
		} else {
			n_id[par.second] = ++last_id;
			nodes[last_id].x = p.x;
			nodes[last_id].yl = nodes[last_id].yr = p.y;
		}
		last = p;
	}
	m = last_id;
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		Node& nd = nodes[i];
		for (int j = nd.yl; j <= nd.yr; j++) {
			if (mp_idx.count(Point(nd.x - 1, j))) {
				int id = n_id[mp_idx[Point(nd.x - 1, j)]];
				if (!vis[id]) {
					vis[id] = true;
					G[i].push_back(id);
					G[id].push_back(i);
				}				
			}
		}
		for (auto& e : G[i]) {
			vis[e] = false;
		}
	}
	scanf("%d", &q);
	boolean open = false;
	for (int i = 1, op, x, y, id; i <= q; i++) {
		scanf("%d%d%d", &op, &x, &y);
		id = mp_idx[Point(x, y)];
		if (op == 2) {
			q_id[i] = ++cnt;
			if (!open) {
				ans[cnt] = -1;
			} else {
				ans[cnt] = 1 << 20;
				qry[n_id[id]].push_back(Point(y, i));
			}
		} else {
			open = true;
			mdf[n_id[id]].push_back(Point(y, i));
		}
	}
	cnt_q = cnt;
}

int sz[N];
Position ps[N];

void dfs1(int p, int fa) {
	sz[p] = 1;
	for (auto& e : G[p]) {
		if (!vis[e] && e != fa) {
			dfs1(e, p);
			sz[p] += sz[e];
		}
	}
}

void dfs2(int p, int fa, int all, int& g, int& Mx) {
	int mx = all - sz[p];	
	for (auto& e : G[p]) {
		if (!vis[e] && e != fa) {
			dfs2(e, p, all, g, Mx);
			mx = max(mx, sz[e]);
		}
	}
	if (mx < Mx) {
		Mx = mx;
		g = p;
	}
}

void dfs3(int p, int fa, vector<Event>& E) {
	ps[p] = ps[fa] + (nodes[p].y_seg() & nodes[fa].y_seg());
	for (auto &par : qry[p]) {
		E.push_back(Event(par.y, ps[p].pos_s(par.x), ps[p].value(par.x), 1));
	}
	for (auto &par : mdf[p]) {
		E.push_back(Event(par.y, ps[p].pos_s(par.x), ps[p].value(par.x), 2));
	}
	for (auto &e : G[p]) {
		if (!vis[e] && e != fa) {
			dfs3(e, p, E);
		}
	}
}

map<int, int> Q;
vector<Event> E;
void dividing(int p) {
	int g, Mx = 1 << 20;
	dfs1(p, 0);
	dfs2(p, 0, sz[p], g, Mx);
	vis[g] = true;
	
	E.clear();
	ps[g] = Position(nodes[g].y_seg());
	for (auto &par : qry[g]) {
		E.push_back(Event(par.y, par.x, 0, 1));
	}
	for (auto &par : mdf[g]) {
		E.push_back(Event(par.y, par.x, 0, 2));
	}
	for (auto &e : G[g]) {
		if (!vis[e]) {
			dfs3(e, g, E);
		}
	}
	
	sort(E.begin(), E.end());
	for (auto &e : E) {
		assert(nodes[g].yl <= e.y && nodes[g].yr >= e.y);
		e.y -= nodes[g].yl - 1;
	}

	int s= nodes[g].yr - nodes[g].yl + 1;
	for (int i = 1; i <= s; i++) {
		fen1[i] = fen2[i] = (1 << 20);
	}

	for (auto& e : E) {
		if (e.op == 2) {
			for (int i = e.y; i <= s; i += (i & (-i))) {
				smin(fen1[i], e.d - e.y);
			}
			for (int i = e.y; i; i -= (i & (-i))) {
				smin(fen2[i], e.d + e.y);
			}
		} else {
			int& res = ans[q_id[e.
				t]];
			for (int i = e.y; i; i -= (i & (-i))) {
				smin(res, fen1[i] + e.d + e.y);
			}
			for (int i = e.y; i <= s; i += (i & (-i))) {
				smin(res, fen2[i] + e.d - e.y);
			}
		}
	}

	for (auto& e : G[g]) {
		if (!vis[e]) {
			dividing(e);
		}
	}
}

inline void solve() {
	dividing(1);
	for (int i = 1; i <= cnt_q; i++) {
		printf("%d\n", ans[i]);
	}
}

int main() {
#ifdef local
	freopen("iqea.in", "r", stdin);
//	freopen("iqea.out", "w", stdout);
#endif
	init();
	solve();
	return 0;
}