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


class SuffixArray {
public:
	typedef char Alpha;
	typedef int Index;

	void build(const Alpha *str, Index n, int AlphaSize);
	void build(const Alpha *str, Index n);
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

class SchieberVishkinLCA {
public:
	typedef unsigned Word;
	typedef int Vertex;
private:

	static inline Word lowestOneBit(Word v) {
		return v & (~v+1);
	}
	static inline Word highestOneBitMask(Word v) {
		v |= v >> 1; v |= v >> 2; v |= v >> 4; v |= v >> 8; v |= v >> 16;
		return v >> 1;
	}

	std::vector<Word> indices;			//Vertex -> index
	std::vector<Word> maxHIndices;		//Vertex -> index
	std::vector<Word> ancestorHeights;	//Vertex -> Word
	std::vector<Vertex> pathParents;	//index-1 -> Vertex
public:

	void build(const std::vector<Vertex> &preorder, const std::vector<Vertex> &parents, Vertex root) {
		Vertex N = static_cast<Vertex>(preorder.size());

		ancestorHeights.resize(N);
		maxHIndices.resize(N);
		indices.resize(N);
		pathParents.resize(N);

		for(Vertex ix = 0; ix < N; ++ ix)
			indices[preorder[ix]] = ix + 1;

		for(Vertex i = 0; i < N; ++ i)
			maxHIndices[i] = indices[i];
		for(Vertex ix = N-1; ix > 0; -- ix) {
			Vertex v = preorder[ix], parent = parents[v];
			if(lowestOneBit(maxHIndices[parent]) < lowestOneBit(maxHIndices[v]))
				maxHIndices[parent] = maxHIndices[v];
		}

		ancestorHeights[root] = 0;
		for(Vertex ix = 1; ix < N; ++ ix) {
			Vertex v = preorder[ix], parent = parents[v];
			ancestorHeights[v] = ancestorHeights[parent] | lowestOneBit(maxHIndices[v]);
		}

		pathParents[0] = root;
		for(Vertex ix = 1; ix < N; ++ ix) {
			Vertex v = preorder[ix], parent = parents[v];
			if(maxHIndices[v] != maxHIndices[parent])
				pathParents[indices[v]-1] = parent;
			else
				pathParents[indices[v]-1] = pathParents[indices[parent]-1];
		}
	}

	Vertex query(Vertex v, Vertex u) const {
		Word Iv = maxHIndices[v], Iu = maxHIndices[u];
		Word hIv = lowestOneBit(Iv), hIu = lowestOneBit(Iu);
		Word hbMask = highestOneBitMask((Iv ^ Iu) | hIv | hIu);
		Word j = lowestOneBit(ancestorHeights[v] & ancestorHeights[u] & ~hbMask);
		Vertex x, y;
		if(j == hIv) x = v;
		else {
			Word kMask = highestOneBitMask(ancestorHeights[v] & (j-1));
			x = pathParents[(indices[v] & ~kMask | (kMask+1))-1];
		}
		if(j == hIu) y = u;
		else {
			Word kMask = highestOneBitMask(ancestorHeights[u] & (j-1));
			y = pathParents[(indices[u] & ~kMask | (kMask+1))-1];
		}
		return indices[x] < indices[y] ? x : y;
	}
};

struct SuffixTree {
	typedef SuffixArray::Alpha Alpha;
	typedef SuffixArray::Index Index;
	struct Node {
		Index begin, end;
		Index parent;
		Node() { }
		Node(Index begin_, Index end_, Index parent_): begin(begin_), end(end_), parent(parent_) { }
		Index length() const { return end - begin; }
	};
	
	//'\0'SuffixArray'\1', '$'
	enum { TERMINATOR = '\1' };

