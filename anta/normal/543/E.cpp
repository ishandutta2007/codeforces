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
		if(length == 0) return;
		ranktable.assign(blockslength + 1, 0);
		for(Index i = 0; i < blockslength; i ++) {
			ranktable[i] = count;
			count += popcount(blocks[i]);
		}
		ranktable[blockslength] = count;
	}
	inline bool access(Index pos) const { return blocks[pos / 32] >> pos % 32 & 1; }
	inline Index rank(Index pos) const {	//[0..pos)1
		int block_idx = pos / 32;
		return ranktable[block_idx] + popcount(blocks[block_idx] & (1U << pos % 32)-1);
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
		bitnum = 1; while((maxval >> 1 >> (bitnum-1)) != 0) ++ bitnum;

		bitvectors.assign(bitnum, BitVector(length));
		mids.resize(bitnum);

		vector<Val> cur = data, next; next.resize(length);
		for(int i = 0; i < bitnum; i ++) {
			Val mask = Val(1) << (bitnum - 1 - i);
			Index zeros = 0;
			for(Index j = 0, n = length; j < n; j ++)
				zeros += (cur[j] & mask) == 0;
			mids[i] = zeros;

			BitVector &bv = bitvectors[i];
			Index zeroPos = 0, onePos = zeros;
			for(Index j = 0, n = length; j < n; j ++) {
				bool b = (cur[j] & mask) != 0;
				if(b) next[onePos  ++] = cur[j], bv.set(j);
				else  next[zeroPos ++] = cur[j];
			}
			bv.build();
			next.swap(cur);
		}
	}
	Val access(Index pos) const {
		Val val = 0;
		for(int i = 0; i < bitnum; i ++) {
			const BitVector &bv = bitvectors[i];
			bool dir = bv.access(pos);
			val = val << 1 | (dir ? 1 : 0);
			pos = bv.rank(dir, pos);
			if(dir) pos += mids[i];
		}
		return val;
	}
	Val quantile(int left, int right, int k) const {
		if(k < 0 || right - left <= k) { return -1; }
		Val val = 0;
		for(int i = 0; i < bitnum; i ++) {
			const BitVector &bv = bitvectors[i];
			int count = bv.rank(true, left, right);
			bool dir = k < count;
			val = val << 1 | (dir ? 1 : 0);
			if(!dir) k -= count;
			left = bv.rank(dir, left), right = bv.rank(dir, right);
			if(dir) left += mids[i], right += mids[i];
		}
		return val;
	}
	int rank_all(Val val, int left, int right, int &res_lt, int &res_gt) const {
		if(val > maxval) {
			res_lt = right - left;
			res_gt = 0;
			return 0;
		}
		res_lt = res_gt = 0;
		for(int i = 0; i < bitnum; i ++) {
			const BitVector &bv = bitvectors[i];
			bool dir = val >> (bitnum - i - 1) & 1;
			int leftcount = bv.rank(dir, left), rightcount = bv.rank(dir, right);
			(dir ? res_lt : res_gt) += (right - left) - (rightcount - leftcount);
			left = leftcount, right = rightcount;
			if(dir) left += mids[i], right += mids[i];
		}
		return right - left;
	}
};

struct Sum {
	int sum, minPrefix;
	Sum(): sum(0), minPrefix(0) { }
	Sum(int sum_, int minPrefix_): sum(sum_), minPrefix(minPrefix_) { }
	Sum operator+(const Sum &that) const {
		Sum s;
		s.sum = sum + that.sum;
		s.minPrefix = min(minPrefix, sum + that.minPrefix);
		return s;
	}
	Sum &operator+=(const Sum &that) {
		amin(minPrefix, sum + that.minPrefix);
		sum += that.sum;
		return *this;
	}
};

struct PackedArray {
	vector<unsigned> data;
	void resize(size_t bits) {
		data.resize((bits + 31) / 32 + 1);
	}

	unsigned get(int offset, int size) const {
		const unsigned * const block = &data[offset / 32];
		const int bitpos = offset % 32;
		if(bitpos + size <= 32) {
			return (block[0] >> bitpos) & Mask(size);
		}else {
			return (block[0] >> bitpos | block[1] << (32 - bitpos)) & Mask(size);
		}
	}
	void set(int offset, int size, unsigned x) {
		unsigned * const block = &data[offset / 32];
		const int bitpos = offset % 32;
		if(bitpos + size <= 32) {
			block[0] = block[0] & ~(Mask(size) << bitpos) | (x << bitpos);
		}else {
			block[0] = block[0] & Mask(bitpos) | (x << bitpos);
			block[1] = block[1] & ~Mask(bitpos + size - 32) | (x >> (32 - bitpos));
		}
	}
	static unsigned Mask(int size) { return (2U << (size-1)) - 1; }
};

extern PackedArray vNodes;

static const int Degree = 4;
struct NodeIndex {
	static const int NodeIndexBits = 22;
	static const int SumOffset = NodeIndexBits * Degree;
	static const int SumBits = 19;
	static const int PrefixMinBits = 18;
	static const int NodeBits = NodeIndexBits * 4 + SumBits + PrefixMinBits;

	int index;
	NodeIndex(): index(-1) { }
	explicit NodeIndex(int index_): index(index_) { }

	unsigned localGet(int offset, int size) const {
		return vNodes.get(index * NodeBits + offset, size);
	}
	void localSet(int offset, int size, unsigned x) {
		vNodes.set(index * NodeBits + offset, size, x);
	}

	NodeIndex getChild(int i) const {
		int k = localGet(i * NodeIndexBits, NodeIndexBits);
		return NodeIndex(k-1);
	}

	void setChild(int i, NodeIndex c) {
		localSet(i * NodeIndexBits, NodeIndexBits, c.index + 1);
	}

