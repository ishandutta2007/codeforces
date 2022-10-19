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
#define forall(it,s) for(auto it : s)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e18
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define sq(a) (a)*(a)
#define teamSize(t) ((t)<t4 ? 4 : ( (t)<t4+t3 ) ? 3 : 2 )
#define R real
#define I imag
const ll mod = 1e9+7;

struct nodo {

    void upd(int val, int x, int y){
        v = val;
    }

    nodo comb(nodo& izq, nodo& der){
        v = max(izq.v,der.v);
        return *this;
    }

    int v;
};

struct segmentTreeLazy {
    segmentTreeLazy (int _n){
        n = _n;
        tree = vector<nodo>(4*n);
    }

    void build(vi& a){
        build(a,1,0,n);
    }

    void build(vi& a, int v, int l, int r){
        if(l+1 == r){
            tree[v].upd(a[l],l,r);
            return;
        }
        int m = (l+r)/2;
        build(a,2*v,l,m);
        build(a,2*v+1,m,r);
        tree[v].comb(tree[2*v],tree[2*v+1]);
    }

    void upd(int i, int val){
        upd(i, val, 1, 0, n);
    }

    void upd(int i, int val, int v, int x, int y){
        if(i < x or y <= i) return;
        if(x+1 == y) {
            tree[v].upd(val,x,y);
            return;
        }
        int m = (x+y)/2;
        upd(i, val, 2 * v, x, m);
        upd(i, val, 2 * v + 1, m, y);
        tree[v].comb(tree[2*v],tree[2*v+1]);
    }

    nodo get(int l, int r){
        return get(l,r,1,0,n);
    }

    nodo get(int l, int r, int v, int x, int y){
        if(r <= x or l >= y) return nodo();
        if(l <= x and r >= y) return tree[v];
        int m = (x+y)/2;
        nodo izq = get(l,r,2*v,x,m);
        nodo der = get(l,r,2*v+1,m,y);
        return nodo().comb(izq,der);
    }

    int trav(int l, int x){
        return trav(l,x,1,0,n);
    }

    int trav(int l, int k, int v, int x, int y){
        if(y <= l) return n;
        if(tree[v].v < k) return n;
        if(x+1 == y) return x;
        int m = (x+y)/2;
        int izq = trav(l,k,2*v,x,m);
        if(izq != n) return izq;
        return trav(l,k,2*v+1,m,y);
    }

    vector<nodo> tree;
    int n;
};

void controversial_rounds(){
    int n;
    string s;
    cin>>n>>s;
    segmentTreeLazy st(n);
    vi nxt1(n+1),nxt0(n+1);
    nxt1[n] = n;
    nxt0[n] = n;
    F0R(i,n) {
        if(s[i] == '1') nxt1[i] = i;
        else nxt1[i] = nxt1[i+1];
    }
    F0R(i,n) {
        if(s[i] == '0') nxt0[i] = i;
        else nxt0[i] = nxt0[i+1];
    }
    vi a(n);
    F0(i,n) a[i] = max(nxt0[i],nxt1[i])-i;
    st.build(a);
    vi res(n+1);
    F1(x,n){
        int l = 0;
        l = st.trav(l,x);
        while(l < n){
            l += x;
            l = st.trav(l,x);
            res[x]++;
        }
    }
    F1(i,n) cout<<res[i]<<' ';
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    controversial_rounds();

}