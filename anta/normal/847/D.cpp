#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }
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

	bool isNull() const { return this == &nullNode; }

	Node *set(int p) {
		left = right = &nullNode;
		pos = p;
		return update();
	}

	inline Node *update() {
		assert(!isNull());
		size = left->size + 1 + right->size;
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
};

struct RBST {
	typedef Node *Ref;
	static Ref join(Ref l, Ref r) {
		if (l->isNull()) return r;
		if (r->isNull()) return l;
		if ((int)(xor128() % (l->size + r->size)) < l->size) {
			l->propagate();
			return l->linkr(join(l->right, r));
		} else {
			r->propagate();
			return r->linkl(join(l, r->left));
		}
	}
	typedef pair<Ref, Ref> RefPair;
	static RefPair splitPos(Ref t, int pos) {
		if (t->isNull()) return RefPair(&Node::nullNode, &Node::nullNode);
		t->propagate();
		if (pos <= t->pos) {
			RefPair p = splitPos(t->left, pos);
			return RefPair(p.first, t->linkl(p.second));
		} else {
			RefPair p = splitPos(t->right, pos);
			return RefPair(t->linkr(p.first), p.second);
		}
	}
};

int main() {
	int n; int T;
	while (~scanf("%d%d", &n, &T)) {
		vector<int> ts(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &ts[i]);
		vector<Node> nodes(n);
		auto t = &Node::nullNode;
		int ans = 0;
		rep(i, n) {
			{
				int x = ts[i] - (i + 1);
				auto p = RBST::splitPos(t, x);
				nodes[i].set(max(ts[i], i + 1) - (i + 1));
				t = RBST::join(RBST::join(p.first, &nodes[i]), p.second);
			}
			{
				int y = T - (i + 1);
				auto p = RBST::splitPos(t, y);
				amax(ans, p.first->size);
				t = p.first;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}