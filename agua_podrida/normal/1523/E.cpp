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
const ll INF  = 1e18;
const double eps = 0.000000001;

const int N = 1e5;
ll fact[N+1];

void calc_fact(){
    fact[0] = 1;
    F1(i,N) fact[i] = (fact[i-1]*(ll) i) % mod;
}

ll powmod(ll a, int exp){
    if(exp == 0) return 1;
    ll b = powmod(a,exp/2);
    b *= b;
    b %= mod;
    if(exp%2) b *= a;
    return b % mod;
}

ll inv(ll a){
    return powmod(a,mod-2);
}

ll comb(int n, int k){
    ll res = fact[n] * inv(fact[k]);
    res %= mod;
    res *= inv(fact[n-k]);
    return res % mod;
}

void e(){
    int n,k;
    cin>>n>>k;
    vll P(n+2);
    F1(p,n){
        if(p > n-(k-1)*(p-1)) break;
        P[p] = comb(n - (k-1)*(p-1),p);
        P[p] *= inv(comb(n,p));
        P[p] %= mod;
    }
    ll res = 1;
    F1(i,n){
        res += (P[i] - P[i+1]) * (ll) i;
        res %= mod;
    }
    cout<<res<<'\n';
}

int main(){
    calc_fact();
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) e();
    return 0;
}