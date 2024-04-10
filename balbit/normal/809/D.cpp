#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 1e9+7 ;


void GG(){cout<<"0\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e6+5;

struct Nd{
    int pri = rand();
    int val = 0, tag = 0, id = 0, idtg = 0, mx=0;
    Nd * lc=0, *rc = 0;
    Nd(int v, int pos) {
        val = mx=v; id = pos;
    }
};

inline void push(Nd *& o) {
    if (!o) return;
    if (o->tag) {
        o->val += o->tag;
        o->mx += o->tag;
        if (o->lc) o->lc->tag += o->tag;
        if (o->rc) o->rc->tag += o->tag;
        o->tag=0;
    }
    if (o->idtg) {
        o->id += o->idtg;
        if (o->lc) o->lc->idtg += o->idtg;
        if (o->rc) o->rc->idtg += o->idtg;
        o->idtg = 0;
    }
}

inline void pull(Nd *&o) {
    if (!o)return;
    o->mx = o->val;
    if (o->lc) o->mx = max(o->mx, o->lc->mx);
    if (o->rc) o->mx = max(o->mx, o->rc->mx);
}

Nd * merge(Nd *&A, Nd*&B) {
    push(A); push(B);
    if (!A) return B;
    if (!B) return A;
    if (A->pri > B->pri) {
        A->rc = merge(A->rc, B);
        push(A->lc);
        pull(A);
        return A;
    }else{
        B->lc = merge(A, B->lc);
        push(B->rc);
        pull(B);
        return B;
    }
}

void split(Nd *o, Nd * & A, Nd *& B, int id) {
    A=B=0;
    if (!o) return;
    push(o);
    if (o -> id < id) {
        A = o;
        split(o->rc, A->rc, B, id);
        push(A->lc);
        pull(A);
    }else{
        B = o;
        split(o->lc,A, B->lc, id);
        push(B->rc);
        pull(B);
    }
}

signed main(){
    IOS();
    srand(time(0));
    int n; cin>>n;
    Nd * o = new Nd(0,0);
    for (int i = 0; i<n; ++i) {
        int l,r; cin>>l>>r;
        Nd * A, *tmp, *B, *C;
        split(o,A,tmp,l); split(tmp,B,C,r);
        // (-inf, l) [l, r), [r, inf)
        if (A) bug("Has A");
        if (B) bug("Has B");
        if (C) bug("Has C");
        if (B) {
            bug("Has b", i);
            B->tag++; B->idtg++; push(B);
        }

        assert(A!=nullptr);

        Nd * AB = new Nd(A->mx+1,l);

        o = merge(A, AB);
        o = merge(o, B);
        o = merge(o,C);
        bug(o->mx);
    }
    cout<<o->mx<<endl;
}