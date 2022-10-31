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


struct Node {
	static const int K = 3;
	static Node nullNode;

	Node *left, *right;
	int size;
	int pos;
	int val, sum;

	bool isNull() const { return this == &nullNode; }

	Node *set(int p, int v) {
		left = right = &nullNode;
		pos = p;
		val = v;
		return update();
	}

	inline Node *update() {
		assert(!isNull());
		size = left->size + 1 + right->size;
		sum = left->sum + val + right->sum;
		return this;
	}
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
Node Node::nullNode = {
	&nullNode, &nullNode,
	0, -1,
	0, 0
};

struct RBST {
	typedef Node *Ref;
	static const int MaxHeight = 32 * 4;
	static Ref join(Ref l, Ref r) {
		if(l->isNull()) return r;
		if(r->isNull()) return l;
		if((int)(xor128() % (l->size + r->size)) < l->size) {
			l->propagate();
			return l->linkr(join(l->right, r));
		} else {
			r->propagate();
			return r->linkl(join(l, r->left));
		}
	}
	typedef pair<Ref, Ref> RefPair;
	static RefPair splitRemovePos(Ref t, int pos, bool remove) {
		if(t->isNull()) return RefPair(&Node::nullNode, &Node::nullNode);
		t->propagate();
		if(pos == t->pos && remove) {
			Node *l = t->left, *r = t->right;
			*t = Node::nullNode;
			return RefPair(l, r);
		} else if(pos <= t->pos) {
			RefPair p = splitRemovePos(t->left, pos, remove);
			return RefPair(p.first, t->linkl(p.second));
		} else {
			RefPair p = splitRemovePos(t->right, pos, remove);
			return RefPair(t->linkr(p.first), p.second);
		}
	}
	static Ref insertPos(Ref t, Ref n) {
		if(xor128() % (t->size + 1) == 0 || n->pos == t->pos) {
			RefPair p = splitRemovePos(t, n->pos, true);
			return n->linklr(p.first, p.second);
		}
		t->propagate();
		if(n->pos < t->pos)
			return t->linkl(insertPos(t->left, n));
		else
			return t->linkr(insertPos(t->right, n));
	}
};

int main() {
	rep(k, 100) xor128();
	int Q;
	while(~scanf("%d", &Q)) {
		map<int, int> valID;
		vector<Node> nodes(Q);
		vector<Node*> seqs(Q, &Node::nullNode);
		for(int i = 0; i < Q; ++ i) {
			int ty;
			scanf("%d", &ty);
			int t; int x;
			scanf("%d%d", &t, &x);
			int k = valID.emplace(x, valID.size()).first->second;
			if(ty == 1) {
				Node *a = &nodes[i];
				a->set(t, 1);
				seqs[k] = RBST::insertPos(seqs[k], a);
			} else if(ty == 2) {
				Node *a = &nodes[i];
				a->set(t, -1);
				seqs[k] = RBST::insertPos(seqs[k], a);
			} else if(ty == 3) {
				auto p = RBST::splitRemovePos(seqs[k], t, false);
				int ans = p.first->sum;
				seqs[k] = RBST::join(p.first, p.second);
				printf("%d\n", ans);
			} else abort();
		}
	}
	return 0;
}