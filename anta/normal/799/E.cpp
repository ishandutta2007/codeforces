#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

random_device rd;

struct Node {
	static Node nullNode;

	Node *left, *right;
	int size;
	int pos;
	int val;
	long long sum;

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
	static Ref join(Ref l, Ref r) {
		if (l->isNull()) return r;
		if (r->isNull()) return l;
		if ((int)(rd() % (l->size + r->size)) < l->size) {
			l->propagate();
			return l->linkr(join(l->right, r));
		} else {
			r->propagate();
			return r->linkl(join(l, r->left));
		}
	}
	typedef pair<Ref, Ref> RefPair;
	static RefPair split(Ref t, int k) {
		if (t->isNull()) return RefPair(&Node::nullNode, &Node::nullNode);
		t->propagate();
		int s = t->left->size;
		if (k <= s) {
			RefPair p = split(t->left, k);
			return RefPair(p.first, t->linkl(p.second));
		} else {
			RefPair p = split(t->right, k - s - 1);
			return RefPair(t->linkr(p.first), p.second);
		}
	}
	static RefPair splitPos(Ref t, int pos) {
		if (t->isNull()) return RefPair(&Node::nullNode, &Node::nullNode);
		t->propagate();
		if (pos < t->pos) {
			RefPair p = splitPos(t->left, pos);
			return RefPair(p.first, t->linkl(p.second));
		} else {
			RefPair p = splitPos(t->right, pos);
			return RefPair(t->linkr(p.first), p.second);
		}
	}
	static Ref insertPos(Ref t, Ref n) {
		if (rd() % (t->size + 1) == 0) {
			RefPair p = splitPos(t, n->pos);
			return n->linklr(p.first, p.second);
		}
		t->propagate();
		if (n->pos < t->pos)
			return t->linkl(insertPos(t->left, n));
		else
			return t->linkr(insertPos(t->right, n));
	}
};

int main() {
	int n; int m; int k;
	while (~scanf("%d%d%d", &n, &m, &k)) {
		vector<int> cs(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &cs[i]);
		vector<int> flag(n, 0);
		rep(i, 2) {
			int a;
			scanf("%d", &a);
			rep(j, a) {
				int x;
				scanf("%d", &x), -- x;
				flag[x] |= 1 << i;
			}
		}
		vector<int> items[1 << 2];
		rep(i, n)
			items[flag[i]].push_back(cs[i]);
		vector<long long> sums[1 << 2];
		rep(S, 1 << 2) {
			auto &v = items[S];
			sort(v.begin(), v.end());
			sums[S].assign(v.size() + 1, 0);
			rep(i, v.size())
				sums[S][i + 1] = sums[S][i] + v[i];
		}
		vector<Node> nodes(n);
		int nNodes = 0;
		Node *T = &Node::nullNode;
		auto insert = [&](int p) {
			Node &x = nodes[nNodes ++];
			x.set(p, p);
			T = RBST::insertPos(T, &x);
		};
		auto getSum = [&](int k) {
			if (T->size < k) return INFL;
			auto p = RBST::split(T, k);
			ll res = p.first->sum;
			T = RBST::join(p.first, p.second);
			return res;
		};
		for (int p : items[0])
			insert(p);
		int pj[2] = { (int)items[1].size(), (int)items[2].size() };
		long long ans = INFL;
		rer(i, 0, items[3].size()) {
			int j = max(0, k - i);
			int l = m - (i + j * 2);
			if (j > (int)min(items[1].size(), items[2].size())) continue;
			if (l < 0) continue;
			rep(s, 2) {
				for (; j < pj[s]; -- pj[s])
					insert(items[1 << s][pj[s] - 1]);
			}
			ll cost = 0;
			cost += sums[3][i];
			cost += sums[1][j];
			cost += sums[2][j];
			cost += getSum(l);
			amin(ans, cost);
		}
		printf("%lld\n", ans == INFL ? -1 : ans);
	}
	return 0;
}