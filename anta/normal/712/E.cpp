#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

//f(x) = (ax+b)/(cx+d) 1/1L"Mobius transformation"B
//functional composition 2x2s [[a b] [c d]] |ZSI

struct MobiusTransformation {
	typedef double Val;
	Val a, b, c, d;
	MobiusTransformation() : a(0), b(0), c(0), d(1) {}
	explicit MobiusTransformation(Val a, Val b, Val c, Val d) : a(a), b(b), c(c), d(d) {}
	static MobiusTransformation identity() { return MobiusTransformation(1, 0, 0, 1); }

	Val evaluate(Val x) const {
		return (a * x + b) / (c * x + d);
	}

	static Val flush(Val x) {
		return abs(x) < 1e-99 ? 0 : x;
	}

	MobiusTransformation normalize() const {
		return MobiusTransformation(a / c, b / c, 1, flush(d / c));
	}

	MobiusTransformation operator*(const MobiusTransformation &that) const {
		Val e = that.a, f = that.b, g = that.c, h = that.d;
		return MobiusTransformation(
			a * e + b * g, a * f + b * h,
			c * e + d * g, c * f + d * h).normalize();
	}
};

struct GetRangeSegmentTree {
	typedef MobiusTransformation Val;
	static Val combineVal(const Val &x, const Val &y) { return x * y; }
	static void assignCombineVal(Val &x, const Val &y) { x = x * y; }
	static Val identityVal() { return Val::identity(); }

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
	//commutativitylP
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

int main() {
	int n; int q;
	while(~scanf("%d%d", &n, &q)) {
		vector<double> p(n);
		rep(i, n) {
			int a; int b;
			scanf("%d%d", &a, &b);
			p[i] = a * 1. / b;
		}
		sort(p.begin(), p.end());


		auto getFunction = [](double p) {
			//x * p / (1 - p * (1 - x))
			return MobiusTransformation(p, 0, p, 1 - p).normalize();
		};

		vector<MobiusTransformation> initVals(n);
		rep(i, n)
			initVals[i] = getFunction(p[i]);
		GetRangeSegmentTree segt;
		segt.init(initVals);
		for(int ii = 0; ii < q; ++ ii) {
			int ty;
			scanf("%d", &ty);
			if(ty == 1) {
				int i; int a; int b;
				scanf("%d%d%d", &i, &a, &b), -- i;
				p[i] = a * 1. / b;
				segt.set(i, getFunction(p[i]));
			} else if(ty == 2) {
				int l; int r;
				scanf("%d%d", &l, &r), -- l, -- r;
				MobiusTransformation f = segt.getRange(l, r);
				double ans = f.evaluate(p[r]);
				printf("%.10f\n", ans);
			} else abort();
		}
	}
	return 0;
}