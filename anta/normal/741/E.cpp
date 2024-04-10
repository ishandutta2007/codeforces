#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }


template<typename Val, typename Compare = std::less<Val>, int BlockSize = 10>
class DirectRMQ {
public:
	typedef int Index;	//int(query)
	typedef char InBlockIndex;
	typedef InBlockIndex(*BlockTypeRef)[BlockSize];

	DirectRMQ(Compare comp_ = Compare()) :
		blockTypes(0), innerBlockTable(0), sparseTable(0) {
		comp = comp_;
		calcBallotNumbers();
		buildInnerBlockTable();
	}
	~DirectRMQ() {
		delete[] innerBlockTable;
		delete[] blockTypes; delete[] sparseTable;
	}

	void build(const Val *a, Index n) {
		blocks = (n + BlockSize - 1) / BlockSize;
		stHeight = 0; while(1 << stHeight < blocks) ++ stHeight;
		delete[] blockTypes; delete[] sparseTable;

		blockTypes = new BlockTypeRef[blocks];
		calcBlockTypes(a, n);
		buildInnerBlockTable(a, n);
		sparseTable = new Index[blocks * stHeight];
		buildSparseTable(a);
	}

	//[l,r]
	Index query(const Val *a, Index l, Index r) const {
		Index x = l / BlockSize, y = r / BlockSize, z = y - x;
		if(z == 0) return x * BlockSize + blockTypes[x][l % BlockSize][r % BlockSize];
		if(z == 1) return assumeleft_minIndex(a,
			x * BlockSize + blockTypes[x][l % BlockSize][BlockSize - 1],
			y * BlockSize + blockTypes[y][0][r % BlockSize]);
		z -= 2;
		Index k = 0, s;
		s = ((z & 0xffff0000) != 0) << 4; z >>= s; k |= s;
		s = ((z & 0x0000ff00) != 0) << 3; z >>= s; k |= s;
		s = ((z & 0x000000f0) != 0) << 2; z >>= s; k |= s;
		s = ((z & 0x0000000c) != 0) << 1; z >>= s; k |= s;
		s = ((z & 0x00000002) != 0) << 0; z >>= s; k |= s;
		return assumeleft_minIndex(a
			, assumeleft_minIndex(a,
				x * BlockSize + blockTypes[x][l % BlockSize][BlockSize - 1],
				sparseTable[x + 1 + blocks * k])
			, assumeleft_minIndex(a,
				sparseTable[y + blocks * k - (1 << k)],
				y * BlockSize + blockTypes[y][0][r % BlockSize])
		);
	}

	Val queryVal(const Val *a, Index l, Index r) const {
		Index x = l / BlockSize, y = r / BlockSize, z = y - x;
		if(z == 0) return a[x * BlockSize + blockTypes[x][l % BlockSize][r % BlockSize]];
		Val edge = minVal(
			a[x * BlockSize + blockTypes[x][l % BlockSize][BlockSize - 1]],
			a[y * BlockSize + blockTypes[y][0][r % BlockSize]]);
		if(z == 1) return edge;
		z -= 2;
		Index k = 0, s;
		s = ((z & 0xffff0000) != 0) << 4; z >>= s; k |= s;
		s = ((z & 0x0000ff00) != 0) << 3; z >>= s; k |= s;
		s = ((z & 0x000000f0) != 0) << 2; z >>= s; k |= s;
		s = ((z & 0x0000000c) != 0) << 1; z >>= s; k |= s;
		s = ((z & 0x00000002) != 0) << 0; z >>= s; k |= s;
		return minVal(edge, minVal(
			a[sparseTable[x + 1 + blocks * k]],
			a[sparseTable[y + blocks * k - (1 << k)]]));
	}
private:
	Compare comp;

	int ballotNumbers[BlockSize + 1][BlockSize + 1];
	InBlockIndex(*innerBlockTable)[BlockSize][BlockSize];

	Index blocks;
	int stHeight;
	BlockTypeRef *blockTypes;
	Index *sparseTable;

	inline Index minIndex(const Val *a, Index x, Index y) const {
		return comp(a[x], a[y]) || (a[x] == a[y] && x < y) ? x : y;
	}
	inline Index assumeleft_minIndex(const Val *a, Index x, Index y) const {
		return comp(a[y], a[x]) ? y : x;
	}

	inline Val minVal(Val x, Val y) const {
		return comp(y, x) ? y : x;
	}

