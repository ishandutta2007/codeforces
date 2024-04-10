
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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


int C[31][31];

const int len = 19;
int coeffs[10][len + 1];
int toID2(int cnt[10]) {
	int res = 0;
	int sum = 0;
	rep(d, 9) {
		sum += cnt[d];
		res += coeffs[d][sum];
	}
	return res;
}

const int totalStates = 4686825;
vector<int> digitsL, digitsR;
DP<bool, 20, 2, 2, totalStates> vis;
int cnt[10];
void dfs(int i, bool gtL, bool ltR) {
	int state = toID2(cnt);
	if (vis(i + 1, gtL, ltR, state)) return;
	vis(i + 1, gtL, ltR, state)  = true;
	if (i == -1)
		return;
	int dL = digitsL[i], dR = digitsR[i];
	rep(d, 10) {
		if (!gtL && d < dL) continue;
		if (!ltR && dR < d) continue;
		-- cnt[0], ++ cnt[d];
		dfs(i - 1, gtL || dL < d, ltR || d < dR);
		++ cnt[0], -- cnt[d];
	}
}

int main() {
	for (int i = 0; i <= 30; i ++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j ++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	rep(d,9) rep(i, len + 1) {
		int r = len - (i + 1), n = 10 - d;
		coeffs[d][i] = r == 0 ? 1 : C[n + r - 1][r];
	}
	long long L; long long R;
	while (~scanf("%lld%lld", &L, &R)) {
		digitsL.clear();
		digitsR.clear();
		{
			ll x = L;
			rep(i, len + 1) {
				digitsL.push_back(x % 10);
				x /= 10;
			}
		}
		{
			ll x = R;
			rep(i, len + 1) {
				digitsR.push_back(x % 10);
				x /= 10;
			}
		}
		vis.init(false);
		cnt[0] = len;
		dfs(len, false, false);
		cnt[0] = 0;
		int ans = 0;
		rep(s, totalStates) {
			bool ok = false;
			rep(a, 2)rep(b, 2)
				ok |= vis(0,a,b,s);
			ans += ok;
		}
		printf("%d\n", ans);
	}
	return 0;
}