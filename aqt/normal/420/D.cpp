#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)
#define F first
#define S second

const int MN = 1e6+6;
int n, m, i, j, x, y, pos[MN], lst[MN], use[MN], nxt, fl;
pii arr[MN]; queue<int> fr;

struct nd{
    int k, sz, p; nd *l, *r;
    nd(int id):k(id),sz(1),p(rand()),l(0),r(0){}
}*rt,*l,*r,*t;
inline int sz(nd *n){return n?n->sz:0;}
inline void upd(nd *&n){if(n)n->sz=sz(n->l)+sz(n->r)+1;}
void split(nd *n,nd *&l,nd *&r,int k){
    if(!n) l=r=NULL;
    else if(sz(n->l)+1<=k) split(n->r,n->r,r,k-sz(n->l)-1), l=n;
    else split(n->l,l,n->l,k), r=n;
    upd(n);
}
void mrg(nd *&n,nd *l,nd *r){
    if(!l||!r) n=l?l:r;
    else if(l->p>r->p) mrg(l->r,l->r,r), n=l;
    else mrg(r->l,l,r->l), n=r;
    upd(n);
}

int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
        scanf("%d%d",&arr[i].F,&arr[i].S);
    rt = NULL;
    for(i=1;i<=n;i++)
        mrg(rt, rt, new nd(++nxt));
    for(i=1;i<=m;i++){
        split(rt, l, r, arr[i].S);
        split(l, l, t, arr[i].S-1);
        int id = t->k;
        if(pos[arr[i].F]&&use[id]!=arr[i].F){
            fl = 1;
            break;
        }
        if(use[id]&&use[id]!=arr[i].F){
            fl = 1;
            break;
        }
        use[id] = arr[i].F;
        pos[arr[i].F] = id;
        mrg(l, l, t);
        mrg(rt, l, r);
        split(rt, l, r, arr[i].S);
        split(l, l, t, arr[i].S-1);
        mrg(l, t, l);
        mrg(rt, l, r);
    }
    if(fl) printf("-1\n");
    else{
        for(i=1;i<=n;i++){
            if(!pos[i]) fr.push(i);
        }
        for(i=1;i<=n;i++){
            if(use[i]) printf("%d ",use[i]);
            else{
                x = fr.front(); fr.pop();
                printf("%d ",x);
            }
        }
        printf("\n");
    }
    return 0;
}