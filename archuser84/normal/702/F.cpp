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
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize("O0")

const int N = 200'100;
pii a[N];
pii b[N];
int n, k;


struct node
{
    int v, i;
    int lzy1, lzy2;
    int ans = 0;
    int pr;
    node *l, *r;
    node(int val, int p, int x = 0)
    {
        static mt19937 rd(time(0));
        pr = rd();
        v = val;
        i = p;
        lzy1 = lzy2 = 0;
        ans = x;
        l = r = 0;
    }
};

inline void ppg(node* t)
{
    t->v += t->lzy1;
    if(t->l) t->l->lzy1 += t->lzy1;
    if(t->r) t->r->lzy1 += t->lzy1;
    t->lzy1 = 0;
    t->ans += t->lzy2;
    if(t->l) t->l->lzy2 += t->lzy2;
    if(t->r) t->r->lzy2 += t->lzy2;
    t->lzy2 = 0;
}

void merge(node* &t, node* l, node* r)
{
    if(!l) {t = r; return;}
    if(!r) {t = l; return;}
    ppg(l); ppg(r);
    if(l->pr > r->pr) {t = l; merge(l->r, l->r, r);}
    else              {t = r; merge(r->l, l, r->l);}
}

void split(node* t, node* &l, node* &r, int v)
{
    if(!t){l = r = 0; return;}
    ppg(t);
    if(v <= t->v) {r = t; split(t->l, l, r->l, v);}
    else          {l = t; split(t->r, l->r, r, v);}
}

void bad_merge(node* &l, node* r)
{
    if(!r) return;
    ppg(r);
    bad_merge(l, r->l);
    node *A, *B;
    split(l, A, B, r->v);
    merge(A, A, new node(r->v, r->i, r->ans));
    merge(l, A, B);
    bad_merge(l, r->r);
    delete r;
}

void make_ans(node* t)
{
    if(!t) return;
    ppg(t);
    make_ans(t->l);
    b[t->i].F = t->ans;
    make_ans(t->r);
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
    {
        cin >> a[i].S >> a[i].F;
        a[i].F = ~a[i].F;
    }
    sort(a, a+n);
    cin >> k;
    node* rt = 0;
    Loop(i,0,k)
    {
        cin >> b[i].F;
        b[i].S = i;
    }
    sort(b, b+k);
    Loop(i,0,k) merge(rt, rt, new node(b[i].F, b[i].S));
    Loop(i,0,n)
    {
        node *A=0, *B=0, *C=0;
        split(rt, A, B, a[i].S);
        if(!B) {rt = A; continue;}
        B->lzy1 -= a[i].S;
        B->lzy2++;
        split(B, B, C, a[i].S);
        bad_merge(A, B);
        merge(rt, A, C);
    }
    make_ans(rt);
    Loop(i,0,k)
    {
        cout << b[i].F << ' ';
    }
}