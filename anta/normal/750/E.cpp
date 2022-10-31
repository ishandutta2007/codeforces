#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct Val {
	int A[5][5];
	Val() {
		rep(i, 5) rep(j, 5) A[i][j] = INF;
	}
	static Val identity() {
		Val res;
		rep(i, 5) res.A[i][i] = 0;
		return res;
	}
	Val operator*(const Val &that) const {
		Val res;
		rep(i, 5) rep(j, 5) {
			int x = INF;
			rep(k, 5)
				amin(x, A[i][k] + that.A[k][j]);
			res.A[i][j] = x;
		}
		return res;
	}
};

struct GetRangeSegmentTree {
	static Val combineVal(const Val &x, const Val &y) { return x * y; }
	static void assignCombineVal(Val &x, const Val &y) { x = x * y; }
	static Val identityVal() { return Val::identity(); }

	vector<Val> nodes;
	int n;
	void init(int n_, const Val &v = Val()) { init(vector<Val>(n_, v)); }
	void init(const vector<Val> &u) {
		n = 1; while (n < (int)u.size()) n *= 2;
		nodes.resize(n, identityVal());
		nodes.insert(nodes.end(), u.begin(), u.end());
		nodes.resize(n * 2, identityVal());
		for (int i = n - 1; i > 0; -- i)
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
		for (; l && l + (l&-l) <= r; l += l&-l)
			assignCombineVal(m, nodes[(n + l) / (l&-l)]);
		for (; l < r; r -= r&-r)
			indices[k ++] = (n + r) / (r&-r) - 1;
		while (-- k >= 0) assignCombineVal(m, nodes[indices[k]]);
		return m;
	}
	void set(int i, const Val &x) {
		i += n; nodes[i] = x;
		for (i >>= 1; i > 0; i >>= 1)
			nodes[i] = combineVal(nodes[i * 2], nodes[i * 2 + 1]);
	}
};

int main() {
	int n; int q;
	while (~scanf("%d%d", &n, &q)) {
		Val matrices[10];
		rep(d, 10) {
			Val A;
			rep(i, 5)
				A.A[i][i] = 1;
			rep(i, 3)
				A.A[i]["201"[i] == d + '0' ? i + 1 : i] = 0;
			if (d == 7)
				A.A[3][4] = A.A[4][4] = 0;
			else if (d != 6)
				A.A[3][3] = A.A[4][4] = 0;
			matrices[d] = A;
		}
		char S[200001];
		scanf("%s", S);
		vector<Val> values(n);
		rep(i, n)
			values[i] = matrices[S[i] - '0'];
		GetRangeSegmentTree segt;
		segt.init(values);
		rep(i, q) {
			int a; int b;
			scanf("%d%d", &a, &b), -- a;
			Val A = segt.getRange(a, b);
			int ans = A.A[0][4];
			printf("%d\n", ans == INF ? -1 : ans);
		}
	}
	return 0;
}