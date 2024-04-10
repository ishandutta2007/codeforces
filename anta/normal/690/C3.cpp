#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }


struct Node {
	typedef int Weight;
	typedef int WeightSum;

	Node *pathLeft, *pathRight;			//path tree
	Node *siblingLeft, *siblingRight;	//sibling tree
	Node *topChild;						//path treesibling tree
	Node *parent;						//path/sibling treep
	Weight weight;							//_
	WeightSum pathWeightSum;			//path-local
	WeightSum maxDistLeft, maxDistRight;		//pX[EE[_
	WeightSum maxDistSibling;				//sibling treepXl

	Node()
		: pathLeft(NULL), pathRight(NULL)
		, siblingLeft(NULL), siblingRight(NULL)
		, topChild(NULL), parent(NULL)
		, weight(0), pathWeightSum(0)
		, maxDistLeft(0), maxDistRight(0)
		, maxDistSibling(0) {
	}

	inline Node *&path(bool lr) { return !lr ? pathLeft : pathRight; }
	inline Node *&sibling(bool lr) { return !lr ? siblingLeft : siblingRight; }
	inline Node *&child(bool ps, bool lr) { return !ps ? path(lr) : sibling(lr); }

	static WeightSum getNodePathWeightSum(const Node *a) {
		return a->pathWeightSum;
	}

	static WeightSum getNodeMaxDistLR(const Node *a, bool lr) {
		return !lr ? a->maxDistLeft : a->maxDistRight;
	}
	static WeightSum getNodeMaxDistSibling(const Node *a) {
		return a->maxDistSibling;
	}

	static inline void assignMax(WeightSum &x, WeightSum y) {
		if(x < y) x = y;
	}

	void treeUpdate() {
		Node *a = this;
		WeightSum treeWeightSum = a->weight;

		WeightSum leftSum = a->weight + (a->pathLeft != NULL ? a->pathLeft->pathWeightSum : 0);
		WeightSum rightSum = a->weight + (a->pathRight != NULL ? a->pathRight->pathWeightSum : 0);
		WeightSum maxDistLeft = leftSum, maxDistRight = rightSum;
		WeightSum maxDistSibling = 0;

		if(a->pathLeft) {
			assignMax(maxDistLeft, getNodeMaxDistLR(a->pathLeft, false));
			assignMax(maxDistRight, rightSum + getNodeMaxDistLR(a->pathLeft, true));
		}
		if(a->pathRight) {
			assignMax(maxDistLeft, leftSum + getNodeMaxDistLR(a->pathRight, false));
			assignMax(maxDistRight, getNodeMaxDistLR(a->pathRight, true));
		}
		if(a->topChild) {
			WeightSum childrenMaxDist = getNodeMaxDistSibling(a->topChild);
			assignMax(maxDistLeft, leftSum + childrenMaxDist);
			assignMax(maxDistRight, rightSum + childrenMaxDist);
		}
		if(a->siblingLeft) {
			assignMax(maxDistSibling, getNodeMaxDistSibling(a->siblingLeft));
		}
		if(a->siblingRight) {
			assignMax(maxDistSibling, getNodeMaxDistSibling(a->siblingRight));
		}

		a->maxDistLeft = maxDistLeft;
		a->maxDistRight = maxDistRight;

		assignMax(maxDistSibling, maxDistLeft);
		a->maxDistSibling = maxDistSibling;
	}

	void pathAndTreeUpdate() {
		Node *a = this;
		WeightSum pathWeightSum = a->weight;
		if(a->pathLeft) {
			pathWeightSum += getNodePathWeightSum(a->pathLeft);
		}
		if(a->pathRight) {
			pathWeightSum += getNodePathWeightSum(a->pathRight);
		}
		a->pathWeightSum = pathWeightSum;

		a->treeUpdate();
	}
};

class DynamicTree {
private:
	static inline bool isLocalRoot(const Node *a, bool ps) {
		return !a->parent || (a->parent->child(ps, false) != a && a->parent->child(ps, true) != a);
	}

