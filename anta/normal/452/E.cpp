#define _CRT_SECURE_NO_WARNINGS
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }


//GST
//()x,y
//x*y
//

namespace solve {

class SuffixTree {
public:
	//Alpha[0,NAlpha)
	//(NAlpha)IsTerminatingAlpha
	//[0,32)
	//OKNAlpha
	typedef unsigned char Alpha; static const int NAlpha = 256;
	static inline bool IsTerminatingAlpha(Alpha a) { return a < 32; }
	typedef size_t Index;	//32bit
	typedef unsigned long long Count;	//Index^2
	typedef std::pair<const Alpha*, const Alpha*> StrPair;
	static const int ListToArrayParam;

private:
	struct Leaf {
		const Alpha *begin, *end;
		Leaf *next;
		Leaf() { }
		Leaf(const Alpha *b): begin(b), next(NULL), end(NULL) { }
		Alpha terminatingAlpha() const { return *(end-1); }
		Index length() const { return end - begin; }	//
	};
	struct Node : Leaf {	//rootinternal node
		union { Leaf *head; Leaf **edges; };
		Node *suffix;
		Node() { suffix = NULL; head = NULL; }
	};

	Index nNodes, nLeafs;
	Node *nodes; Leaf *leafs, *poolend;
	Node *root;
	Alpha *stringBuffer;	//
	std::vector<Leaf**> edgeArrays;
	std::vector<std::pair<Alpha*,Alpha*> > addedStrings;	//
	//inorderTraversalinorder
	std::vector<const Node*> nodeSequence, nodeParent, leafParent;
	std::vector<const Leaf*> leafSequence;
	//calcNodeDepths
	std::vector<Index> nodeDepth, leafDepth;

	std::vector<std::vector<Index> > numDescendantLeafs;	//
	
	//==========================================================================
	//SuffixTree.cpp
public:
	SuffixTree(Index n);	//()
	~SuffixTree();

private:
	bool isLeaf(const Leaf *p) const { return leafs <= p; }
	bool isListStyle(const Node *p) const { return !p->head || ((Leaf*)nodes <= p->head && p->head < poolend); }

	Leaf **listToArray(Node *node);
	Leaf **getEdgeRef(Node *node, Alpha a);
	Leaf *getEdge(const Node *node, Alpha a) const;
	void addEdge(Node *node, Alpha a, Leaf *edge);

	static const Alpha *findStringEnd(const Alpha *str) { while(!IsTerminatingAlpha(*str)) ++ str; return str; }

	void addStringMain(const Alpha *str);
public:
	//end
	//
	void addString(const Alpha *begin, const Alpha *end, Alpha terminatingAlpha);
	//strIsTerminatingAlpha(a)true
	void addString(const Alpha *str);

	//==========================================================================
	//SuffixTreeCalcs.cpp
public:
	void inorderTraversal();
	//inorderTraversal
	void calcNodeDepth();

