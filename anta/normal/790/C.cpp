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

int solve(const vi &A) {
	int n = (int)A.size();
	vector<int> indices[3];
	rep(i, n)
		indices[A[i]].emplace_back(i);
	int X = (int)indices[0].size();
	int Y = (int)indices[1].size();
	int Z = (int)indices[2].size();
	DP<int, 0, 0, 0, 2> dp(X + 1, Y + 1, Z + 1);
	dp.init(INF);
	dp(0, 0, 0, 0) = 0;
	rep(x, X + 1) rep(y, Y + 1) rep(z, Z + 1) rep(p, 2) {
		int t = dp(x, y, z, p);
		if (t == INF) continue;
		vector<bool> used(n);
		rep(k, x) used[indices[0][k]] = true;
		rep(k, y) used[indices[1][k]] = true;
		rep(k, z) used[indices[2][k]] = true;
		int w = x + y + z;
		if (x < X) {
			int cost = 0;
			rep(k, indices[0][x])
				cost += !used[k];
			amin(dp(x + 1, y, z, 1), t + cost);
		}
		if (y < Y && p == 0) {
			int cost = 0;
			rep(k, indices[1][y])
				cost += !used[k];
			amin(dp(x, y + 1, z, 0), t + cost);
		}
		if (z < Z) {
			int cost = 0;
			rep(k, indices[2][z])
				cost += !used[k];
			amin(dp(x, y, z + 1, 0), t + cost);
		}
	}
	int ans = INF;
	rep(p, 2)
		amin(ans, dp(X, Y, Z, p));
	return ans;
}

int main() {
	int n;
	while (~scanf("%d", &n)) {
		char buf[101];
		scanf("%s", buf);
		vector<int> A(n);
		rep(i, n)
			A[i] = buf[i] == 'V' ? 0 : buf[i] == 'K' ? 1 : 2;
		int ans = solve(A);
		printf("%d\n", ans);
	}
	return 0;
}