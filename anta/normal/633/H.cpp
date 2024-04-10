#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <array>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

unsigned long long readTimeStampCounter() {
	unsigned a = 123456789, b = 987654321;
#ifdef __GNUC__
	asm(
		"rdtsc;\n\t"
		: "=d" (a), "=a" (b)
		);
#else
	__asm {
		rdtsc;
		mov a, edx;
		mov b, eax;
	};
#endif
	return (unsigned long long)a << 32 | b;
}
unsigned xor128() {
	static unsigned x = 123456789, y = 362436069,
		z = (unsigned)(readTimeStampCounter() >> 32), w = (unsigned)readTimeStampCounter();
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}


struct GModInt {
	static int Mod;
	unsigned x;
	GModInt() : x(0) {}
	GModInt(signed sig) { int sigt = sig % Mod; if(sigt < 0) sigt += Mod; x = sigt; }
	GModInt(signed long long sig) { int sigt = sig % Mod; if(sigt < 0) sigt += Mod; x = sigt; }
	int get() const { return (int)x; }

	GModInt &operator+=(GModInt that) { if((x += that.x) >= (unsigned)Mod) x -= Mod; return *this; }
	GModInt &operator-=(GModInt that) { if((x += Mod - that.x) >= (unsigned)Mod) x -= Mod; return *this; }
	GModInt &operator*=(GModInt that) { x = (unsigned long long)x * that.x % Mod; return *this; }
	GModInt &operator/=(GModInt that) { return *this *= that.inverse(); }

	GModInt operator+(GModInt that) const { return GModInt(*this) += that; }
	GModInt operator-(GModInt that) const { return GModInt(*this) -= that; }
	GModInt operator*(GModInt that) const { return GModInt(*this) *= that; }
	GModInt operator/(GModInt that) const { return GModInt(*this) /= that; }

