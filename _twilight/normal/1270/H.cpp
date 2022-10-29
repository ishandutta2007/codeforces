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
void discrete(T* a, int* b, int n) {
    vector<T> v(a + 1, a + n + 1);
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
}

typedef class Input {
	protected:
		const static int limit = 65536;
		FILE* file; 

		int ss, st;
		char buf[limit];
	public:
		
		Input() : file(NULL)	{	};
		Input(FILE* file) : file(file) {	}

		void open(FILE *file) {
			this->file = file;
		}

		void open(const char* filename) {
			file = fopen(filename, "r");
		}

		char pick() {
			if (ss == st)
				st = fread(buf, 1, limit, file), ss = 0;//, cerr << "str: " << buf << "ed " << st << endl;
			return (ss == st) ? (-1) : (buf[ss++]);
		}
} Input;

#define digit(_x) ((_x) >= '0' && (_x) <= '9')

Input& operator >> (Input& in, unsigned& u) {
	char x;
	while (~(x = in.pick()) && !digit(x));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	return in;
}

Input& operator >> (Input& in, unsigned long long& u) {
	char x;
	while (~(x = in.pick()) && !digit(x));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	return in;
}

Input& operator >> (Input& in, int& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	u *= aflag;
	return in;
}

Input& operator >> (Input& in, long long& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	u *= aflag;
	return in;
}

Input& operator >> (Input& in, double& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	if (x == '.') {
		double dec = 1;
		for ( ; ~(x = in.pick()) && digit(x); u = u + (dec *= 0.1) * (x - '0'));
	}
	u *= aflag;
	return in;
}

Input& operator >> (Input& in, char* str) {
	char x;
	while (~(x = in.pick()) && x != '\n' && x != ' ')
		*(str++) = x;
	*str = 0;
	return in;
}

Input in (stdin);

typedef class Output {
	protected:
		const static int Limit = 65536;
		char *tp, *ed;
		char buf[Limit];
		FILE* file;
		int precision;

		void flush() {
			fwrite(buf, 1, tp - buf, file);
			fflush(file);
			tp = buf;
		}

	public:

		Output() {	}
		Output(FILE* file) : tp(buf), ed(buf + Limit), file(file), precision(6) {	}
		Output(const char *str) : tp(buf), ed(buf + Limit), precision(6) {
			file = fopen(str, "w");
		}
		~Output() {
			flush();
		}

		void put(char x) {
			if (tp == ed)
				flush();
			*(tp++) = x;
		}

		int get_precision() {
			return precision;
		}
		void set_percision(int x) {
			precision = x;
		}
} Output;

Output& operator << (Output& out, int x) {
	static char buf[35];
	static char * const lim = buf + 34;
	if (!x)
		out.put('0');
	else {
		if (x < 0)
			out.put('-'), x = -x;
		char *tp = lim;
		for ( ; x; *(--tp) = x % 10, x /= 10);
		for ( ; tp != lim; out.put(*(tp++) + '0'));
	}
	return out;
}

Output& operator << (Output& out, long long x) {
	static char buf[36];
	static char * const lim = buf + 34;
	if (!x)
		out.put('0');
	else {
		if (x < 0)
			out.put('-'), x = -x;
		char *tp = lim;
		for ( ; x; *(--tp) = x % 10, x /= 10);
		for ( ; tp != lim; out.put(*(tp++) + '0'));
	}
	return out;
}

Output& operator << (Output& out, unsigned x) {
	static char buf[35];
	static char * const lim = buf + 34;
	if (!x)
		out.put('0');
	else {
		char *tp = lim;
		for ( ; x; *(--tp) = x % 10, x /= 10);
		for ( ; tp != lim; out.put(*(tp++) + '0'));
	}
	return out;
}

Output& operator << (Output& out, char x)  {
	out.put(x);
	return out;
}

Output& operator << (Output& out, const char* str) {
	for ( ; *str; out.put(*(str++)));
	return out;
}

Output& operator << (Output& out, double x) {
	int y = x;
	x -= y;
	out << y << '.';
	for (int i = out.get_precision(); i; i--, y = x * 10, x = x * 10 - y, out.put(y + '0'));
	return out;
}

Output out (stdout);

const int N = 1e6 + 5;

pii operator + (pii a, pii b) {
	if (a.fi ^ b.fi) {
		return min(a, b);
	}
	a.sc += b.sc;
	return a;
}

typedef class SegTreeNode {
	public:
		pii v;
		int tg;
		bool enable;
		SegTreeNode *l, *r;
		
		void upd(int d) {
			v.first += d;
			tg += d;
		}
		void push_down() {
			if (tg) {
				l->upd(tg);
				r->upd(tg);
				tg = 0;
			}
		}
		void push_up() {
			v = pii(N, 0);
			if (l->enable) {
				v = l->v;
			}
			if (r->enable) {
				v = v + r->v;
			}
		}
} SegTreeNode;

typedef class SegmentTree {
	public:
		static SegTreeNode pool[N << 1];
		static SegTreeNode* top;

		static SegTreeNode* newnode() {
			top->l = top->r = NULL;
			return top++;
		}
		
		int n;
		SegTreeNode* rt;

		SegmentTree() : rt(NULL) {	}
		
		void build(SegTreeNode*& p, int l, int r) {
			p = newnode();
			p->enable = true;
			if (l ^ r) {
				int mid = (l + r) >> 1;
				build(p->l, l, mid);
				build(p->r, mid + 1, r);
				p->push_up();
			} else {
				p->enable = false;
				p->v = pii(0, 1);
			}
		}

		void build(int n) {
			this->n = n;
			build(rt, 1, n);
		}

		int query() {
			pii x = rt->v;
			assert(x.fi == 0);
			return x.sc;
		}

		void modify(SegTreeNode* p, int l, int r, int ql, int qr, int v) {
			if (l == ql && r == qr) {
				p->upd(v);
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
			return modify(rt, 1, n, l, r, v);
		}

		void modify(SegTreeNode* p, int l, int r, int idx, bool val) {
			if (l == r) {
				p->enable = val;
				return;
			}
			int mid = (l + r) >> 1;
			p->push_down();
			if (idx <= mid) {
				modify(p->l, l, mid, idx, val);
			} else {
				modify(p->r, mid + 1, r, idx, val);
			}
			p->push_up();
		}
		void enable(int p) {
			modify(rt, 1, n, p, true);
		}
		void disable(int p) {
			modify(rt, 1, n, p, false);
		}
} SegmentTree;

SegTreeNode SegmentTree :: pool[N << 1];
SegTreeNode* SegmentTree :: top = SegmentTree :: pool;

int n, q;
vector<int> a;
SegmentTree st;

void update(int p, int sgn) {
	if (p <= n && a[p - 1] < a[p]) {
		st.modify(a[p - 1], a[p] - 1, sgn);
	}
}

int main() {
	in >> n >> q;
	a.resize(n + 1);
	st.build(1000001);
	a[0] = 1000001;
	for (int i = 1; i <= n; i++) {
		in >> a[i];
		st.enable(a[i]);
		update(i, 1);
	}
	int x, y;
	while (q--) {
		in >> x >> y;
		st.disable(a[x]);
		update(x, -1);
		update(x + 1, -1);
		a[x] = y;
		st.enable(y);
		update(x, 1);
		update(x + 1, 1);
		out << st.query() << '\n';
	}
	return 0;
}