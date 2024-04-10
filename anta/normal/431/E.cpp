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

unsigned xor128() {
    static unsigned x = 123456789, y = 362436069, z = (unsigned)time(0), w = 88675123;
    unsigned t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}
typedef double Val;

struct Node {
    Node *left, *right, *parent;
    int size;
    Val val, sum;
    Node(): left(NULL), right(NULL), parent(NULL), size(1) { }
    Node(Val x): left(NULL), right(NULL), parent(NULL), size(1), val(x), sum(x) { }
    inline Node *update() {
        size = (!left ? 0 : left->size) + 1 + (!right ? 0 : right->size);
        sum = (!left ? 0 : left->sum) + val + (!right ? 0 : right->sum);
        return this;
    }
    inline void propagate() { }
    inline Node *linkl(Node *c) {
        if(left = c) c->parent = this;
        return update();
    }
    inline Node *linkr(Node *c) {
        if(right = c) c->parent = this;
        return update();
    }
    inline Node *linklr(Node *l, Node *r) {
        if(left = l) l->parent = this;
        if(right = r) r->parent = this;
        return update();
    }
    static inline Node *cut(Node *t) {
        if(t) t->parent = NULL;
        return t;
    }
};

struct PRBSTBase {
    typedef Node *Ref;
    static int size(Ref t) { return !t ? 0 : t->size; }
    static Ref join(Ref l, Ref r) {
        if(!l) return r;
        if(!r) return l;
        if((int)(xor128() % (l->size + r->size)) < l->size) {
            l->propagate();
            return l->linkr(join(Node::cut(l->right), r));
        }else {
            r->propagate();
            return r->linkl(join(l, Node::cut(r->left)));
        }
    }
    typedef pair<Ref,Ref> RefPair;
    static RefPair split(Ref t, int k) {
        if(!t) return RefPair((Ref)NULL, (Ref)NULL);
        t->propagate();
        int s = size(t->left);
        if(k <= s) {
            RefPair p = split(Node::cut(t->left), k);
            return RefPair(p.first, t->linkl(p.second));
        }else {
            RefPair p = split(Node::cut(t->right), k - s - 1);
            return RefPair(t->linkr(p.first), p.second);
        }
    }
    static Ref insert(Ref t, int k, Ref n) {
        if(!t) return n;
        if(xor128() % (t->size + 1) == 0) {
            RefPair p = split(t, k);
            return n->linklr(p.first, p.second);
        }
        t->propagate();
        int s = size(t->left);
        if(k <= s)
            return t->linkl(insert(Node::cut(t->left), k, n));
        else
            return t->linkr(insert(Node::cut(t->right), k - s - 1, n));
    }
    static RefPair remove(Ref t, int k) {
        if(!t) return RefPair((Ref)NULL, (Ref)NULL);
        t->propagate();
        int s = size(t->left);
        if(k < s) {
            RefPair p = remove(Node::cut(t->left), k);
            return RefPair(t->linkl(p.first), p.second);
        }else if(k > s) {
            RefPair p = remove(Node::cut(t->right), k - s - 1);
            return RefPair(t->linkr(p.first), p.second);
        }else {
            Ref a = join(Node::cut(t->left), Node::cut(t->right));
            return RefPair(a, t->linklr(NULL, NULL));
        }
    }
    static pair<Ref,int> findRoot(Ref t) {
        if(!t) return make_pair((Ref)NULL, 0);
        int k = size(t->left);
        while(true) {
            Ref p = t->parent;
            if(!p) return make_pair(t, k);
            if(p->right == t)
                k += size(p->left) + 1;
            t = p;
        }
    }
    static int lowerbound(Ref t, Ref x) {
        if(!t) return 0;
        t->propagate();
        if(x->val <= t->val) {
            return lowerbound(t->left, x);
        }else {
            return size(t->left) + 1 + lowerbound(t->right, x);
        }
    }
    static Ref insertSorted(Ref t, Ref x) {
        int k = lowerbound(t, x);
        return insert(t, k, x);
    }
    static bool solve(Ref t, Val x) {
        if(x <= t->val) {   //
            return solve(t->left, x);
        }
    }
};
typedef PRBSTBase BST;

Node nodes[100000];
int main() {
    //1,2,0
    //2
    //
    //greedy
    //sum
    int n, q;
    scanf("%d%d", &n, &q);
    rep(i, n) {
        int h;
        scanf("%d", &h);
        nodes[i] = Node(h);
    }
    Node *t = NULL;
    rep(i, n) t = BST::insertSorted(t, &nodes[i]);
    rep(ii, q) {
        int ty;
        scanf("%d", &ty);
        if(ty == 1) {
            int p, x;
            scanf("%d%d", &p, &x), p --;
            int k = BST::findRoot(&nodes[p]).second;
            t = BST::remove(t, k).first;
            nodes[p] = Node(x);
            t = BST::insertSorted(t, &nodes[p]);
        }else {
            long long v;
            scanf("%I64d", &v);
            Val l = 0, u = 1e16;
            rep(ii, 70) {
                Val mid = (l + u) / 2;
                Node tmp = Node(mid);
                int k = BST::lowerbound(t, &tmp);
                BST::RefPair p = BST::split(t, k);
                int m = !p.first ? 0 : p.first->size;
                if(mid * m - (!p.first ? 0 : p.first->sum) >= v)
                    u = mid;
                else
                    l = mid;
                t = BST::join(p.first, p.second);
            }
            printf("%.10f\n", (double)(l + u) / 2);
        }
    }
    return 0;
}