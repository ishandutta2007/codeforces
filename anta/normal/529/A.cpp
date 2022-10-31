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



template<typename Val, typename Compare = std::less<Val>, int BlockSize = 10>
class DirectRMQ {
public:
	typedef int Index;	//int(query)
	typedef char InBlockIndex;
	typedef InBlockIndex (*BlockTypeRef)[BlockSize];
	
	DirectRMQ(Compare comp_ = Compare()):
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
			x * BlockSize + blockTypes[x][l % BlockSize][BlockSize-1],
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
				x * BlockSize + blockTypes[x][l % BlockSize][BlockSize-1],
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
			a[x * BlockSize + blockTypes[x][l % BlockSize][BlockSize-1]],
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

	int ballotNumbers[BlockSize+1][BlockSize+1];
	InBlockIndex (*innerBlockTable)[BlockSize][BlockSize];

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
			b[i] = i * BlockSize + blockTypes[i][0][BlockSize-1];
		for(Index t = 1; t*2 < blocks; t *= 2) {
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
		Val tmp_rp[BlockSize+1];
		for(Index i = 0; i < blocks; i ++)
			blockTypes[i] = calcBlockType(getBlock(a, n, i), tmp_rp);
	}

	BlockTypeRef calcBlockType(const Val *a, Val *rp) {
		int q = BlockSize, N = 0;
		for(int i = 0; i < BlockSize; i ++) {
			while(q + i - BlockSize > 0 && comp(a[i], rp[q + i - BlockSize])) {
				N += ballotNumbers[BlockSize-i-1][q];
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
						(q ? ballotNumbers[p][q-1] : 0) +
						(p ? ballotNumbers[p-1][q] : 0);
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
	inline Index length() const { return suffixArray.size() - 1; }
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
	suffixArray.resize(n+1);
	if(n == 0) suffixArray[0] = 0;
	else {
		//I = sizeof(Index) * CHAR_BITS 
		//suffixArray + bucketOffsets + types + 
		//= n*I + max(AlphaSize, n/2)*I + 2*n + O(log n) bits
		//I = 4 * 32AlphaSize:
		//(6+1/16) * n + O(log n) bytes
		std::vector<Index> bucketOffsets(std::max(AlphaSize, (n+1) / 2) + 1);
		sa_is<Alpha>(str, n, AlphaSize, &suffixArray[0], bucketOffsets);
	}
}

void SuffixArray::build(const Alpha *str, Index n) {
	Alpha maxElem = *std::max_element(str, str + n);
	assert(maxElem+0 < std::numeric_limits<int>::max());
	build(str, n, (int)(maxElem+1));
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
	std::vector<bool> types(n+1);
	types[n-1] = 0; types[n] = 1;
	for(Index i = n-2; i >= 0; i --)
		types[i] = str[i] < str[i+1] || (str[i] == str[i+1] && types[i+1]);

	countAlphabets(str, n, AlphaSize, bucketOffsets);
	getBucketOffsets(str, n, true, AlphaSize, bucketOffsets);
	std::fill(sa, sa + n + 1, -1);
	for(Index i = 1; i < n; i ++)
		if(types[i] && !types[i-1]) sa[-- bucketOffsets[(int)str[i]]] = i;
	sa[0] = n;
	inducedSort(str, n, AlphaSize, types, sa, bucketOffsets);

	Index n1 = 0;
	for(Index i = 0; i <= n; i ++) {
		Index j = sa[i];
		if(j > 0 && types[j] && !types[j-1]) sa[n1 ++] = j;
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
				}else if(j != pos && ((types[j] && !types[j-1]) || (types[k] && !types[k-1])))
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
		if(types[i] && !types[i-1]) s1[j ++] = i;
	for(Index i = 0; i < n1; i ++) sa1[i] = s1[sa1[i]];
	std::fill(sa + n1, sa + n + 1, -1);
	for(Index i = n1-1; i >= 1; i --) {
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
	}else alphabetCounts = bucketOffsets.begin() + AlphaSize;
	Index cumsum = 1;	//'$'
	if(dir) {
		for(int i = 0; i < AlphaSize; i ++) {
			cumsum += alphabetCounts[i];
			bucketOffsets[i] = cumsum;
		}
	}else {
		for(int i = 0; i < AlphaSize; i ++) {
			Index x = alphabetCounts[i];
			bucketOffsets[i] = cumsum;
			cumsum += x;
		}
	}
}

void SuffixArray::buildInverseSuffixArray() {
	Index n = length();
	inverseSuffixArray.resize(n+1);
	for(Index i = 0; i <= n; i ++)
		inverseSuffixArray[suffixArray[i]] = i;
}

void SuffixArray::computeLCPArray(const Alpha *str) {
	int n = length();
	lcpArray.resize(n+2);
	Index h = 0;
	for(Index i = 0; i < n; i ++) {
		Index pos = inverseSuffixArray[i];
		Index j = suffixArray[pos-1];
		Index hbound = std::min(n - j, n - i);
		for(Index k = 0; h < hbound && str[i+h] == str[j+h]; ++ h) ;
		lcpArray[pos-1] = h;
		if(h > 0) -- h;
	}
	lcpArray[n] = lcpArray[n+1] = 0;
}

SuffixArray::Index SuffixArray::computeLCP(Index i, Index j) const {
	Index n = length();
	if(i == j) return n - i;
	Index x = inverseSuffixArray[i], y = inverseSuffixArray[j];
	if(x > y) std::swap(x, y);
	return lcpArrayRMQ.queryVal(&lcpArray[0], x, y-1);
}


struct Sum {
	int miniLv, addLv;
	Sum(): miniLv(0), addLv(0) { }
	Sum(char c): miniLv(c == '(' ? 0 : -1), addLv(c == '(' ? 1 : -1) { }
	void add_front(char c) {
		*this = Sum(c) + *this;
	}
	void add_back(char c) {
		*this = *this + Sum(c);
	}
	Sum operator+(const Sum &that) const {
		Sum res;
		res.miniLv = min(miniLv, addLv + that.miniLv);
		res.addLv = addLv + that.addLv;
		return res;
	}
};

struct TwoStackQueue {
	typedef char Val;

	//queue = reverse(vals2) ++ vals1
	vector<Val> vals1, vals2;
	vector<Sum> sums1, sums2;

	pair<Sum,Sum> getsumparts() const {
		Sum s1 = sums1.empty() ? Sum() : sums1.back();
		Sum s2 = sums2.empty() ? Sum() : sums2.back();
		return make_pair(s2, s1);
	}
	void push(const Val &v) {
		Sum s = !sums1.empty() ? sums1.back() : Sum();
		s.add_back(v);
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
			s.add_front(vals2[i]);
			sums2[i] = s;
		}
	}
};


bool compareJoinedStrings(int K1, pii s1[/*K1*/], int K2, pii s2[/*K2*/], const SuffixArray &sa, const char *S) {
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
	return (i1 < K1) < (i2 < K2);
}

bool compare(int n, int len1, int len2, int i1, int i2, int h1, int h2, const SuffixArray &sa, const char *S) {
	if(len1 != len2) return len1 < len2;
	int O = n + n + 1, C = O + n + 1;
	int len = len1;
	pii s1[3] = { mp(O, h1), mp(i1, n), mp(C, len - n - h1) };
	pii s2[3] = { mp(O, h2), mp(i2, n), mp(C, len - n - h2) };
	return compareJoinedStrings(3, s1, 3, s2, sa, S);
}

int main() {
	char *S = new char[4000004];
	char *ans = new char[2000001];
	while(~scanf("%s", S)) {
	int n = strlen(S);
	rep(i, n) S[n+i] = S[i];
	S[n+n] = '$';
	char *O = S + (n+n+1);
	rep(i, n) O[i] = '(';
	O[n] = '$';
	char *C = O + (n+1);
	rep(i, n) C[i] = ')';
	C[n] = 0;
	SuffixArray sa;
	sa.buildAll(S, n + n + 1 + n + 1 + n);

	int minLen = INF;
	int minHead = 0, minPos = -1;
	TwoStackQueue q;
	rep(i, n) q.push(S[i]);
	rep(i, n) {
		pair<Sum,Sum> p = q.getsumparts();
		Sum sum = p.first + p.second;
		int len = n + sum.addLv + -sum.miniLv * 2;
		int head = -sum.miniLv;
//		cerr << i << ": "<< sum.addLv << ", " << sum.miniLv << ", " << len << ", " << head << endl;
		if(compare(n, len, minLen, i, minPos, head, minHead, sa, S)) {
			minLen = len;
			minPos = i;
			minHead = head;
		}
		q.pop();
		q.push(S[i]);
	}
	char *p = ans;
	rep(k, minHead) *(p ++) = '(';
	rep(i, n) *(p ++) = S[minPos+i];
	rep(i, minLen - n - minHead) *(p ++) = ')';
	*p = 0;
	puts(ans);
	}
	return 0;
}