#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }


struct BitVectorRank {
	typedef unsigned u32;
	typedef size_t Index;
	Index length, blockslength, count;
	vector<u32> blocks;
	vector<Index> ranktable;
	BitVectorRank(Index len = 0) { init(len); }
	void init(Index len) {
		length = len;
		blockslength = (len + 31) / 32 + 1;
		blocks.assign(blockslength, 0);
	}
	inline void set(Index i) { blocks[i / 32] |= 1 << i % 32; }
	void build() {
		count = 0;
		if (length == 0) return;
		ranktable.assign(blockslength + 1, 0);
		for (Index i = 0; i < blockslength; i ++) {
			ranktable[i] = count;
			count += popcount(blocks[i]);
		}
		ranktable[blockslength] = count;
	}
	inline bool access(Index pos) const { return blocks[pos / 32] >> pos % 32 & 1; }
	inline Index rank(Index pos) const {	//[0..pos)1
		int block_idx = pos / 32;
		return ranktable[block_idx] + popcount(blocks[block_idx] & (1U << pos % 32) - 1);
	}
	inline Index rank(bool b, Index pos) const { return b ? rank(pos) : pos - rank(pos); }
	inline Index rank(bool b, Index left, Index right) const { return rank(b, right) - rank(b, left); }
private:
	static inline int popcount(u32 x) {
		x = x - ((x >> 1) & 0x55555555);
		x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
		return ((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
	}
};

struct WaveletMatrix {
	typedef BitVectorRank BitVector;
	typedef unsigned int Val;
	typedef size_t Index;
	int bitnum; Index length; Val maxval;
	vector<BitVector> bitvectors;
	vector<Index> mids;

	WaveletMatrix() { init(vector<Val>()); }
	void init(const vector<Val> &data) {
		length = data.size();
		maxval = length == 0 ? 0 : *max_element(data.begin(), data.end());
		bitnum = 1; while ((maxval >> 1 >> (bitnum - 1)) != 0) ++ bitnum;

		bitvectors.assign(bitnum, BitVector(length));
		mids.resize(bitnum);

		vector<Val> cur = data, next; next.resize(length);
		for (int i = 0; i < bitnum; i ++) {
			Val mask = Val(1) << (bitnum - 1 - i);
			Index zeros = 0;
			for (Index j = 0, n = length; j < n; j ++)
				zeros += (cur[j] & mask) == 0;
			mids[i] = zeros;

			BitVector &bv = bitvectors[i];
			Index zeroPos = 0, onePos = zeros;
			for (Index j = 0, n = length; j < n; j ++) {
				bool b = (cur[j] & mask) != 0;
				if (b) next[onePos  ++] = cur[j], bv.set(j);
				else  next[zeroPos ++] = cur[j];
			}
			bv.build();
			next.swap(cur);
		}
	}
	int rank_all(Val val, int left, int right, int &res_lt, int &res_gt) const {
		if (val > maxval) {
			res_lt = right - left;
			res_gt = 0;
			return 0;
		}
		res_lt = res_gt = 0;
		for (int i = 0; i < bitnum; i ++) {
			const BitVector &bv = bitvectors[i];
			bool dir = val >> (bitnum - i - 1) & 1;
			int leftcount = bv.rank(dir, left), rightcount = bv.rank(dir, right);
			(dir ? res_lt : res_gt) += (right - left) - (rightcount - leftcount);
			left = leftcount, right = rightcount;
			if (dir) left += mids[i], right += mids[i];
		}
		return right - left;
	}
	int rank_lt(int left, int right, Val bottom) const {
		int lt, gt;
		rank_all(bottom, left, right, lt, gt);
		return lt;
	}
	int query(int left, int right, Val top, Val bottom) const {
		if (top >= bottom) return 0;
		return rank_lt(left, right, bottom) - rank_lt(left, right, top);
	}
};

int main() {
	int n; int q;
	while (~scanf("%d%d", &n, &q)) {
		vector<int> p(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &p[i]), -- p[i];
		WaveletMatrix wm;
		wm.init(vector<unsigned>(p.begin(), p.end()));
		auto calc = [](int n) { return (ll)n * (n - 1) / 2; };
		rep(ii, q) {
			int xL; int yL; int xR; int yR;
			scanf("%d%d%d%d", &xL, &yL, &xR, &yR), -- xL, -- yL;
			ll ans = calc(n);
			ans -= calc(wm.query(0, n, 0, yL));
			ans -= calc(wm.query(0, n, yR, n));
			ans -= calc(wm.query(0, xL, 0, n));
			ans -= calc(wm.query(xR, n, 0, n));
			ans += calc(wm.query(0, xL, 0, yL));
			ans += calc(wm.query(0, xL, yR, n));
			ans += calc(wm.query(xR, n, 0, yL));
			ans += calc(wm.query(xR, n, yR, n));
			printf("%lld\n", ans);
		}
	}
	return 0;
}