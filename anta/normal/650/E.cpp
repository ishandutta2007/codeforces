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


struct Val {
	int pos;
	Val() : pos(-1) {}
	explicit Val(int pos) : pos(pos) {}
};
struct Sum {
	int pos;
	Sum() : pos(-1) {}
	Sum(const Val &val) : pos(val.pos) {}
	Sum &operator+=(const Sum &that) { amax(pos, that.pos); return *this; }
	Sum operator+(const Sum &that) const { return Sum(*this) += that; }
};

struct Node {
private:
	Node *parent, *left, *right;
	Val val; Sum sum;
	bool rev;

public:
	Node() : parent(NULL), left(NULL), right(NULL),
		val(), sum(Val()), rev(false) {
	}

private:
	bool is_root() const {
		return !parent || (parent->left != this && parent->right != this);
	}
	void update() {
		sum = Sum(val);
		if(left) {
			left->propagate();
			sum += left->sum;
		}
		if(right) {
			right->propagate();
			sum += right->sum;
		}
	}
	void propagate() {
		if(rev) {
			if(left) left->rev = !left->rev;
			if(right) right->rev = !right->rev;
			swap(left, right);
			rev = false;
		}
	}

private:
	void rotateR() {
		Node *q = parent, *r = q->parent;
		if(q->left = right) right->parent = q;
		right = q; q->parent = this;
		if(parent = r) {
			if(r->left == q) r->left = this;
			else if(r->right == q) r->right = this;
		}
	}
	void rotateL() {
		Node *q = parent, *r = q->parent;
		if(q->right = left) left->parent = q;
		left = q; q->parent = this;
		if(parent = r) {
			if(r->left == q) r->left = this;
			else if(r->right == q) r->right = this;
		}
	}

	static void global_topdown(Node *a) {
		Node *r = a, *q = a->parent;
		while(q != NULL) {
			Node *p = q;
			q = p->parent;
			p->parent = r;
			r = p;
		}
		while(r != a) {
			Node *c = r->parent;
			r->parent = q;
			q = r;
			r->propagate();
			r = c;
		}
		a->propagate();
	}

	static void splay(Node *a, bool nolastupdate = false) {
		if(a->is_root()) return;
		while(1) {
			Node *p = a->parent;
			bool plr = p->right == a;
			if(p->is_root()) {
				if(!plr) a->rotateR(), a->right->update();
				else a->rotateL(), a->left->update();
				break;
			} else {
				Node *g = p->parent;
				bool glr = g->right == p;
				bool groot = g->is_root();
				if(plr == glr) {
					if(!plr) p->rotateR(), a->rotateR(), p->right->update();
					else p->rotateL(), a->rotateL(), p->left->update();
					p->update();
				} else {
					if(!plr) a->rotateR(), a->rotateL();
					else a->rotateL(), a->rotateR();
					a->left->update();
					a->right->update();
				}
				if(groot) break;
			}
		}
		if(!nolastupdate) a->update();
	}

public:
	void setVal(const Val &val_) {
		assert(is_root());
		val = val_;
		update();
	}
	Val getVal() const {
		assert(is_root());
		return val;
	}
	Sum getSum() const {
		assert(is_root());
		return sum;
	}

private:
	static Node *pathHead(Node *a) {
		Node *h = a;
		while(1) {
			Node *c = h->left;
			if(!c) break;
			c->propagate();
			h = c;
		}
		splay(h);
		return h;
	}

	static void splitPath(Node *a) {
		Node *r = a->right;
		if(r != NULL) {
			a->right = NULL;
			a->update();
		}
	}

public:
	static void expose(Node *a) {
		global_topdown(a);
		Node *rp = NULL;
		for(Node *p = a; p != NULL; p = p->parent) {
			splay(p, true);
			p->right = rp;
			p->update();
			rp = p;
		}
		splay(a);
	}

	static bool exposePath(Node *a, Node *b) {
		evert(a);
		a->propagate();
		expose(b);
		if(a != b && a->parent == NULL)
			return false;
		splitPath(b);
		return true;
	}

	static void evert(Node *x) {
		expose(x);
		splitPath(x);
		x->rev = true;
	}
	static void connect(Node *x, Node *y) {
		evert(x);
		x->parent = y;
	}
	static void cut(Node *c) {
		expose(c);
		Node *p = c->left;
		assert(p);
		c->left = NULL;
		c->update();
		p->parent = NULL;
	}
};

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<Node> nodes(n), edges(n - 1);
		map<pii,int> orgEdges;
		vpii edgePairs(n - 1);
		rep(i, n - 1) {
			int x; int y;
			scanf("%d%d", &x, &y), -- x, -- y;
			if(x > y) swap(x, y);
			orgEdges[mp(x, y)] = i;
			edges[i].setVal(Val(i));
			Node::connect(&nodes[x], &edges[i]);
			Node::connect(&edges[i], &nodes[y]);
			edgePairs[i] = mp(x, y);
		}
		vector<vector<int>> ans;
		vpii queries;
		rep(ii, n - 1) {
			int x; int y;
			scanf("%d%d", &x, &y), -- x, -- y;
			if(x > y) swap(x, y);
			if(orgEdges.count(mp(x, y))) {
				int i = orgEdges[mp(x, y)];
				Node::expose(&edges[i]);
				edges[i].setVal(Val(-1));
			} else {
				queries.emplace_back(x, y);
			}
		}
		for(auto q : queries) {
			int x, y;
			tie(x, y) = q;
			Node::exposePath(&nodes[x], &nodes[y]);
			int i = nodes[y].getSum().pos;
			assert(i != -1);
			int a, b; tie(a, b) = edgePairs[i];
			Node::evert(&nodes[a]);
			Node::cut(&edges[i]);
			Node::evert(&nodes[b]);
			Node::cut(&edges[i]);
			edges[i].setVal(Val(-1));
			Node::connect(&nodes[x] , &edges[i]);
			Node::connect(&edges[i], &nodes[y]);
			ans.push_back({a, b, x, y});
		}
		printf("%d\n", (int)ans.size());
		for(const auto &v : ans) {
			for(int i = 0; i < 4; ++ i) {
				if(i != 0) putchar(' ');
				printf("%d", v[i] + 1);
			}
			puts("");
		}
	}
	return 0;
}