
#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

typedef class Node {
	public:
		int v;
		Node *pre, *suf;
		
		Node() : v(0), pre(NULL), suf(NULL) {	}
		Node(int v) : v(v), pre(NULL), suf(NULL) {	}

		int operator * () {
			return v;
		}
		void destroy() {
			if (pre)
				pre->suf = suf;
			if (suf)
				suf->pre = pre;	
		}
} Node;

int Limit;
Node *pool;
Node *_top = pool;

Node* newnode() {
	return (_top == pool + Limit) ? (new Node(0)) : (_top++);
}

Node* append(Node* p, int v) {
	Node* np = newnode();
	np->v = v;
	if (p)
		p->suf = np;
	np->pre = p;
	return np;
}

typedef class List {
	public:
		Node *st, *ed;
		
		List() : st(NULL), ed(NULL) {	}

		void append(int v) {
			ed = ::append(ed, v);
			if (!st)
				st = ed;
		}
		void destroy(Node* p) {
			if (p == st)
				st = st->suf;
			if (p == ed)
				ed = ed->pre;
			p->destroy();
		}
		List copy() {
			List rt;
			for (Node *p = st; p; p = p->suf) {
				rt.append(**p);
			}
			return rt;
		}
} List;

int n, m;
int dfc;
int id[N];
int x1[N], y1[N], x2[N], y2[N];

vector<int> get(Node* st, Node* ed) {
	vector<int> rt;
	++dfc;
	while (st != ed) {
		id[**st] = dfc;
		rt.push_back(**st);
		st = st->suf;
	}
	return rt;
}

Node* fix(Node* &p, List& l, int x) {
	while (p && id[**p] != x)
		l.destroy(p), p = p->suf;
	return p;
}

#define build_list(vec, list) \
	for (auto x : vec) \
		list.append(x);

void build(vector<int> a, List& A, List& B, List& C, List& D) {
	vector<int> b, c, d;
	b = c = d = a;
	sort(a.begin(), a.end(), [&] (int a, int b) {
				return x1[a] < x1[b];
			});
	sort(b.begin(), b.end(), [&] (int a, int b) {
				return x2[a] > x2[b];
			});
	sort(c.begin(), c.end(), [&] (int a, int b) {
				return y1[a] < y1[b];
			});
	sort(d.begin(), d.end(), [&] (int a, int b) {
				return y2[a] > y2[b];
			});
	build_list(a, A);
	build_list(b, B);
	build_list(c, C);
	build_list(d, D);
}

boolean solve(int p, List xL, List xR, List yL, List yR) {
	int sz = 0;
	List A, B, C, _D;
	vector<int> tmp;
	int L = -1, R = -1, U = -1, D = -1;
	Node* pxl = xL.st, *pxr = xR.st, *pyl = yL.st, *pyr = yR.st;
	while (fix(pxl, xL, p) && fix(pxr, xR, p) && fix(pyl, yL, p) && fix(pyr, yR, p)) {
		sz++;
		if (pxl) {
			if (R == -1) {
				R = x2[**pxl];
			} else {
				if (x1[**pxl] >= R) {
					tmp = get(xL.st, pxl);
					build(tmp, A, B, C, _D);
					return solve(dfc, A, B, C, _D) && solve(p, xL, xR, yL, yR);
				}
				R = max(R, x2[**pxl]);
			}
			pxl = pxl->suf;
		}
		if (pxr) {
			if (L == -1) {
				L = x1[**pxr];
			} else {
				if (x2[**pxr] <= L) {
					tmp = get(xR.st, pxr);
					build(tmp, A, B, C, _D);
					return solve(dfc, A, B, C, _D) && solve(p, xL, xR, yL, yR);
				}
				L = min(L, x1[**pxr]);
			}
			pxr = pxr->suf;
		}
		if (pyl) {
			if (D == -1) {
				D = y2[**pyl];
			} else {
				if (y1[**pyl] >= D) {
					tmp = get(yL.st, pyl);
					build(tmp, A, B, C, _D);
					return solve(dfc, A, B, C, _D) && solve(p, xL, xR, yL, yR);
				}
				D = max(D, y2[**pyl]);
			}
			pyl = pyl->suf;
		}
		if (pyr) {
			if (U == -1) {
				U = y1[**pyr];
			} else {
				if (y2[**pyr] <= U) {
					tmp = get(yR.st, pyr);
					build(tmp, A, B, C, _D);
					return solve(dfc, A, B, C, _D) && solve(p, xL, xR, yL, yR);
				}
				U = min(U, y1[**pyr]);
			}
			pyr = pyr->suf;
		}
	}
	return sz == 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
	}
	Limit = 80 * n;
	pool = new Node[Limit + 5];
	_top = pool;
	List A, B, C, D;
	vector<int> a;	
	a.resize(n);
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	build(a, A, B, C, D);
	boolean ans = solve(0, A, B, C, D);
	puts((ans) ? ("YES") : ("NO"));
	return 0;
}