	static void updateNode(Node *a, bool ps) {
		if(!ps) a->pathAndTreeUpdate();
		else a->treeUpdate();
	}

	//updaterotate
	static void rotate(Node *a, bool ps, bool lr) {
		Node *p = a->parent, *g = p->parent, *c = a->child(ps, lr);
		if(p->child(ps, !lr) = c) c->parent = p;
		a->child(ps, lr) = p; p->parent = a;
		if(a->parent = g) {
			if(g->pathLeft == p) g->pathLeft = a;
			else if(g->pathRight == p) g->pathRight = a;
			else if(g->topChild == p) g->topChild = a;
			else if(g->siblingLeft == p) g->siblingLeft = a;
			else if(g->siblingRight == p) g->siblingRight = a;
		}
	}

	//siblingN
	static void moveSiblingLinks(Node *a, Node *g) {
		if(a->siblingLeft = g->siblingLeft) a->siblingLeft->parent = a;
		if(a->siblingRight = g->siblingRight) a->siblingRight->parent = a;
		g->siblingLeft = g->siblingRight = NULL;
	}

	//apXpath treeB
	//Aps = false siblingsB
	//a`globalpXSpropagateOB
	//lastupdate = true_aupdateKvB
	//lastupdate = falseaupdateB
	static void localSplay(Node *a, bool ps, bool lastupdate = true) {
		if(isLocalRoot(a, ps)) return;
		//s:
		//	EapXOlocal treem[hSupdate
		//		(alocal treeOm[h^Blocal treeem[hupdate)
		//	EaglobalpXm[hSpropagate
		while(true) {
			Node *p = a->parent;
			bool plr = p->child(ps, true) == a;
			if(isLocalRoot(p, ps)) {
				if(!ps) moveSiblingLinks(a, p);
				rotate(a, ps, !plr);
				updateNode(a->child(ps, !plr), ps);
				break;
			} else {
				Node *g = p->parent;
				bool glr = g->child(ps, true) == p;
				bool groot = isLocalRoot(g, ps);

				if(groot && !ps) moveSiblingLinks(a, g);
				if(plr == glr) {
					rotate(p, ps, !plr);
					rotate(a, ps, !plr);
					updateNode(p->child(ps, !plr), ps);
					updateNode(p, ps);
				} else {
					rotate(a, ps, glr);
					rotate(a, ps, plr);
					updateNode(a->child(ps, plr), ps);
					updateNode(a->child(ps, !plr), ps);
				}
				if(groot) break;
			}
		}
		if(lastupdate) updateNode(a, ps);
	}

	//alocal treepXpropagateKv
	static void localPathSplay(Node *a, bool lastupdate = true) {
		localSplay(a, false, lastupdate);
	}
	//alocal treepXpropagateKv
	static void localSiblingSplay(Node *a, bool lastupdate = true) {
		localSplay(a, true, lastupdate);
	}

	//asplayEpropagateKvB
	//lastupdate = trueaupdateKvB
	//lastupdate = falsea,hupdateB
	static Node *pathHead(Node *a, bool lr = false, bool lastupdate = true) {
		assert(isLocalRoot(a, false));
		Node *h = a;
		while(true) {
			Node *c = h->path(lr);
			if(!c) break;
			h = c;
		}
		localPathSplay(h, lastupdate);	//~
		return h;
	}

	//apath treeaEutopChildB
	//apath treesplayKvB
	static void splitPath(Node *a) {
		assert(isLocalRoot(a, false));
		Node *r = a->pathRight, *c = a->topChild;
		if(r != NULL) {
			a->pathRight = NULL;
			a->topChild = r;
			assert(r->siblingLeft == NULL && r->siblingRight == NULL);
			if(r->siblingLeft = c) {
				c->parent = r;
				r->treeUpdate();
			}
			a->pathAndTreeUpdate();
		}
	}

