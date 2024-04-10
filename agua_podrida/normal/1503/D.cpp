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
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e9
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
const ll mod = 998244353;

int n;
vi as;
vb top,use;

bool esta_piola(vi& arr){
    F0(i,(int) arr.size() - 1){
        if(arr[i] > arr[i]+1) return false;
        if(as[arr[i]] < as[arr[i+1]]) return false;
    }
    return true;
}

int solve(int l, int r){
    if(l > r) return 0;
    if(as[l] == r) return solve(l+1,r-1);
    int x = as[l], y = as[r];
    if(x < y) return -1;
    vi arr,der;
    arr.pb(l), der.pb(r);
    use[l] = true, use[r] = true;
    use[x] = true, use[y] = true;
    int lo = l+1, hi = r-1;
    while(use[lo]) lo++;
    while(use[hi]) hi--;
    while(lo < y or x < hi){
        if(lo < y) {
            if(as[lo] > x) return -1;
            x = as[lo];
            use[as[lo]] = true;
            use[lo] = true;
            arr.pb(lo);
        }
        else {
            if(as[hi] < y) return -1;
            y = as[hi];
            use[hi] = true;
            use[as[hi]] = true;
            der.pb(hi);
        }
        while(lo < r and use[lo]) lo++;
        while(hi > l and use[hi]) hi--;
    }
    F0R(i,der.size()) arr.pb(der[i]);
    if(!esta_piola(arr)) return -1;
    int res = solve(lo,hi);
    if(res == -1) return -1;
    int darVuelta = 0;
    for(auto u : arr) if(top[u]) darVuelta++;
    mini(darVuelta, (int) arr.size() - darVuelta);
    return res + darVuelta;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int u,v;
    as.resize(2*n);
    top = vb(2*n,false);
    use = top;
    F0(i,n){
        cin>>u>>v;
        u--, v--;
        top[u] = true;
        as[u] = v;
        as[v] = u;
    }

    int res = solve(0,2*n-1);
    cout<<res<<'\n';
}