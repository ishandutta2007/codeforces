#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

template <typename T>
boolean vmin(T& a, T b) {
	return (a > b) ? (a = b, true) : (false);
}
template <typename T>
boolean vmax(T& a, T b) {
	return (a < b) ? (a = b, true) : (false);
}

template <typename T>
T smax(T x) {
	return x;
}
template <typename T, typename ...K>
T smax(T a, const K &...args) {
	return max(a, smax(args...));
}

template <typename T>
T smin(T x) {
	return x;
}
template <typename T, typename ...K>
T smin(T a, const K &...args) {
	return min(a, smin(args...));
}

// debugging lib

#define VN(x) #x
#define Vmsg(x) VN(x) << " = " << (x)
#define printv(x) cerr << VN(x) << " = " << (x);
#define debug(...) fprintf(stderr, __VA_ARGS__);

template <typename A, typename B>
ostream& operator << (ostream& os, const pair<A, B>& z) {
	os << "(" << z.first << ", " << z.second << ')';
	return os;
}
template <typename T>
ostream& operator << (ostream& os, const vector<T>& a) {
	boolean isfirst = true;
	os << "{";
	for (auto z : a) {
		if (!isfirst) {
			os << ", ";
		}
		os << z;
		isfirst = false;
	}
	os << '}';
	return os;
}

#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define ll long long
#define ull unsigned long long

const int inf = (signed) (~0u >> 2);
const ll llf = (signed ll) (~0ull >> 2);

#define pb push_back
#define eb emplace_back
#define fi first
#define sc second

template <typename T>
int vsize(vector<T>& x) {
	return (signed) x.size(); 
}

template <typename T>
void discrete(T* a, int* b, int n) {
    vector<T> v(a + 1, a + n + 1);
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
}

const int N = 1e6 + 10;

typedef class SegTreeNode {
	public:
		ll v, tg;
		SegTreeNode *l, *r;
		
		void modify(ll dv) {
			v += dv;
			tg += dv;
		}
		void push_down() {
			if (tg) {
				l->modify(tg);
				r->modify(tg);
				tg = 0;
			}
		}
		void push_up() {
			v = max(l->v, r->v);
		}
} SegTreeNode;

typedef class SegmentTree {
	public:
		static SegTreeNode pool[N << 1];
		static SegTreeNode* top;

		static SegTreeNode* newnode() {
			top->v = top->tg = 0;
			top->l = top->r = NULL;
			return top++;
		}
		
		int n;
		SegTreeNode* rt;

		SegmentTree() : rt(NULL) {	}
		
		void build(SegTreeNode*& p, int l, int r) {
			p = newnode();
			if (l ^ r) {
				int mid = (l + r) >> 1;
				build(p->l, l, mid);
				build(p->r, mid + 1, r);
			}
		}

		void build(int n) {
			this->n = n;
			build(rt, 1, n);
		}

		void modify(SegTreeNode* p, int l, int r, int ql, int qr, int v) {
			if (l == ql && r == qr) {
				if (v == -inf) {
					p->modify(-llf);
				} else {
					p->modify(v);
				}
				return;
			}
			int mid = (l + r) >> 1;
			p->push_down();
			if (qr <= mid) {
				modify(p->l, l, mid, ql, qr, v);
			} else if (ql > mid) {
				modify(p->r, mid + 1, r, ql, qr, v);
			} else {
				modify(p->l, l, mid, ql, mid, v);
				modify(p->r, mid + 1, r, mid + 1, qr, v);
			}
			p->push_up();
		}

		void modify(int l, int r, int v) {
			(r > n) && (r = n);
			if (l > r) {
//				cerr << "Warning" << '\n';
				return;
			}
			return modify(rt, 1, n, l, r, v);
		}
		ll query() {
			return rt->v;
		}
} SegmentTree;

SegTreeNode SegmentTree :: pool[N << 1];
SegTreeNode* SegmentTree :: top = SegmentTree :: pool;

const int V = 1e6 + 3;

typedef class Event {
	public:
		int op, p, x, v;

		Event(int op, int p, int x, int v): op(op), p(p), x(x), v(v){	}

		boolean operator < (Event b) const {
			return (p ^ b.p) ? (p < b.p) : (op < b.op);
		}
} Event;

int n, m, p;
ll ans = -llf;
int b[V + 1];
vector<Event> E;
SegmentTree st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> p;
	for (int i = 1, a, ca; i <= n; i++) {
		cin >> a >> ca;
		E.eb(0, a, 0, ca);
	}
	for (int i = 1; i < V; i++)
		b[i] = inf;
	for (int i = 1, b, cb; i <= m; i++) {
		cin >> b >> cb;
		vmin(::b[b], cb);
	}
	for (int i = 1, x, y, z; i <= p; i++) {
		cin >> x >> y >> z;
		E.eb(1, x, y + 1, z);
	}
	st.build(V - 1);
	sort(E.begin(), E.end());
	for (int i = 1; i < V; i++) {
		st.modify(i, i, -b[i]);
	}
	for (auto e : E) {
		if (e.op == 0) {
			vmax(ans, -e.v + st.query());
		} else {
			st.modify(e.x, V - 1, e.v);
		}
	}
	cout << ans << '\n';
	return 0;
}