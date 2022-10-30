#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
};
typedef ModInt<1000000007> mint;

template<typename Val>
struct GetRangeSegmentTree {
	static Val combineVal(const Val &x, const Val &y) { return x + y; }
	static void assignCombineVal(Val &x, const Val &y) { x = x + y; }
	static Val identityVal() { return Val(); }

	vector<Val> nodes;
	int n;
	void init(int n_, const Val &v = Val()) { init(vector<Val>(n_, v)); }
	void init(const vector<Val> &u) {
		n = 1; while(n < (int)u.size()) n *= 2;
		nodes.resize(n, identityVal());
		nodes.insert(nodes.end(), u.begin(), u.end());
		nodes.resize(n * 2, identityVal());
		for(int i = n - 1; i > 0; -- i)
			nodes[i] = combineVal(nodes[i * 2], nodes[i * 2 + 1]);
	}
	Val get(int i) {
		return nodes[i + n];
	}
	Val getWhole() const {
		return nodes[1];
	}
	Val getRange(int l, int r) const {
		Val m = identityVal();
		int indices[64]; int k = 0;
		for(; l && l + (l&-l) <= r; l += l&-l)
			assignCombineVal(m, nodes[(n + l) / (l&-l)]);
		for(; l < r; r -= r&-r)
			indices[k ++] = (n + r) / (r&-r) - 1;
		while(-- k >= 0) assignCombineVal(m, nodes[indices[k]]);
		return m;
	}
	Val getRangeCommutative(int l, int r) const {
		Val m = identityVal();
		for(; l && l + (l&-l) <= r; l += l&-l)
			assignCombineVal(m, nodes[(n + l) / (l&-l)]);
		for(; l < r; r -= r&-r)
			assignCombineVal(m, nodes[(n + r) / (r&-r) - 1]);
		return m;
	}
	void set(int i, const Val &x) {
		i += n; nodes[i] = x;
		for(i >>= 1; i > 0; i >>= 1)
			nodes[i] = combineVal(nodes[i * 2], nodes[i * 2 + 1]);
	}
};

typedef const char *Pos;

int nNodes;
char expr[400001];

struct Node {
	int type;
	int parent;
	int left, right;
	vector<int> children;
};

vector<int> nodeId;
vector<Node> nodes;
vector<int> postOrder;

int getIndex(Pos p) { return (int)(p - expr); }
int newNode(int type) {
	nodes.push_back(Node{ type, -1, -1, -1, {} });
	return nNodes ++;
}

int p_expr(Pos &p, int t);

int p_term(Pos &p) {
	if(*p == '(') {
		int i = getIndex(p);
		++ p;
		int node = p_expr(p, 0);
		assert(*p == ')');
		int j = getIndex(p);
		++ p;
		nodeId[i] = nodeId[j] = node;
		return node;
	} else if(isdigit(*p)) {
		int left = getIndex(p);
		int node = newNode(2);
		while(isdigit(*p)) {
			nodeId[getIndex(p)] = node;
			++ p;
		}
		postOrder.push_back(node);
		nodes[node].left = left;
		nodes[node].right = getIndex(p);
		return node;
	} else {
		return -1;
	}
}

int p_expr(Pos &p, int t) {
	int left = getIndex(p);
	int x = t == 0 ? p_expr(p, t + 1) : p_term(p);
	if(x == -1) return -1;
	int node = newNode(t);
	nodes[x].parent = node;
	nodes[node].children.push_back(x);
	while(*p == (t == 0 ? '+' : '*')) {
		++ p;
		int y = t == 0 ? p_expr(p, t + 1) : p_term(p);
		assert(y != -1);
		nodes[y].parent = node;
		nodes[node].children.push_back(y);
	}
	postOrder.push_back(node);
	nodes[node].left = left;
	nodes[node].right = getIndex(p);
	return node;
}

struct Paren {
	int sum, mini;
	Paren() : Paren(0) {}
	explicit Paren(int x) : sum(x), mini(min(x, 0)) {}
	Paren operator+(const Paren &that) const {
		Paren res;
		res.sum = sum + that.sum;
		res.mini = min(mini, sum + that.mini);
		return res;
	}
};

struct Digits {
	mint num, pow;
	Digits() : num(), pow(1) {}
	explicit Digits(int d) : num(d), pow(10) {}
	Digits operator+(const Digits &that) const {
		Digits res;
		res.num = num * that.pow + that.num;
		res.pow = pow * that.pow;
		return res;
	}
};

struct SumProd {
	mint sum, prod;
	SumProd() : sum(), prod(1) {}
	explicit SumProd(mint x) : sum(x), prod(x) {}
	SumProd(mint sum, mint prod) : sum(sum), prod(prod) {}
	SumProd operator+(const SumProd &that) const {
		return SumProd(sum + that.sum, prod * that.prod);
	}
};

