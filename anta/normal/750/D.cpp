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
	int n;
	while (~scanf("%d", &n)) {
		vector<int> t(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &t[i]);
		int sum = accumulate(t.begin(), t.end(), 0);
		const int N = sum * 2 + 1;
		DP<bool, 0, 0> visited(N, N);
		DP<bool, 0, 0, 0, 8> dp(n + 1, N, N);
		visited.init();
		dp.init();
		const int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
		const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
		dp(0, 0 + sum, 0 + sum, 0) = true;
		rep(i, n) rer(y, -sum, sum) rer(x, -sum, sum) rep(d, 8)
		if(dp(i, y + sum, x + sum, d)) {
			int len = t[i] + (i != 0);
			rep(j, len) {
				int yy = y + dy[d] * j, xx = x + dx[d] * j;
				visited(yy + sum, xx + sum) = true;
				if (j == len - 1) {
					dp(i + 1, yy + sum, xx + sum, (d + 7) % 8) = true;
					dp(i + 1, yy + sum, xx + sum, (d + 1) % 8) = true;
				}
			}
		}
		int ans = 0;
		rer(y, -sum, sum) rer(x, -sum, sum)
			ans += visited(y + sum, x + sum);
		printf("%d\n", ans);
	}
	return 0;
}