	void buildSparseTable(const Val *a) {
		Index *b = sparseTable;
		if(stHeight) for(Index i = 0; i < blocks; i ++)
			b[i] = i * BlockSize + blockTypes[i][0][BlockSize - 1];
		for(Index t = 1; t * 2 < blocks; t *= 2) {
			std::memcpy(b + blocks, b, blocks * sizeof(Index));
			b += blocks;
			for(Index i = 0; i < blocks - t; ++ i)
				b[i] = assumeleft_minIndex(a, b[i], b[i + t]);
		}
	}

	void buildInnerBlockTable(const Val *a, Index n) {
		for(Index i = 0; i < blocks; i ++) {
			BlockTypeRef table = blockTypes[i];
			if(table[0][0] != -1) continue;
			const Val *p = getBlock(a, n, i);
			for(InBlockIndex left = 0; left < BlockSize; left ++) {
				Val minV = p[left];
				InBlockIndex minI = left;
				for(InBlockIndex right = left; right < BlockSize; right ++) {
					if(comp(p[right], minV)) {
						minV = p[right];
						minI = right;
					}
					table[left][right] = minI;
				}
			}
		}
	}

	//static
	const Val *getBlock(const Val *a, Index n, Index i) {
		Index offset = i * BlockSize;
		if(offset + BlockSize <= n)
			return a + offset;
		else {
			static Val tmp_a[BlockSize];
			std::copy(a + offset, a + n, tmp_a);
			Val maxVal = Val();
			for(Index j = i; j < n; j ++)	//ioffset()(())
				if(comp(maxVal, a[j])) maxVal = a[j];
			std::fill(tmp_a + (n - offset), tmp_a + BlockSize, maxVal);
			return tmp_a;
		}
	}

	void calcBlockTypes(const Val *a, Index n) {
		Val tmp_rp[BlockSize + 1];
		for(Index i = 0; i < blocks; i ++)
			blockTypes[i] = calcBlockType(getBlock(a, n, i), tmp_rp);
	}

	BlockTypeRef calcBlockType(const Val *a, Val *rp) {
		int q = BlockSize, N = 0;
		for(int i = 0; i < BlockSize; i ++) {
			while(q + i - BlockSize > 0 && comp(a[i], rp[q + i - BlockSize])) {
				N += ballotNumbers[BlockSize - i - 1][q];
				q --;
			}
			rp[q + i + 1 - BlockSize] = a[i];
		}
		return innerBlockTable[N];
	}

	void calcBallotNumbers() {
		for(int p = 0; p <= BlockSize; p ++) {
			for(int q = 0; q <= BlockSize; q ++) {
				if(p == 0 && q == 0)
					ballotNumbers[p][q] = 1;
				else if(p <= q)
					ballotNumbers[p][q] =
					(q ? ballotNumbers[p][q - 1] : 0) +
					(p ? ballotNumbers[p - 1][q] : 0);
				else
					ballotNumbers[p][q] = 0;
			}
		}
	}

	void buildInnerBlockTable() {
		int numberOfTrees = ballotNumbers[BlockSize][BlockSize];
		innerBlockTable = new InBlockIndex[numberOfTrees][BlockSize][BlockSize];
		for(int i = 0; i < numberOfTrees; i ++)
			innerBlockTable[i][0][0] = -1;
	}
};

class SuffixArray {
public:
	typedef char Alpha;
	typedef int Index;

	void build(const Alpha *str, Index n, int AlphaSize);
	void build(const Alpha *str, Index n);
	void buildAll(const Alpha *str, Index n);
	inline Index getKThSuffix(Index k) const { return suffixArray[k]; }
	inline Index length() const { return static_cast<Index>(suffixArray.size() - 1); }
	std::vector<Index> suffixArray;
	template<typename AlphaT> void sa_is(const AlphaT *str, Index n, int AlphaSize, Index *sa, std::vector<Index> &bucketOffsets);
	template<typename AlphaT> void inducedSort(const AlphaT *str, Index n, int AlphaSize, const std::vector<bool> &types, Index *sa, std::vector<Index> &bucketOffsets);
	template<typename AlphaT> void countAlphabets(const AlphaT *str, Index n, int AlphaSize, std::vector<Index> &bucketOffsets, bool b = false);
	template<typename AlphaT> void getBucketOffsets(const AlphaT *str, Index n, bool dir, int AlphaSize, std::vector<Index> &bucketOffsets);
	void buildInverseSuffixArray();
	std::vector<Index> inverseSuffixArray;
	void computeLCPArray(const Alpha *str);
	std::vector<Index> lcpArray;
	typedef DirectRMQ<Index> LCPArrayRMQ;
	LCPArrayRMQ lcpArrayRMQ;
	void preprocessLCPArrayRMQ() {
		lcpArrayRMQ.build(&lcpArray[0], length() + 1);
	}
	Index computeLCP(Index i, Index j) const;
};

