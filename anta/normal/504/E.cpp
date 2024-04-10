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
#include <memory>
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
	
	DirectRMQ(Compare comp_ = Compare()) {
		comp = comp_;
		calcBallotNumbers();
		buildInnerBlockTable();
	}

	void build(const Val *a, Index n) {
		blocks = (n + BlockSize - 1) / BlockSize;
		stHeight = 0; while(1 << stHeight < blocks) ++ stHeight;
		
		blockTypes.reset(new BlockTypeRef[blocks]);
		calcBlockTypes(a, n);
		buildInnerBlockTable(a, n);
		sparseTable.reset(new Index[blocks * stHeight]);
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
	std::unique_ptr<InBlockIndex[][BlockSize][BlockSize]> innerBlockTable;

	Index blocks;
	int stHeight;
	std::unique_ptr<BlockTypeRef[]> blockTypes;
	std::unique_ptr<Index[]> sparseTable;

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
		Index *b = sparseTable.get();
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
		innerBlockTable.reset(new InBlockIndex[numberOfTrees][BlockSize][BlockSize]);
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
	inline Index getKThSuffix(Index k) const { return suffixArray[k]; }
	inline Index length() const { return suffixArray.size() - 1; }
	std::vector<Index> suffixArray;
	template<typename AlphaT> void sa_is(const AlphaT *str, Index n, int AlphaSize, Index *sa, std::vector<Index> &bucketOffsets);
	template<typename AlphaT> void inducedSort(const AlphaT *str, Index n, int AlphaSize, const std::vector<bool> &types, Index *sa, std::vector<Index> &bucketOffsets);
	template<typename AlphaT> void countingAlphabets(const AlphaT *str, Index n, int AlphaSize, std::vector<Index> &bucketOffsets, bool b = false);
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
	Index numOccurings(Index i, Index len) const;
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

//str[0,n)sa[0,n]
template<typename AlphaT>
void SuffixArray::sa_is(const AlphaT *str, Index n, int AlphaSize, Index *sa, std::vector<Index> &bucketOffsets) {
	std::vector<bool> types(n+1);
	types[n-1] = 0; types[n] = 1;
	for(Index i = n-2; i >= 0; i --)
		types[i] = str[i] < str[i+1] || (str[i] == str[i+1] && types[i+1]);

	countingAlphabets(str, n, AlphaSize, bucketOffsets);
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

	countingAlphabets(str, n, AlphaSize, bucketOffsets);
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
void SuffixArray::countingAlphabets(const AlphaT *str, Index n, int AlphaSize, std::vector<Index> &bucketOffsets, bool b) {
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
		countingAlphabets(str, n, AlphaSize, bucketOffsets, true);
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

struct CentroidPathDecomposition {
	vector<int> colors, positions;	//Vertex -> Color, Vertex -> Offset
	vector<int> lengths, parents, branches;	//Color -> Int, Color -> Color, Color -> Offset
	vector<int> parentnodes, depths;	//Vertex -> Vertex, Vertex -> Int
	//vector<FenwickTree>1
	//sortednodes[lefts[v], rights[v])vsubtree
	vector<int> sortednodes, offsets;	//Index -> Vertex, Color -> Index
	vector<int> lefts, rights;	//Vertex -> Index

	struct BuildDFSState {
		int i, len, parent;
		BuildDFSState() { }
		BuildDFSState(int i_, int l, int p): i(i_), len(l), parent(p) { }
	};

	//
	void build(const vector<vi> &g, int root) {
		int n = g.size();

		colors.assign(n, -1); positions.assign(n, -1);
		lengths.clear(); parents.clear(); branches.clear();
		parentnodes.assign(n, -1); depths.assign(n, -1);

		sortednodes.clear(); offsets.clear();
		lefts.assign(n, -1); rights.assign(n, -1);

		vector<int> subtreesizes;
		measure(g, root, subtreesizes);

		typedef BuildDFSState State;
		depths[root] = 0;
		vector<State> s;
		s.push_back(State(root, 0, -1));
		while(!s.empty()) {
			State t = s.back(); s.pop_back();
			int i = t.i, len = t.len;
			int index = sortednodes.size();
			int color = lengths.size();

			if(t.parent == -3) {
				rights[i] = index;
				continue;
			}

			if(t.parent != -2) {
				assert(parents.size() == color);
				parents.push_back(t.parent);
				branches.push_back(len);
				offsets.push_back(index);
				len = 0;
			}
			colors[i] = color;
			positions[i] = len;

			lefts[i] = index;
			sortednodes.push_back(i);

			int maxsize = -1, maxj = -1;
			each(j, g[i]) if(colors[*j] == -1) {
				if(maxsize < subtreesizes[*j]) {
					maxsize = subtreesizes[*j];
					maxj = *j;
				}
				parentnodes[*j] = i;
				depths[*j] = depths[i] + 1;
			}
			s.push_back(State(i, -1, -3));
			if(maxj == -1) {
				lengths.push_back(len + 1);
			}else {
				each(j, g[i]) if(colors[*j] == -1 && *j != maxj)
					s.push_back(State(*j, len, color));
				s.push_back(State(maxj, len + 1, -2));
			}
		}
	}
	
	void get(int v, int &c, int &p) const {
		c = colors[v]; p = positions[v];
	}
	bool go_up(int &c, int &p) const {
		p = branches[c]; c = parents[c];
		return c != -1;
	}

	inline const int *nodesBegin(int c) const { return &sortednodes[0] + offsets[c]; }
	inline const int *nodesEnd(int c) const { return &sortednodes[0] + offsets[c+1]; }

private:
	void measure(const vector<vi> &g, int root, vector<int> &out_subtreesizes) const {
		out_subtreesizes.assign(g.size(), -1);
		vector<int> s;
		s.push_back(root);
		while(!s.empty()) {
			int i = s.back(); s.pop_back();
			if(out_subtreesizes[i] == -2) {
				int s = 1;
				each(j, g[i]) if(out_subtreesizes[*j] != -2)
					s += out_subtreesizes[*j];
				out_subtreesizes[i] = s;
			}else {
				s.push_back(i);
				each(j, g[i]) if(out_subtreesizes[*j] == -1)
					s.push_back(*j);
				out_subtreesizes[i] = -2;
			}
		}
	}
};

int lowest_common_ancestor(const CentroidPathDecomposition &cpd, int x, int y) {
	int cx, px, cy, py;
	cpd.get(x, cx, px);
	cpd.get(y, cy, py);
	while(cx != cy) {
		if(cpd.depths[*cpd.nodesBegin(cx)] < cpd.depths[*cpd.nodesBegin(cy)])
			cpd.go_up(cy, py);
		else
			cpd.go_up(cx, px);
	}
	return cpd.nodesBegin(cx)[min(px, py)];
}

int main() {
	int n;
	scanf("%d", &n);
	char *s = new char[n+1];
	scanf("%s", s);
	vector<vi> g(n);
	rep(i, n-1) {
		int u, v;
		scanf("%d%d", &u, &v), -- u, -- v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	CentroidPathDecomposition cpd;
	cpd.build(g, 0);
	char *t = new char[(n+1) * 2];
	rep(i, n)
		t[i] = s[cpd.sortednodes[i]];
	t[n] = '#';
	rep(i, n)
		t[n+1+(n-1-i)] = t[i];
	t[n+1+n] = 0;
//	cerr << "      "; rep(i, n) cerr << i; cerr << endl;
//	cerr << "ord = "; rep(i, n) cerr << cpd.sortednodes[i]; cerr << endl;
	SuffixArray sa;
	sa.build(t, n+1+n);
	sa.buildInverseSuffixArray();
	sa.computeLCPArray(t);
	sa.preprocessLCPArrayRMQ();
	vector<pair<int,pii> > path[2];
//	cerr << "cpd:" << endl; rep(i, cpd.offsets.size()) cerr << i << ": " << cpd.offsets[i] << ", " << cpd.lengths[i] << endl;
	int m;
	scanf("%d", &m);
	rep(ii, m) {
		int u[2], v[2];
		scanf("%d%d%d%d", &u[0], &v[0], &u[1], &v[1]);
		rep(k, 2) {
			-- u[k], -- v[k];
			int w = lowest_common_ancestor(cpd, u[k], v[k]), wc, wp;
			path[k].clear();
			cpd.get(w, wc, wp);
			rep(uv, 2) {
				int c, p;
				cpd.get(uv == 0 ? u[k] : v[k], c, p);
				int sz = path[k].size();
				while(1) {
					int top = c == wc ? wp + uv : 0;
					pii q = uv == 0 ? mp(p + 1, top) : mp(top, p + 1);
					if(q.first != q.second)
						path[k].push_back(mp(c, q));
					if(c == wc) break;
					cpd.go_up(c, p);
				}
				if(uv == 1)
					reverse(path[k].begin() + sz, path[k].end());
			}
//			cerr << "path[" << k << "] = "; each(i, path[k]) cerr << i->first << "," << i->second.first << "," << i->second.second << "; "; cerr << endl;
		}
		int ans = 0;
		int is[2] = { 0, 0 };
		while(is[0] < (int)path[0].size() && is[1] < (int)path[1].size()) {
			int pos[2];
			rep(k, 2) {
				pair<int,pii> &q = path[k][is[k]];
				int c = q.first, l = q.second.first, r = q.second.second;
				if(l >= r)
					pos[k] = n+1+(n - 1 - (cpd.offsets[c] + (l-1)));
				else
					pos[k] = cpd.offsets[c] + l;
			}
			int len = sa.computeLCP(pos[0], pos[1]);
			rep(k, 2) {
				pair<int,pii> &q = path[k][is[k]];
				int l = q.second.first, r = q.second.second;
				amin(len, abs(l - r));
			}
			if(len == 0) break;
			ans += len;
			rep(k, 2) {
				pair<int,pii> &q = path[k][is[k]];
				int c = q.first, &l = q.second.first, r = q.second.second;
				if(l >= r)
					l -= len;
				else
					l += len;
				if(l == r)
					++ is[k];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}