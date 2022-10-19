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
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define todo(v) v.begin(),v.end()
const int mod = 998244353;
const int INF  = 1e9;
const double eps = 0.00000001;


const int magic = 350;
int dpd[magic],dpx[magic];
int ndpd[magic],ndpx[magic];
vi a;

inline int bb(int ar, int d){
    return (ar-1)/d;
}

inline int g1(int r, int d){
    if(r == 0) return 0;
    if(d < magic) return dpd[d];
    int x = bb(a[r],d);
    return dpx[x];
}

void avanzar(int r){
    F0(x,magic){
        int d = a[r] / (x+1);
        ll rx = (ll) r * (ll) x;
        ndpx[x] = (g1(r-1,d) + rx) % mod;
    }
    F1(d,magic-1){
        int x = bb(a[r],d);
        int dd = a[r] / (x+1);
        ll rx = (ll) r * (ll) x;
        ndpd[d] = (g1(r-1,dd) + rx) % mod;
    }
    swap(dpd,ndpd);
    swap(dpx,ndpx);
}

void c(){
    int n;
    cin>>n;
    a = vi(n+1);
    F1(i,n) cin>>a[i];
    F0(i,magic) dpd[i] = dpx[i] = 0;
    int res = 0;
    F1(r,n) {
        avanzar(r);
        res = (res + dpx[0]) % mod;
    }
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) c();
}