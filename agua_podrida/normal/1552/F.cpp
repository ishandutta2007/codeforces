#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
using ll = long long;
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
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
const int mod = 998244353;
const ll INF  = 1e18;
const double eps = 0.00000001;

struct nodo {

    void upd(ll val, int x, int y){
        v = val;
    }

    nodo comb(nodo& izq, nodo& der){
        v = (izq.v + der.v) % mod;
        return *this;
    }

    ll v;
};

struct segmentTree {
    segmentTree(int _n){
        n = _n;
        tree = vector<nodo>(4*n);
    }

    void upd(int i, ll val){
        upd(i, val, 1, 0, n);
    }

    void upd(int i, ll val, int v, int x, int y){
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

    vector<nodo> tree;
    int n;
};

int bb(vll& v, ll x){
    int lo = -1;
    int hi = v.size();
    while(lo+1 != hi){
        int m = (lo+hi)/2;
        if(v[m] <= x) lo = m;
        else hi = m;
    }
    return hi;
}

void F(){
    int n;
    cin>>n;
    vll x(n),y(n),s(n);
    F0(i,n) cin>>x[i]>>y[i]>>s[i];

    segmentTree st(n);
    F0(i,n){
        int j = bb(x,y[i]);
        ll res = x[i]-y[i];
        if(j < i) res += st.get(j,i).v;
        res %= mod;
        st.upd(i,res);
    }
    ll res = x[n-1]+1;
    F0(i,n) {
        if(s[i] == 1) res += st.get(i,i+1).v;
        res %= mod;
    }
    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    F();
    return 0;
}