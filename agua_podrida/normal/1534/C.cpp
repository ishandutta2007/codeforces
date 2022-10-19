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
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
const ll mod = 1000000007;
const ll INF  = 1e9;
const double eps = 0.000000001;

void b(){
    int n;
    cin>>n;
    vi a(n),b(n);
    F0(i,n) cin>>a[i];
    F0(i,n) cin>>b[i];
    vi g(n);
    F0(i,n) g[a[i]-1] = b[i]-1;
    vb marcado(n,false);
    int ciclos = 0;
    F0(i,n) {
        if(a[i] == b[i]) {
            cout<<"0\n";
            return;
        }
    }
    F0(i,n){
        if(!marcado[i]){
            ciclos ++;
            int j = i;
            do {
                marcado[j] = true;
                j = g[j];
            } while(j != i);
        }
    }
    ll res = 1;
    while(ciclos--) res *= 2, res %= mod;
    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) b();
    return 0;
}