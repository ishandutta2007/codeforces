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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER)
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
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

typedef int Val;
struct Node {
    int priority;
    Node *ch[2];
    Val val; int size;
    Val add;
    //
    Node(Val v, int p)
        : priority(p)
        , val(v), size(1), add(0) { ch[0] = ch[1] = NULL; }
};
//NULL(Node)
//addvalmini
Val val(Node *x) { return x->val + x->add; }
int size(Node *x) { return !x ? 0 : x->size; }

Node *update(Node *x) {
    //
    if(!x) return x;
    x->size = size(x->ch[0]) + 1 + size(x->ch[1]);
    if(x->add) {
        x->val += x->add;
        if(x->ch[0]) x->ch[0]->add += x->add;
        if(x->ch[1]) x->ch[1]->add += x->add;
        x->add = 0;
    }
    return x;
}
Node *link(Node *x, Node *c, bool b) {
    x->ch[b] = c; return update(x);
}
Node *merge(Node *x, Node *y) {
    x = update(x); y = update(y);
    if(!x || !y) return x ? x : y;
    if(x->priority < y->priority) {
        return link(x, merge(x->ch[1], y), 1);
    }else {
        return link(y, merge(x, y->ch[0]), 0);
    }
}
//split([0,k) , [k,n))
typedef pair<Node*, Node*> NPair;
NPair split(Node *t, int k) {
    if(!update(t)) return mp((Node*)NULL, (Node*)NULL);
    if(size(t->ch[0]) < k) {
        NPair u = split(t->ch[1], k - size(t->ch[0]) - 1);
        return mp(link(t, u.first, 1), u.second);
    }else {
        NPair u = split(t->ch[0], k);
        return mp(u.first, link(t, u.second, 0));
    }
}
Node *singleton(Val val) { return update(new Node(val, rand())); }
Val getvalue(Node *t, int k) {
    if(!update(t)) return -1;
    if(size(t->ch[0]) == k) {
        return val(t);
    } else if(k < size(t->ch[0])) {
        return getvalue(t->ch[0], k);
    }else {
        return getvalue(t->ch[1], k - size(t->ch[0]) - 1);
    }
}
Node *rangeadd(Node *t, int l, int r, Val x) {
    if(r <= l) return t;
    NPair p = split(t, l);
    NPair q = split(p.second, r - l);
    q.first->add += x;
    return merge(p.first, merge(q.first, q.second));
}
ostream& operator<<(ostream& o, Node *t) {
    int n = size(t);
    o << "[";
    rep(i, n) {
        pair<Node*, Node*> p = split(t, i);
        pair<Node*, Node*> q = split(p.second, 1);
        o << val(q.first);
        if(i+1 != n) o << ", ";
        t = merge(p.first, merge(q.first, q.second));
    }
    return o << "]";
}

vector<vi> edges;
int branchindex[100100], branchdepth[100100], branchsize[100100];
Node *all = NULL;
vector<Node*> branches;

void dfs(int index, int depth, int i, int parent) {
    branchindex[i] = index;
    branchdepth[i] = depth;
    branchsize[index] = depth + 1;
    branches[index] = merge(branches[index], singleton(0));
    each(j, edges[i]) if(*j != parent) dfs(index, depth+1, *j, i);
}
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    edges.resize(n);
    rep(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        u --, v --;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    rep(i, edges[0].size()) {
        branches.pb(NULL);
        dfs(i, 0, edges[0][i], 0);
    }
    rep(i, 100100) all = merge(all, singleton(0));
    rep(ii, q) {
        int qq;
        scanf("%d", &qq);
        if(qq == 0) {
            int v, x, d;
            scanf("%d%d%d", &v, &x, &d);
            v --;
            if(v == 0) {
                all = rangeadd(all, 0, d + 1, x);
            }else {
                int idx = branchindex[v], dep = branchdepth[v];
                int bu = max(0, dep - d),
                    bb = min(branchsize[idx], dep + d + 1);
                branches[idx] = rangeadd(branches[idx], bu, bb, x);
                if(dep < d) {
                    all = rangeadd(all, 0, d - dep, x);
                    branches[idx] = rangeadd(branches[idx], 0, d - dep - 1, - x);
                }
            }
        }else {
            int v;
            scanf("%d", &v);
            v --;
            int a = 0;
            if(v == 0) {
                a += getvalue(all, 0);
            }else {
                a += getvalue(branches[branchindex[v]], branchdepth[v]);
                a += getvalue(all, branchdepth[v] + 1);
            }
            printf("%d\n", a);
        }

        /*
        rep(i, edges[0].size()) {
            cerr << "B" << i << ": " << branches[i] << endl;
        }
        cerr << "A: " << all << endl;
        */
    }
    
    return 0;
}