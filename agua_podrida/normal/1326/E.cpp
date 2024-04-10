#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
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
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 998244353;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
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
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

struct lazySegmentTreeMax {

    lazySegmentTreeMax(int nn);

    int maxr(int a, int b, int nodo, int x, int y);

    void add(int a, int b, int val, int nodo, int x, int y);

    int n;
    vi tree;
    vi lazy;
};

lazySegmentTreeMax::lazySegmentTreeMax(int nn) {
    n = nn;
    tree = vi(4*n);
    lazy = vi(4*n);
}

int lazySegmentTreeMax::maxr(int a, int b, int nodo, int x, int y){
    if(b < x or y < a) return -INF;
    if(lazy[nodo]){
        if(x != y){
            lazy[2*nodo] += lazy[nodo];
            lazy[2*nodo+1] += lazy[nodo];
        }
        tree[nodo] += lazy[nodo];
        lazy[nodo] = 0;
    }
    if(a <= x and y <= b) return tree[nodo];
    int d = (x+y)/2;
    int resIzq = maxr(a,b,2*nodo,x,d);
    int resDer = maxr(a,b,2*nodo+1,d+1,y);
    return max(resIzq,resDer);
}

void lazySegmentTreeMax::add(int a, int b, int val, int nodo, int x, int y) {
    if(lazy[nodo]){
        if(x != y){
            lazy[2*nodo] += lazy[nodo];
            lazy[2*nodo+1] += lazy[nodo];
        }
        tree[nodo] += lazy[nodo];
        lazy[nodo] = 0;
    }
    if(b < x or y < a) return;
    if(a <= x and b >= y){
        tree[nodo] += val;
        if(x != y) {
            lazy[2*nodo] += val;
            lazy[2*nodo+1] += val;
        }
        return;
    }

    int d = (x+y)/2;
    add(a,b,val,nodo*2,x,d);
    add(a,b,val,nodo*2+1,d+1,y);
    tree[nodo] = max(tree[2*nodo],tree[2*nodo+1]);
}

int p[300005];

bool cmp(int a, int b){
    return p[a] < p[b];
}

void e(){
    int n;
    cin>>n;
    F1(i,n) cin>>p[i];
    vi q(n+1);
    F1(i,n) cin>>q[i];

    vi pos(n+1);
    F1(i,n) pos[p[i]] = i;

    lazySegmentTreeMax t(n+1);

    vi res(n);
    res[0] = n;
    t.add(1,pos[n],1,1,0,n);
    int agregueHasta = n;
    F1(i,n-1){
        t.add(1,q[i],-1,1,0,n);
        while(t.maxr(1,n,1,0,n) <= 0){
            agregueHasta--;
            t.add(1,pos[agregueHasta],1,1,0,n);
        }
        res[i] = agregueHasta;
    }
    F0(i,n) cout<<res[i]<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    e();
    return 0;
}