	SuffixArray sa;					//build
	vector<Alpha> alphas;
	vector<Index> stringIndex;		//pos ->  ([0,0,...,1,1,...,2...])
	vector<Index> stringPos;		//stringPos[i] =  i , stringPos[i+1] = 
	vector<Node> nodes;				//nodes[0] = root; 
	vector<Index> leafs;			//leafIndices[pos]: S[pos..] inverse suffix array
	vector<Index> edges;			//graph of parent -> child; 
	vector<Index> offsets;			//
	vector<Index> order;			//sequence of nodes; 
	vector<Index> lefts, rights;	//node -> suffixArray[left, right)
	vector<Index> depths;			//node -> depth
	vector<Index> bfsOrder;			//sequence of nodes; 
	vector<Index> suffixLink;		//node -> node; 

	SchieberVishkinLCA lca;

	//TERMINATOR 
	Index size() const { return static_cast<Index>(alphas.size()); }
	Index numNodes() const { return static_cast<Index>(nodes.size()); }

	//str  TERMINATOR 
	//n  TERMINATOR  ('\0')
	void build(const Alpha *str, Index n, Index nStrings = 1) {
		assert(str != NULL);
		assert(n > 0 && str[n-1] == TERMINATOR);
		assert(nStrings >= 1);
		assert(TERMINATOR != '\0' && std::count(str, str + n, '\0') == 0);
		assert(std::count(str, str + n, TERMINATOR) == nStrings);
		
		sa.build(str, n);
		sa.buildInverseSuffixArray();
		sa.computeLCPArray(str);

		stringIndex.resize(n);
		stringPos.resize(nStrings + 1);
		for(Index pos = 0, k = 0; pos < n; ++ pos) {
			stringIndex[pos] = k;
			if(str[pos] == TERMINATOR)
				stringPos[++ k] = pos + 1;
		}

		//lcpArray TERMINATOR 
		for(Index i = 1; i < n; ++ i) {
			Index posx = sa.suffixArray[i], posy = sa.suffixArray[i+1];
			Index ix = stringIndex[posx], iy = stringIndex[posy];
			Index dist = min(stringPos[ix+1] - 1 - posx, stringPos[iy+1] - 1 - posy);
			sa.lcpArray[i] = std::min(sa.lcpArray[i], dist);
		}

		//'\0'+1
		buildSuffixTree(str, n, &sa.suffixArray[0] + 1, &sa.lcpArray[0] + 1);
	}

	//build -> buildGraph -> depthFirstTraversal -> breadthFirstTraversal -> buildSuffixLinks
	void buildAll(const Alpha *str, Index n, Index nStrings = 1) {
		build(str, n, nStrings);
		buildGraph();
		depthFirstTraversal();
		breadthFirstTraversal();
		buildSuffixLinks();
		buildLCA();
	}

private:
	//lcpArray[i] = lcp(S[sa[i]..], S[sa[i]+1..])
	void buildSuffixTree(const Alpha *str, Index n, const Index *suffixArray, const Index *lcpArray) {
		assert(n > 0 && str[n-1] == TERMINATOR);

		nodes.resize(n * 2);
		alphas.assign(str, str + n);
		leafs.assign(n, -1);
		Index pNodes = 0;
		Node *curNode = new(&nodes[pNodes ++]) Node(0, 0, -1);
		Index curDepth = 0;
		for(Index i = 0; i < n; ++ i) {
			Index pos = suffixArray[i];
			Index lcp = i == 0 ? 0 : lcpArray[i-1];
			while(curDepth != lcp) {
				Index len = curNode->length();
				if(curDepth - len < lcp) {
					Index midPos = curNode->end - (curDepth - lcp);
					Node *newNode = new(&nodes[pNodes ++]) Node(curNode->begin, midPos, curNode->parent);
					curNode->begin = midPos;
					curNode->parent = static_cast<Index>(newNode - &nodes[0]);

					curDepth -= curNode->length();
					curNode = newNode;
					break;
				}
				curNode = &nodes[curNode->parent];
				curDepth -= len;
			}
			Index leafEndPos = stringPos[stringIndex[pos] + 1];
			Node *newLeaf = new(&nodes[pNodes ++]) Node(pos + lcp, leafEndPos, static_cast<Index>(curNode - &nodes[0]));
			curNode = newLeaf;
			curDepth += newLeaf->length();
			leafs[pos] = static_cast<Index>(newLeaf - &nodes[0]);
		}
		nodes.resize(pNodes);
		for(Index i = 1; i < n; ++ i)
			assert(comparePos(suffixArray[i-1], suffixArray[i]) <= 0);
	}

public:
	bool isLeaf(Index i) const {
		return i != 0 && alphas[nodes[i].end-1] == TERMINATOR;
	}

