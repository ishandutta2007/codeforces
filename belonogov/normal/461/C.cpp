#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = -1;
const int INF = 1e9;

struct node{
    node * l, * r;
    int sum, cnt, val, y;
    bool rev;
    node () {
        cnt = 1;
        l = r = NULL;
        sum = val = -1;
        rev = 0;
    }
};

int getCnt(node * v) {
    return (v == NULL)? 0: v->cnt;
}

int getSum(node * v) {
    return (v == NULL)? 0: v->sum;
}

void upd(node * v) {
    assert(v != NULL);
    v->cnt = getCnt(v->l) + getCnt(v->r) + 1;
    v->sum = getSum(v->l) + getSum(v->r) + v->val;
}

void push(node * v) {
    assert(v != NULL);
    if (v->rev) {
        v->rev = 0;
        if (v->l) v->l->rev ^= 1;
        if (v->r) v->r->rev ^= 1;
        swap(v->l, v->r);
    }
}

node * merge(node * l, node * r) {
    if (l == NULL) return r;
    if (r == NULL) return l;
    if (l->y > r->y) {
        push(l);
        l->r = merge(l->r, r);
        upd(l);
        return l;
    } 
    else {
        push(r);
        r->l = merge(l, r->l);
        upd(r);
        return r;
    }
}

void split(node * v, int key, node * & l, node * & r) {
    if (v == NULL) {
        l = r = NULL;
        return;
    }
    push(v);
    if (getCnt(v->l) >= key) {
        split(v->l, key, l, v->l);
        upd(v);
        r = v;
        return;
    }
    else {
        split(v->r, key - getCnt(v->l) - 1, v->r, r);
        upd(v);
        l = v;
        return;
    }
}

void print(node * v, int tabs = 0) {
    if (v == NULL) return;
    print(v->r, tabs + 1);
    for (int i = 0; i < tabs; i++)
        cerr << "\t";
    cerr << "val sum: " << v->val << " " << v->sum << endl;
    print(v->l, tabs + 1);
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n, q;
    scanf("%d%d", &n, &q);
    node * head = NULL;
    int pos, type;
    for (int i = 0; i < n; i++) {
        node * v = new node;
        v->val = v->sum = 1;
        v->y = rand();
        head = merge(head, v);
    }
    //cerr << getCnt(head) << endl; 
    int len = n;
    node * ll, * rr, * mm, *l, *r, *m;
    while (q--) {
        //print(head);
        //cerr << endl;
        //cerr << endl;
        //cerr << endl;
        //cerr << "sdf\n";
        scanf("%d", &type); 
        if (type == 1) {
            scanf("%d", &pos); 
            split(head, pos, l, r);
            //cerr << getCnt(l) << endl;
            //cerr << getCnt(r) << endl;
            int cntL = getCnt(l);
            len -= cntL;
            //cerr << "sdf\n";
            //cerr << "sdf\n";
            for (int i = 0; i < min(cntL, len); i++) {
                //cerr << getCnt(l) << endl;
                split(l, getCnt(l) - 1, l, m);
                //cerr << getCnt(l) << endl;
                //cerr << getCnt(m) << endl;
                int tmp = m->val;
                //cerr << getCnt(l) << endl;
                split(r, i + 1, ll, rr);
                split(ll, i, ll, mm);
                //cerr << getCnt(mm) << endl;
                mm->val += tmp;
                mm->sum += tmp;
                r = merge(ll, merge(mm, rr));
            //cerr << "sdf\n";
            }
            //cerr << "sdf\n";
            if (getCnt(l) > 0) {
                l->rev ^= 1;
                len += getCnt(l);
            }
            //cerr << "sdf\n";
            head = merge(r, l);
            //cerr << "sdf\n";
        }
        if (type == 2) {
            int l, r;
            scanf("%d%d", &l, &r);
            split(head, r, ll, rr);
            split(ll, l, ll, mm); 
            printf("%d\n", getSum(mm));
            head = merge(ll, merge(mm, rr));
            assert(mm != NULL);
        }
    }
    


    return 0;
}