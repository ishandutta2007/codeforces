#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct Sum {
	int size;
	int negativePrefix, positiveSuffix;
	int hillPrefix, hillSuffix;
	int maxHill;
	Sum() : size(0), negativePrefix(0), positiveSuffix(0), hillPrefix(0), hillSuffix(0), maxHill(0) {}
	explicit Sum(ll val) :
		size(1),
		negativePrefix(val < 0),
		positiveSuffix(val > 0),
		hillPrefix(val != 0), hillSuffix(val != 0), maxHill(val != 0)
		{ }
	Sum &operator+=(const Sum &that) { return *this = *this + that; }
	bool isNegative() const { return negativePrefix == size; }
	bool isPositive() const { return positiveSuffix == size; }
	bool isHill() const { return hillPrefix == size; }
	Sum operator+(const Sum &that) const {
		Sum res;
		res.size = size + that.size;
		res.negativePrefix = isNegative() ? size + that.negativePrefix : negativePrefix;
		res.positiveSuffix = that.isPositive() ? positiveSuffix + that.size : that.positiveSuffix;
		res.hillPrefix = isHill() ? size + (isPositive() ? that.hillPrefix : that.negativePrefix) : hillPrefix;
		res.hillSuffix = that.isHill() ? (that.isNegative() ? hillSuffix : positiveSuffix) + that.size : that.hillSuffix;
		res.maxHill = max(maxHill, that.maxHill);
		amax(res.maxHill, positiveSuffix + that.hillPrefix);
		amax(res.maxHill, hillSuffix + that.negativePrefix);
		return res;
	}
};

struct GetRangeSegmentTree {
	typedef Sum Val;
	static Val combineVal(const Val &x, const Val &y) { return x + y; }
	static void assignCombineVal(Val &x, const Val &y) { x += y; }
	static Val identityVal() { return Sum(); }

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
	void set(int i, const Val &x) {
		i += n; nodes[i] = x;
		for(i >>= 1; i > 0; i >>= 1)
			nodes[i] = combineVal(nodes[i * 2], nodes[i * 2 + 1]);
	}
};

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<ll> diffs(n - 1);
		rep(i, n - 1) diffs[i] = a[i + 1] - a[i];
		GetRangeSegmentTree segt;
		segt.init(vector<Sum>(diffs.begin(), diffs.end()));
		int m;
		scanf("%d", &m);
		rep(ii, m) {
			int l; int r; int d;
			scanf("%d%d%d", &l, &r, &d), -- l;
			if(l > 0) {
				diffs[l - 1] += d;
				segt.set(l - 1, Sum(diffs[l - 1]));
			}
			if(r < n) {
				diffs[r - 1] -= d;
				segt.set(r - 1, Sum(diffs[r - 1]));
			}

			Sum sum = segt.getWhole();
			int ans = sum.maxHill + 1;
			printf("%d\n", ans);
		}
	}
	return 0;
}