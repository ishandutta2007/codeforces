#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
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
using namespace std;
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl; typedef pair<ll,ll> pll; typedef vector<pll> vpll; typedef vector<string> vs;
const int INF = 0x3f3f3f3f; const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

typedef int Val;
#define BITS 20
struct Node {
    Val val; int priority;
    Node *ch[2];
    //(sum, min, etc.)
    //splitsize
    int size;
    int count[BITS]; int xorx;
    //
    Node(Val v, int p)
        : val(v), priority(p)
        , size(1), xorx(0) { ch[0] = ch[1] = NULL; mset(count, 0); }
};
//NULL(Node)
int val(Node *x) { assert(x); return x->val; }
int size(Node *x) { return !x ? 0 : x->size; }
int count(Node *x, int j) {
    return !x ? 0 : ((x->xorx>>j)&1 ? size(x) - x->count[j] : x->count[j]);
}

Node *update(Node *x) {
    //
    if(!x) return x;
    x->size = size(x->ch[0]) + 1 + size(x->ch[1]);
    rep(j, BITS) {
        x->count[j] = count(x->ch[0], j) + ((val(x)>>j)&1) + count(x->ch[1], j);
        if((x->xorx>>j)&1)
            x->count[j] = x->size - x->count[j];
    }
    if(x->ch[0]) x->ch[0]->xorx ^= x->xorx;
    if(x->ch[1]) x->ch[1]->xorx ^= x->xorx;
    x->val ^= x->xorx; x->xorx = 0;
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
pair<Node*, Node*> split(Node *t, int k) {
    if(!update(t)) return mp((Node*)NULL, (Node*)NULL);
    if(size(t->ch[0]) < k) {
        aut(u, split(t->ch[1], k - size(t->ch[0]) - 1));
        return mp(link(t, u.first, 1), u.second);
    }else {
        aut(u, split(t->ch[0], k));
        return mp(u.first, link(t, u.second, 0));
    }
}
Node *singleton(Val val) { return update(new Node(val, rand())); }

int rnd(int x) {
    return (rand()*(RAND_MAX+1)+rand())%x;
}
//#define RANDOM_INPUT
int main() {
    Node *t = NULL;
    int n, m;
    scanf("%d", &n);
//  srand(clock());
    rep(i, n) {
        int a;
#ifndef RANDOM_INPUT
        scanf("%d", &a);
#else
        a = rnd(1000000);
#endif
        t = merge(t, singleton(a));
    }
    scanf("%d", &m);
    clock_t cl = clock();
    rep(i, m) {
        int y, l, r;
#ifndef RANDOM_INPUT
        scanf("%d%d%d", &y, &l, &r);
#else
        y = rnd(2)+1; l = rnd(n)+1; r = rnd(n)+1; if(l > r) swap(l, r);
#endif
        l--; r--; r ++;
        Node *tl, *tm, *tr;
        pair<Node*,Node*> p, q;
        p = split(t, l);
        q = split(p.second, r-l);
        tl = p.first; tm = q.first; tr = q.second;
        if(y == 1) {
            ll s = 0;
            rep(j, BITS)
                s += (ll)count(tm, j) << j;
#ifndef RANDOM_INPUT
            cout << s << endl;
#endif
        }else if(y == 2) {
            int x;
#ifndef RANDOM_INPUT
            scanf("%d", &x);
#else
            x = rnd(1000000);
#endif
            tm->xorx ^= x;
        }
        t = merge(merge(tl, tm), tr);
        if(0){
            cerr << "t: ";
            int i = 0;
            while(1) {
                int x = 0;
                pair<Node*,Node*> p = split(t, i);
                if(p.second == NULL) goto break_;
                pair<Node*,Node*> q = split(p.second, 1);
                x = q.first->val;
                t = merge(merge(p.first, q.first), q.second);
                cerr << x << " ";
                i ++;
            }
            break_:;
            cerr << endl;
        }
    }
    cerr << "time: " << (clock() - cl) << endl;
    return 0;
}