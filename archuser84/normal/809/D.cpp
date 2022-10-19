///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize("O0")

mt19937 rd(time(0));

struct node
{
    int v;
    int pr;
    int lzy;
    node *l, *r;
    node(int val)
    {
        v = val;
        pr = rd();
        lzy = 0;
        l = r = 0;
    }
};

inline void ppg(node* t)
{
    if(t->l) t->l->lzy += t->lzy;
    if(t->r) t->r->lzy += t->lzy;
    t->v += t->lzy;
    t->lzy = 0;
}

node* merge(node* l, node* r)
{
    if(!l) return r;
    if(!r) return l;
    ppg(l); ppg(r);
    if(l->pr > r->pr)
    {
        l->r = merge(l->r, r);
        return l;
    }
    else
    {
        r->l = merge(l, r->l);
        return r;
    }
}

void split(node* t, int v, node* &l, node* &r, bool e = 0)
{
    if(!t) {l = r = 0; return;}
    ppg(t);
    if(t->v < v || (e && t->v == v)) {l = t; split(t->r, v, t->r, r, e);}
    else                             {r = t; split(t->l, v, l, t->l, e);}
}

node* lowbnd(node* t, int v)
{
    if(!t) return 0;
    ppg(t);
    if(t->v < v) return lowbnd(t->r, v);
    else         {auto tmp = lowbnd(t->l, v); return tmp? tmp: t;}
}

node* lst(node* t)
{
    ppg(t);
    return t->r? lst(t->r): t;
}

int cnt(node* t){return t? 1+cnt(t->l)+cnt(t->r): 0;}

void print(node* t){
    if(!t) return;
    ppg(t);
    print(t->l);
    cout << t->v << ' ';
    print(t->r);
}

int main()
{
    FAST;
    node *rt = new node(0), *dmy = new node(-1);
    int n;
    cin >> n;
    while(n--)
    {
        int l, r;
        cin >> l >> r;
        node* i = lowbnd(rt, l); if(!i) rt = merge(rt, i = new node(1e9+10));
        node* j = lowbnd(rt, r); if(!j) rt = merge(rt, j = new node(1e9+10));
        node *X, *Y, *Z;
        split(rt, i->v, X, Y, 0);
        split(Y, j->v, Y, Z, 1);
        if(Y) {
            Y->lzy++;
            split(Y, lst(Y)->v, Y, dmy);
        }
        Y = merge(new node(l), Y);
        rt = merge(X, Y);
        rt = merge(rt, Z);
    }
    split(rt, 1e9 + 5, rt, dmy);
    cout << cnt(rt)-1 << '\n';
}