	//Mod
	GModInt inverse() const {
		signed a = x, b = Mod, u = 1, v = 0;
		while(b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if(u < 0) u += Mod;
		GModInt res; res.x = (unsigned)u;
		return res;
	}

	bool operator==(GModInt that) const { return x == that.x; }
	bool operator!=(GModInt that) const { return x != that.x; }
	GModInt operator-() const { GModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
int GModInt::Mod = 0;
typedef GModInt mint;

typedef array<mint, 2> ModPoly2;

ModPoly2 addpoly(const ModPoly2 &a, const ModPoly2 &b) {
	return ModPoly2{ { a[0] + b[0], a[1] + b[1] } };
}
ModPoly2 mulpoly(const ModPoly2 &a, const ModPoly2 &b) {
	mint c2 = a[1] * b[1];
	return ModPoly2{ { a[0] * b[0] + c2, a[0] * b[1] + a[1] * b[0] + c2 } };
}
ModPoly2 mulXpoly(const ModPoly2 &a) {
	return ModPoly2{ { a[1], a[0] + a[1] } };
}

vector<ModPoly2> powX;
struct Node {
	Node *left, *right;
	int size;
	int key;
	mint val;
	ModPoly2 coeffs;
	Node() : left(NULL), right(NULL), size(1) {}
	static ModPoly2 getcoeffs(const Node *p) { return !p ? ModPoly2() : p->coeffs; }
	static ModPoly2 getpowX(const Node *p) { return powX[!p ? 0 : p->size]; }
	inline Node *update() {
		size = (!left ? 0 : left->size) + 1 + (!right ? 0 : right->size);
		coeffs = addpoly(getcoeffs(left),
			mulpoly(addpoly(ModPoly2{ { val, mint() } }, mulXpoly(getcoeffs(right))),
				getpowX(left)));
		return this;
	}
	//propagateget...revgetLeft()
	inline void propagate() {}
	inline Node *linkl(Node *c) {
		left = c;
		return update();
	}
	inline Node *linkr(Node *c) {
		right = c;
		return update();
	}
	inline Node *linklr(Node *l, Node *r) {
		left = l, right = r;
		return update();
	}
};

struct RBST {
	typedef Node *Ref;
	static int size(Ref t) { return !t ? 0 : t->size; }
	static const int MaxHeight = 32 * 4;
	static Ref join(Ref l, Ref r) {
		if(!l) return r;
		if(!r) return l;
		if((int)(xor128() % (l->size + r->size)) < l->size) {
			l->propagate();
			return l->linkr(join(l->right, r));
		} else {
			r->propagate();
			return r->linkl(join(l, r->left));
		}
	}
	typedef pair<Ref, Ref> RefPair;
	static RefPair splitKey(Ref t, int key) {
		if(!t) return RefPair((Ref)NULL, (Ref)NULL);
		t->propagate();
		if(key <= t->key) {
			RefPair p = splitKey(t->left, key);
			return RefPair(p.first, t->linkl(p.second));
		} else {
			RefPair p = splitKey(t->right, key);
			return RefPair(t->linkr(p.first), p.second);
		}
	}
	static Ref insertKey(Ref t, Ref n) {
		if(!t) return n->linklr(NULL, NULL);
		if(xor128() % (t->size + 1) == 0) {
			RefPair p = splitKey(t, n->key);
			return n->linklr(p.first, p.second);
		}
		t->propagate();
		if(n->key <= t->key)
			return t->linkl(insertKey(t->left, n));
		else
			return t->linkr(insertKey(t->right, n));
	}
	static RefPair removeKey(Ref t, int key) {
		if(!t) return RefPair((Ref)NULL, (Ref)NULL);
		t->propagate();
		if(key < t->key) {
			RefPair p = removeKey(t->left, key);
			return RefPair(t->linkl(p.first), p.second);
		} else if(key > t->key) {
			RefPair p = removeKey(t->right, key);
			return RefPair(t->linkr(p.first), p.second);
		} else {
			Ref a = join(t->left, t->right);
			return RefPair(a, t->linklr(NULL, NULL));
		}
	}
};

vector<int> sqrtSort(const vector<pair<int, int> > &q, const int S) {
	int n = q.size();
	vector<long long> pack(n);
	for(int i = 0; i < n; i ++) {
		pack[i] =
			(long long)(q[i].first / S) << 50 |
			(long long)((q[i].first / S & 1) == 0 ? q[i].second : (1 << 25) - 1 - q[i].second) << 25 |
			i;
	}
	sort(all(pack));
	vector<int> res(n);
	for(int i = 0; i < n; i ++)
		res[i] = pack[i] & ((1 << 25) - 1);
	return res;
}

vector<Node*> freeNodes;
map<int, int> curCnt;
Node *root;
void insertEntry(int a) {
	if(++ curCnt[a] == 1) {
		Node *node = new(freeNodes.back()) Node();
		freeNodes.pop_back();
		node->key = a;
		node->val = a;
		node->update();
		root = RBST::insertKey(root, node);
	}
}
void removeEntry(int a) {
	if(-- curCnt[a] == 0) {
		auto p = RBST::removeKey(root, a);
		root = p.first;
		freeNodes.push_back(p.second);
	}
}

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		mint::Mod = m;
		vector<int> a(n);
		for(int i = 0; i < n; ++ i) {
			scanf("%d", &a[i]);
//			a[i] = rand() % 100000;
		}
		int q;
		scanf("%d", &q);
		vpii queries(q);
		rep(i, q) {
			int l; int r;
			scanf("%d%d", &l, &r), -- l, -- r;
//			l = rand() % n, r = rand() % n; if(l > r)swap(l, r);
			queries[i] = { l, r };
		}
		powX.resize(n + 1);
		powX[0] = ModPoly2{ {1, 0} };
		rep(i, n)
			powX[i + 1] = mulXpoly(powX[i]);
		vi ord = sqrtSort(queries, 200);
		curCnt.clear();
		root = NULL;
		vector<Node> nodes(n);
		freeNodes.clear();
		rep(i, n) freeNodes.push_back(&nodes[i]);
		vector<mint> ans(q);
		for(int ii = 0, L = 0, R = -1; ii < q; ii ++) {
			int q = ord[ii];
			int qL = queries[q].first, qR = queries[q].second;
			while(R < qR) {
				R ++;
				insertEntry(a[R]);
			}
			while(L > qL) {
				L --;
				insertEntry(a[L]);
			}
			while(R > qR) {
				removeEntry(a[R]);
				R --;
			}
			while(L < qL) {
				removeEntry(a[L]);
				L ++;
			}
			ans[q] = root->coeffs[0] + root->coeffs[1];
		}
		for(int i = 0; i < q; ++ i)
			printf("%d\n", ans[i].get());
	}
	return 0;
}