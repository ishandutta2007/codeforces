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


#ifndef _TREE_H_
#define _TREE_H_

#include <bits/stdc++.h>
using namespace std;

namespace yyf {

	typedef bool boolean;
	typedef unsigned int uint;
	
	template <typename T>
	class Pool {
		protected:
			int sz;
			T* p;
			T* top;

		public:
			Pool(int sz = 0) : sz(sz) {
				p = new T[sz];
				top = p;
			}

			T* alloc() {
				if (top == p + sz)
					return new T();
				return top++;
			}
	};

	template <typename T>
	class Treap {
		protected:

			typedef class Node {
				public:
					T v;
					int rd, sz;
					Node *fa;
					Node *l, *r;
					Node *pre, *suf;

					Node() : sz(1), fa(NULL), l(NULL), r(NULL), pre(NULL), suf(NULL) {	}

					void push_up() {
						sz = 1;
						if (l) sz += l->sz;
						if (r) sz += r->sz;
					}
					int rank(int coef = 1) const {
						int x = ((l) ? (l->sz + 1) : (1)) * coef;
						if (fa)
							x += fa->rank(this == fa->r);
						return x;
					}
			} Node;

#define pnn pair<Node*, Node*>

#define check_null(p) if (!p) return p
			Node* find_pre(Node* p) {
				check_null(p);
				if (p->l) {
					p = p->l;
					while (p->r) p = p->r;
					return p;
				}
				while (p->fa) {
					if (p->fa->r == p)
						return p->fa;
					p = p->fa;
				}
				return NULL;
			}
			Node* find_suf(Node* p) {
				check_null(p);
				if (p->r) {
					p = p->r;
					while (p->l) p = p->l;
					return p;
				}
				while (p->fa) {
					if (p->fa->l == p)
						return p->fa;
					p = p->fa;
				}
				return NULL;
			}

			void split_value(Node* p, const T& x, Node* &L, Node* &R) {
				if (!p) {
					L = R = NULL;
					return;
				}
				if (p->v <= x) {
					split_value(p->r, x, p->r, R);
					(p->r) ? (p->r->fa = p) : (0);
					L = p, p->push_up();
				} else {
					split_value(p->l, x, L, p->l);
					(p->l) ? (p->l->fa = p) : (0);
					R = p, p->push_up();
				}
			}
			pnn split_value(Node* p, const T& x) {
				pnn rt (NULL, NULL);
				split_value(p, x, rt.first, rt.second);
				return rt;
			}

			pnn split_rank(Node* p, int k) {
				if (!p) return pnn(NULL, NULL);
				p->fa = NULL;
				if (!k) return pnn(NULL, p);
				if (k >= p->sz) return pnn(p, NULL);
				pnn rt;
				int ls = ((p->l) ? (p->l->sz) : (0));
				if (ls < k) {
					rt = split_rank(p->r, k - ls - 1);
					if (rt.first) rt.first->fa = p;
					p->r = rt.first, rt.first = p;
					p->push_up();
					return rt;
				}
				rt = split_rank(p->l, k);
				if (rt.second) rt.second->fa = p;
				p->l = rt.second, rt.second = p;
				p->push_up();
				return rt;
			}

			Node* merge(Node *a, Node *b) {
				if (!a) return b;
				if (!b) return a;
				if (a->rd <= b->rd) {
					a->r = merge(a->r, b);
					a->push_up();
					if (a->r) a->r->fa = a;
					return a;
				}
				b->l = merge(a, b->l);
				b->push_up();
				if (b->l) b->l->fa = b;
				return b;
			}
		public:
			Pool<Node> pool;

			Node* alloc() {
				Node* p = pool.alloc();
				p->rd = ((uint) rand()) << 15 ^ rand();
				return p;
			}
			typedef class Iterator {
				public:
					const Node* p;

					Iterator(const Node* p) : p(p) {	}

					T operator * () {
						return p->v;
					}

					operator boolean() {
						return p != NULL;
					}
					Iterator suf() {
						return p->suf;
					}
					Iterator pre() {
						return p->pre;
					}
					int rank() {
						return p->rank();
					}
			} Iterator;

			Node* rt;

			Treap(int alloc_sz = 200000) : pool(alloc_sz) {	}

			Iterator insert(const T& x) {
				Node* p = alloc();
				p->v = x;
				pnn par = split_value(rt, x);
				par.first = merge(par.first, p);
				rt = merge(par.first, par.second);
				p->pre = find_pre(p);
				p->suf = find_suf(p);
				if (p->pre) p->pre->suf = p;
				if (p->suf) p->suf->pre = p;
				return p;
			}

			void erase(const T& x) {
				pnn a = split_value(rt, x);
				assert(a.first);
				pnn b = split_rank(a.first, a.first->sz - 1);
				assert(b.second);
				Node* p = b.second;
				if (p->pre) p->pre->suf = p->suf;
				if (p->suf) p->suf->pre = p->pre;
				rt = merge(b.first, a.second);
			}

			template <typename Tp>
			Iterator lower_bound(const Tp& x) {
				Node *p = rt, *q = NULL;
				while (p) {
					if (p->v < x) {
						p = p->r;
					} else {
						q = p, p = p->l;
					}
				}
				return q;
			}
			template <typename Tp>
			Iterator upper_bound(const Tp& x) {
				Node *p = rt, *q = NULL;
				while (p) {
					if (p->v <= x) {
						p = p->r;
					} else {
						q = p, p = p->l;
					}
				}
				return q;
			}

			Iterator find_by_rank(int k) {
				if (!rt || k <= 0 || k > rt->sz)
					return NULL; 
				Node* p = rt;
				while (p) {
					int ls = ((p->l) ? (p->l->sz) : (0));
					if (k == ls + 1) {
						return p;
					}
					if (ls < k) {
						k -= ls + 1;
						p = p->r;
					} else {
						p = p->l;
					}
				}
				assert(false);
				return NULL;
			}

			template <typename Tp>
			int rank(const Tp& x) {
				if (!rt) return 0;
				Iterator p = lower_bound(x);
				if (!p) return rt->sz + 1;
				return p ? p.rank() : 0;
			}

			int size() {
				return (rt) ? (rt->sz) : (0);
			}

			template<typename Tp>
			Iterator find_pre(const Tp& x) {
				check_null(rt);
				Iterator it = lower_bound(x);
				if (it) {
					return it.pre();
				} 
				Node* p = rt;
				while (p->r) p = p->r;
				return p;
			}
	};

}

#endif

using namespace yyf;

const int N = 2e5 + 5;

int n, m;
int a[N];
int ans[N];
vector<pii> b;
Treap<int> tr;
vector<pii> qry[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		b.eb(-a[i], i);
	cin >> m;
	for (int i = 1, k, x; i <= m; i++) {
		cin >> k >> x;
		qry[k].eb(x, i);
	}
	sort(b.begin(), b.end());
	for (int i = 1; i <= n; i++) {
		int p = b[i - 1].second;
		tr.insert(p);
		for (auto t : qry[i]) {
			int q = *tr.find_by_rank(t.first);
			ans[t.second] = a[q];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}