void SuffixArray::build(const Alpha *str, Index n, int AlphaSize) {
	suffixArray.resize(n + 1);
	if(n == 0) suffixArray[0] = 0;
	else {
		//I = sizeof(Index) * CHAR_BITS 
		//suffixArray + bucketOffsets + types + 
		//= n*I + max(AlphaSize, n/2)*I + 2*n + O(log n) bits
		//I = 4 * 32AlphaSize:
		//(6+1/16) * n + O(log n) bytes
		std::vector<Index> bucketOffsets(std::max(AlphaSize, (n + 1) / 2) + 1);
		sa_is<Alpha>(str, n, AlphaSize, &suffixArray[0], bucketOffsets);
	}
}

void SuffixArray::build(const Alpha *str, Index n) {
	Alpha maxElem = *std::max_element(str, str + n);
	assert(maxElem + 0 < std::numeric_limits<int>::max());
	build(str, n, (int)(maxElem + 1));
}

void SuffixArray::buildAll(const Alpha *str, Index n) {
	build(str, n);
	buildInverseSuffixArray();
	computeLCPArray(str);
	preprocessLCPArrayRMQ();
}

//str[0,n)sa[0,n]
template<typename AlphaT>
void SuffixArray::sa_is(const AlphaT *str, Index n, int AlphaSize, Index *sa, std::vector<Index> &bucketOffsets) {
	std::vector<bool> types(n + 1);
	types[n - 1] = 0; types[n] = 1;
	for(Index i = n - 2; i >= 0; i --)
		types[i] = str[i] < str[i + 1] || (str[i] == str[i + 1] && types[i + 1]);

	countAlphabets(str, n, AlphaSize, bucketOffsets);
	getBucketOffsets(str, n, true, AlphaSize, bucketOffsets);
	std::fill(sa, sa + n + 1, -1);
	for(Index i = 1; i < n; i ++)
		if(types[i] && !types[i - 1]) sa[-- bucketOffsets[(int)str[i]]] = i;
	sa[0] = n;
	inducedSort(str, n, AlphaSize, types, sa, bucketOffsets);

	Index n1 = 0;
	for(Index i = 0; i <= n; i ++) {
		Index j = sa[i];
		if(j > 0 && types[j] && !types[j - 1]) sa[n1 ++] = j;
	}

	//LMS substringssa[0..n1-1]
	//sa
	//pos
	//LMS substringLMS substringn/21
	Index *buffer = sa + n1;
	std::fill(buffer, sa + n + 1, -1);
	Index uniqueLMSCount = 0, prevPos = -1;
	assert(sa[0] == n);
	buffer[sa[0] / 2] = uniqueLMSCount ++;	//'$'
	for(Index i = 1; i < n1; i ++) {
		Index pos = sa[i]; bool diff = false;
		if(prevPos == -1) diff = true;
		else for(Index j = pos, k = prevPos; ; j ++, k ++) {
			if(str[j] != str[k] || types[j] != types[k]) {
				diff = true;
				break;
			} else if(j != pos && ((types[j] && !types[j - 1]) || (types[k] && !types[k - 1])))
				break;
		}
		if(diff) {
			uniqueLMSCount ++;
			prevPos = pos;
		}
		buffer[pos / 2] = uniqueLMSCount - 1;
	}
	for(Index i = n, j = n; i >= n1; i --)
		if(sa[i] >= 0) sa[j --] = sa[i];

	Index *sa1 = sa, *s1 = sa + n + 1 - n1;
	if(uniqueLMSCount == n1)
		for(Index i = 0; i < n1; i ++) sa1[s1[i]] = i;
	else
		sa_is<Index>(s1, n1 - 1, uniqueLMSCount, sa1, bucketOffsets);

	countAlphabets(str, n, AlphaSize, bucketOffsets);
	getBucketOffsets(str, n, true, AlphaSize, bucketOffsets);
	for(Index i = 1, j = 0; i <= n; i ++)
		if(types[i] && !types[i - 1]) s1[j ++] = i;
	for(Index i = 0; i < n1; i ++) sa1[i] = s1[sa1[i]];
	std::fill(sa + n1, sa + n + 1, -1);
	for(Index i = n1 - 1; i >= 1; i --) {
		Index j = sa[i]; sa[i] = -1;
		sa[-- bucketOffsets[(int)str[j]]] = j;
	}
	inducedSort(str, n, AlphaSize, types, sa, bucketOffsets);
}

