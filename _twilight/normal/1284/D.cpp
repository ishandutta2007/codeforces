#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

// missed charactors / ?

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

const int N = 4e5 + 5;

typedef class SegTreeNode {
	public:
		ll sum, tg;
		boolean clr;
		SegTreeNode *l, *r;
		
		void modify(int L, int R, ll v) {
			sum += (R - L + 1) * v;
			tg += v;
		}
		void push_down(int L, int R, int mid) {
			if (clr) {
				l->clr = true, l->sum = l->tg = 0;
				r->clr = true, r->sum = r->tg = 0;
				clr = false;
			}
			if (tg) {
				l->modify(L, mid, tg);
				r->modify(mid + 1, R, tg);
				tg = 0;
			}
		}
		void push_up() {
			sum = l->sum + r->sum;
		}
} SegTreeNode;

typedef class SegmentTree {
	public:
		static SegTreeNode pool[N << 1];
		static SegTreeNode* top;

		static SegTreeNode* newnode() {
			top->sum = top->tg = 0;
			top->clr = false;
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

		ll query(SegTreeNode* p, int l, int r, int ql, int qr) {
			if (l == ql && r == qr) {
				return p->sum;
			}
			int mid = (l + r) >> 1;
			p->push_down(l, r, mid);
			if (qr <= mid) {
				return query(p->l, l, mid, ql, qr);
			} else if (ql > mid) {
				return query(p->r, mid + 1, r, ql, qr);
			}
			return query(p->l, l, mid, ql, mid) + query(p->r, mid + 1, r, mid + 1, qr);
		}

		void modify(SegTreeNode* p, int l, int r, int ql, int qr, int v) {
			if (l == ql && r == qr) {
				p->modify(l, r, v);
				return;
			}
			int mid = (l + r) >> 1;
			p->push_down(l, r, mid);
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

		ll query(int l, int r) {
			(r > n) && (r = n);
			if (l > r) return 0;
			return query(rt, 1, n, l, r);
		}
		void modify(int l, int r, int v) {
			(r > n) && (r = n);
			if (l > r) {
//				cerr << "Warning" << '\n';
				return;
			}
			return modify(rt, 1, n, l, r, v);
		}
		void reset() {
			rt->clr = true;
			rt->sum = rt->tg = 0;
		}
} SegmentTree;

SegTreeNode SegmentTree :: pool[N << 1];
SegTreeNode* SegmentTree :: top = SegmentTree :: pool;

typedef class Data {
	public:
		int sa, ea, sb, eb;

		void read() {
			cin >> sa >>ea >> sb >> eb;
		}
} Data;

SegmentTree st;

void work(vector<Data> a) {
	st.reset();
	vector<Data> b = a;
	sort(a.begin(), a.end(), [&] (Data a, Data b) {	return a.sa < b.sa;	});
	sort(b.begin(), b.end(), [&] (Data a, Data b) {	return a.ea < b.ea;	});
	auto pb = b.begin(), _pb = b.end();
	for (auto x : a) {
		while (pb != _pb && (*pb).ea < x.sa) {
			st.modify((*pb).sb, (*pb).eb, 1);
			pb++;
		}
		if (st.query(x.sb, x.eb)) {
			cout << "NO\n";
			exit(0);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<Data> a (n);
	vector<int> V;
	for (auto& x : a) {
		x.read();
		V.pb(x.sa), V.pb(x.ea);
		V.pb(x.sb), V.pb(x.eb);
	}
	sort(V.begin(), V.end());
	for (auto& x : a) {
		x.sa = lower_bound(V.begin(), V.end(), x.sa) - V.begin() + 1;
		x.ea = lower_bound(V.begin(), V.end(), x.ea) - V.begin() + 1;
		x.sb = lower_bound(V.begin(), V.end(), x.sb) - V.begin() + 1;
		x.eb = lower_bound(V.begin(), V.end(), x.eb) - V.begin() + 1;
	}
	st.build(V.size());
	work(a);
	for (auto &x : a)
		swap(x.sa, x.sb), swap(x.ea, x.eb);
	work(a);
	cout << "YES\n";
	return 0;
}