	int comparePos(Index i, Index j) const {
		Alpha a = alphas[i], b = alphas[j];
		if(a != TERMINATOR || b != TERMINATOR) {
			return a > b ? 1 : a < b ? -1 : 0;
		}else {
			Index x = leafs[i], y = leafs[j];
			return x > y ? 1 : x < y ? -1 : 0;
		}
	}

	void buildGraph() {
		Index nNodes = numNodes();
		assert(nNodes > 0);
		edges.resize(nNodes);
		offsets.assign(nNodes + 1, 0);
		for(Index i = 1; i < nNodes; ++ i)
			++ offsets[nodes[i].parent];
		for(Index i = 0; i < nNodes; ++ i)
			offsets[i+1] += offsets[i];
		for(Index i = nNodes - 1; i > 0; -- i)
			edges[-- offsets[nodes[i].parent]] = i;
	}

	const Index *edgesBegin(Index i) const { return &edges[0] + offsets[i]; }
	const Index *edgesEnd(Index i) const { return &edges[0] + offsets[i+1]; }

	void depthFirstTraversal() {
		assert(offsets.size() > 0);
		Index nNodes = numNodes();
		order.clear(); order.reserve(nNodes);
		lefts.assign(nNodes, -1);
		rights.assign(nNodes, -1);
		depths.resize(nNodes);
		depths[0] = 0;

		Index curLeafs = 0;
		vector<Index> stk;
		stk.push_back(0);

		while(!stk.empty()) {
			Index i = stk.back(); stk.pop_back();
			if(lefts[i] != -1) {
				rights[i] = curLeafs;
				continue;
			}
			order.push_back(i);
			lefts[i] = curLeafs;
			stk.push_back(i);
			const Index *p = edgesBegin(i), *q = edgesEnd(i);
			if(p == q) {
				++ curLeafs;
			}else {
				do {
					Index child = *(-- q);
					depths[child] = depths[i] + nodes[child].length();
					stk.push_back(child);
				}while(p != q);
			}
		}
	}

	void breadthFirstTraversal() {
		assert(depths.size() > 0);
		Index n = size(), nNodes = numNodes();
		bfsOrder.resize(nNodes);
		vector<Index> levels(n + 1);
		for(Index i = 0; i < nNodes; ++ i)
			++ levels[depths[i]];
		for(Index i = 0; i < n; ++ i)
			levels[i+1] += levels[i];
		for(Index i = nNodes - 1; i >= 0; -- i)
			bfsOrder[-- levels[depths[i]]] = i;
	}

	//O(log A) where A = || + nStrings
	Index findChild(Index i, Index pos) const {
		Index l = offsets[i], u = offsets[i+1];
		while(l < u) {
			Index mid = (l + u) / 2;
			Index child = edges[mid];
			Index edgePos = nodes[child].begin;
			int c = comparePos(pos, edgePos);
			if(c == 0)
				return child;
			else if(c > 0)
				l = mid + 1;
			else
				u = mid;
		}
		return -1;
	}

private:

