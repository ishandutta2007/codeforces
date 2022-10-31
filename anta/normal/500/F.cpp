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
#include <bitset>
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

struct Item {
	int c, h, t;
	Item() { }
	explicit Item(int t_): c(0), h(0), t(t_) { }
	bool operator<(const Item &that) const { return t < that.t; }
};
struct Query {
	int L, R, b, i;
	bool operator<(const Query &that) const { return L != that.L ? L < that.L : R < that.R; }
};

const int C = 4000;
struct DP {
	vector<int> dp;
	DP(): dp(C+1, 0) { }
	DP &operator+=(const Item &a) {
		int c = a.c, h = a.h;
		for(int i = C - c; i >= 0; -- i)
			amax(dp[i + c], dp[i] + h);
		return *this;
	}
};

struct TwoStackQueue {
	typedef Item Val;
	typedef DP Sum;

	//queue = reverse(vals2) ++ vals1
	vector<Val> vals1, vals2;
	vector<Sum> sums1, sums2;

	pair<Sum,Sum> getsumparts() const {
		Sum s1 = sums1.empty() ? Sum() : sums1.back();
		Sum s2 = sums2.empty() ? Sum() : sums2.back();
		return make_pair(s1, s2);
	}
	void push(const Val &v) {
		Sum s = !sums1.empty() ? sums1.back() : Sum();
		s += v;
		vals1.push_back(v);
		sums1.push_back(s);
	}
	void pop() {
		ensure();
		if(!vals2.empty()) {
			vals2.pop_back();
			sums2.pop_back();
		}
	}

private:
	void ensure() {
		if(!vals2.empty()) return;
		reverse(all(vals1));
		vals2.swap(vals1);
		sums1.clear();
		Sum s;
		sums2.resize(vals2.size());
		for(size_t i = 0; i < vals2.size(); ++ i) {
			s += vals2[i];
			sums2[i] = s;
		}
	}
};

int main() {
	int n, p;
	scanf("%d%d", &n, &p);
	vector<Item> items(n);
	rep(i, n) {
		Item a;
		scanf("%d%d%d", &a.c, &a.h, &a.t);
		items[i] = a;
	}
	sort(all(items));
	int q;
	scanf("%d", &q);
	vector<Query> queries(q);
	rep(i, q) {
		int a, b;
		scanf("%d%d", &a, &b);
		int L = lower_bound(all(items), Item(a - p + 1)) - items.begin();
		int R = upper_bound(all(items), Item(a)) - items.begin();
		Query qq = { L, R, b, i };
		queries[i] = qq;
	}
	sort(all(queries));
	vector<int> ans(q, -1);
	TwoStackQueue queue;
	for(int L = 0, R = 0, qi = 0; qi < q; ++ qi) {
		const Query &qq = queries[qi];
		while(R < qq.R) queue.push(items[R]), ++ R;
		while(L < qq.L) queue.pop(), ++ L;
		int b = qq.b;
		const DP &dp1 = queue.sums1.empty() ? DP() : queue.sums1.back();
		const DP &dp2 = queue.sums2.empty() ? DP() : queue.sums2.back();
		int hapiness = 0;
		rer(i, 0, b)
			amax(hapiness, dp1.dp[i] + dp2.dp[b-i]);
		ans[qq.i] = hapiness;
	}
	rep(i, q)
		printf("%d\n", ans[i]);
	return 0;
}