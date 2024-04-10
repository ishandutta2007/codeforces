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
	int getIndexAcc(int acc, int head, TailT... tail) const {
#ifdef _DEBUG
		assert(0 <= head && head < size);
#endif
		return Base::getIndexAcc(acc * size + head, tail...);
	}
};
template<int... Tail>
struct MultidimensionalIndex<0, Tail...> : MultidimensionalIndex<Tail...> {
	using Base = MultidimensionalIndex<Tail...>;
	const int size;
	template<typename... TailT>
	MultidimensionalIndex(int head, TailT... tail) : size(head), MultidimensionalIndex<Tail...>(tail...) {}
	int getTotalSize() const { return size * Base::getTotalSize(); }
	template<typename... TailT>
	int getIndexAcc(int acc, int head, TailT... tail) const {
#ifdef _DEBUG
		assert(0 <= head && head < size);
#endif
		return Base::getIndexAcc(acc * size + head, tail...);
	}
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
	decltype(dp[0]) operator()(SizesT... indices) { return dp[Base::getIndexAcc(0, indices...)]; }
	template<typename... SizesT>
	Val operator()(SizesT... indices) const { return dp[Base::getIndexAcc(0, indices...)]; }
	void swap(DP &that) { dp.swap(that.dp); }
};


int main() {
	int N; int K;
	while (~scanf("%d%d", &N, &K)) {
		int M;
		scanf("%d", &M);
		vector<vector<pair<int, int> > > gw(N);
		for (int i = 0; i < M; ++ i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w), -- u, -- v;
			if (u == v) continue;
			gw[u].push_back(make_pair(v, w));
		}
		if (K == 1) {
			puts("0");
			continue;
		}
		DP<int, 0, 0, 2> dp(N + 1, N + 1), ndp = dp;
		ndp.init(INF);
		auto update = [&ndp](int L, int R, int i, int j, int y) {
			if (i < j) {
				if (j >= R) return;
				amin(ndp(i + 1, j, 1), y);
				amin(ndp(j + 1, R, 0), y);
			} else {
				if (j < L) return;
				amin(ndp(j + 1, i, 0), y);
				amin(ndp(L, j, 1), y);
			}
		};
		rep(i, N) for (auto e : gw[i])
			update(0, N, i, e.first, e.second);
		rep(kk, K - 2) {
			dp.swap(ndp);
			ndp.init(INF);
			rep(i, N + 1) rep(j, N + 1) rep(d, 2) {
				int x = dp(i, j, d);
				if (x == INF) continue;
				if (d == 0) {
					for (auto e : gw[i - 1])
						update(i, j, i - 1, e.first, x + e.second);
				} else {
					for (auto e : gw[j])
						update(i, j, j, e.first, x + e.second);
				}
			}
		}
		int ans = INF;
		rep(i, N + 1) rep(j, N + 1) rep(d, 2)
			amin(ans, ndp(i, j, d));
		printf("%d\n", ans == INF ? -1 : ans);
	}
	return 0;
}