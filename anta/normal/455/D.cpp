#define _CRT_SECURE_NO_WARNINGS
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

unsigned xor128() {
	static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}

template<typename Derived>
struct PNodeBase {
	Derived *left, *right, *parent;
	int size;
	PNodeBase(): left(NULL), right(NULL), parent(NULL), size(1) { }
	inline Derived *update() {
		size = (!left ? 0 : left->size) + 1 + (!right ? 0 : right->size);
		return derived();
	}
	inline void propagate() { }
	inline Derived *linkl(Derived *c) {
		if(left = c) c->parent = derived();
		return derived()->update();
	}
	inline Derived *linkr(Derived *c) {
		if(right = c) c->parent = derived();
		return derived()->update();
	}
	inline Derived *linklr(Derived *l, Derived *r) {
		if(left = l) l->parent = derived();
		if(right = r) r->parent = derived();
		return derived()->update();
	}
	static inline Derived *cut(Derived *t) {
		if(t) t->parent = NULL;
		return t;
	}
private:
	inline Derived *derived() { return static_cast<Derived*>(this); }
};
struct PNode : PNodeBase<PNode> { };

template<typename Node>
struct PRBSTBase {
	typedef Node *Ref;
	static int size(Ref t) { return !t ? 0 : t->size; }
	static Ref join(Ref l, Ref r) {
		if(!l) return r;
		if(!r) return l;
		if((int)(xor128() % (l->size + r->size)) < l->size) {
			l->propagate();
			return l->linkr(join(Node::cut(l->right), r));
		}else {
			r->propagate();
			return r->linkl(join(l, Node::cut(r->left)));
		}
	}
	typedef pair<Ref,Ref> RefPair;
	static RefPair split(Ref t, int k) {
		if(!t) return RefPair((Ref)NULL, (Ref)NULL);
		t->propagate();
		int s = size(t->left);
		if(k <= s) {
			RefPair p = split(Node::cut(t->left), k);
			return RefPair(p.first, t->linkl(p.second));
		}else {
			RefPair p = split(Node::cut(t->right), k - s - 1);
			return RefPair(t->linkr(p.first), p.second);
		}
	}
	template<typename It> static Ref fromList(It b, It e) {
		int n = e - b;
		if(n == 0) return NULL;
		It m = b + n / 2;
		Ref l = fromList(b, m);
		Ref r = fromList(m+1, e);
		return (*m)->linklr(l, r);
	}
	static int rank(Ref t) {
		if(!t) return 0;
		int k = size(t->left);
		while(true) {
			Ref p = t->parent;
			if(!p) return k;
			if(p->right == t)
				k += size(p->left) + 1;
			t = p;
		}
	}
	static Ref insert(Ref t, int k, Ref n) {
		if(!t) return n;
		if(xor128() % (t->size + 1) == 0) {
			RefPair p = split(t, k);
			return n->linklr(p.first, p.second);
		}
		t->propagate();
		int s = size(t->left);
		if(k <= s)
			return t->linkl(insert(t->left, k, n));
		else
			return t->linkr(insert(t->right, k - s - 1, n));
	}
	static RefPair remove(Ref t, int k) {
		if(!t) return RefPair((Ref)NULL, (Ref)NULL);
		t->propagate();
		int s = size(t->left);
		if(k < s) {
			RefPair p = remove(Node::cut(t->left), k);
			return RefPair(t->linkl(p.first), p.second);
		}else if(k > s) {
			RefPair p = remove(Node::cut(t->right), k - s - 1);
			return RefPair(t->linkr(p.first), p.second);
		}else {
			Ref a = join(Node::cut(t->left), Node::cut(t->right));
			return RefPair(a, t->linklr(NULL, NULL));
		}
	}
	static Ref find(Ref t, int k) {
		if(!t) return NULL;
		t->propagate();
		int s = size(t->left);
		if(k < s) return find(t->left, k);
		else if(k > s) return find(t->right, k - s - 1);
		else return t;
	}
	template<typename It> static It toList(Ref t, It it) {
		if(t) {
			t->propagate();
			it = toList(t->left, it);
			*it = t; ++ it;
			it = toList(t->right, it);
		}
		return it;
	}
};
typedef PRBSTBase<PNode> PRBST;

int main() {
	//2
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, n) {
//		a[i] = xor128() % 3;
		scanf("%d", &a[i]), -- a[i];
	}
	vector<vi> indices(n);
	rep(i, n) indices[a[i]].push_back(i);

	vector<PNode> pnodes(n);
	PNode *t;
	{	vector<PNode*> v;
		rep(i, n) v.push_back(&pnodes[i]);
		t = PRBST::fromList(all(v));
	}

	vector<PNode> nodes(n);
	vector<PNode*> roots(n);
	rep(k, n) {
		vector<PNode*> v;
		each(i, indices[k])
			v.push_back(&nodes[*i]);
		roots[k] = PRBST::fromList(all(v));
	}

	int q;
	scanf("%d", &q);
	int lastans = 0;
	rep(ii, q) {
		int ty, ll, rr, kk;
		scanf("%d%d%d", &ty, &ll, &rr);
		int l = (ll + lastans - 1) % n, r = (rr + lastans - 1) % n;
//		ty = xor128() % 2 + 1; int l = xor128() % n, r = xor128() % n;
		if(l > r) swap(l, r);
		++ r;
		if(ty == 1) {
			int j, k;
			{
				pair<PNode*,PNode*> p = PRBST::split(t, l);
				pair<PNode*,PNode*> q = PRBST::split(p.second, r-l);
				pair<PNode*,PNode*> u = PRBST::split(q.first, r-l-1);
				j = u.second - &pnodes[0], k = a[j];
				t = PRBST::join(PRBST::join(p.first, u.second), PRBST::join(u.first, q.second));
			}

			{
				int x = PRBST::rank(&nodes[j]);
				int p = PRBST::rank(&pnodes[j]);
				roots[k] = PRBST::remove(roots[k], x).first;
				int l1 = 0, u1 = PRBST::size(roots[k]);
				while(u1-l1 > 0) {
					int mid = (l1 + u1) / 2;
					int y = PRBST::find(roots[k], mid) - &nodes[0];
					int q = PRBST::rank(&pnodes[y]);
					if(q < p)
						l1 = mid + 1;
					else
						u1 = mid;
				}
				roots[k] = PRBST::insert(roots[k], l1, &nodes[j]);
			}
		}else {
			scanf("%d", &kk);
			int k = (kk + lastans - 1) % n;
//			int k = xor128() % 3;
			int ans = 0;
			
			{	int l1 = 0, u1 = PRBST::size(roots[k]);
				while(u1-l1 > 0) {
					int mid = (l1 + u1) / 2;
					int y = PRBST::find(roots[k], mid) - &nodes[0];
					int q = PRBST::rank(&pnodes[y]);
					if(q < r)
						l1 = mid + 1;
					else
						u1 = mid;
				}
				ans += l1;
			}
			{	int l1 = 0, u1 = PRBST::size(roots[k]);
				while(u1-l1 > 0) {
					int mid = (l1 + u1) / 2;
					int y = PRBST::find(roots[k], mid) - &nodes[0];
					int q = PRBST::rank(&pnodes[y]);
					if(q < l)
						l1 = mid + 1;
					else
						u1 = mid;
				}
				ans -= l1;
			}
			printf("%d\n", ans);
			lastans = ans;
		}
	}
	return 0;
}