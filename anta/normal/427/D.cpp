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

typedef unsigned char Alpha; const int NAlpha = 256;
inline bool IsTerminatingAlpha(Alpha a) { return a < 32; }
void OutAlpha(std::ostream &o, Alpha a) {
    if(IsTerminatingAlpha(a))
        o << '$' << static_cast<unsigned>(a);
    else
        o << static_cast<char>(a);
}

const int ListToArrayParam = (int)pow(NAlpha*1., 0.4);
class GeneralizedSuffixTree {
public:
    typedef std::pair<const Alpha*, const Alpha*> StrPair;
private:
    struct Leaf {
        const Alpha *begin, *end;   //1endLeafgeneralized
        Leaf *next;
        Leaf() { }
        Leaf(const Alpha *b): begin(b), next(NULL), end(NULL) { }
        Alpha terminatingAlpha() const { return *(end-1); }
        int length() const { return end - begin; }
    };
    struct Node : Leaf {    //rootinternal node
        union { Leaf *head; Leaf **edges; };
        Node *suffix;
        Node() { suffix = NULL; head = NULL; }
    };

    int nNodes, nLeafs;
    Node *nodes; Leaf *leafs, *poolend;
    Node *root;
    std::vector<Leaf**> edgeArrays;
    std::vector<StrPair> addedStrings;

    bool isLeaf(const Leaf *p) const { return leafs <= p; }
    bool isListStyle(const Node *p) const { return !p->head || ((Leaf*)nodes <= p->head && p->head < poolend); }

#define FOR_EACH_EDGES_(e, n, c)\
    for(Leaf *c *e##_ = isListStyle(n) ? &n->head : n->edges;\
    isListStyle(n) ? (*e##_ != NULL) : (e##_ < n->edges + NAlpha);\
    isListStyle(n) ? (e##_ = &(*e##_)->next) : (++ e##_))\
    if(c Leaf *e = *e##_)
#define FOR_EACH_EDGES_V(e, n) FOR_EACH_EDGES_(e, n, )
#define FOR_EACH_EDGES_C(e, n) FOR_EACH_EDGES_(e, n, const)

    Leaf **listToArray(Node *node) {
        Leaf **edges = (Leaf**)malloc(NAlpha * sizeof(Leaf*));
        memset(edges, 0, sizeof(Leaf*) * NAlpha);
        FOR_EACH_EDGES_V(leaf, node)
            edges[*leaf->begin] = leaf;
        edgeArrays.push_back(edges);
        return edges;
    }

    inline Leaf **getEdgeRef(Node *node, Alpha a) {
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
    inline Leaf *getEdge(const Node *node, Alpha a) const {
        if(!isListStyle(node)) return node->edges[a];
        for(Leaf *leaf = node->head; leaf != NULL; leaf = leaf->next)
            if(*leaf->begin == a) return leaf;
        return NULL;
    }
    inline void addEdge(Node *node, Alpha a, Leaf *edge) {
        if(!isListStyle(node)) {
            node->edges[a] = edge;
        }else {
            Leaf *head = node->head;
            node->head = edge;
            edge->next = head;
        }
    }
    void outLeafName(std::ostream &o, const Leaf *leaf) const {
        o << '"' << static_cast<const void*>(leaf) << '"';
    }
    void outRec(std::ostream &o, const Node *node, bool visSuffix) const {
        if(visSuffix && node->suffix) {
            outLeafName(o, node); o << " -> "; outLeafName(o, node->suffix); o << ' ';
            o << "[style=dotted, constraint=false]" << ";\n";
        }
        FOR_EACH_EDGES_C(edge, node) {
            outLeafName(o, node); o << " -> "; outLeafName(o, edge); o << ' ';
            o << "[label=<";
            for(const Alpha *p = edge->begin; p < edge->end; ++ p) {
                OutAlpha(o, *p);
            }
            o << ">];\n";
            if(!isLeaf(edge))
                outRec(o, (Node*)edge, visSuffix);
        }
    }
public:
    GeneralizedSuffixTree(int n): nNodes(0), nLeafs(0),
        nodes((Node*)malloc(sizeof(Node) * n + sizeof(Leaf) * n)), leafs((Leaf*)(nodes + n)),
        poolend(leafs + n), root(new(&nodes[nNodes ++]) Node()) {
        root->begin = root->end = NULL;
    }
    ~GeneralizedSuffixTree() {
        free(nodes);
        for(int i = 0; i < (int)edgeArrays.size(); i ++)
            free(edgeArrays[i]);
    }

    //strIsTerminatingAlpha(a)true
    //
    void addString(const Alpha *str) {
        Node *active = root; const Alpha *activePos; int activeLen = 0;
        const Alpha *currentPos = str, *proceeded = str;
        int old_nLeafs = nLeafs;
        do {
            if(currentPos-str && (currentPos-str) % 100000 == 0) std::cout << (proceeded-str) << ", " << (currentPos-str) << ": edgeArrays = " << edgeArrays.size() << std::endl;
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
        addedStrings.push_back(std::make_pair(str, currentPos));
        for(int i = old_nLeafs; i < nLeafs; i ++)
            leafs[i].end = currentPos;
    }

public:
    void addByteString(const char *s) { addString((const Alpha*)s); }

    int shortestCommonUniqueSubstring() const {
        return shortestCommonUniqueSubstring_rec(root).second;
    }
private:
    pair<pair<unsigned, int>,int> shortestCommonUniqueSubstring_rec(const Leaf *leaf) const {
        if(isLeaf(leaf)) {
            return mp(mp(1U << leaf->terminatingAlpha(), 1), INF);
        }
        const Node *node = static_cast<const Node*>(leaf);
        unsigned bits = 0;
        int cnt = 0; int p = INF;
        FOR_EACH_EDGES_C(edge, node) {
            pair<pair<unsigned, int>, int > q;
            q = shortestCommonUniqueSubstring_rec(edge);
            amin(p, q.second + edge->length());
            bits |= q.first.first;
            cnt += q.first.second;
        }
        if(bits == 3 && cnt == 2) amin(p, 1 - leaf->length());
        return mp(mp(bits, cnt), p);
    }

};

char s1[5001], s2[5001];
int main() {
    scanf("%s%s", s1, s2);
    int n = strlen(s1), m = strlen(s2);
    GeneralizedSuffixTree st(n + m + 2);
    s1[n] = 0; s2[m] = 1;
    st.addByteString(s1);
    st.addByteString(s2);
    int ans = st.shortestCommonUniqueSubstring();
    if(ans == INF) puts("-1");
    else printf("%d\n", ans);
    return 0;
}