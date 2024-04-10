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

struct nodo {

    void push(nodo& izq, nodo& der, int x, int y){
        if(x+1 != y)
            izq.z += z, der.z += z;
        v += z * (ll) (y-x);
        z = 0;
    }

    void upd(ll val, int x, int y){
        z += val;
    }

    nodo comb(nodo& izq, nodo& der){
        v = izq.v + der.v;
        return *this;
    }

    ll v;
    ll z;
};

void push(vector<nodo>& tree, int v, int x, int y){
    if(x+1 != y) tree[v].push(tree[2*v],tree[2*v+1],x,y);
    else tree[v].push(tree[0],tree[0],x,y);
}

struct segmentTreeLazy {
    segmentTreeLazy (int _n){
        n = _n;
        tree = vector<nodo>(4*n);
    }

    void upd(int l, int r, ll val){
        upd(l, r, val, 1, 0, n);
    }

    void upd(int l, int r, ll val, int v, int x, int y){
        push(tree,v,x,y);
        if(r <= x or l >= y) return;
        if(l <= x and r >= y) {
            tree[v].upd(val, x, y);
            push(tree,v,x,y);
            return;
        }
        int m = (x+y)/2;
        upd(l, r, val, 2 * v, x, m);
        upd(l, r, val, 2 * v + 1, m, y);
        tree[v].comb(tree[2*v],tree[2*v+1]);
    }

    nodo get(int l, int r){
        return get(l,r,1,0,n);
    }

    nodo get(int l, int r, int v, int x, int y){
        push(tree,v,x,y);
        if(r <= x or l >= y) return nodo();
        if(l >= x and r <= y) return tree[v];
        int m = (x+y)/2;
        nodo izq = get(l,r,2*v,x,m);
        nodo der = get(l,r,2*v+1,m,y);
        return nodo().comb(izq,der);
    }

    int trav(ll k){
        return trav(k,1,0,n);
    }

    int trav(ll k, int v, int x, int y){
        push(tree,v,x,y);
        if(x+1 == y) return x;
        int m = (x+y)/2;
        push(tree,2*v,x,m);
        push(tree,2*v+1,m,y);
        if(tree[2*v].v >= k) return trav(k,2*v,x,m);
        else return trav(k-tree[2*v].v,2*v+1,m,y);
    }

    vector<nodo> tree;
    int n;
};

void power_sockets(){
    int n;
    ll k;
    cin>>n>>k;
    vll l(n);
    F0(i,n) cin>>l[i];
    sort(todo(l));
    reverse(todo(l));
    segmentTreeLazy st(6e5);
    st.upd(0,1,1);
    int res = 6e5;
    F0(i,n){
        int p = st.trav(1);
        st.upd(p,p+1,-1);
        st.upd(p+2,p+2+l[i]/2,1);
        st.upd(p+2,p+2+(l[i]-1)/2,1);
        if(st.get(0,6e5).v >= k) mini(res,st.trav(k));
    }
    if(res == 6e5) res = -1;
    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    power_sockets();
}