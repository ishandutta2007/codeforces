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
int discrete(T* a, int* b, int n) {
    vector<T> v(a + 1, a + n + 1);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; i++) b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	return v.size();
}

mt19937 rng (time(NULL));

int randint(int l, int r) {
	return rng() % (r - l + 1) + l;
}

const int N = 6e5 + 4;

typedef class Data {
	public:
		int sum, mi;
		
		Data() {	}
		Data(int sum, int mi) : sum(sum), mi(mi) {	}

		Data operator + (Data b) const {
			Data rt;
			rt.sum = sum + b.sum;
			rt.mi = max(mi + b.sum, b.mi);
			return rt;
		}
} Data;

typedef class SegTreeNode {
	public:
		Data d;
		SegTreeNode *l, *r;
		
		void push_up() {
			d = l->d + r->d;
		}
} SegTreeNode;

typedef class SegmentTree {
	public:
		static SegTreeNode pool[N << 1];
		static SegTreeNode* top;

		static SegTreeNode* newnode() {
			top->d = Data(0, 0);
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

		Data query(SegTreeNode* p, int l, int r, int ql, int qr) {
			if (l == ql && r == qr) {
				return p->d;
			}
			int mid = (l + r) >> 1;
			if (qr <= mid) {
				return query(p->l, l, mid, ql, qr);
			} else if (ql > mid) {
				return query(p->r, mid + 1, r, ql, qr);
			}
			return query(p->l, l, mid, ql, mid) + query(p->r, mid + 1, r, mid + 1, qr);
		}

		void modify(SegTreeNode* p, int l, int r, int idx, Data v) {
			if (l == r) {
				p->d = v;
				return;
			}
			int mid = (l + r) >> 1;
			if (idx <= mid) {
				modify(p->l, l, mid, idx, v);
			} else {
				modify(p->r, mid + 1, r, idx, v);
			}
			p->push_up();
		}
		
		Data query(int l, int r) {
			return query(rt, 1, n, l, r);
		}
		void modify(int idx, Data v) {
			return modify(rt, 1, n, idx, v);
		}
} SegmentTree;

SegTreeNode SegmentTree :: pool[N << 1];
SegTreeNode* SegmentTree :: top = SegmentTree :: pool;

int n;
SegmentTree st;
vector<int> p, q, pos;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	p.resize(n + 1);
	q.resize(n + 1);
	pos.resize(n + 1);
	st.build(n << 1);
	int ans = n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> q[i];
	}
	st.modify((pos[n] << 1) - 1, Data(1, 1));
	for (int i = 0; i < n; i++) {
		if (i) {
			st.modify(q[i] << 1, Data(-1, -1));
		}
		while (ans > 1 && st.query(1, n << 1).mi <= 0) {
			ans--;
			st.modify((pos[ans] << 1) - 1, Data(1, 1));
		}
		cout << ans << " ";
	}
	return 0;
}