template<typename AlphaT>
void SuffixArray::inducedSort(const AlphaT *str, Index n, int AlphaSize, const std::vector<bool> &types, Index *sa, std::vector<Index> &bucketOffsets) {
	getBucketOffsets(str, n, false, AlphaSize, bucketOffsets);
	for(Index i = 0; i < n; i ++) {
		Index j = sa[i] - 1;
		if(j >= 0 && !types[j]) sa[bucketOffsets[(int)str[j]] ++] = j;
	}

	getBucketOffsets(str, n, true, AlphaSize, bucketOffsets);
	for(Index i = n; i >= 1; i --) {
		Index j = sa[i] - 1;
		if(j >= 0 && types[j]) sa[-- bucketOffsets[(int)str[j]]] = j;
	}
}

template<typename AlphaT>
void SuffixArray::countAlphabets(const AlphaT *str, Index n, int AlphaSize, std::vector<Index> &bucketOffsets, bool b) {
	if(b || (int)bucketOffsets.size() / 2 >= AlphaSize) {
		std::vector<Index>::iterator alphabetCounts =
			b ? bucketOffsets.begin() : bucketOffsets.begin() + AlphaSize;
		std::fill(alphabetCounts, alphabetCounts + AlphaSize, 0);
		for(Index i = 0; i < n; i ++)
			alphabetCounts[(int)str[i]] ++;
	}
}

template<typename AlphaT>
void SuffixArray::getBucketOffsets(const AlphaT *str, Index n, bool dir, int AlphaSize, std::vector<Index> &bucketOffsets) {
	//AlphaSizebucketOffsetalphabet
	//AlphaSizebucketOffsetalphabetCounts
	std::vector<Index>::iterator alphabetCounts;
	if((int)bucketOffsets.size() / 2 < AlphaSize) {
		countAlphabets(str, n, AlphaSize, bucketOffsets, true);
		alphabetCounts = bucketOffsets.begin();
	} else alphabetCounts = bucketOffsets.begin() + AlphaSize;
	Index cumsum = 1;	//'$'
	if(dir) {
		for(int i = 0; i < AlphaSize; i ++) {
			cumsum += alphabetCounts[i];
			bucketOffsets[i] = cumsum;
		}
	} else {
		for(int i = 0; i < AlphaSize; i ++) {
			Index x = alphabetCounts[i];
			bucketOffsets[i] = cumsum;
			cumsum += x;
		}
	}
}

void SuffixArray::buildInverseSuffixArray() {
	Index n = length();
	inverseSuffixArray.resize(n + 1);
	for(Index i = 0; i <= n; i ++)
		inverseSuffixArray[suffixArray[i]] = i;
}

void SuffixArray::computeLCPArray(const Alpha *str) {
	int n = length();
	lcpArray.resize(n + 2);
	Index h = 0;
	for(Index i = 0; i < n; i ++) {
		Index pos = inverseSuffixArray[i];
		Index j = suffixArray[pos - 1];
		Index hbound = std::min(n - j, n - i);
		for(Index k = 0; h < hbound && str[i + h] == str[j + h]; ++ h);
		lcpArray[pos - 1] = h;
		if(h > 0) -- h;
	}
	lcpArray[n] = lcpArray[n + 1] = 0;
}

SuffixArray::Index SuffixArray::computeLCP(Index i, Index j) const {
	Index n = length();
	if(i == j) return n - i;
	Index x = inverseSuffixArray[i], y = inverseSuffixArray[j];
	if(x > y) std::swap(x, y);
	return lcpArrayRMQ.queryVal(&lcpArray[0], x, y - 1);
}

//s1, s2: [(offset, len)]
bool compareJoinedStrings(int K1, pii s1[/*K1*/], int K2, pii s2[/*K2*/], const SuffixArray &sa, const SuffixArray::Alpha *S) {
	int i1 = 0, o1 = 0, i2 = 0, o2 = 0;
	while(i1 < K1 && i2 < K2) {
		int p1 = s1[i1].first + o1, p2 = s2[i2].first + o2;
		int c = sa.computeLCP(p1, p2);
		int r1 = s1[i1].second - o1, r2 = s2[i2].second - o2;
		int d = min(c, min(r1, r2));
		o1 += d, o2 += d;
		if(d < r1 && d < r2)
			return S[p1 + d] < S[p2 + d];
		if(d == r1) ++ i1, o1 = 0;
		if(d == r2) ++ i2, o2 = 0;
	}
	while(i1 < K1 && s1[i1].second == 0) ++ i1;
	while(i2 < K2 && s2[i2].second == 0) ++ i2;
	return (i1 < K1) < (i2 < K2);
}