	//buildSuffixLinks
	// findChild  n-1 
	Index findDecendantNode(Index i, Index pos, Index len) const {
		while(len > 0) {
			Index child = findChild(i, pos);
			assert(child != -1);
			Index edgeLen = nodes[child].length();
			pos += edgeLen;
			len -= edgeLen;
			i = child;
		}
		assert(len == 0);
		return i;
	}

public:
	// O(n log A)
	void buildSuffixLinks() {
		assert(bfsOrder.size() > 0);
		Index n = size(), nNodes = numNodes();
		suffixLink.assign(nNodes, -1);
		for(const Index *p = edgesBegin(0), *pEnd = edgesEnd(0); p != pEnd; ++ p) {
			Index child = *p;
			const Node &childNode = nodes[child];
			suffixLink[child] = findDecendantNode(0, childNode.begin + 1, childNode.length() - 1);
		}
		for(Index ix = 1; ix < nNodes; ++ ix) {
			Index i = bfsOrder[ix], j = suffixLink[i];
			assert(j != -1);
			const Index *p = edgesBegin(i), *pEnd = edgesEnd(i);
			const Index *q = edgesBegin(j), *qEnd = edgesEnd(j);
			for(; p != pEnd; ++ p) {
				Index pos = nodes[*p].begin, len = nodes[*p].length();
				while(comparePos(pos, nodes[*q].begin) > 0)
					++ q;
				assert(comparePos(pos, nodes[*q].begin) == 0);
				Index linkedEdgeLen = nodes[*q].length();
				suffixLink[*p] = findDecendantNode(*q, pos + linkedEdgeLen, len - linkedEdgeLen);
			}
		}
	}

	void buildLCA() {
		Index nNodes = numNodes();
		vector<Index> parents(nNodes);
		for(Index i = 0; i < nNodes; ++ i)
			parents[i] = nodes[i].parent;
		lca.build(order, parents, 0);
	}

	//
	Index computeLCP(Index i, Index j) const {
		Index x = leafs[i], y = leafs[j];
		Index z = lca.query(x, y);
		return depths[z] - isLeaf(z);	//
	}


public:
	//
	void debugOutputGraphviz(bool visSuffixLink = false) const {
		ostream &o = std::cerr;
		o << "digraph {\n";
		o << "style = dot;\n";
		Index nNodes = numNodes();
		for(Index i = 0; i < nNodes; ++ i) {
			const Node &node = nodes[i];
			if(node.parent == -1) continue;
			o << node.parent << " -> " << i << " [label=<";
			for(Index p = node.begin; p != node.end; ++ p) {
				Alpha a = alphas[p];
				if(a == TERMINATOR)
					o << '$';
				else
					o << a;
			}
			o << ">];\n";
		}
		if(visSuffixLink && !suffixLink.empty()) {
			for(Index i = 0; i < nNodes; ++ i) {
				Index j = suffixLink[i];
				if(j == -1) continue;
				o << i << " -> " << j << " [style=dotted];\n";
			}
		}
		o << "}" << std::endl;
	}

	string debugGetPathString(Index i) const {
		string res;
		for(Index j = i; j != -1; ) {
			const Node &node = nodes[j];
			for(Index p = node.end - 1; p >= node.begin; -- p)
				res += alphas[p];
			j = node.parent;
		}
		std::reverse(res.begin(), res.end());
		return res;
	}
};


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
	int rangefreq(Val bottom, Val top, int left, int right) {
		int lt1, lt2, dummy;
		rank_all(top, left, right, lt1, dummy);
		rank_all(bottom, left, right, lt2, dummy);
		return lt1 - lt2;
	}
};

int main() {
	char *s = new char[200001];
	int n, q;
	while(cin >> n >> q) {
		string S;
		vector<int> poses(n);
		rep(i, n) {
			poses[i] = S.size();
			scanf("%s", s);
			S += s;
			S += (char)SuffixTree::TERMINATOR;
		}
		SuffixTree st;
		st.build(S.c_str(), S.size(), n);
		st.buildGraph();
		st.depthFirstTraversal();

		vector<unsigned> leafStringIndices(S.size());
		rep(i, st.numNodes()) if(st.isLeaf(i)) {
			int k = st.stringIndex[st.nodes[i].end - 1];
			leafStringIndices[st.lefts[i]] = k;
		}
		WaveletMatrix wm;
		wm.init(leafStringIndices);

		rep(i, q) {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k), -- l, -- k;
			int L, R;

			int leaf = st.leafs[poses[k]], node;
			if(st.nodes[leaf].length() > 1)
				node = leaf;
			else
				node = st.nodes[leaf].parent;
			
			L = st.lefts[node], R = st.rights[node];

			int ans = wm.rangefreq(l, r, L, R);
			printf("%d\n", ans);
		}
	}
	return 0;
}