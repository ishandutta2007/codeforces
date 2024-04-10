#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }


template<int... Sizes>
struct MultidimensionalIndex;
template<>
struct MultidimensionalIndex<> {
	MultidimensionalIndex() {}
	int getTotalSize() const { return 1; }
	int getIndexAcc(int acc) const { return acc; }
};
template<int Head, int... Tail>
struct MultidimensionalIndex<Head, Tail...> : MultidimensionalIndex<Tail...> {
	using Base = MultidimensionalIndex<Tail...>;
	enum { size = Head };
	template<typename... TailT>
	MultidimensionalIndex(TailT... tail) : Base(tail...) {}
	int getTotalSize() const { return size * Base::getTotalSize(); }
	template<typename... TailT>
	int getIndexAcc(int acc, int head, TailT... tail) const { return Base::getIndexAcc(acc * size + head, tail...); }
};
template<int... Tail>
struct MultidimensionalIndex<0, Tail...> : MultidimensionalIndex<Tail...> {
	using Base = MultidimensionalIndex<Tail...>;
	const int size;
	template<typename... TailT>
	MultidimensionalIndex(int head, TailT... tail) : size(head), MultidimensionalIndex<Tail...>(tail...) {}
	int getTotalSize() const { return size * Base::getTotalSize(); }
	template<typename... TailT>
	int getIndexAcc(int acc, int head, TailT... tail) const { return Base::getIndexAcc(acc * size + head, tail...); }
};

template<typename Val, int... Sizes>
struct DP : MultidimensionalIndex<Sizes...> {
	using Base = MultidimensionalIndex<Sizes...>;
	std::vector<Val> dp;
	template<typename... SizesT>
	DP(SizesT... sizes) : Base(sizes...) {}
	void init(Val val) { dp.assign(Base::getTotalSize(), val); }
	void init() { dp.assign(Base::getTotalSize(), Val()); }
	template<typename... SizesT>
	Val &operator()(SizesT... indices) { return dp[Base::getIndexAcc(0, indices...)]; }
	template<typename... SizesT>
	Val operator()(SizesT... indices) const { return dp[Base::getIndexAcc(0, indices...)]; }
	void swap(DP &that) { dp.swap(that.dp); }
};

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]), --a[i];
		const int K = 8;
		int m = n / K + 1;
		DP<int, K, 0, 0> nextPos(n + 1, m + 1);
		nextPos.init(INF);
		rep(k, K) {
			nextPos(k, n, 0) = n;
			for (int i = n - 1; i >= 0; --i) {
				nextPos(k, i, 0) = i;
				if (a[i] == k) {
					rer(j, 1, m)
						nextPos(k, i, j) = nextPos(k, i + 1, j - 1);
				}
				else {
					rer(j, 1, m)
						nextPos(k, i, j) = nextPos(k, i + 1, j);
				}
			}
		}
		int ans = 0;
		rep(a, m) {
			DP<int, 1 << K, K + 1> dp;
			dp.init(INF);
			dp(0, 0) = 0;
			rep(s, 1 << K) rep(p, K + 1) {
				int x = dp(s, p);
				if (x == INF) continue;
				rep(k, K) if (~s >> k & 1) {
					rep(q, 2)
						amin(dp(s | 1 << k, p + q), nextPos(k, x, a + q));
				}
			}
			rep(p, K + 1) if (dp((1 << K) - 1, p) < INF)
				amax(ans, a * K + p);
		}
		printf("%d\n", ans);
	}
	return 0;
}