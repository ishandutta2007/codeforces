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
	Val access(Index pos) const {
		Val val = 0;
		for (int i = 0; i < bitnum; i ++) {
			const BitVector &bv = bitvectors[i];
			bool dir = bv.access(pos);
			val = val << 1 | (dir ? 1 : 0);
			pos = bv.rank(dir, pos);
			if (dir) pos += mids[i];
		}
		return val;
	}
	Val quantile(int left, int right, int k) const {
		if (k < 0 || right - left <= k) { return -1; }
		Val val = 0;
		for (int i = 0; i < bitnum; i ++) {
			const BitVector &bv = bitvectors[i];
			int count = bv.rank(true, left, right);
			bool dir = k < count;
			val = val << 1 | (dir ? 1 : 0);
			if (!dir) k -= count;
			left = bv.rank(dir, left), right = bv.rank(dir, right);
			if (dir) left += mids[i], right += mids[i];
		}
		return val;
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
};

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]), -- a[i];
		vector<uint32_t> data(n);
		{
			int A = *max_element(a.begin(), a.end());
			vi prev(A + 1, -1);
			rep(i, n) {
				data[i] = prev[a[i]] + 1;
				prev[a[i]] = i;
			}
		}
		WaveletMatrix wm;
		wm.init(data);
		auto query = [&](int i, int j) {
			int lt, gt;
			wm.rank_all(i + 1, i, j, lt, gt);
			return lt;
		};
		rer(k, 1, n) {
			int ans = 0;
			for (int i = 0; i < n; ++ ans) {
				int lo = min(n, i + k), up = n;
				while (up - lo > 0) {
					int mid = up == n ? min(n, lo + (lo - i)) : (lo + up + 1) / 2;
					if (query(i, mid) <= k)
						lo = mid;
					else
						up = mid - 1;
				}
				i = up;
			}
			if (k != 1) putchar(' ');
			printf("%d", ans);
		}
		puts("");
	}
	return 0;
}