struct Query {
	int qi;
	int L, R;
};


struct Query2 {
	int qi;
	int L, R;
	int K;
	int X, Y;
};

int main() {
	ios_base::sync_with_stdio(false);
	string S, T;
	while(cin >> S >> T) {
		string ST = S + "$" + T;
		SuffixArray sa;
		sa.buildAll(ST.c_str(), ST.size());
		int n = S.size(), m = T.size();
		vector<int> ord(n + 1);
		rep(i, n + 1) ord[i] = i;
		vector<vector<pii>> ss(n + 1);
		rep(i, n + 1) {
			if(0 < i) ss[i].emplace_back(0, i);
			ss[i].emplace_back(n + 1, m);
			if(i < n) ss[i].emplace_back(i, n - i);
		}
		sort(ord.begin(), ord.end(), [&](int i, int j) {
			auto &&s1 = ss[i], &&s2 = ss[j];
			bool a = compareJoinedStrings(s1.size(), s1.data(), s2.size(), s2.data(), sa, ST.c_str());
			bool b = compareJoinedStrings(s2.size(), s2.data(), s1.size(), s1.data(), sa, ST.c_str());
			if(!a && !b)
				return i < j;
			else
				return a;
		});
		vector<int> value(n + 1, -1);
		rep(i, n + 1) value[ord[i]] = i;
		const int SqrtN = 300;
		vector<vector<Query2>> queriyaaa(SqrtN);
		vector<Query2> queriybbb;
		int Q;
		cin >> Q;
		rep(qi, Q) {
			int L; int R;
			cin >> L >> R; ++ R;
			int K;
			cin >> K;
			int X; int Y;
			cin >> X >> Y; ++ Y;
			Query2 q = {qi, L, R, K, X, Y};
			if(K < SqrtN) {
				/*
				for(int k = X; k < Y; ++ k) {
					int l = (L - k + K - 1) / K;
					int r = (R - k + K - 1) / K;
					if(l < r)
						smallKQueries[K * SqrtN + k].push_back(Query{ qi, l, r });
				}
				*/
				queriyaaa[K].push_back(q);
			} else {
				/*
				for(int i = 0; i <= n; i += K) {
					int l = max(L, i + X), r = min(R, i + Y);
					if(l < r)
						otherQueries.push_back(Query{ qi, l, r });
				}
				*/
				queriybbb.push_back(q);
			}
		}

		vector<pair<int, int>> ans(Q, make_pair(INF, -1));
		DirectRMQ<int> rmq;
		auto update = [&ans, &rmq, &value](const vector<int> &seq, const vector<Query> &queries, auto calcIndex) {
			rmq.build(seq.data(), seq.size());
			for(auto &&q : queries) {
				int x = rmq.query(seq.data(), q.L, q.R - 1);
				int i = calcIndex(x);
				amin(ans[q.qi], make_pair(value[i], i));
			}
		};

		vector<int> seq;
		vector<vector<Query>> smallKQueries(SqrtN);
		reu(K, 1, SqrtN) {
			rep(k, K)
				smallKQueries[k].clear();
			for(auto &&q : queriyaaa[K]) {
				for(int k = q.X; k < q.Y; ++ k) {
					int l = (q.L - k + K - 1) / K;
					int r = (q.R - k + K - 1) / K;
					if(l < r)
						smallKQueries[k].push_back(Query{ q.qi, l, r });
				}
			}
			rep(k, K) {
				seq.clear();
				for(int i = k; i <= n; i += K)
					seq.push_back(value[i]);
				update(seq, smallKQueries[k], [K, k](int i) {
					return i * K + k;
				});
			}
		}
		seq = value;
		vector<Query> otherQueries;
		for(int bL = 0; bL < (int)queriybbb.size(); bL += 1000) {
			int bR = min((int)queriybbb.size(), bL + 1000);
			otherQueries.clear();
			reu(qj, bL, bR) {
				auto &&q = queriybbb[qj];
				for(int i = 0; i <= n; i += q.K) {
					int l = max(q.L, i + q.X), r = min(q.R, i + q.Y);
					if(l < r)
						otherQueries.push_back(Query{ q.qi, l, r });
				}
			}
			update(seq, otherQueries, [](int i) { return i; });
		}

		rep(i, Q)
			cout << ans[i].second << '\n';//printf("%d\n", ans[i].second);
	}
	return 0;
}