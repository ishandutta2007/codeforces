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
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 2e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define mod 1000000007

#define no_op -1

struct nodo {

    void push(nodo& izq, nodo& der, int x, int y){
        if(z == no_op) return;
        if(x+1 != y)
            izq.z = z, der.z = z;
        h = z;
        s = z*(y-x);
        z = no_op;
    }

    void upd(ll val, int x, int y){
        z = val;
    }

    nodo comb(nodo& izq, nodo& der){
        h = min(izq.h,der.h);
        s = izq.s + der.s;
        return *this;
    }

    ll h;
    ll s;
    ll z = no_op;
};

struct segmentTreeLazy {
    segmentTreeLazy (int _n){
        n = _n;
        tree = vector<nodo>(4*n);
    }

    segmentTreeLazy(vll& a){
        n = a.size();
        tree = vector<nodo>(4*n);
        build(a,1,0,n);
    }

    void build(vll& a, int v, int x, int y){
        if(x+1 == y){
            tree[v].h = a[x];
            tree[v].s = a[x];
            return;
        }
        int m = (x+y)/2;
        build(a,2*v,x,m);
        build(a,2*v+1,m,y);
        tree[v].comb(tree[2*v],tree[2*v+1]);
    }

    void upd(int l, int r, ll val){
        upd(l, r, val, 1, 0, n);
    }

    void upd(int l, int r, ll val, int v, int x, int y){
        push(v,x,y);
        if(r <= x or l >= y) return;
        if(l <= x and r >= y) {
            tree[v].upd(val, x, y);
            push(v,x,y);
            return;
        }
        int m = (x+y)/2;
        upd(l, r, val, 2 * v, x, m);
        upd(l, r, val, 2 * v + 1, m, y);
        tree[v].comb(tree[2*v],tree[2*v+1]);
    }

    ll get(int l, int r){
        return get(l,r,1,0,n);
    }

    ll get(int l, int r, int v, int x, int y){
        push(v,x,y);
        if(r <= x or l >= y) return 0;
        if(l <= x and r >= y) return tree[v].s;
        int m = (x+y)/2;
        ll izq = get(l,r,2*v,x,m);
        ll der = get(l,r,2*v+1,m,y);
        return izq+der;
    }

    int trav(ll k){
        return trav(k,1,0,n);
    }

    int trav(ll k, int v, int x, int y){
        push(v,x,y);
        while(x+1 != y and tree[v].s > k){
            int m = (x+y)/2;
            push(2*v,x,m);
            if(tree[2*v].s > k) {
                v = 2*v;
                y = m;
            }
            else {
                push(2*v+1,m,y);
                k -= tree[2*v].s;
                v = 2*v+1;
                x = m;
            }
        }
        if(tree[v].s <= k) return n;
        return x;
    }

    int masChico(ll k){
        return masChico(k,1,0,n);
    }

    int masChico(ll k, int v, int x, int y){
        push(v,x,y);
        while(tree[v].h <= k and x+1 != y){
            int m = (x+y)/2;
            push(2*v,x,m);
            if(tree[2*v].h <= k) {
                v = 2*v;
                y = m;
            }
            else {
                push(2*v+1,m,y);
                v = 2*v+1;
                x = m;
            }
        }
        if(tree[v].h > k) return n;
        return x;
    }

    void push(int v, int x, int y){
        if(x+1 != y) tree[v].push(tree[2*v],tree[2*v+1],x,y);
        else tree[v].push(tree[0],tree[0],x,y);
    }

    vector<nodo> tree;
    int n;
};

void greedy_shopping(){
    int n,q;
    cin>>n>>q;
    vll a(n);
    F0(i,n) cin>>a[i];
    segmentTreeLazy st(a);
    int t,x;
    ll y;
    while(q--){
        cin>>t>>x>>y;
        x--;
        if(t == 1){
            int l = st.masChico(y);
            x++;
            if(l < x) st.upd(l,x,y);
        }
        else {
            int res = 0;
            int l = x;
            int i = 0;
            while(l < n){
                if(l > 0) y += st.get(0,l);
                i = st.trav(y);
                res += i-l;
                if(i == n) break;
                if(i > 0) y -= st.get(0,i);
                l = st.masChico(y);
            }
            cout<<res<<'\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    greedy_shopping();
}