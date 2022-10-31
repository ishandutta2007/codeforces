#define _CRT_SECURE_NO_WARNINGS
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
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

const int K = 60;

struct Sum {
	char func[K];
	short time[K];
	Sum() {
		rep(k, K-1) func[k] = k + 1;
		rep(k, K-1) time[k] = 0;
		func[K-1] = 0; time[K-1] = 1;
	}
	explicit Sum(int a) {
		rep(k, K-1) func[k] = k + 1;
		rep(k, K-1) time[k] = 0;
		func[K-1] = 0; time[K-1] = 1;
		for(int k = 0; k < K; k += a)
			func[k] = k + 2;
		if(a == 2) {
			func[K-2] = 0;
			time[K-2] = 1;
		}
	}
	Sum operator+(const Sum &that) const {
		Sum t;
		rep(k, K) {
			int l = func[k];
			t.func[k] = that.func[l];
			t.time[k] = time[k] + that.time[l];
		}
		return t;
	}
	Sum &operator+=(const Sum &that) { return *this = *this + that; }
};

struct GetRangeSegmentTree {
	typedef Sum Val;
	static Val combineVal(const Val &x, const Val &y) { return x + y; }
	static void combinesVal(Val &x, const Val &y) { x += y; }
	static Val identityVal() { return Sum(); } 

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
	int n;
	scanf("%d", &n);
	vector<Sum> vals(7);
	rer(k, 2, 6) vals[k] = Sum(k);
	vector<Sum> initval(n);
	rep(i, n) {
		int a;
		scanf("%d", &a);
		initval[i] = vals[a];
	}
	GetRangeSegmentTree segt;
	segt.init(initval);
	int q;
	scanf("%d", &q);
	char ty[2];
	rep(ii, q) {
		int x, y;
		scanf("%s%d%d", ty, &x, &y);
		if(*ty == 'A') {
			-- x, -- y;
			Sum sum = segt.getRange(x, y);
			int ans = (int)sum.time[0] * K + sum.func[0];
			printf("%d\n", ans);
		}else if(*ty == 'C') {
			-- x;
			segt.set(x, vals[y]);
		}
	}
	return 0;
}