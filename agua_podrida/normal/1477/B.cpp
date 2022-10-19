#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 2e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define mod 1000000007


struct nodo{
    nodo(){
        v = 0;
        lazy = -1;
    }

    bool tieneLazy(){
        return lazy != -1;
    }

    void propagarLazy(nodo& izq, nodo& der, int x, int y){
        izq.lazy = lazy;
        der.lazy = lazy;
        convertirLazy(x,y);
    }

    void convertirLazy(int x, int y){
        v = lazy*(y-x+1);
        lazy = -1;
    }

    void combinar(nodo a, nodo b){
        v = a.v + b.v;
    }

    void op1(ll val, int x, int y){
        ponerLazy(val,x,y);
        convertirLazy(x,y);
    }

    void ponerLazy(ll val, int x, int y){
        lazy = val;
    }

    ll v;
    ll lazy;
};

struct lazySegmentTree{
    lazySegmentTree(int nn);

    nodo suma(int a, int b, int nodo, int x, int y);
    ll suma(int a, int b){
        return this->suma(a,b,1,0,n-1).v;
    }

    void asignar(int a, int b, ll val, int nodo, int x, int y);

    void asignar(int a, int b, ll val){
        this->asignar(a,b,val,1,0,n-1);
    }

    int n;
    vector<nodo> tree;
    vector<nodo> lazy;
};

lazySegmentTree::lazySegmentTree(int nn) {
    n = nn;
    tree = vector<nodo>(4*n);
}

nodo lazySegmentTree::suma(int a, int b, int i, int x, int y) {
    nodo acc;
    if(b < x or y < a) return acc;
    if(tree[i].tieneLazy()){
        if(x != y) tree[i].propagarLazy(tree[2*i],tree[2*i+1],x,y);
        else tree[i].convertirLazy(x,y);
    }
    if(a <= x and y <= b) return tree[i];
    int d = (x+y)/2;
    acc.combinar(acc,suma(a,b,2*i,x,d));
    acc.combinar(acc,suma(a,b,2*i+1,d+1,y));
    return acc;
}

void lazySegmentTree::asignar(int a, int b, ll val, int i, int x, int y) {
    if(tree[i].tieneLazy()){
        if(x != y) tree[i].propagarLazy(tree[2*i],tree[2*i+1],x,y);
        else tree[i].convertirLazy(x,y);
    }
    if(b < x or y < a) return;
    if(a <= x and b >= y){
        tree[i].op1(val,x,y);
        if(x != y) {
            int d = (x+y)/2;
            tree[2*i].ponerLazy(val,x,d);
            tree[2*i+1].ponerLazy(val,d+1,y);
        }
        return;
    }

    int d = (x+y)/2;
    asignar(a, b, val, i * 2, x, d);
    asignar(a, b, val, i * 2 + 1, d + 1, y);
    tree[i].combinar(tree[2*i],tree[2*i+1]);
}

void b(){
    int n,q;
    cin>>n>>q;
    string s,t;
    cin>>s>>t;
    vi l(q),r(q);
    F0(i,q) cin>>l[i]>>r[i];
    F0(i,q) l[i]--;
    F0(i,q) r[i]--;

    lazySegmentTree st(n);
    F0(i,n) st.asignar(i,i,(int) t[i] - '0');

    F0R(i,q){
        ll unos = st.suma(l[i],r[i]);
        ll ceros = r[i]-l[i]+1 - unos;
        if(unos == ceros) {
            cout<<"NO\n";
            return;
        }
        if(unos < ceros) st.asignar(l[i],r[i],0);
        else st.asignar(l[i],r[i],1);
    }

    F0(i,n) {
        if(st.suma(i,i) != (int) s[i] - '0') {
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) b();
}