	Sum getSum() const {
		int sum = (int)localGet(SumOffset, SumBits) - (1 << (SumBits-1));
		int prefixMin = -(int)localGet(SumOffset + SumBits, PrefixMinBits);
		return Sum(sum, prefixMin);
	}

	void setSum(Sum sum) {
		localSet(SumOffset, SumBits, (unsigned)(sum.sum + (1 << (SumBits-1))));
		localSet(SumOffset + SumBits, PrefixMinBits, (unsigned)-sum.minPrefix);
	}
};



PackedArray vNodes;
int vNodesSize, nNodes, prevTime;
NodeIndex newNode() {
	if(nNodes >= vNodesSize) {
		cerr << "memory exhausted" << endl;
		abort();
	}
	return NodeIndex(nNodes ++);
}

int n, m;
vector<int> a;
vector<int> curseq;
int curq;

Sum getSum(NodeIndex node, int l, int r) {
	if(l == r) {
		return Sum();
	}else if(l + 1 == r) {
		int sum;
		if(curq == -1)
			sum = curseq[l];
		else
			sum = (a[l+m] < curq) - (a[l] < curq);
		return Sum(sum, min(0, sum));
	}else {
		return node.getSum();
	}
}

Sum aggregateSum(NodeIndex t, int l, int r) {
	Sum sum;
	rep(k, Degree) {
		int cl = l + (r - l) * k / Degree;
		int cr = l + (r - l) * (k+1) / Degree;
		sum += getSum(t.getChild(k), cl, cr);
	}
	assert(-n <= sum.sum && sum.sum <= n);
	return sum;
}

void updateNode(NodeIndex t, int l, int r) {
	t.setSum(aggregateSum(t, l, r));
}

NodeIndex construct(int l, int r) {
	if(l == r || l + 1 == r)
		return NodeIndex();
	NodeIndex t = newNode();
	rep(k, Degree) {
		int cl = l + (r - l) * k / Degree;
		int cr = l + (r - l) * (k+1) / Degree;
		t.setChild(k, construct(cl, cr));
	}
	updateNode(t, l, r);
	return t;
}

const NodeIndex leafUpdated(const NodeIndex t, int i, int l, int r) {
	if(l == r || l + 1 == r)
		return NodeIndex();
	if(i < l || r <= i)
		return t;
	NodeIndex u = prevTime <= t.index ? t : newNode();
	int m = (l + r) / 2;
	rep(k, Degree) {
		int cl = l + (r - l) * k / Degree;
		int cr = l + (r - l) * (k+1) / Degree;
		u.setChild(k, leafUpdated(t.getChild(k), i, cl, cr));
	}
	updateNode(u, l, r);
	return u;
}

Sum querySum(const NodeIndex t, int ql, int qr, int l, int r) {
	if(qr <= l || r <= ql)
		return Sum();
	if(ql <= l && r <= qr)
		return getSum(t, l, r);
	Sum sum;
	rep(k, Degree) {
		int cl = l + (r - l) * k / Degree;
		int cr = l + (r - l) * (k+1) / Degree;
		sum += querySum(t.getChild(k), ql, qr, cl, cr);
	}
	return sum;
}

int main() {
	scanf("%d%d", &n, &m);

	vNodesSize = (n - m) + (9 + 8) * n;
	vNodes.resize(vNodesSize * NodeIndex::NodeBits);
	nNodes = 0;

	a.resize(n);
	rep(i, n) {
		scanf("%d", &a[i]);
//		a[i]=rand();
	}
	vi values = a;
	sort(all(values)); values.erase(unique(all(values)), values.end());
	int X = values.size();
	vpii ais(n);
	rep(i, n) ais[i] = mp(a[i], i);
	sort(all(ais));

	curseq.assign(n - m, 0);
	curq = -1;

	vector<NodeIndex> history(X+1);

	prevTime = 0;
	NodeIndex curt = construct(0, n - m);
	for(int ix = 0, ai = 0; ; ++ ix) {
		history[ix] = curt;
		if(ix == X) break;

		prevTime = nNodes;
		int x = values[ix];
		for(; ai < n && ais[ai].first == x; ++ ai) {
			int i = ais[ai].second;
			if(0 <= i - m) {
				++ curseq[i - m];
				curt = leafUpdated(curt, i - m, 0, n - m);
			}
			if(i < n - m) {
				-- curseq[i];
				curt = leafUpdated(curt, i, 0, n - m);
			}
		}
	}

	WaveletMatrix wm;
	wm.init(vector<unsigned>(all(a)));
	int s;
	scanf("%d", &s);
	int lastans = 0;
	rep(ii, s) {
		int l, r, xx;
		scanf("%d%d%d", &l, &r, &xx), -- l;
//		l=rand()%(n-m+1),r=rand()%(n-m+1);if(l>r)swap(l,r);++r; xx=rand();
		int q = lastans ^ xx;
		curq = q;

		int base;
		{	int lt, gt; wm.rank_all(q, l, l + m, lt, gt);
			base = lt;
		}
		int xi = upper_bound(all(values), q-1) - values.begin();

		Sum sum = querySum(history[xi], l, r - 1, 0, n - m);
		int ans = base + sum.minPrefix;

		/*
		int naiveans = base, naivet = base;
		reu(i, l + 1, r) {
			naivet -= a[i-1] < q;
			naivet += a[i+m-1] < q;
			amin(naiveans, naivet);
		}
		if(ans != naiveans) {
			cerr << ans << " != " << naiveans << endl;
			reu(i, l, r) cerr << querySum(history[xi], i, i+1, 0, n-m).sum << ", "; cerr << endl;
		}
//		*/
		
		printf("%d\n", ans);
		lastans = ans;
	}
	return 0;
}