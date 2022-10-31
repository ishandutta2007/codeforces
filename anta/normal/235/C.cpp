//x_i
//x_i2matching statistics
//matching statistics|x_i|suffix linkminimal
//()
//
#include <cstdio>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

namespace solve {

	
#define FOR_EACH_EDGES_(e, n, c)\
	for(Leaf *c *e##_ = isListStyle(n) ? &n->head : n->edges;\
	isListStyle(n) ? (*e##_ != NULL) : (e##_ < n->edges + NAlpha);\
	isListStyle(n) ? (e##_ = &(*e##_)->next) : (++ e##_))\
	if(c Leaf *e = *e##_)
#define FOR_EACH_EDGES_V(e, n) FOR_EACH_EDGES_(e, n, )
#define FOR_EACH_EDGES_C(e, n) FOR_EACH_EDGES_(e, n, const)

class SuffixTree {
public:
	//Alpha[0,NAlpha)
	//(NAlpha)IsTerminatingAlpha
	//[0,32)
	//OKNAlpha
	typedef unsigned char Alpha; static const int NAlpha = 256;
	static inline bool IsTerminatingAlpha(Alpha a) { return a < 32; }
	typedef size_t Index;	//32bit
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
	//calcNodeIntervalleaf
	std::vector<Index> nodeLeftPos, nodeRightPos;
	
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
	//strIsTerminatingAlpha(a)true
	//
	void addString(const Alpha *str);

	//==========================================================================
	//SuffixTreeCalcs.cpp
public:
	void inorderTraversal();
	//inorderTraversal
	void calcNodeInterval();
private:
	Index nodeIntervalLength(const Node *node) const;	//calcNodeInterval

	//==========================================================================
	//SuffixTreeMatchingStatistics.cpp
private:
	struct PositionS {
		const Node *node;
		Alpha alpha;
		const Leaf *cache_edge;
		Index length;
	};
	PositionS initialPositionS() const;
	bool moveSuffixLink(PositionS &pos) const;
	Index matchAlphaS(PositionS &pos, Alpha a) const;
	const Alpha *getEndPosS(const PositionS &pos) const;
public:
	Index countCyclicIsomorphicSubstrings(const Alpha *begin, const Alpha *end, std::vector<bool> &tmpNodeMark, std::vector<bool> &tmpLeafMark) const;
};

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

void SuffixTree::addString(const Alpha *str) {
	const Alpha *endp = findStringEnd(str);
	Index size = endp - str + 1;
	Alpha *copied = addedStrings.empty() ? stringBuffer : addedStrings.back().second + 1;
	std::memcpy(copied, str, size);
	addedStrings.push_back(std::make_pair(copied, copied + (size - 1)));
	addStringMain(copied);
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

void SuffixTree::calcNodeInterval() {
	assert(!nodeSequence.empty());
	nodeLeftPos.assign(nNodes, -1);
	nodeRightPos.assign(nNodes, -1);

	for(Index i = 0; i < nLeafs; i ++) {
		const Leaf *leaf = leafSequence[i];
		const Node *parent = leafParent[leaf - leafs];
		Index &pLeft = nodeLeftPos[parent - nodes], &pRight = nodeRightPos[parent - nodes];
		if(pLeft == -1 || i < pLeft) pLeft = i;
		if(pRight == -1 || pRight < i + 1) pRight = i + 1;
	}
	if(nNodes > 0) for(Index ii = nNodes - 1; ii > 0; -- ii) {
		const Node *node = nodeSequence[ii];
		const Node *parent = nodeParent[node - nodes];
		Index &pLeft = nodeLeftPos[parent - nodes], &pRight = nodeRightPos[parent - nodes];
		Index cLeft = nodeLeftPos[node - nodes], cRight = nodeRightPos[node - nodes];
		if(pLeft == -1 || cLeft < pLeft) pLeft = cLeft;
		if(pRight == -1 || pRight < cRight) pRight = cRight;
	}
}

SuffixTree::Index SuffixTree::nodeIntervalLength(const Node *node) const {
	return nodeRightPos[node - nodes] - nodeLeftPos[node - nodes];
}

//PositionSNodePositionLeaf
//pos.leaf = posS.length == 0 ? posS.node : posS.cache_edge
//pos.pos = posS.length == 0 ? leaf->end : leaf->begin + posS.length
//()
//matching statistics

SuffixTree::PositionS SuffixTree::initialPositionS() const {
	PositionS pos;
	pos.node = root;
	pos.length = 0;
	pos.cache_edge = NULL;
	return pos;
}
//
//: suffix link(root)
//Ukkonen's
//(pos.node + pos.length)(1)

bool SuffixTree::moveSuffixLink(PositionS &pos) const {
	const Alpha *p = pos.cache_edge ? pos.cache_edge->begin : NULL;
	if(pos.node == root) {
		if(pos.length == 0) return false;
		if(-- pos.length)
			pos.cache_edge = getEdge(pos.node, pos.alpha = *(++ p));
	}else {
		pos.node = pos.node->suffix;
		if(pos.length != 0) pos.cache_edge = getEdge(pos.node, pos.alpha);
	}
	if(pos.cache_edge != NULL) {
		while(pos.length >= pos.cache_edge->length()) {
			pos.length -= pos.cache_edge->length();
			p += pos.cache_edge->length();
			pos.node = static_cast<const Node*>(pos.cache_edge);
			if(pos.length != 0) {
				pos.cache_edge = getEdge(pos.node, pos.alpha = *p);
			}else {
				pos.cache_edge = NULL;
				break;
			}
		}
	}
	return true;
}

SuffixTree::Index SuffixTree::matchAlphaS(PositionS &pos, Alpha a) const {
	Index count = 0;
	while(1) {
		if(pos.length == 0)
			pos.cache_edge = getEdge(pos.node, pos.alpha = a);
		if(pos.cache_edge != NULL && *(pos.cache_edge->begin + pos.length) == a)
			break;
		count ++;
		if(!moveSuffixLink(pos)) break;
	}
	if(pos.cache_edge != NULL) {
		if(pos.cache_edge->length() == ++ pos.length) {
			pos.node = static_cast<const Node*>(pos.cache_edge);
			pos.length = 0;
			pos.cache_edge = NULL;
		}
	}
	return count;
}

SuffixTree::Index SuffixTree::countCyclicIsomorphicSubstrings(const Alpha *begin, const Alpha *end, std::vector<bool> &tmpNodeMark, std::vector<bool> &tmpLeafMark) const {
	assert(!nodeLeftPos.empty());
	if(tmpNodeMark.empty()) tmpNodeMark.assign(nNodes, false);
	if(tmpLeafMark.empty()) tmpLeafMark.assign(nLeafs, false);
	Index m = end - begin, mh = m / 2, matchHead = 0;
	assert(m > 0 && m % 2 == 0);	//
	PositionS pos = initialPositionS();
	std::vector<std::vector<bool>::iterator> markits;
	Index cnt = 0;
	for(Index i = 0; i < m; ++ i) {
		matchHead += matchAlphaS(pos, *(begin + i));
		if(i + 1 - matchHead == mh) {
			const Leaf *leaf = pos.length == 0 ? pos.node : pos.cache_edge;
			std::vector<bool>::iterator markit;
			if(isLeaf(leaf)) markit = tmpLeafMark.begin() + (leaf - leafs);
			else markit = tmpNodeMark.begin() + (static_cast<const Node*>(leaf) - nodes);
			if(!*markit) {
				Index descendantCount;
				if(isLeaf(leaf)) descendantCount = 1;
				else descendantCount = nodeIntervalLength(static_cast<const Node*>(leaf));
				cnt += descendantCount;
				markits.push_back(markit);
				*markit = true;
			}
			bool b = moveSuffixLink(pos);
			assert(b);
			++ matchHead;
		}
	}
	for(size_t i = 0; i < markits.size(); i ++)
		*(markits[i]) = false;
	return cnt;
}


char s[1000001];
char x[2000001];
}

int main() {
	using namespace solve;
	scanf("%s", s);
	int n = strlen(s);
	SuffixTree st(n + 1);
	st.addString((unsigned char*)s);
	st.inorderTraversal();
	st.calcNodeInterval();
	std::vector<bool> tmpNodeArray, tmpLeafArray;
	int Q;
	scanf("%d", &Q);
	for(int ii = 0; ii < Q; ii ++) {
		scanf("%s", x);
		int m = strlen(x);
		memcpy(x + m, x, m * sizeof(char));
		x[m * 2] = 0;
		unsigned char *xp = (unsigned char*)x;
		int ans = st.countCyclicIsomorphicSubstrings(xp, xp + m * 2, tmpNodeArray, tmpLeafArray);
		printf("%d\n", ans);
	}
	return 0;
}