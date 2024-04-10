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
#include <list>
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
    Val val; int size; ll sum;
    Val add;
    Node(Val v, int p)
        : priority(p)
        , val(v), size(1), add(0), sum(v) { ch[0] = ch[1] = NULL; }
};
//NULL(Node)
//addvalmini
Val val(Node *x) { return x->val + x->add; }
int size(Node *x) { return !x ? 0 : x->size; }
ll sum(Node *x) { return !x ? 0 : x->sum + (ll)x->add * x->size; }

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
    x->sum = sum(x->ch[0]) + x->val + sum(x->ch[1]);
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

int main() {
    int n;
    scanf("%d", &n);
    Node *t = singleton(0);
    rep(i, n) {
        int ty;
        scanf("%d", &ty);
        if(ty == 1) {
            int a, x;
            scanf("%d%d", &a, &x);
            NPair p = split(t, a);
            p.first->add += x;
            t = merge(p.first, p.second);
        }else if(ty == 2) {
            int k;
            scanf("%d", &k);
            t = merge(t, singleton(k));
        }else if(ty == 3) {
            t = split(t, t->size-1).first;
        }
        printf("%.10f\n", sum(t) * 1. / size(t));
    }
    return 0;
}