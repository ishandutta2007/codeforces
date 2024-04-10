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
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct Node {
	long long len;
	long long maxi;
	long long maxL, maxR;
	Node(): len(0), maxi(0), maxL(-INFL), maxR(-INFL) { }
	Node(int h, int d): len(d), maxi(0), maxL(2LL * h), maxR(2LL * h + d) { }
	Node &operator+=(const Node &that) {
		amax(maxi, that.maxi);
		if(maxR >= 0 && that.maxL >= 0)
			amax(maxi, maxR + that.maxL);
		maxL = max(maxL, that.maxL >= 0 ? len + that.maxL : -INFL);
		maxR = max(maxR >= 0 ? maxR + that.len : -INFL, that.maxR);
		len += that.len;
		return *this;
	}
};

struct GetRangeSegmentTree {
	typedef Node Val;
	static Val combineVal(const Val &x, const Val &y) { return Node(x) += y; }
	static void combinesVal(Val &x, const Val &y) { x += y; }
	static Val identityVal() { return Node(); } 

	vector<Val> nodes;
	int n;
	void init(int n_, const Val &v = Val()) { init(vector<Val>(n_, v)); }
	void init(const vector<Val> &u) {
		n = 1; while(n < (int)u.size()) n *= 2;
		nodes.resize(n, identityVal());
		nodes.insert(nodes.end(), u.begin(), u.end());
		nodes.resize(n * 2, identityVal());
		for(int i = n-1; i > 0; -- i)
			nodes[i] = combineVal(nodes[i*2], nodes[i*2+1]);
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
			combinesVal(m, nodes[(n+l) / (l&-l)]);
		for(; l < r; r -= r&-r)
			indices[k ++] = (n+r) / (r&-r) - 1;
		while(-- k >= 0) combinesVal(m, nodes[indices[k]]);
		return m;
	}
	void set(int i, const Val &x) {
		i += n; nodes[i] = x;
		for(i >>= 1; i > 0; i >>= 1)
			nodes[i] = combineVal(nodes[i*2], nodes[i*2+1]);
	}
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> d(n), h(n);
	rep(i, n) scanf("%d", &d[i]);
	rep(i, n) scanf("%d", &h[i]);
	vector<Node> nodes(n + n);
	rep(i, n)
		nodes[n+i] = nodes[i] = Node(h[i], d[i]);
	GetRangeSegmentTree segt; segt.init(nodes);
	rep(ii, m) {
		int a, b;
		scanf("%d%d", &a, &b), -- a, -- b;
		int L, R;
		if(a <= b) {
			L = b + 1, R = n + a - 1;
		}else {
			L = b + 1, R = a - 1;
		}
		Node sum = segt.getRange(L, R+1);
		long long ans = sum.maxi;
		printf("%lld\n", ans);
	}
	return 0;
}