	//solve
public:
	void calcNumDescendantLeafs();
	void countCommonSubstrings(Count cnts[]) const;	//k2
};

#define FOR_EACH_EDGES_(e, n, c)\
	for(Leaf *c *e##_ = isListStyle(n) ? &n->head : n->edges;\
	isListStyle(n) ? (*e##_ != NULL) : (e##_ < n->edges + NAlpha);\
	isListStyle(n) ? (e##_ = &(*e##_)->next) : (++ e##_))\
	if(c Leaf *e = *e##_)
#define FOR_EACH_EDGES_V(e, n) FOR_EACH_EDGES_(e, n, )
#define FOR_EACH_EDGES_C(e, n) FOR_EACH_EDGES_(e, n, const)


const int SuffixTree::ListToArrayParam = (int)std::pow(NAlpha*1., 0.4);	//

SuffixTree::SuffixTree(Index n) : nNodes(0), nLeafs(0) {
	assert(n > 0);
	size_t poolSize = sizeof(Node) * n + sizeof(Leaf) * n;
	char *pool = static_cast<char*>(std::malloc(poolSize));
	nodes = reinterpret_cast<Node*>(pool);
	leafs = reinterpret_cast<Leaf*>(pool + n * sizeof(Node));
	poolend = reinterpret_cast<Leaf*>(pool + poolSize);
	stringBuffer = static_cast<Alpha*>(std::malloc(n * sizeof(Alpha)));

	root = new(&nodes[nNodes ++]) Node();
	root->begin = root->end = NULL;
}
SuffixTree::~SuffixTree() {
	free(nodes);
	for(size_t i = 0; i < edgeArrays.size(); i ++) free(edgeArrays[i]);
	free(stringBuffer);
}

SuffixTree::Leaf **SuffixTree::listToArray(Node *node) {
	Leaf **edges = static_cast<Leaf**>(std::malloc(NAlpha * sizeof(Leaf*)));
	memset(edges, 0, sizeof(Leaf*) * NAlpha);
	FOR_EACH_EDGES_V(leaf, node)
		edges[*leaf->begin] = leaf;
	edgeArrays.push_back(edges);
	return edges;
}

SuffixTree::Leaf **SuffixTree::getEdgeRef(Node *node, Alpha a) {
	if(!isListStyle(node)) return &node->edges[a];
	Leaf **ref; int len = 0;
	for(ref = &node->head; *ref != NULL; ref = &(*ref)->next, ++ len) {
		if(len >= ListToArrayParam)
			return &(node->edges = listToArray(node))[a];
		if(*(*ref)->begin == a)
			return ref;
	}
	return ref;
}
SuffixTree::Leaf *SuffixTree::getEdge(const Node *node, Alpha a) const {
	if(!isListStyle(node)) return node->edges[a];
	for(Leaf *leaf = node->head; leaf != NULL; leaf = leaf->next)
		if(*leaf->begin == a) return leaf;
	return NULL;
}
void SuffixTree::addEdge(Node *node, Alpha a, Leaf *edge) {
	if(!isListStyle(node)) {
		node->edges[a] = edge;
	}else {
		Leaf *head = node->head;
		node->head = edge;
		edge->next = head;
	}
}

//str
void SuffixTree::addStringMain(const Alpha *str) {
	Node *active = root; const Alpha *activePos; Index activeLen = 0;
	const Alpha *currentPos = str, *proceeded = str;
	Index old_nLeafs = nLeafs;
	do {
		Alpha currentAlpha = *currentPos; Node *prevNode = NULL;
		while(proceeded <= currentPos) {
			if(activeLen == 0) activePos = currentPos;
			Leaf **activeEdgeRef = getEdgeRef(active, *activePos);
			Leaf *activeEdge = *activeEdgeRef;
			Node *splitNode = active;
			if(activeEdge) {
				if(!isLeaf(activeEdge) && activeLen >= activeEdge->length()) {
					active = (Node*)activeEdge;
					activePos += ((Node*)activeEdge)->length();
					activeLen -= ((Node*)activeEdge)->length();
					continue;
				}else if(*(activeEdge->begin + activeLen) == currentAlpha) {
					activeLen ++;
					if(prevNode) prevNode->suffix = active;
					break;
				}else {
					const Alpha *splitPos = activeEdge->begin + activeLen;
					Leaf *nextLeaf = activeEdge->next;
					*activeEdgeRef = splitNode = new(&nodes[nNodes ++]) Node();
					splitNode->begin = activeEdge->begin;
					splitNode->end = activeEdge->begin = splitPos;
					addEdge(splitNode, *splitPos, activeEdge);
					splitNode->next = nextLeaf;
				}
			}
			addEdge(splitNode, currentAlpha, new(&leafs[nLeafs ++]) Leaf(currentPos));
			if(prevNode) prevNode->suffix = splitNode;
			prevNode = splitNode;
			proceeded ++;
			if(active == root && activeLen > 0) {
				activeLen --;
				activePos = proceeded;
			}else
				active = active->suffix ? active->suffix : root;
		}
	}while(!IsTerminatingAlpha(*(currentPos ++)));
	assert(currentPos == proceeded);
	for(Index i = old_nLeafs; i < nLeafs; i ++)
		leafs[i].end = currentPos;
}

void SuffixTree::addString(const Alpha *begin, const Alpha *end, Alpha terminatingAlpha) {
	Index len = end - begin;
	Alpha *copied = addedStrings.empty() ? stringBuffer : addedStrings.back().second + 1;
	std::memcpy(copied, begin, len * sizeof(Alpha));
	copied[len] = terminatingAlpha;
	addedStrings.push_back(std::make_pair(copied, copied + len));
	addStringMain(copied);
}

void SuffixTree::addString(const Alpha *str) {
	const Alpha *endp = findStringEnd(str);
	return addString(str, endp, *endp);
}


void SuffixTree::inorderTraversal() {
	leafSequence.assign(nLeafs, NULL);
	leafParent.assign(nLeafs, NULL);
	nodeSequence.assign(nNodes, NULL);
	nodeParent.assign(nNodes, NULL);

	Index leafCount = 0, nodeCount = 0;
	std::vector<const Node*> stk; stk.reserve(nNodes);
	stk.push_back(root);
	while(!stk.empty()) {
		const Node *node = stk.back(); stk.pop_back();
		nodeSequence[nodeCount ++] = node;
		FOR_EACH_EDGES_C(edge, node) {
			if(isLeaf(edge)) {
				leafSequence[leafCount ++] = edge;
				leafParent[edge - leafs] = node;
			}else {
				const Node *child = static_cast<const Node*>(edge);
				nodeParent[child - nodes] = node;
				stk.push_back(child);
			}
		}
	}
	assert(leafCount == nLeafs && nodeCount == nNodes);
}

void SuffixTree::calcNodeDepth() {
	assert(!nodeSequence.empty());
	leafDepth.assign(nLeafs, -1);
	nodeDepth.assign(nNodes, -1);

	nodeDepth[root - nodes] = 0;
	for(Index ii = 0; ii < nNodes; ++ ii) {
		const Node *node = nodeSequence[ii];
		int depth = nodeDepth[node - nodes];
		FOR_EACH_EDGES_C(edge, node) {
			if(isLeaf(edge)) {
				leafDepth[edge - leafs] = depth + edge->length();
			}else {
				const Node *child = static_cast<const Node*>(edge);
				nodeDepth[child - nodes] = depth + edge->length();
			}
		}
	}
}

void SuffixTree::calcNumDescendantLeafs() {
	assert(!nodeSequence.empty());
	size_t K = addedStrings.size();
	numDescendantLeafs.assign(K, std::vector<Index>(nNodes, 0));
	if(nNodes == 0) return;

	for(Index i = 0; i < nLeafs; i ++) {
		const Leaf *leaf = leafSequence[i];
		const Node *parent = leafParent[leaf - leafs];
		Alpha terminatingAlpha = *(leaf->end - 1);
		++ numDescendantLeafs[terminatingAlpha][parent - nodes];
	}
	for(Index ii = nNodes - 1; ii > 0; -- ii) {
		const Node *node = nodeSequence[ii];
		const Node *parent = nodeParent[node - nodes];
		for(size_t k = 0; k < K; k ++)
			numDescendantLeafs[k][parent - nodes] += numDescendantLeafs[k][node - nodes];
	}
}

void SuffixTree::countCommonSubstrings(Count cnts[/*Min n_i + 1*/]) const {
	assert(!nodeDepth.empty() && !numDescendantLeafs.empty());
	size_t K = addedStrings.size();
	assert(K > 0);
	Index minn = std::numeric_limits<Index>::max();
	for(size_t k = 0; k < K; k ++)
		minn = std::min(minn, (Index)(addedStrings[k].second - addedStrings[k].first));
	for(Index i = 0; i <= minn; i ++)
		cnts[i] = 0;
	//root
	{	Count cnt = 1;
		for(size_t k = 0; k < K; k ++)
			cnt *= numDescendantLeafs[k][0];
		cnts[0] += cnt;
		if(0 < minn) cnts[1] -= cnt;
	}
	//0
	for(Index i = 1; i < nNodes; i ++) {
		Index depth = nodeDepth[i], edgeLen = nodes[i].length();
		Index lenLower = depth - (edgeLen - 1), lenUpper = depth;
		Count cnt = 1;
		for(size_t k = 0; k < K; k ++)
			cnt *= numDescendantLeafs[k][i];
		if(cnt == 0) continue;
		assert(lenLower <= minn);
		cnts[lenLower] += cnt;
		if(lenUpper < minn) cnts[lenUpper+1] -= cnt;
	}
	for(Index ix = 0; ix < nLeafs; ix ++) {
		Index i = leafSequence[ix] - leafs;
		Index depth = leafDepth[i], edgeLen = leafs[i].length();
		if(edgeLen == 0) continue;	//
		Index lenLower = depth - (edgeLen - 1), lenUpper = depth - 1;
		Alpha terminatingAlpha = leafs[i].terminatingAlpha();
		Count cnt = 1;
		for(size_t k = 0; k < K; k ++)
			cnt *= k == terminatingAlpha ? 1 : 0;
		if(cnt == 0) continue;
		assert(lenLower <= minn);
		cnts[lenLower] += cnt;
		if(lenUpper < minn) cnts[lenUpper+1] -= cnt;
	}
	for(Index i = 1; i <= minn; i ++)	//
		cnts[i] += cnts[i-1];
}


}




int main() {
	const int N = 3;
	char *buf = new char[300000 + N];
	char *s[N];
	vector<int> n(N);
	int nsum = 0;
	rep(i, N) {
		s[i] = buf;
		scanf("%s", s[i]);
		n[i] = strlen(s[i]);
		nsum += n[i];
		buf += n[i] + 1;
	}
	using namespace solve;
	typedef SuffixTree::Alpha Alpha;
	SuffixTree st(nsum + N);
	rep(i, N)
		st.addString((Alpha*)s[i], (Alpha*)s[i] + n[i], i);
	st.inorderTraversal();
	st.calcNodeDepth();
	st.calcNumDescendantLeafs();
	int minn = *min_element(all(n));
	vector<SuffixTree::Count> cnts(minn + 1);
	st.countCommonSubstrings(&cnts[0]);
	rer(l, 1, minn) {
		if(l != 1) putchar(' ');
		printf("%d", (int)(cnts[l] % 1000000007));
	}
	puts("");
	return 0;
}