	//sibling treea()B
	//asibling treesplayKvB
	//aglobal treepXpropagateKvB
	//lastupdate = falseaaeupdateB
	static void deleteChild(Node *a, bool lastupdate = true) {
		Node *r = a->siblingLeft;
		if(!r) {
			Node *p = a->parent;
			if(r = a->siblingRight) r->parent = p;
			if(p != NULL) {
				p->topChild = r;
				if(lastupdate) p->treeUpdate();
			}
		} else {
			while(r->siblingRight) {
				r = r->siblingRight;
			}
			localSiblingSplay(r, false);
			assert(r->siblingRight == a && !a->siblingLeft);
			Node *b = a->siblingRight;
			if(r->siblingRight = b) b->parent = r;
			r->treeUpdate();
		}
		a->siblingLeft = a->siblingRight = a->parent = NULL;
		if(lastupdate) a->treeUpdate();
	}

public:
	//aglobal treeB
	//alazinessB
	static void expose(Node *a) {
		if(!a->parent) return;
		while(true) {
			localPathSplay(a, false);
			localSiblingSplay(a, false);
			Node *p = a->parent;
			if(!p) break;
			assert(p->topChild == a);
			Node *h = pathHead(a, false, false);
			//_ahupdateB
			assert(p->topChild == h);
			//pX(h)pXe(p)Bp
			localPathSplay(p, false);
			Node *r = p->pathRight;
			//hsiblingsBrB
			if(r != NULL) {
				p->topChild = r;
				if(r->siblingLeft = h->siblingLeft) r->siblingLeft->parent = r;
				if(r->siblingRight = h->siblingRight) r->siblingRight->parent = r;
				h->siblingLeft = h->siblingRight = NULL;
				r->treeUpdate();
			} else {
				deleteChild(h, false);
			}
			p->pathRight = h;
			h->parent = p;
			//localPathSplayupdateKv
		}
		a->pathAndTreeUpdate();
	}

public:
	static void directedLink(Node *a, Node *p) {
		//aptopChildBpexposeentire-treelazinessKv
		expose(a); expose(p);
		assert(a->parent == NULL);
		Node *c = p->topChild;
		p->topChild = a;
		a->parent = p;
		if(a->siblingLeft = c) c->parent = a;
		a->treeUpdate();
		p->treeUpdate();
	}

	//a(e)AaeBaANULLB
	//lexposeB
	static Node *directedCut(Node *a) {
		//apathLeft()

		expose(a);
		Node *l = a->pathLeft;
		if(l != NULL) {
			a->pathLeft = NULL;
			l->parent = NULL;
			a->pathAndTreeUpdate();
		}
		return pathHead(l, true);
	}

	static void exposePath(Node *a) {
		expose(a);
		splitPath(a);
	}

	friend struct DynamicTreeDebugCheck;
};

typedef DynamicTree Tree;

struct NodeOps {
	static int getWeight(Node *a) {
		Tree::expose(a);
		return a->weight;
	}

	static void setWeight(Node *a, int weight) {
		Tree::expose(a);
		a->weight = weight;
		a->pathAndTreeUpdate();
	}

	static Node::WeightSum getMaxDistance(Node *a) {
		Tree::exposePath(a);
		Node::WeightSum res = Node::getNodeMaxDistLR(a, true);
		return res;
	}
};

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<Node> nodes(n);
		for(int i = 0; i < n; ++ i)
			NodeOps::setWeight(&nodes[i], 1);
		vector<int> ans(n, 0);
		reu(i, 1, n) {
			int p;
			scanf("%d", &p), -- p;
			Tree::directedLink(&nodes[i], &nodes[p]);
			int dist = NodeOps::getMaxDistance(&nodes[i]);
			ans[i] = max(ans[i - 1], dist - 1);
		}
		for(int i = 1; i < (int)ans.size(); ++ i) {
			if(i != 1) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}