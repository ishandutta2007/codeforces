#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

unsigned xor128() {
	static unsigned x = 123456789, y = 362436069, z = random_device{}(), w = random_device{}();
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}

struct Node {
	static Node nullNode;

	unsigned priority;
	Node *left, *right;
	int size;
	int pos;
	int val;
	int addPos;
	int addVal;

	bool isNull() const { return priority == 0; }

	Node *set(int p, int v) {
		*this = nullNode;
		do priority = xor128(); while(priority == 0);
		pos = p;
		val = v;
		return update();
	}

	inline Node *update() {
		assert(!isNull());
		size = left->size + 1 + right->size;
		return this;
	}
	inline void propagate() {
		if(addPos != 0 || addVal != 0) {
			pos += addPos;
			val += addVal;
			if(!left->isNull()) {
				left->addPos += addPos;
				left->addVal += addVal;
			}
			if(!right->isNull()) {
				right->addPos += addPos;
				right->addVal += addVal;
			}
			addPos = 0;
			addVal = 0;
		}
	}
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
	inline Node *linkl2(Node *c) {
		if(priority >= c->priority)
			return linkl(c);
		else
			return c->linkr(linkl(c->right));
	}
	inline Node *linkr2(Node *c) {
		if(priority >= c->priority)
			return linkr(c);
		else
			return c->linkl(linkr(c->left));
	}
};
Node Node::nullNode = {
	0,
	&nullNode, &nullNode,
	0, -1,
	0,
	0, 0
};

struct RBST {
	typedef Node *Ref;
	static Ref join(Ref l, Ref r) {
		if(l->isNull()) return r;
		if(r->isNull()) return l;
		if(l->priority >= r->priority) {
			l->propagate();
			return l->linkr(join(l->right, r));
		} else {
			r->propagate();
			return r->linkl(join(l, r->left));
		}
	}
	typedef pair<Ref, Ref> RefPair;
	static RefPair splitPos(Ref t, int pos) {
		if(t->isNull()) return RefPair(&Node::nullNode, &Node::nullNode);
		t->propagate();
		if(pos <= t->pos) {
			RefPair p = splitPos(t->left, pos);
			return RefPair(p.first, t->linkl(p.second));
		} else {
			RefPair p = splitPos(t->right, pos);
			return RefPair(t->linkr(p.first), p.second);
		}
	}
	static Ref insertPos(Ref t, Ref n) {
		if(t->isNull()) return n;
		t->propagate();
		if(n->pos <= t->pos)
			return t->linkl2(insertPos(t->left, n));
		else
			return t->linkr2(insertPos(t->right, n));
	}
	static void decompose(Ref t, vector<Ref> &res) {
		if(t->isNull()) return;
		t->propagate();
		Ref l = t->left, r = t->right;
		t->left = t->right = &Node::nullNode;
		decompose(l, res);
		res.push_back(t);
		decompose(r, res);
	}
};

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vpii shirts(n);
		rep(i, n) {
			int c; int q;
			scanf("%d%d", &c, &q);
			shirts[i] = { -q, c };
		}
		sort(shirts.begin(), shirts.end());
		int q;
		scanf("%d", &q);
		vector<Node> nodes(q);
		for(int i = 0; i < q; ++ i) {
			int b;
			scanf("%d", &b);
			nodes[i].set(b, 0);
		}
		Node *t = &Node::nullNode;
		rep(i, q)
			t = RBST::insertPos(t, &nodes[i]);
		vector<Node*> list;
		list.reserve(q);
		for(auto s : shirts) {
			int c = s.second;
			Node *l, *m, *r;
			tie(l, r) = RBST::splitPos(t, c);
			if(!r->isNull()) {
				r->addPos -= c;
				r->addVal += 1;
			}1;
			tie(m, r) = RBST::splitPos(r, c);
			list.clear();
			RBST::decompose(m, list);
			for(auto x : list)
				l = RBST::insertPos(l, x);
			t = RBST::join(l, r);
		}
		list.clear();
		RBST::decompose(t, list);
		for(int i = 0; i < q; ++ i) {
			if(i != 0) putchar(' ');
			int ans = nodes[i].val;
			printf("%d", ans);
		}
		puts("");
	}
	return 0;
}