namespace naive {

bool p_expr(Pos &p, int t, mint &res);

bool p_term(Pos &p, mint &res) {
	if(*p == '(') {
		++ p;
		p_expr(p, 0, res);
		if(*p != ')') throw 0;
		++ p;
		return true;
	} else if(isdigit(*p)) {
		res = mint();
		while(isdigit(*p)) {
			res = res * 10 + (*p - '0');
			++ p;
		}
		return true;
	} else {
		return false;
	}
}

bool p_expr(Pos &p, int t, mint &res) {
	if(!(t == 0 ? p_expr(p, t + 1, res) : p_term(p, res)))
		return false;
	while(*p == (t == 0 ? '+' : '*')) {
		++ p;
		mint x;
		if(!(t == 0 ? p_expr(p, t + 1, x) : p_term(p, x)))
			throw 0;
		if(t == 0)
			res += x;
		else
			res *= x;
	}
	return true;
}

}

int main() {
	while(~scanf("%s", expr)) {
		int len = (int)strlen(expr);
		int root;
		nNodes = 0;
		nodes.clear();
		nodeId.assign(len, -1);
		postOrder.clear();
		{
			Pos p = expr;
			root = p_expr(p, 0);
			assert(root != -1);
			assert(*p == '\0');
		}
		vi t_ord = postOrder, t_parent(nNodes);
		reverse(t_ord.begin(), t_ord.end());
		rep(i, nNodes) t_parent[i] = nodes[i].parent;
		vector<int> depth(nNodes, -1);
		depth[root] = 0;
		for(int ix = 1; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			depth[i] = depth[p] + 1;
		}
		GetRangeSegmentTree<Paren> segtParen;
		vector<Paren> parentheses(len);
		rep(i, len)
			parentheses[i] = Paren(expr[i] == '(' ? 1 : expr[i] == ')' ? -1 : 0);
		segtParen.init(parentheses);

		GetRangeSegmentTree<Digits> segtDigits;
		vector<Digits> digits(len);
		rep(i, len) if(isdigit(expr[i]))
			digits[i] = Digits(expr[i] - '0');
		segtDigits.init(digits);

		vector<mint> values(nNodes);
		vector<GetRangeSegmentTree<SumProd>> segtSumProds(nNodes);
		vector<SumProd> tmpSumProds;
		vector<vi> childLefts(nNodes), childRights(nNodes);
		for(int ix = (int)t_ord.size() - 1; ix >= 0; -- ix) {
			int i = t_ord[ix];
			auto &n = nodes[i];
			int l = n.left, r = n.right;
			if(n.type == 2) {
				values[i] = segtDigits.getRange(l, r).num;
			} else {
				childLefts[i].reserve(n.children.size());
				childRights[i].reserve(n.children.size());
				tmpSumProds.clear();
				for(int j : n.children) {
					childLefts[i].push_back(nodes[j].left);
					childRights[i].push_back(nodes[j].right);
					tmpSumProds.emplace_back(values[j]);
				}
				segtSumProds[i].init(tmpSumProds);
				SumProd sp = segtSumProds[i].getWhole();
				values[i] = n.type == 0 ? sp.sum : sp.prod;
			}
		}

		auto calc = [&](int node, int l, int r) -> mint {
			int type = nodes[node].type;
			if(type == 2) {
				int L = max(l, nodes[node].left);
				int R = min(r, nodes[node].right);
				return segtDigits.getRange(L, R).num;
			} else {
				int L = (int)(lower_bound(childLefts[node].begin(), childLefts[node].end(), l) - childLefts[node].begin());
				int R = (int)(lower_bound(childRights[node].begin(), childRights[node].end(), r) - childRights[node].begin());
				SumProd sp = segtSumProds[node].getRangeCommutative(L, R);
				return type == 0 ? sp.sum : sp.prod;
			}
		};

		auto combine = [&](int node, mint x, mint y) -> mint {
			int type = nodes[node].type;
			if(type == 0)
				return x + y;
			else if(type == 1)
				return x * y;
			assert(false);
			return mint();
		};

		int q;
		scanf("%d", &q);
		rep(ii, q) {
			int l; int r;
			scanf("%d%d", &l, &r), -- l;

			bool ok = true;
			Paren paren = segtParen.getRange(l, r);
			ok &= paren.sum == 0;
			ok &= paren.mini == 0;
			int nodeL = nodeId[l], nodeR = nodeId[r - 1];
			ok &= nodeL != -1;
			ok &= nodeR != -1;
			if(!ok) {
				puts("-1");
				continue;
			}
			int x = nodeL, y = nodeR;
			mint valx = calc(x, l, r), valy = calc(y, l, r);
			while(x != y) {
				if(t_parent[x] == t_parent[y]) {
					int p = t_parent[x];
					valx = valy = combine(p, combine(p, valx,
						calc(p, nodes[x].right, nodes[y].left)), valy);
					x = y = p;
				} else if(depth[x] >= depth[y]) {
					int p = t_parent[x];
					valx = combine(p, valx, calc(p, nodes[x].right, r));
					x = p;
				} else {
					int p = t_parent[y];
					valy = combine(p, calc(p, l, nodes[y].left), valy);
					y = p;
				}
			}
			assert(valx.get() == valy.get());
			mint ans = valx;
			printf("%d\n", ans.get());
		}
	}
	return 0;
}